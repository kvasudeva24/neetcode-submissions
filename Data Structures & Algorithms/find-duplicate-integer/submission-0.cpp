class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int num : nums){
            if(++map[num] > 1) return num;
        }
        return -1;
    }
};
