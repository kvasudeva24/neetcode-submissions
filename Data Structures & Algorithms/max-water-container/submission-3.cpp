class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int max_area = 0;
        while ( l < r ) {
            if ( min(heights[l], heights[r]) * (r - l) > max_area) { max_area = min(heights[l], heights[r]) * (r - l); }

            if ( heights[l] >= heights[r] ) r--;
            else l++;
        }
        return max_area;
    }
};
