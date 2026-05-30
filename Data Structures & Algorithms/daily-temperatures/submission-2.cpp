class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stack;
        vector<int> ans(temperatures.size(), 0);
        for(int i = 0; i<temperatures.size(); i++){
            int temp = temperatures[i];

            while(!stack.empty() && temp > stack.top().first){
                auto [_, idx] = stack.top(); stack.pop();
                ans[idx] = i - idx;
            }

            stack.push({temp, i});
        }
        return ans;
    }
};
