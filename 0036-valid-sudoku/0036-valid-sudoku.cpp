class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<int> tempCol(10,0);
        vector<int> tempRow(10,0);
        vector<int> tempSubmatrix(10,0);

        int row,col;
        //for each row-col
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                if(tempCol[board[i][j]-'0']) return false;
                else tempCol[board[i][j]-'0']=1;}
                if(board[j][i]!='.'){
                if(tempRow[board[j][i]-'0']) return false;
                else tempRow[board[j][i]-'0']=1;}

                row=(i/3)*3+j/3;
                col=(i%3)*3+j%3;
                if(board[row][col]!='.'){
                if(tempSubmatrix[board[row][col]-'0']) return false;
                else tempSubmatrix[board[row][col]-'0']=1;}

                
            }
            fill(tempCol.begin(), tempCol.end(),0);
            fill(tempRow.begin(), tempRow.end(),0);
            fill(tempSubmatrix.begin(),tempSubmatrix.end(),0);
            
        }
        return true;
        
    }
};