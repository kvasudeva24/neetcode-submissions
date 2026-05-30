class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq_count;

        for ( size_t i = 0; i < nums.size(); i++ ) freq_count[nums[i]]++;

        priority_queue<pair<int,int>> pq;

        for ( const auto& [num, count] : freq_count ) {
            pq.push({count, num});
        }

        vector<int> ans;

        while ( !pq.empty() && k > 0 ) {
            auto [_ , num] = pq.top();
            pq.pop();

            ans.push_back(num);
            k--;
        } 

        return ans;


    }    
};
