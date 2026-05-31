class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;

        if ( A.size() < B.size() ) { swap(A, B); }

        int left = -1;
        int right = A.size() - 1;

        int total_elements = A.size() + B.size();
        int floor_half = total_elements / 2;


        while ( left <= right ) {
            int mid = left + ( right - left )/2;

            int i = ( floor_half - (mid+1) ) - 1;

            int A_left = ( mid == -1 ) ? INT_MIN : A[mid];
            int A_right = ( mid == A.size() - 1 ) ? INT_MAX : A[mid+1];
            int B_left = ( i == -1 ) ? INT_MIN : B[i];
            int B_right = ( i == B.size() - 1 ) ? INT_MAX : B[i+1];

            cout << mid << endl;
            cout << i << endl;
            cout << A_left << endl;
            cout << A_right << endl;
            cout << B_left << endl;
            cout << B_right << endl;
            cout << "-" << endl;

            if ( A_left <= B_right && B_left <= A_right ) {
                if ( total_elements % 2 == 0 ) {
                    return static_cast<double>( (max(A_left, B_left) + min(A_right, B_right))/2.0 );
                } else {
                    return static_cast<double>( min(B_right, A_right) );
                }
            }

            cout << "Triggers" << endl;

            if ( A_left > B_right ) { right = mid - 1; }
            else { left = mid + 1; }


        }
        return 0.0;
    }
};
