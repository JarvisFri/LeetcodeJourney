class Solution {

public:
    int bs_start(vector<int>& nums, int target){
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
        if(nums[lo]==target){
            return lo;
        }else {
            return -1;
        }
    }


    int bs_end(vector<int>&nums, int target){

        int lo=0, hi=nums.size()-1;
        int mid;

        while(lo<hi){
            mid=lo+(hi-lo+1)/2;

            if(nums[mid]>target){
                hi=mid-1;
            }else{
                lo=mid;
            }
        }

        if (nums[lo]==target){
            return lo;
        }else {
            return -1;
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            vector<int> ans0 ={-1,-1};
            return ans0;
        }

        int start=bs_start(nums,target);
        int end;
        if (start!=-1){
            end=bs_end(nums,target);
        }else{
            end=-1;
        }
        
        vector<int> ans ={start,end};

        return ans;
    }
};