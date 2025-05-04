class Solution {
public:

    //Approach: Set land distance as zero, then iterate for water distance from land 
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        int maxDistance =-1;

        vector<vector<int>> directions={{1,0},{-1,0},{0,-1},{0,1}};
        //vector stores i, j, distance
        queue<vector<int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                //Push to 1s to queue and mark as visited
                if(grid[i][j]==1){
                    q.push({i,j,0});
                    visited[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            vector<int> temp=q.front();
            q.pop();
            

            for(auto dir: directions){
                int x=temp[0]+dir[0];
                int y=temp[1]+dir[1];
                
                //Bounds Check
                if(x<0 || x>=m || y<0 || y>=n) continue;
                //Already visited
                if(visited[x][y]) continue;

                q.push({x,y,temp[2]+1});
                visited[x][y]=1;
                maxDistance=temp[2]+1;
                
            }
        }
        return maxDistance;

    }
};