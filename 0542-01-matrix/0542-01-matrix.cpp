class Solution {
public:
    //Approach:Define distance for all zeros first ie initize q for zeros then move ahead with bfs for 1s
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> distance(m,vector<int>(n,0));

        vector<vector<int>> directions={{-1,0},{1,0},{0,1},{0,-1}};

        //vector stores 3 values i,j,dist;
        queue<vector<int>> q;
        
        //Fill all zeros
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    visited[i][j]=1;
                    distance[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            vector<int> temp=q.front();
            q.pop();
            int dist=temp[2];
            //Visit all neighbours of temp
            for(auto dir: directions){
                int x=temp[0]+dir[0];
                int y=temp[1]+dir[1];
                //Out of bounds
                if(x<0 || x>=m || y<0 || y>=n) continue;

                //Already visited
                if(visited[x][y]) continue;

                q.push({x,y,dist+1});
                visited[x][y]=1;
                distance[x][y]=dist+1;
            }

        }

        return distance;
        
    }
};