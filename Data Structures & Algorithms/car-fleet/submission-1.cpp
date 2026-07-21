class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int size = position.size();
        for(int i = 0;i<size;i++) {
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end(), [](const pair<int,int> &a,const pair<int,int> &b) {
            return a.first > b.first;
        });
        float leadCarTime = 0;
        int fleetCount = 0;
        for(int i = 0;i<size;i++) {
            float time = (float)(target - cars[i].first)/cars[i].second;
            if(time > leadCarTime) {
                fleetCount+= 1;
                leadCarTime = time;
            }
        }
        return fleetCount;
    }
};
