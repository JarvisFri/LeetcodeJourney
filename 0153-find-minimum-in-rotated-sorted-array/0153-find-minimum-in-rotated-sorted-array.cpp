class Solution {
public:
    int findMin(vector<int>& nums) {
        //p(x): nums[0]<nums[x]
        //TTT*FF*: First F


        int lo=0, hi=nums.size()-1, mid; 
        
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(nums[0]<=nums[mid]){
                lo=mid+1;
            }else{
                hi=mid;
            }
        }
        if(nums[0]<nums[lo]) return nums[0];

        return nums[lo];
    }
};