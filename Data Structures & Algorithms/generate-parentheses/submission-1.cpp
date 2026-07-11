class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> allStrings;
        string curString = "";
        createParen(n, n, curString, allStrings);
        return allStrings;
    }

    void createParen(int leftGood, int rightGood, string& curString, vector<string>& allStrings) {
        if ( (leftGood == 0) && (rightGood == 0) ) {
            allStrings.push_back(curString);
        }

        if ( leftGood == rightGood ) {
            curString.push_back('(');
            createParen(leftGood - 1, rightGood, curString, allStrings);
            curString.pop_back();
        } else {

            if ( leftGood > 0 ) {
                curString.push_back('(');
                createParen(leftGood - 1, rightGood, curString, allStrings);
                curString.pop_back();
            }

            if ( rightGood > 0 ) {
                curString.push_back(')');
                createParen(leftGood, rightGood - 1, curString, allStrings);
                curString.pop_back();
            }

        }
    }
};
