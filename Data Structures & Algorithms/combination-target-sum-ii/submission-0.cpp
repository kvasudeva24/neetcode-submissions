class Solution {
public:


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

      vector<vector<int>> ans;
      vector<int> path;
      int cur = 0;
      int i = 0;
      backtrack(ans, path, cur, i, target, candidates);
      return ans;  
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& path, int cur, int i, const int& target, const vector<int>& nums){
        if(cur == target){
            if(find(ans.begin(), ans.end(), path) == ans.end()){
                ans.push_back(path);
            }
            return;
        }

        for(int j = i; j<nums.size(); j++){
            if(nums[j] + cur > target) continue;
            else {
                cur += nums[j];
                path.push_back(nums[j]);
                backtrack(ans, path, cur, j+1, target, nums);
                path.pop_back();
                cur -= nums[j];
            }
        }
    }
};
