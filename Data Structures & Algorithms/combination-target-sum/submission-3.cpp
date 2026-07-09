class Solution {
public:
    int tar;
    vector<int> numbers;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        tar = target;
        numbers = nums;

        // sort(nums.begin(), nums.end());

        vector<vector<int>> groups;
        vector<int> curGroup;
        
        findSum(0, 0, groups, curGroup);
        return groups;
    }

    void findSum(int i, int cur, vector<vector<int>>& groups, vector<int>& curGroup) {
        if ( i == numbers.size()) {
            return;
        }

        if ( cur == tar ) {
            groups.push_back(curGroup);
            return;
        }


        for ( int j = i; j < numbers.size(); j++) {
            
            if ( cur + numbers[j] > tar ) {
                continue;
            } 


            curGroup.push_back(numbers[j]);
            findSum(j, cur + numbers[j], groups, curGroup);
            curGroup.pop_back();
        }        
    }
};
