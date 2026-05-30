class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> map;
        for(int num : hand){
            map[num]++;
        }
        while(!map.empty()){
            int back = map.begin()->first;
            if(--map[back] == 0) map.erase(back);
            for(int i = 1; i<groupSize; i++){
                if(map.count(back+1)){
                    if(--map[back+1] == 0) map.erase(back+1);
                    back = back+1;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
