class Solution {
public:
    //Backtracking: Enumerate all possible ways to climb up
    //Decision
    //Either take 1 step or 2 step
    //Subproblem f(currStep,n, count)
    //Base positive: currStep=n count++;
    //Base negative: currStep>n return
    //Recurrsive

    int f(int currStep, int n, int count, vector<int> & dp){
        //Base
        //Positive
        if(currStep==n){
            count++;
            return count;
        }
        //Negative
        if(currStep>n) return 0;

        //DP Step
        if(dp[currStep]) {
            return dp[currStep];
        }

        //Recurrsive 
        //Take one step
        int count1=f(currStep+1,n, count,dp);
        //Take two step
        int count2=f(currStep+2,n, count,dp);

        dp[currStep]=count1+count2;

        return dp[currStep];



    }

    int climbStairs(int n) {
        vector<int> dp(n,0);
        int count=0;
        return f(0,n,count,dp);
        // return count;
    }
};