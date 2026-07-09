class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> curSubset;
        findSubsets(0, subsets, curSubset, nums);
        return subsets;
    }

    void findSubsets(int i, vector<vector<int>>& subsets, vector<int>& curSubset,
                     const vector<int>& nums) {

        if ( i == nums.size() ) {
            subsets.push_back(curSubset);
            return;
        }


        curSubset.push_back(nums[i]);
        findSubsets(i+1, subsets, curSubset, nums);
        curSubset.pop_back();

        findSubsets(i+1, subsets, curSubset, nums);

    }
};
