class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> curSubset;
        subsets.push_back(curSubset);
        findSubsets(0, subsets, curSubset, nums);
        return subsets;
    }

    void findSubsets(int i, vector<vector<int>>& subsets, vector<int>& curSubset,
                     const vector<int>& nums) {

        if ( i == nums.size() ) {
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            curSubset.push_back(nums[j]);
            subsets.push_back(curSubset);
            findSubsets(j+1, subsets, curSubset, nums);
            curSubset.pop_back();
        }
    }
};
