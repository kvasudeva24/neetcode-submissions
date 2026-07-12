class Solution {
public:
    vector<vector<string>> allPartitions;
    vector<string> curPartition;
    string input;

    vector<vector<string>> partition(string s) {
        input = s;
        findPalindromes(0, 0);
        return allPartitions;
    }

    void findPalindromes(int i, int lastStart) {
        if ( (i == input.size()) && (lastStart == input.size()) ) {
            allPartitions.push_back(curPartition);
            return;
        } 

        if ( i == input.size() ) {
            return;
        }

        for (int j = i; j < input.size(); j++ ) {
            if ( isPalindrome(lastStart, j) ) {
                string palin = input.substr(lastStart, j-lastStart+1);
                curPartition.push_back(palin);
                findPalindromes(j+1, j+1);
                curPartition.pop_back();
            }
        }
        
    } 

    bool isPalindrome(const int& i, const int& j) {
        int l = i;
        int r = j;

        while ( l < r ) {
            if ( input[l] == input[r] ) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }
};
