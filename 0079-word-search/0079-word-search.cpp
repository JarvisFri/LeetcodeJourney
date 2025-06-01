class Solution {
public:

    vector<vector<int>> dirn={{-1,0},{+1,0},{0,-1},{0,+1}};

    void f(vector<vector<char>>& board, vector<vector<int>>& visited, int i,int j, int k, string &word, bool & res){
        int m=board.size();
        int n=board[0].size();
        int l=word.size();
        //Base
        //Already Found
        if(res) return;
        int i_next, j_next;
        //Positive
        if(k==l-1 && word[k]==board[i][j]){
            res=true;
            return;
        }
        //Negative
        if(word[k]!=board[i][j]) return;
        
           
        //Recurssive Step
        for(int x=0; x<4; x++){
            i_next=i+dirn[x][0];
            j_next=j+dirn[x][1];
            if(i_next>=0 && j_next>=0 && i_next<m && j_next<n && !visited[i_next][j_next] ){
                //Mark Visited
                visited[i_next][j_next]=1;
                f(board,visited,i_next,j_next,k+1,word, res);
                visited[i_next][j_next]=0;
            }
        }
        
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool res=false;
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i=0; i<m; i++){
            for(int j=0;j<n;j++){
                visited[i][j]=1;
                f(board,visited,i,j,0,word,res);
                visited[i][j]=0;
            }
        }

        return res;
    }
};