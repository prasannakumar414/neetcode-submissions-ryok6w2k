class Solution {
public:
    double getDistance(int x, int y) {
        return sqrt(x*x + y*y);
    }
    struct CustomOp {
        bool operator()(const pair<double,vector<int>>& a, const pair<double,vector<int>>& b) const {
            return a.first > b.first;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)    {
        priority_queue<
        pair<double,vector<int>>,
        vector<pair<double,vector<int>>>,
        CustomOp
        > heap;
        for(int i = 0;i<points.size();i++) {
            heap.push({getDistance(points[i][0],points[i][1]), points[i]});
        }
        vector<vector<int>> result;
        while(k--) {
            //cout << heap.top().first << endl;
            result.push_back(heap.top().second);
            heap.pop();
        }
        return result;
    }
};
