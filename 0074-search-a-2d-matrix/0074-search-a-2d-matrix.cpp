class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m=matrix.size(), n=matrix[0].size();
       //SS:0 to m*n -1;
       //BS on SS: P(x): A[x]>=target
       //FFF*TTT*: First T

       int lo=0, hi=m*n -1, mid,i,j;

       while(lo<hi){
        mid=lo+(hi-lo)/2;

        i=mid/n;
        j=mid%n;

        if(matrix[i][j]>=target){
            hi=mid;
        }else{
            lo=mid+1;
        }
       }

       i=lo/n;
       j=lo%n;
       if(matrix[i][j]==target) return true;

       return false;

        
    }
};