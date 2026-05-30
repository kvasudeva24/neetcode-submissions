class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;

        backtrack(ans, path, nums);

        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& path, const vector<int>& nums){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }

        for(int i = 0; i<nums.size(); i++){
            if(find(path.begin(), path.end(), nums[i]) == path.end()){
                path.push_back(nums[i]);
                backtrack(ans, path, nums);
                path.pop_back();
            } else {
                continue;
            }
        }
    }
};
