class Solution {
public:

void f(vector<vector<char>>&board,int p,vector<pair<int,int>> &unsolvedIdx,vector<vector<char>>&ans, vector<vector<int>>&rowFilled, vector<vector<int>>&colFilled, vector<vector<int>>&boxFilled){
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
            if(board[i][j]=='.' ){
                int boxIdx=(i/3)*3+j/3;
                if(rowFilled[i][k]||colFilled[j][k]||boxFilled[boxIdx][k]) continue;
                board[i][j]='0'+k;
                rowFilled[i][k]=colFilled[j][k]=boxFilled[boxIdx][k]=1;
                f(board,p+1,unsolvedIdx,ans,rowFilled,colFilled, boxFilled );
                rowFilled[i][k]=colFilled[j][k]=boxFilled[boxIdx][k]=0;
                board[i][j]='.';
            }
        }

    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> boardTemp=board;
        vector<pair<int,int>> unsolvedIdx;

        vector<vector<int>> rowFilled (9,vector<int>(10,0));
        vector<vector<int>> colFilled (9,vector<int>(10,0));
        vector<vector<int>> boxFilled (9,vector<int>(10,0));



        int unsolved_count=0;
        for(int i=0; i<9;i++){
            for(int j=0; j<9; j++){
                int row=(i/3)*3+j/3;
                // int col=(j%3)*3+j%3;
                
                if(board[i][j]=='.') unsolvedIdx.push_back(make_pair(i,j));
                else{
                    int nums=board[i][j]-'0';
                    rowFilled[i][nums]=1;
                    colFilled[j][nums]=1;
                    boxFilled[row][nums]=1;
                }
            }
        }

        f(boardTemp,0,unsolvedIdx,board, rowFilled, colFilled, boxFilled);
        return;
        
    }
};