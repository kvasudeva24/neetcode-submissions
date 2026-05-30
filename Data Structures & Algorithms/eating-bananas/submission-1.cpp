class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int slow = 1;
        int fast = *max_element(piles.begin(), piles.end());

        while ( slow < fast ) {
            int new_speed = slow + (fast - slow)/2;

            int new_hours = time_to_eat(piles, new_speed);
            if ( new_hours > h ) { slow = new_speed + 1; }
            else { fast = new_speed; }
        }
        return slow;
    }

    int time_to_eat(const vector<int>& piles, int speed) {
        int hours = 0;
        for ( auto pile : piles ) {
            double hrs = (double)pile/speed;
            hours += ceil(hrs);
        }
        return hours;
    }
};  
