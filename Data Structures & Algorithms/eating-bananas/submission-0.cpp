class Solution {
public:
    vector<int> p;
    int limit;

    int minEatingSpeed(vector<int>& piles, int h) {
        p = piles;
        limit = h;

        int left = 1;
        int right = 0;
        for(int p : piles){
            right = max(right, p);
        }

        while(left < right){
            int mid = left + (right - left) / 2;
            if(check(mid)){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool check(int& speed){
        long hours = 0;
        for(double bananas : p){
            hours += ceil(bananas/speed);
        }
        return hours <= limit;
    }
};