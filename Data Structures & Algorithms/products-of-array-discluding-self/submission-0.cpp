class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> postfix(nums.size(), -1);
        for(int i = 0; i<nums.size(); i++){
            if(i == 0){
                prefix.push_back(nums[i]);
                continue;
            } 
            prefix.push_back(prefix[i-1] * nums[i]);
        }

        for(int i = nums.size() - 1; i>-1; i--){
            if(i == nums.size() - 1){
               postfix[i] = nums[i];
                continue;
            } 
            postfix[i] = postfix[i+1] * nums[i];
        }
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            if(i==0){
                ans.push_back(postfix[i+1]);
                continue;
            }
            if(i == nums.size() - 1){
                ans.push_back(prefix[i-1]);
                continue;
            }

            ans.push_back(prefix[i-1] * postfix[i+1]);    
        }

        return ans;
    }
};
