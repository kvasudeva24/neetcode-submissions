class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int l = 0;
        int l_wall = height[l];
        int r = height.size() - 1;
        int r_wall = height[r];

        while ( l < r ) {
            if ( l_wall <= r_wall ) {
                l++;
                while ( height[l] < l_wall ) {
                    water += (l_wall - height[l]);
                    l++;
                }
                l_wall = height[l];
            } else {
                r--;
                while ( height[r] < r_wall ) {
                    water += ( r_wall - height[r]);
                    r--;
                }
                r_wall = height[r];
            }
        }
        return water;
    }
};
