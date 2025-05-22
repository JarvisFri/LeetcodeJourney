class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //If we start form top-right or bottom-left  we can eliminate a row or a col in each comprison
        //Lets take top right

        int m=matrix.size(), n=matrix[0].size();

        if(n==0) return false;

        int i=0, j=n-1;

        while(i<m && j>=0){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target) i++;//Remove ith row
            else j--;//remove jth col
        }

        return false;

    }
};