class Solution {
public:
    int numDistinct(string s, string t) {
        int i = 0;
        int counter = 0;
        string cur = "";
        backtrack(cur, s, t, i, counter);
        return counter;
    }

    void backtrack(string& curr, const string& bank, const string& target, int i, int& counter){
        if(curr == target){
            counter++;
            return;
        }

        if(curr.size() == target.size()){
            return;
        }


        for(int j = i; j<bank.size(); j++){
            if(target[curr.size()] == bank[j]){
                curr.push_back(bank[j]);
                backtrack(curr, bank, target, j+1, counter);
                curr.pop_back();
            } else {
                continue;
            }
        }
    }
};
