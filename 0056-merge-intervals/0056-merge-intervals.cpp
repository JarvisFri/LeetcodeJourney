class Solution {
    //Sort intervals on first index
    //keep to pointers for end and start
    //check for end>start+1 for merge
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int currStart=0, currEnd=0;

        sort(intervals.begin(), intervals.end(),[](vector<int> & a, vector<int> & b){
            return a[0]<b[0];
        });

        if(intervals.size()==1) return intervals;

        vector<vector<int>> ans;

        for(int nextStart=0; nextStart< intervals.size(); nextStart++){

            

            if(intervals[nextStart][0]<=intervals[currEnd][1]){
                //If next intervals submerge into other
                if(intervals[nextStart][1]>intervals[currEnd][1]) 
                currEnd=nextStart;
                
            }
            else{
                ans.push_back({intervals[currStart][0], intervals[currEnd][1]});
                currStart=nextStart;
                currEnd=nextStart;
            }

        }
        ans.push_back({intervals[currStart][0], intervals[currEnd][1]});
        return ans;
        
    }
};