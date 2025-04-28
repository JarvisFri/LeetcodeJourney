class Solution {
public:
    //Approach:
    //:Lets count bricks ending with possible edges
    //key count in a hashmap
    //ans=n-most edges betwwen 1 to width -1;

    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size();//n
        int maxEdges=0;
        long long currWidth;
        unordered_map<int,int> edgeCount;

        //Store all width edges count
        for(int i=0; i<n; i++){
            currWidth=0;
            for(int j=0; j<(wall[i].size()-1); j++){
                currWidth+=wall[i][j];
                edgeCount[currWidth]++;
            }
        }

        for(auto pair : edgeCount){
            maxEdges=max(maxEdges, pair.second);
        }

        return n-maxEdges;



    }
};