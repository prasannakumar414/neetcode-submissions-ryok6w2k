class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> maxHeap;
        unordered_map<int,int> Nmap;
        vector<int> values;
        for(int i=0;i<nums.size();i++) {
            Nmap[nums[i]] += 1;
        }
        for(const auto &[key,v] : Nmap) {
            maxHeap.push({v,key});
        }
        while(k--) {
            pair<int,int> val = maxHeap.top();
            values.push_back(val.second);
            maxHeap.pop();
        }
        return values;
    }
};
