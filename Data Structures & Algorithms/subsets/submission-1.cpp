class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int i = 0;
        backtrack(ans, path, 0, nums);
        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& path, int i, const vector<int>& nums){
        if(find(ans.begin(), ans.end(), path) == ans.end()){
            ans.push_back(path);
        }

        if(path.size() == ans.size()) return;

        
        for(int j = i; j<nums.size(); j++){
            path.push_back(nums[j]);
            backtrack(ans, path, j+1, nums);
            path.pop_back();
        }
    }
};
