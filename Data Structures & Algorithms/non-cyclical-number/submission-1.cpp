class Solution {
public:
    bool isHappy(int n) {
        set<int> seen;

        while(!seen.count(n)){
            if(n == 1) return true;

            seen.insert(n);

            string cur = to_string(n);
            int sum = 0;

            for(char c : cur) sum += ((c - '0') * (c-'0'));

            n = sum;
        }
        return false;
    }
};
