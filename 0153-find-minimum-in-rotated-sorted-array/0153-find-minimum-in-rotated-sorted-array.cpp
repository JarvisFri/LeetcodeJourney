class Solution {
public:
    
    int bs(vector<int>&nums){
        int lo=1;
        int hi=nums.size()-1;
        int mid;

        while(lo<hi){
            
            mid = lo+ (hi-lo)/2;

            if(nums[mid]>nums[0]){
                lo=mid+1;
            }else{
                hi=mid;
            }
        }

        // if(nums[0]<nums[lo]){
        //     return nums[0];
        // }
        return nums[lo];
    }

    int findMin(vector<int>& nums) {

        if (nums.size()==1){
            return nums[0];
        }

        int ans= bs(nums);

        int first=nums[0];

        if (first<ans){
            return first;
        }
        else return ans;
        
    }
};