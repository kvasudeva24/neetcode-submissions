class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i<nums.size(); i++){
            for(int j = 0; j<nums.size(); j++){
                if(i==j) continue;
                if(nums[i] == target - nums[j]){
                    vector<int> ans = {i, j};
                    sort(ans.begin(), ans.end());
                    return ans;
                }
            }
        }
        return vector<int>();
    }
};
