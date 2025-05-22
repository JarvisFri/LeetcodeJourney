class Solution {
public:
    int getSum(vector<vector<int>> & prefixSum, int i, int j, int len){

        int k=i-len+1;
        int l=j-len+1;

        int subSum=0;

        //Add P(i,j)
        subSum+=prefixSum[i][j];

        //Sub p(i,l-1)
        if(l-1>=0)
            subSum-=prefixSum[i][l-1];
        //Sub p(k-1,j)
        if(k-1>=0)
            subSum-=prefixSum[k-1][j];
        //Add p(k-1,j-1)
        if(l-1>=0 && k-1>=0)
            subSum+=prefixSum[k-1][l-1];

        return subSum;
    }


    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        int m=mat.size();
        int n=mat[0].size();

        //Calculate prefix array
        vector<vector<int>> prefixSum(m,vector<int>(n,0));
        int curr;
        for(int i=0 ; i<m; i++){
            curr=0;
            for(int j=0; j<n; j++){
                curr+=mat[i][j];
                prefixSum[i][j]=curr;

                if(i>0)
                    prefixSum[i][j]+=prefixSum[i-1][j];
            }

        }

        //Binary search
        int lo, hi, mid,lopt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                lo=1, hi=min(i,j)+1;

                while(lo<hi){
                    mid=lo+(hi-lo+1)/2;

                    if(getSum(prefixSum, i, j, mid)<=threshold)
                        lo=mid;
                    else
                        hi=mid-1;
                }

                if(getSum(prefixSum, i, j, lo)<=threshold)
                    lopt=max(lopt,lo);
            }
        }
        return lopt;
    }
};