class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> bank = {wordList.begin(), wordList.end()};
        if(!bank.count(endWord)) return 0;

        unordered_set<string> seen;
        queue<pair<string, int>> q;

        q.push({beginWord, 1});
        seen.insert(beginWord);

        std::function<vector<string>(string)> combinations = [=](string s){
            vector<string> ans;
            for(int i = 0; i<s.size(); i++){
                string temp = s;
                for(char c = 'a'; c<='z'; c++){
                    temp[i] = c;
                    if(temp != s) ans.push_back(temp);
                }
            }
            return ans;
        };


        while(!q.empty()){
            auto [word, steps] = q.front();
            cout << word << endl;
            q.pop();

            if(word == endWord) return steps;

            vector<string> nextWords = combinations(word);

            for(auto next : nextWords){
                if(!seen.count(next) && bank.count(next)){
                    seen.insert(next);
                    q.push({next, steps + 1});
                }
            }
        }
        return 0;

    }
};
