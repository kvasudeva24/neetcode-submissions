class Solution {
public:
    int numDistinct(string s, string t) {
        int ans = 0;
        string path = "";
        int i = 0;
        backtrack(path, t, s, i, ans);
        return ans;
    }

    void backtrack(string curr, const string& target, const string& s, int i, int& ans){
        if(curr == target){
            ans++;
            return;
        }

        if(!curr.empty() && target.find(curr) != 0) return;

        if(curr.size() == target.size() && curr != target) return;

        for(int j = i; j<s.size(); j++){
            curr.push_back(s[j]);
            backtrack(curr, target, s, j+1, ans);
            curr.pop_back();
        }
    }
};
