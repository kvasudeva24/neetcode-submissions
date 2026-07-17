class Solution {
public:
    string target;
    int n;
    int lastIndex;
    vector<int> numSubstrings;

    int countSubstrings(string s) {
        target = s;
        n = target.size();
        lastIndex = n - 1;
        numSubstrings = vector(n, -1);

        return numPalinSubstrings(0);
    }

    int numPalinSubstrings(int i) {
        if ( i > lastIndex ) {
            return 0;
        }

        if ( numSubstrings[i] != -1 ) {
            return numSubstrings[i];
        }

        int sum = 0;
        for ( int j = i; j < n; j++ ) {
            sum += isPalindrome(i, j);
        }

        sum += numPalinSubstrings(i+1);
        numSubstrings[i] = sum;
        return sum;
    }


    bool isPalindrome(int i, int j) {
        while ( i < j ) {
            if ( target[i] == target[j] ) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
};



/*

numPalinSubstrings(i) = the number of palindromic substrings in the string s[i...n]

isPalindrome(i, j) = TRUE if s[i..j] is a palindrome


base case:
    0 if i > n

recurrence: 
    SUM(from j = i to n) (IsPalindrome(i, j)) + numPalinSubstrings(i+1)


*/