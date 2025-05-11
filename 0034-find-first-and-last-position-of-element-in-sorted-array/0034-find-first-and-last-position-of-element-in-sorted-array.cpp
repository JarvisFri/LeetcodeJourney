class Solution {
public:
    //Approach Find First and Last Occurance of target
    //
    int bsFirst(vector<int>& nums, int target){
        int lo=0, hi=nums.size()-1;
        int mid;

        while(lo<hi){
            mid=lo+(hi-lo)/2;

            if(nums[mid]<target){
                lo=mid+1;
            }else{
                hi=mid;
            }
        }

        if(nums[lo]==target) 
            return lo;
        return -1;
    }

    int bsLast(vector<int>& nums, int target){
        int lo=0, hi=nums.size()-1;
        int mid;

        while(lo<hi){
            mid=lo+(hi-lo+1)/2;

            if(nums[mid]<=target){
                lo=mid;
            }else{
                hi=mid-1;
            }
        }

        if(nums[lo]==target) 
            return lo;
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0) return {-1,-1};
        int first=bsFirst(nums,target);
        if (first==-1) return {-1,-1};
        int last=bsLast(nums, target);
        return {first,last};
    }
};