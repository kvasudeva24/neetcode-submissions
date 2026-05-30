class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 1;
        int startIndex = 0;
        for(int i = 0; i<s.size(); i++){
            //odd case
            int left = i - 1;
            int right = i + 1;
            while(left >= 0 && right < s.size() && (s[left] == s[right])){
                if(right - left + 1 > ans){
                    startIndex = left;
                    ans = right - left + 1;
                }
                left--; 
                right++;
            }

            //even case
            if(i+1 < s.size() && s[i+1] == s[i]){
                
                //check if two is the longest substring
                if(2 > ans){
                    startIndex = i;
                    ans = 2;
                }

                int e_right = i+2;
                int e_left = i-1;
                while(e_left >= 0 && e_right < s.size() && (s[e_left] == s[e_right])){
                    if(e_right - e_left + 1 > ans){
                        startIndex = e_left;
                        ans = e_right - e_left + 1;
                    }
                    e_left--; 
                    e_right++;
                }
            }
        }
        string palin = s.substr(startIndex, ans);
        cout << palin << endl;
        return palin;
    }
};
