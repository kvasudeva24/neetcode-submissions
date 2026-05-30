class Solution {
public:
    map<vector<int>, bool> seen;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        vector<int> path;
        int curSum = 0;
        

        backtrack(ans, path, curSum, nums, target, 0);

        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& path, int curSum, const vector<int>& nums, const int& target, int i){
        if(curSum == target){
            ans.push_back(path);
            return;
        }

        for(int j = i; j<nums.size(); j++){
            if(curSum + nums[j] <= target){
                path.push_back(nums[j]);
                backtrack(ans, path, curSum + nums[j], nums, target, j);
                path.pop_back();
            }
        }
    }
};
