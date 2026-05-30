class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
 
        int total = 0;
        while ( left != right ) {
            int l_wall = height[left];
            int r_wall = height[right];

            //two cases 

            if ( l_wall < r_wall ) {
                while ( left != right ) {
                    left++;
                    
                    if ( height[left] >= l_wall ) {
                        break;
                    } else {
                        total += (l_wall - height[left]);
                    }
                }
            } else {
                while ( left != right ) {
                    right--;
                    
                    if ( height[right] >= r_wall ) {
                        break;
                    } else {
                        total += (r_wall - height[right]);
                    }
                }
            }
        }
        return total;
    }
};
