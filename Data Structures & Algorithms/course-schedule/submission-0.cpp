class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);

        for(const auto& pre : prerequisites){
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
            cout << pre[0] << endl;
            cout << indegree[pre[0]] << endl;
        }

        unordered_set<int> seen;
        queue<int> q;
        int counter = 0;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
                seen.insert(i);
                counter++;
            } 
        }

        while(!q.empty()){
            auto course = q.front(); q.pop();

            for(auto nbor : graph[course]){
                if(--indegree[nbor] == 0 && !seen.count(nbor)){
                    counter++;
                    q.push(nbor);
                }
            }
        }
        return counter == numCourses;
    }
};
