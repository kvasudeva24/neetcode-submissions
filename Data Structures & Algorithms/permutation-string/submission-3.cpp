class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> bank(26, 0);
        for(auto& c : s1){
            bank[c-97]++;
        }

        vector<int> run(26, 0);
        int left = 0;

        for(int i = 0; i<s2.size(); i++){
            char cur = s2[i];

            if(bank[cur-97] == 0){
                run = vector(26,0);
                continue;
            }

            run[cur-97]++;
            if(run[cur-97] > bank[cur-97]){
                while(run[cur-97] > bank[cur-97]){
                    run[s2[left] - 97]--;
                    left++;
                }
                

            } else {
                if(run == bank) return true;
            }
        }
        return false;
    }
};
