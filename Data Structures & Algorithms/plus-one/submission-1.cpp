class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cin = 1;
        vector<int> ans;
        for(int i = digits.size() - 1; i>=0; i--){
            int sum = digits[i] + cin;
            int res = sum % 10;
            cin = sum / 10;
            ans.push_back(res);
        }
        if(cin){
            ans.push_back(cin);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
