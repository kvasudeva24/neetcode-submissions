class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> combined;
        for ( int i = 0; i < position.size(); i++ ) {
            combined.push_back({position[i], speed[i]});
        }

        sort(combined.begin(), combined.end());

        stack<double> finish_time;

        for ( int i = combined.size() - 1; i >=0 ; i-- ) {
            int pos = combined[i].first;
            int spd = combined[i].second;

            int displacement = target - pos;
            double time = (double)displacement/spd;

            cout << pos << ":" << spd << endl;
            cout << time << endl;

            if ( finish_time.empty() ) {
                finish_time.push(time);
            } else {
                if ( time > finish_time.top() ) { finish_time.push(time); }
            }
        }
        return finish_time.size();
    }
};
