class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> net;
        for(int i = 0; i<gas.size(); i++){
            net.push_back(gas[i]-cost[i]);
        }
        if(accumulate(net.begin(), net.end(), 0) < 0) return -1;

        int candidate = -1;
        int sum = 0;
        for(int i = 0; i<net.size(); i++){
            int station = net[i];
            sum += station;
            if(sum < 0){
                sum = 0;
                candidate = -1;
            } else {
                if(candidate == -1) candidate = i;
            }
        }
        return candidate;

    }
};
