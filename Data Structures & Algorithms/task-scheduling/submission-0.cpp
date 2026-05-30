class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(char c : tasks){
            freq[c]++;
        }

        priority_queue<pair<int, char>> q;
        for(auto [c, quant] : freq){
            q.push({quant,c});
        }

        deque<tuple<int,char,int>> cool;

        int time = 0;

        while(!q.empty() || !cool.empty()){
            if(!cool.empty()){
                auto[count, c, t] = cool.front();
                if(t == time){
                    cool.pop_front();
                    q.push({count, c}); 
                }
            }

            if(!q.empty()){
                auto [count, c] = q.top();
                q.pop();

                if(count != 1) cool.push_back({count-1, c, time + n+1});
            }

            time++;
        }
        return time;

    }
};
