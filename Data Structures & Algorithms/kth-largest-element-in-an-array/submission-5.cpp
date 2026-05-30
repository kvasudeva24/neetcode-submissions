class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, k);
    }

    int quickselect(const vector<int>& nums, int k){
        vector<int> left;
        vector<int>  middle;
        vector<int> right;

        int pivot = nums[rand() % nums.size()];

        for(int num : nums){
            if(num > pivot) right.push_back(num);
            if(num < pivot) left.push_back(num);
            if(num == pivot) middle.push_back(num);
        }
        

        if(right.size() >= k) return quickselect(right,  k);
        else if(right.size() + middle.size() < k) return quickselect(left, k - right.size() - middle.size());
        else return pivot;

    }
};
