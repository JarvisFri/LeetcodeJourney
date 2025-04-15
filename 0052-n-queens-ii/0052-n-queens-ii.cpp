class Solution {
public:
    //Decision: For given row all column check and increment row.
    //Subproblem: vRow,vCol, vPosDiag, vNegDia;
    //Recurrance: forloop each clumn
    // check if visited, else mark visited and call for row+1
    //Base: if row=n; ans++; return;

    void f(int n,int row, vector<int> vRow, vector<int> vCol, vector<int> vPosDiag, vector<int> vNegDiag, int &ans){
        //Base Case
        if(row==n){
            ans++;
            return;
        }

        //Recurrance
        for(int j=0; j<n; j++){
            if(vRow[row] || vCol[j] || vPosDiag[j-row+n-1] || vNegDiag[row+j])
                continue;
            vRow[row]=1;
            vCol[j]=1;
            vPosDiag[j-row+n-1]=1;
            vNegDiag[row+j]=1;
            f(n,row+1, vRow, vCol, vPosDiag, vNegDiag, ans);
            vRow[row]=0;
            vCol[j]=0;
            vPosDiag[j-row+n-1]=0;
            vNegDiag[row+j]=0;
            ;
            
        }
    }


    int totalNQueens(int n) {
        int ans=0;

        vector<int> vRow(n,0),vCol(n,0),vPosDiag(2*n-1,0),vNegDiag(2*n-1,0);
        f(n,0,vRow,vCol, vPosDiag, vNegDiag,ans);

        return ans;
        
    }
};