class Solution {
public:
    int search(vector<int>& nums, int target) {
        if ( nums.size() == 1 && nums[0] == target ) { return 0;}

        int left = 0;
        int right = nums.size() - 1;;

        while ( left < right ) {
            int mid = left + ( right - left ) / 2;

            if ( nums[mid] == target ) { return mid; }

            if ( nums[mid] > nums[right] ) {
                if ( target < nums[mid] && target > nums[right] ) { right = mid; }
                else { left = mid + 1; }
            } else {
                if ( nums[mid] < target && target <= nums[right] ) { left = mid + 1; }
                else { right = mid; }
            }
        }
        if ( nums[left] == target ) { return left; }
        return -1;
    }
};
