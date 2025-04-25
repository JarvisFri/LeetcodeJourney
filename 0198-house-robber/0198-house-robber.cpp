class Solution {
public:
    int houseRobber(vector<int>& nums, int i, vector<int> & dp){
        int n=nums.size();
        //Base Case
        if(i>=n) return 0;

        //DP Lookup
        if(dp[i]!=-1) return dp[i];

        //Recurrsive step
        //Decision: Rob current house, or not
        int money1=nums[i]+houseRobber(nums, i+2, dp);

        int money2=houseRobber(nums, i+1,dp);

        dp[i]=max(money1, money2);

        return dp[i];
    }
    int rob(vector<int>& nums) {

        vector<int> dp(nums.size(),-1);

        return houseRobber(nums, 0, dp);
        
    }
};