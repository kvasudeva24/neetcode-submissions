class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0; 
        int right = nums.size() - 1;

        while ( left < right ) {
            int mid = left + ( right - left )/2;

            if ( nums[mid] > nums[right] ) { left = mid+1; }
            else { right = mid;}
        }
        return nums[left];
    }
};



/*
case: left > mid < right (return)
case : left < mid > right 7 8 1 -> seach right
case : left < mid < right 1 2 3 --> search left ???


T(n/2) + O(1)

one call with constant work per call

*/