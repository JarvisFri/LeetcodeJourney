class Solution {
public:
    

    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        // Map from seen state → the day index when we first saw it
        unordered_map<string,int> seen;
        vector<vector<int>> states;    // day-by-day states
        
        auto encode = [&](const vector<int>& v) {
            string s;
            for (int x : v) s += char('0' + x);
            return s;
        };
        
        // Day 0
        seen[encode(cells)] = 0;
        states.push_back(cells);
        
        int day = 0;
        while (day < n) {
            ++day;
            vector<int> next(8, 0);
            // Compute next state
            for (int j = 1; j < 7; ++j) {
                next[j] = (cells[j-1] == cells[j+1]) ? 1 : 0;
            }
            // Encode and check cycle
            string code = encode(next);
            if (seen.count(code)) {
                // cycle found from seen[code] to current day
                int cycleStart = seen[code];
                int cycleLen   = day - cycleStart;
                // jump ahead
                int remaining = (n - cycleStart) % cycleLen;
                return states[cycleStart + remaining];
            }
            // otherwise record and continue
            seen[code] = day;
            states.push_back(next);
            cells = move(next);
        }
        
        // if we never cycled before day n
        return states.back();
    }


};