class Solution {
public:
    unordered_map<string, list<string>> graph;
    vector<vector<string>> flights;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        flights = tickets;
        sort(flights.begin(), flights.end());
        for ( const auto& v : flights ) {
            graph[v[0]].push_back(v[1]);
        }

        vector<string> flightPath = {"JFK"};
        findFlightPath("JFK", flightPath);

        return flightPath;
    }

    bool findFlightPath(string airport, vector<string>& flightPath) {
        if ( flightPath.size() == flights.size() + 1 ) {
            return true;
        } 

        if ( !graph.count(airport) ) {
            return false;
        }

        auto nborCopy = graph[airport];
        int i = 0;
        for ( const auto& nborAirport : nborCopy ) {
            auto iter = graph[airport].begin();
            advance(iter, i);

            auto insertBack = graph[airport].erase(iter);
            flightPath.push_back(nborAirport);

            if ( findFlightPath(nborAirport, flightPath) == false ) {
                graph[airport].insert(insertBack, nborAirport);
                flightPath.pop_back();
                i++;
            } else {
                return true;
            }
        }
        return false;
    }
};
