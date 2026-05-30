class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> warmer = vector(temperatures.size(), 0);

        stack<pair<int,int>> stk;

        for ( int i = 0; i < temperatures.size(); i++ ) {
            
            while ( !stk.empty() && stk.top().first < temperatures[i] ) {
                auto [_, idx] = stk.top();
                stk.pop();
                warmer[idx] = i - idx;
            } 

            stk.push({temperatures[i], i});

        }
        return warmer;
    }
};
