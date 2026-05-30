class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> indegree;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        indegree = vector(numCourses, 0);
        for(const auto& v : prerequisites){
            graph[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }

        vector<int> ans;
        queue<int> q;
        for(int course = 0; course < numCourses; course++){
            if(indegree[course] == 0){
                q.push(course);
            }
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            ans.push_back(cur);

            if(graph.count(cur)){
                for(const auto& nextCourse : graph[cur]){
                    if(--indegree[nextCourse] == 0){
                        q.push(nextCourse);
                    }
                }
            }
        }

        return (ans.size() == numCourses) ? ans : vector<int>();
    }
};
