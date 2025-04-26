class Solution {
public:
    //Backtracking: Enumerate all possible ways to climb up
    //Decision
    //Either take 1 step or 2 step
    //Subproblem f(currStep,n, count)
    //Base positive: currStep=n count++;
    //Base negative: currStep>n return
    //Recurrsive

    int f(int currStep, int n, vector<int> & dp){
        //Base
        //Positive
        if(currStep==n){
            return 1;
        }
        //Negative
        if(currStep>n) return 0;

        //DP Step
        if(dp[currStep]) {
            return dp[currStep];
        }

        //Recurrsive 
        //Take one step
        int count1=f(currStep+1,n, dp);
        //Take two step
        int count2=f(currStep+2,n, dp);

        dp[currStep]=count1+count2;

        return dp[currStep];



    }

    int climbStairs(int n) {
        vector<int> dp(n+2,0);
        //Ways to reach form n-1 to n
        dp[n]=1;
        //Ways to reach form n-2 to n
        dp[n+1]=0;
        //BottomUp:
        for(int i=n-1; i>=0; i--){
            dp[i]=dp[i+2]+dp[i+1];
        }
        // return f(0,n,dp);
        return dp[0];
    }
};