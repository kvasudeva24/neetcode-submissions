class Solution {
public:
    vector<int> numbers;
    int goal;
    set<vector<int>> seenCombos;


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> combo;
        sort(candidates.begin(), candidates.end());
        numbers = candidates;
        goal = target;

        findSum(0, 0, combo, combinations);
        return combinations;
    }

    void findSum(int i, int sum, vector<int>& combo, vector<vector<int>>& combinations) {

        if ( sum == goal && !seenCombos.count(combo) ) { 
            seenCombos.insert(combo);
            combinations.push_back(combo);
            return;
        }

        if ( i == numbers.size() ) { return; }

        for ( int j = i; j < numbers.size(); j++) {
            if ( numbers[j] == numbers[i] && j > i) { continue; }

            if ( (sum + numbers[j]) > goal ) { continue; }
            
            combo.push_back(numbers[j]);
            findSum(j+1, sum + numbers[j], combo, combinations);
            combo.pop_back();
        }
    }
};
