class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 1);
        vector<int> postfix(nums.size(), 1);

        for ( int i = 0; i < nums.size(); i++ ) {
            if ( i == 0 ) continue;

            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for ( int i = nums.size() - 1; i >= 0; i-- ) {
            if ( i == nums.size() - 1 ) continue;

            postfix[i] = postfix[i+1] * nums[i+1];
        }

        vector<int> ans;
        for ( int i = 0; i < nums.size(); i++ ) {
            ans.push_back(prefix[i] * postfix[i]);
        }


        return ans;
    }
};
