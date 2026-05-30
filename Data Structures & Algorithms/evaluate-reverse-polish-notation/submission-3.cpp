class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for ( const auto& token : tokens ){
            
            if ( isdigit(token[0]) || token.size() > 1) {
                cout << stk.size() << endl;
                stk.push(stoi(token));
            } else {
                int second = stk.top();
                cout << second << endl;
                stk.pop();
                int first = stk.top();
                cout << first << endl;
                stk.pop();

                int result = 0;

                if ( token == "+" ) {
                    result = first + second;
                } else if ( token == "-" ) {
                    result = first - second;
                } else if ( token == "*" ) {
                    result = first * second;
                } else {
                    result = first / second;
                }
                cout << result << endl;
                stk.push(result);
            }
        }

        return stk.top();
    }
};
