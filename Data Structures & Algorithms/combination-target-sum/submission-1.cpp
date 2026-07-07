class Solution {
public:
    int tar;
    vector<int> numbers;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        tar = target;
        numbers = nums;

        sort(nums.begin(), nums.end());

        vector<vector<int>> groups;
        vector<int> curGroup;
        
        findSum(0, 0, groups, curGroup);
        return groups;
    }

    void findSum(int i, int cur, vector<vector<int>>& groups, vector<int>& curGroup) {
        if ( i == numbers.size()) {
            return;
        }

        if ( cur > tar ) {
            return;
        } 

        if ( cur == tar ) {
            groups.push_back(curGroup);
            return;
        }

        curGroup.push_back(numbers[i]);
        findSum(i, cur + numbers[i], groups, curGroup);
        curGroup.pop_back();

        findSum(i+1, cur, groups, curGroup);
    }
};
