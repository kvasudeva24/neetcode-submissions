class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;


        //set up deck
        deque<int> window;
        for(int s = 0; s<k; s++){
            while(!window.empty() && nums[s] > nums[window.back()]){
                window.pop_back();
            }
            window.push_back(s);
        }
        ans.push_back(nums[window.front()]);


        //now iterate (monotonic decreasing)
        int left = 1;
        for(int right = k; right<nums.size(); right++){
            if(window.front() < left) window.pop_front();

            while(!window.empty() && nums[right] > nums[window.back()]){
                window.pop_back();
            }
            window.push_back(right);

            ans.push_back(nums[window.front()]);
            left++;
        }
        return ans;
    }
};
