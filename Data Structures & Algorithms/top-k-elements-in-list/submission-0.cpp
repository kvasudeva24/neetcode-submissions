class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> map;
        for(int num : nums){
            map[num]++;
        }

        priority_queue<pair<int,int>> q;
        for(const auto [n, f] : map){
            q.push({f, n});
        }

        vector<int> ans;
        while(k>0){
            ans.push_back(q.top().second);
            q.pop();
            k--;
        }
        return ans;
    }
};
