class Solution {
public:
bool checkBoard(int i, int j, vector<string> &currBoard){
        int n=currBoard.size();
        for(int k=0; k<n; k++){
            if(currBoard[i][k]=='Q') return false;
            if(currBoard[k][j]=='Q') return false;
            if(((i+k)<n && (j+k)<n) && currBoard[i+k][j+k]=='Q') return false;
            if(((i-k)>=0 && (j+k)<n) && currBoard[i-k][j+k]=='Q') return false;
            if(((i+k)<n && (j-k)>=0) && currBoard[i+k][j-k]=='Q') return false;
            if(((i-k)>=0 && (j-k)>=0) && currBoard[i-k][j-k]=='Q') return false;

        }
        // currBoard[i][j]='Q';

        return true;
    }
    vector<string> markBoard(int i, int j, vector<string> &currBoard){
        int n=currBoard.size();
        for(int k=0; k<n; k++){
            currBoard[i][k]='.';
            currBoard[k][j]='.';
            if((i+k)<n && (j+k)<n) currBoard[i+k][j+k]='.';
            if((i-k)>=0 && (j+k)<n) currBoard[i-k][j+k]='.';
            if((i+k)<n && (j-k)>=0) currBoard[i+k][j-k]='.';
            if((i-k)>=0 && (j-k)>=0) currBoard[i-k][j-k]='.';

        }
        currBoard[i][j]='Q';

        return currBoard;
    }
    void f(int n, vector<string> &currBoard, vector<vector<string>> &ans, int starti){
        //Base Case
        if(n==0){
            ans.push_back(currBoard);
            return;
        }


        //Recurrsive
        //Try each index in Currboard
        // for(int i=starti;i<currBoard.size();i++){
           int i=starti;
            for(int j=0; j<currBoard[0].size(); j++){
                if(currBoard[i][j]=='.' && checkBoard(i,j,currBoard)){
                    currBoard[i][j]='Q';
                    // markBoard(i,j,currBoard);
                    f(n-1,currBoard,ans,starti+1);
                    currBoard[i][j]='.';
                }
            }
        // }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> currBoard(n,string(n,'.'));

        f(n,currBoard, ans,0);
        return ans;

    }
};