class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n=nums.size(), i, res=INT_MIN;
        int prev,curr;
        // vector<int> dp(n,0);

        prev=nums[0];
        res=prev;
        for(i=1; i<n; i++){
            // dp[i]=max(nums[i],dp[i-1]+nums[i]);
            curr=max(nums[i], prev+nums[i]);

            res=max(curr, res);

            prev=curr;
        }

        return res;
    }
};