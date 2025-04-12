vector<vector<int>> dirn={ { -1,0 },{0,-1},{1,0},{0,1}};

class Solution {
public:

    void f (vector<vector<char>> & board, vector<vector<int>> & visited, string word,int k, int i , int j, bool &res){
        //Base case
        int l=word.size(), m=board.size(), n=board[0].size();
        //Positive
        if(k==l){
            res=true;
            return;
        }
        //Negative
        if(i<0||j<0||j==n||i==m) return;
        
        if(visited[i][j]) return;

        if(word[k]!=board[i][j]) return;

     
        //Call function further in all direction if dirn exist
        //mark visited
        visited[i][j]=1;
        int new_i,new_j;
        for(int p=0; p<dirn.size();p++){
            new_i=i+dirn[p][0];
            new_j=j+dirn[p][1];

            
                f(board,visited,word,k+1,new_i, new_j, res);
                if(res)return;
            

        }
        visited[i][j]=0;

    }
    bool exist(vector<vector<char>>& board, string word) {
        bool res=false;
        int l=word.size(), m=board.size(), n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i=0; i<m; i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    
                    f(board,visited,word,0,i,j,res);
                    
                    if(res) return res;
                }
            }
        }

        return res;

        
    }
};