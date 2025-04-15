class Solution {
public:
    bool sudokuChecker(vector<vector<char>>&board,int i, int j, int k){
        //Check if k is valid
        int row,col;
        
        for(int n=0; n<9; n++){
            if(board[i][n]!='.'){
                if(board[i][n]-'0'==k) return false;
            }
            if(board[n][j]!='.'){
                if(board[n][j]-'0'==k) return false;
            }
            row = (i / 3) * 3 + n / 3;
            col = (j / 3) * 3 + n % 3;
            if(board[row][col]!='.'){
                if(board[row][col]-'0'==k) return false;
            }

        }
        return true;

    }
    void f(vector<vector<char>>&board,int p,vector<pair<int,int>> &unsolvedIdx,vector<vector<char>>&ans){
        //Base
        int n=unsolvedIdx.size();
        if (p==n){
            ans=board;
            return;
        }
        
        //REcurrance
        int i=unsolvedIdx[p].first;
        int j=unsolvedIdx[p].second;
        for(int k=1; k<10; k++){
            if(board[i][j]=='.' && sudokuChecker(board,i,j,k)){
                board[i][j]='0'+k;
                f(board,p+1,unsolvedIdx,ans);
                board[i][j]='.';
            }
        }

    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> boardTemp=board;
        vector<pair<int,int>> unsolvedIdx;
        int unsolved_count=0;
        for(int i=0; i<9;i++){
            for(int j=0; j<9; j++){

                if(board[i][j]=='.') unsolvedIdx.push_back(make_pair(i,j));
                //
            }
        }

        f(boardTemp,0,unsolvedIdx,board);
        return;
        
    }
};