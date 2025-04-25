class Solution {
public:

    //Backtrack
    //Decision: For each possible j: 1 to i call subproblem
    // void jumpTillN(vector<int> & nums, int currIdx, bool& ans ){
    //     //If ans found as true
    //     int n=nums.size();
    //     if(ans) return;
    //     //Base case
    //     if(currIdx>=n-1 ){
    //         ans=true;
    //         return;
    //     }

    //     //Recurrance
    //     cout<<currIdx<<" ";
    //     for(int j=1; j<=nums[currIdx]; j++){
    //         jumpTillN(nums,currIdx+j,ans);
            
    //     }

    // }

    //Method 2:
    //Lets traverse from i=0 to n-1
    //Keep track of maxReachableIdx till each i
    //For any i if maxReachableIdx<=i return false
    //If Maxjump>=n-1 return true;
    bool canJump(vector<int>& nums) {
        int maxReachableIdx=0, n=nums.size();
        for(int i=0 ; i<n ; i++){
            maxReachableIdx=max(maxReachableIdx, i+nums[i]);
            if(maxReachableIdx>=n-1) return true;
            if(maxReachableIdx<=i) return false;
        }
        return false;
    }
};