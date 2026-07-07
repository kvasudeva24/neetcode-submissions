class Solution {
public:
    unordered_map<char, int> taskCount;
    priority_queue<pair<int, char>> schedule;
    queue<pair<char, int>> blocked;

    int leastInterval(vector<char>& tasks, int n) {
        
        int time = 0;

        for ( const auto c : tasks ) {
            taskCount[c]++;
        }

        for ( const auto& [c, count] : taskCount ) {
            schedule.push({count, c});
        }

        while ( (schedule.size() + blocked.size()) != 0 ) {
            time++;
            cout << "Blocked size: " << blocked.size() << endl;
            removeBlockedTasks(time);

            if (schedule.empty()) {
                continue;
            }

            auto [count, c] = schedule.top();

            cout << "Char: " << c << " - Count: " << count << endl;

            schedule.pop();
            
            if (count == 1) {
                continue;
            }
            

            taskCount[c]--;
            if ( n == 0 ) {
                schedule.push({taskCount[c], c});
                continue;
            }
        
            int nextAllowed = time + n;
            blocked.push({c, nextAllowed});

            cout << "Next: " << nextAllowed << endl;
            cout << "Blocked size: " << blocked.size() << endl;
            cout << "---" << endl;
        }
        return time;
    }

    void removeBlockedTasks(const int& time) {
        while ( !blocked.empty() ) {
            auto [c, nextTime] = blocked.front();
            
            if ( time > nextTime ) {
                blocked.pop();
                schedule.push({taskCount[c], c});
            } else {
                break;
            }
        }
    }
};
