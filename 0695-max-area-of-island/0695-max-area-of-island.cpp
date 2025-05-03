class Solution {
public:
    //Nodes are 1s in grid, edges are its 4 neighbours
    //Traverse  to each node do dfs to compute size of each connected component
    //return max

    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>>&grid,int &count){
    
        //Check if i and j are valid nodes
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0) return;
        //mark as visited if note visted
        if(visited[i][j]) return;

        visited[i][j]=true;
        count++;


        //dfs on neighbors
        for(auto dir: directions){
            int x=i+dir[0];
            int y=j+dir[1];

            dfs(x,y,visited,grid,count);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=0, res=0, m=grid.size(), n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                count=0;
                //Check if its a valid node
                if(grid[i][j]==1 && visited[i][j]==false){
                    dfs(i, j, visited, grid, count);
                    res=max(res, count);
                }
            }
        }

        return res;
        
    }
};