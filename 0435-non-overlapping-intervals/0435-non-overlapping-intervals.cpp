class Solution {
public:
    //Sort By end time
    //And keep only unique end time ie if multiple end time kepp the one with lest interval
    //not in the new intevals set check if curr start time overlaps with prev end time
    //keep the cou
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),[](vector<int>&a, vector<int>&b){
            if(a[1]==b[1]){
                return (a[1]-a[0])<(b[1]-b[0]);
            }
            return(a[1]<b[1]);
        });

        int validCount=1;
        int currStart, currEnd, prevEnd=intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            currStart=intervals[i][0];
            currEnd=intervals[i][1];

            if(currStart>=prevEnd){
                prevEnd=currEnd;
                validCount++;
            }
        }

        return intervals.size()-validCount;
        
    }
};