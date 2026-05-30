class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto& vec = store[key];
        if ( vec.size() == 0 ) { return ""; }

        int left = 0;
        int right = vec.size() - 1;

        while ( left < right ) {
            int mid = left + (right - left)/2;

            if ( vec[mid].first == timestamp ) { return vec[mid].second; }

            if ( timestamp > vec[mid].first ) { left = mid + 1; }
            else { right = mid - 1; }
        }

        if ( vec[left].first <= timestamp ) { return vec[left].second; }
        if ( left != 0 ) { return vec[left-1].second; }
        return "";
    }
};
