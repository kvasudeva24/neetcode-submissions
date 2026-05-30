class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> sm;
        map<char,int> tm;

        if(s.size() != t.size()) return false;
        for(int i = 0; i<s.size(); i++){
            sm[s[i]]++;
            tm[t[i]]++;
        }



        return tm == sm;
    }
};
