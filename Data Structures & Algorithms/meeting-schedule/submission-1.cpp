/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() == 0) return true;

        vector<pair<int,int>> meeting;
        for(const auto& m : intervals){
            meeting.push_back({m.start, m.end});
        }
        sort(meeting.begin(), meeting.end());


        int lastEnd = meeting[0].second;
        for(int i = 1; i<meeting.size(); i++){
            if(meeting[i].first < lastEnd){
                return false;
            } else {
                lastEnd = meeting[i].second;
            }
        }
        return true;
    }
};
