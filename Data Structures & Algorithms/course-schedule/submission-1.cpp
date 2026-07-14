class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> graph;

        for ( int i = 0; i < numCourses; i++ ) {
            indegree[i] = 0;
            graph[i] = vector<int>();
        }

        for ( auto v : prerequisites ) {
            graph[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }

        queue<int> schedule;

        for ( const auto& [course, prereq] : indegree ) {
            if ( prereq == 0 ) {
                schedule.push(course);
            }
        }

        int coursesTaken = 0;

        while ( !schedule.empty() ) {
            auto course = schedule.front();
            coursesTaken++;
            schedule.pop();
            indegree.erase(course);

            for ( int nextCourse : graph[course] ) {
                indegree[nextCourse]--;
                if ( indegree[nextCourse] == 0 ) {
                    schedule.push(nextCourse);
                }
            }
        }

        cout << indegree.size() << endl;

        return (coursesTaken == numCourses);
    }
};
