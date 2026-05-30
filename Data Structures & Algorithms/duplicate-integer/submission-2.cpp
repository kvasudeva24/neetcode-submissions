class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(const int& num : nums){
            if(++map[num] > 1){
                return true;
            }
        }
        return false;
    }
};