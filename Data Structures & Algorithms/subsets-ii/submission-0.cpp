class Solution {
public:

    set<vector<int>> seenSets;
    vector<int> arr;
    vector<vector<int>> allSubsets;
    vector<int> curSet;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        arr = nums;

        findSubsets(0);
        return allSubsets;
    }

    void findSubsets(int i) {

        if ( i == arr.size() && !seenSets.count(curSet)) {
            seenSets.insert(curSet);
            allSubsets.push_back(curSet);
            return;
        } else if ( i == arr.size() ) {
            return;
        }

        curSet.push_back(arr[i]);
        findSubsets(i+1);
        curSet.pop_back();

        findSubsets(i+1);
    }
};
