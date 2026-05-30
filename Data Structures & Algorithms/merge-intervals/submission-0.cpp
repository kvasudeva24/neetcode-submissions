class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for(auto& inter : intervals){
            int start = inter[0];
            int end = inter[1];
            if(ans.empty()){
                ans.push_back({start, end});
            } else if (start <= ans.back()[1]){
                ans.back() = {min(ans.back()[0], start), max(ans.back()[1], end)};
            } else {
                ans.push_back({start, end});
            }
        }
        return ans;
    }
};
