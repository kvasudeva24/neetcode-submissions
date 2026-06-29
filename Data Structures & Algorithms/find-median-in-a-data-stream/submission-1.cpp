class MedianFinder {
public:
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
    double cur_median = INT_MAX;
    

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if ( cur_median == INT_MAX ) {
            low.push(num);
            cur_median = num;
            return;
        } else if ( num <= cur_median) {
            low.push(num);
            if ( low.size() - high.size() > 1) {
                int move = low.top();
                low.pop();
                high.push(move);
                cur_median = (low.top() + move)/2.0;
            } else if ( (low.size() + high.size()) % 2 == 0) {
                cur_median = (low.top() + high.top())/2.0;
            }  else {
                cur_median = low.top();
            }
        } else {
            cout << num << endl;
            cout << cur_median << endl;

            high.push(num);
            if ( high.size() - low.size() > 1) {
                int move = high.top();
                high.pop();
                low.push(move);
                cur_median = (high.top() + move)/2.0;
            } else if ( (low.size() + high.size()) % 2 == 0) {
                cur_median = (low.top() + high.top())/2.0;
            }  else {
                cur_median = high.top();
            }
            cout << "-" << endl;
        }
    }
    
    double findMedian() {
        return cur_median;
    }
};
