class Solution {
public:

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

        allSubsets.push_back(curSet);

        for ( int j = i; j < arr.size(); j++) {
            if ( j > i && arr[j] == arr[j-1] ) { continue; }

            curSet.push_back(arr[j]);
            findSubsets(j+1);
            curSet.pop_back();
        }

    }
};
