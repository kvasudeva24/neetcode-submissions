#include <set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> duplicates;
        for(int num : nums){
            if(duplicates.find(num) != duplicates.end()){
                return true;
            } else {
                duplicates.insert(num);
            }
        }
        return false;
    }
};
