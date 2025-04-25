class Solution {
public:
    //to break circular nature, lets first drop last house ie robbing first house
    // then drop first house 

    int robHelper(vector<int>& nums, int startIdx, int endIdx, vector<int>& dp){
        //Base case
        if(startIdx>=endIdx)
        return 0;

        //Dp lookup
        if(dp[startIdx]!=-1) return dp[startIdx];

        //Recurrsive step
        // rob house
        int money1=nums[startIdx]+robHelper(nums,startIdx+2,endIdx,dp);
        //Dont rob
        int money2=robHelper(nums,startIdx+1, endIdx,dp);

        //save in dp
        dp[startIdx]=max(money1,money2);
        return dp[startIdx];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp_rob_first(n,-1);
        vector<int> dp_dont_rob_first(n,-1);
        

        return max(robHelper(nums,0,n-1,dp_rob_first),robHelper(nums,1,n,dp_dont_rob_first));

        
    }
};