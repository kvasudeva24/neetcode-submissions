class Solution {
public:
    int climbStairs(int n) {
        vector<int> stairs(n+1, 0);
        return NumWays(stairs, n);
    }

    int NumWays(vector<int>& stairs, int n){
        if ( n == 0 ) { return 0; }
        if ( n == 1 ) { return 1; }
        if ( n == 2 ) { return 2; }

        int result = NumWays(stairs, n-1) + NumWays(stairs, n-2);
        stairs[n] = result;
        return result;
    }
};
