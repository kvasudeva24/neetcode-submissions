class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pos_speed;
        for ( int i = 0; i < speed.size(); i++) {
            pos_speed.push_back({position[i], speed[i]});
        }

        sort(pos_speed.begin(), pos_speed.end());

        stack<double> times;

        for ( int i = pos_speed.size() - 1; i >= 0; i-- ) {
            auto [pos, spd] = pos_speed[i];

            cout << "Pos: " << pos << endl;
            cout << "Spd: " << spd << endl;

            double finish_time = (target - pos) / static_cast<double>(spd);
            cout << "F Time: " << finish_time << endl;

            if ( times.empty() ) { times.push(finish_time); }

            if ( finish_time > times.top() ) { times.push(finish_time); }
        }
        return times.size();
    }
};
