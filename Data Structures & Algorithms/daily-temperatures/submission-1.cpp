class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int,int>> s;

        for(int i = 0; i<ans.size(); i++){
            while(!s.empty() && temperatures[i] > s.top().first){
                ans[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({temperatures[i], i});
        }
        return ans;

    }
};
