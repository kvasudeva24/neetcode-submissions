class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> dict;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        dict[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if ( dict[key].size() == 0 ) { return ""; }

        auto& v = dict[key];
        int left = 0;
        int right = v.size() - 1;

        while ( left < right ) {
            int mid =  left + (right - left)/2;

            if ( v[mid].first == timestamp )  { return  v[mid].second; }

            if ( timestamp > v[mid].first ) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if ( v[left].first <= timestamp ) { return v[left].second; }
        else { return ( left == 0 ) ? "" : v[left-1].second; }

    }
};
