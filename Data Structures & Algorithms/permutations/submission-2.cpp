class Solution {
public:
    vector<int> numbers;


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> group;
        unordered_set<int> seen;

        numbers = nums;

        findPermutations(group, seen, permutations);
        return permutations;
    }

    void findPermutations(vector<int>& group, unordered_set<int>& seen, vector<vector<int>>& permutations){

        if ( group.size() == numbers.size() ) {
            permutations.push_back(group);
            return;
        }

        for ( int num : numbers ) {
            if ( !seen.count(num) ) {
                group.push_back(num);
                seen.insert(num);
                findPermutations(group, seen, permutations);
                seen.erase(num);
                group.pop_back();
            }
        }

    }

};
