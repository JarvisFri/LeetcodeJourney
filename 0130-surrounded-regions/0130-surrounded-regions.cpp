class Solution {
public:
    vector<vector<int>> directions={{-1, 0},{1,0},{0,-1},{0,1}};
    //Find all connected component touching edge and mark them visited in res array
    void dfs(int i, int j, vector<vector<char>> & visited, vector<vector<char>>& board){
        // Check valid Nodes 
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='X') return;

        //Check visited
        if(visited[i][j]=='O') return;

        //Mark visited
        visited[i][j]='O';
        
        //Check 4 neighbour
        for(auto dir : directions){
            int x=i+dir[0];
            int y=j+ dir[1];

            dfs(x, y, visited, board);
        }

    }

    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();

        vector<vector<char>>visited(m, vector<char>(n,'X'));
        //Left ans right col
        for(int i=0; i<m; i++){
            //Left
            dfs(i,0,visited, board);
            //Right
            dfs(i,n-1,visited,board);
        }

        for(int j=0;j<n; j++){
            //Top
            dfs(0,j,visited,board);

            //Col
            dfs(m-1,j,visited,board);
        }

        board=visited;
        
    }
};