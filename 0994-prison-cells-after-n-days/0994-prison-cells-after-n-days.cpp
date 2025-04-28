#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        map<vector<int>, int> findLoop;
        int loopIdx = -1;

        // Record Day 0
        findLoop[cells] = 0;
        vector<int> curr = cells;

        // Find cycle
        for (int day = 1; day <= n; ++day) {
            vector<int> next(8, 0);
            for (int j = 1; j < 7; ++j) {
                next[j] = (cells[j-1] == cells[j+1]) ? 1 : 0;
            }
            if (findLoop.count(next)) {
                loopIdx = day;
                curr = next;
                break;
            }
            findLoop[next] = day;
            cells = next;
        }

        // If no cycle, we're done
        if (loopIdx == -1) return cells;

        int loopStart = findLoop[curr];
        int loopLength = loopIdx - loopStart;

        // Build cycle states
        vector<vector<int>> loopStates(loopLength, vector<int>(8));
        cells = curr;
        for (int i = 0; i < loopLength; ++i) {
            loopStates[i] = cells;
            vector<int> next(8, 0);
            for (int j = 1; j < 7; ++j) {
                next[j] = (cells[j-1] == cells[j+1]) ? 1 : 0;
            }
            cells = next;
        }

        int remain = (n - loopStart) % loopLength;
        return loopStates[remain];
    }
};
