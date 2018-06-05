// use an ordered set to store all the current buildings heights.
// add new height when new building comes in, and delete height when the building ends.
// NOTE: multiset.erase(value) removes all identical values. so use an iterator = find(value), erase(iterator) to remove only one.
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        // multiple buildings could start/end at the same place
        map<int, vector<int>> starts;     // start[left] : 0 ==> height
        map<int, vector<int>> ends;       // end[right] : height ==> 0
        for (auto &v : buildings) {
            starts[v[0]].push_back(v[2]);
            ends[v[1]].push_back(v[2]);
        }

        // walk through from left to right.
        multiset<int, greater<int>> heights;         // all the heights, currently hoding, could have multiple same heights.
        vector<pair<int, int>> points;
        auto it_starts = starts.begin();
        auto it_ends = ends.begin();

        int prev_height = 0, curr_height = 0;
        while (it_starts != starts.end()) {
            // compare start/end
            if (it_starts->first <= it_ends->first) {
                // adding new building
                for (int h : it_starts->second) {
                    heights.insert(h);
                    curr_height = max(curr_height, h);
                }
                // add points only when higher
                if (curr_height > prev_height) {
                    points.push_back({it_starts->first, curr_height});
                }
                ++it_starts;
            } else {
                // delete old building
                for (int h : it_ends->second) {
                    auto it = heights.find(h);
                    heights.erase(it);      // only remove one!
                }
                // add new points when lower
                curr_height = (heights.empty()) ? 0 : *heights.begin();
                if (curr_height < prev_height) {
                    points.push_back({it_ends->first, curr_height});
                }
                ++it_ends;
            }
            prev_height = curr_height;
        }

        // since always left < right for all buildings
        while (it_ends != ends.end()) {
            // delete old building one by one
            for (int h : it_ends->second) {
                auto it = heights.find(h);
                heights.erase(it);      // only remove one!            
            }
            // add new points when lower
            curr_height = (heights.empty()) ? 0 : *heights.begin();
            if (curr_height < prev_height) {
                points.push_back({it_ends->first, curr_height});
            }
            prev_height = curr_height;
            ++it_ends;
        }

        return points;
    }
};
