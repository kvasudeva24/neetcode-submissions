class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordBank(wordList.begin(), wordList.end());
        unordered_set<string> seen;

        queue<pair<string, int>> frontier;
        seen.insert(beginWord);
        frontier.push({beginWord, 1});
        
        while ( !frontier.empty() ) {
            auto [word, iterations] = frontier.front();
            frontier.pop();

            if ( word == endWord ) {
                return iterations;
            }

            vector<string> nextWords = generateAllStrings(word);
            
            for ( const auto& next : nextWords ) {
                if ( wordBank.count(next) && !seen.count(next) ) {
                    seen.insert(next);
                    frontier.push({next, iterations + 1});
                }
            }
        }
        return 0;
    }


    vector<string> generateAllStrings(const string& word) {
        vector<string> allWords;

        for ( int i = 0; i < word.size(); i++ ) {
            string temp = word;
            for ( char c = 'a'; c <= 'z'; c++ ) {
                temp[i] = c;
                if ( temp == word  ) { continue; }
                allWords.push_back(temp);
            }
        }
        return allWords;
    }
};
