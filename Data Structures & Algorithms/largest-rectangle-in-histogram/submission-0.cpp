class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> inc_heights;

        int area = -1;

        for ( int i = 0; i < heights.size(); i++ ) {

            cout << "Height: " << heights[i] << endl;
            cout << "Index: " << i << endl;

            int last_pop = -1;

            while ( !inc_heights.empty() && heights[i] < inc_heights.top().first ) {
                auto [h, w] = inc_heights.top();
                cout << "Top Stack Height: " << h << endl;
                cout << "Top Stack Index: " << w << endl;
                inc_heights.pop();
                int width = i - w;
                int cur_area = width * h;
                area = max(area, cur_area);
                last_pop = w;
            }
            inc_heights.push({heights[i], (last_pop == -1) ? i : last_pop });
            cout << "-" << endl;
        }

        int n = heights.size();
        while ( !inc_heights.empty() ) {
            auto [h, w] = inc_heights.top();
            inc_heights.pop();
            int size = ( n - w ) * h;
            area = max(area, size);
        }


        return area;
    }
};
