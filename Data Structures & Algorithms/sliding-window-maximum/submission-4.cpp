class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        if ( k == 1 ) { return nums; }

        vector<int> result;
        deque<pair<int,int>> window;

        //set up window
        for ( int i = 0; i < k; i++ ){

            while ( !window.empty() && nums[i] > window.back().first ) {
                window.pop_back();
            }
            window.push_back({nums[i], i});
        }

        result.push_back(window.front().first);

        for ( int i = k; i < nums.size(); i++ ) {
            //check if front of window is not out of scope

            if ( window.front().second <= i - k ) {
                window.pop_front();
            }

            while ( !window.empty() && nums[i] > window.back().first ) {
                window.pop_back();
            }
            window.push_back({nums[i], i});
            result.push_back(window.front().first);
        }

        return result;

    }
};
