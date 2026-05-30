class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int stone : stones) q.push(stone);

        // auto copy = q;

        while(q.size() > 1){
            // for(int size = 0; size<q.size(); size++){
            //     cout << copy.top() << endl;
            //     copy.pop();
            // } 

            int x = q.top(); q.pop();
            int y = q.top(); q.pop();

            if(x == y) continue;
            else(q.push(abs(y-x)));
            // copy = q;
        }
        return (q.empty()) ? 0 : q.top();
    }
};
