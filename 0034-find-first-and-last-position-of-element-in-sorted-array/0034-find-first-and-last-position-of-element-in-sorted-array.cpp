class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //First Position
        //p(x): x>=target
        //FFF*TTT* : First T

        if(nums.size()==0) return {-1,-1};
        
        int lo=0, hi=nums.size()-1, mid;

        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(nums[mid]>=target){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }

        if(nums[lo]!=target) return {-1,-1};

        int ans1=lo;


        //Last position
        //p(x): x<=Target
        //TTT*FFF*: Last T

        lo=0, hi=nums.size()-1;

        while(lo<hi){
            mid=lo+(hi-lo+1)/2;
            if(nums[mid]<=target){
                lo=mid;
            }else{
                hi=mid-1;
            }
        }

        int ans2=lo;

        return {ans1, ans2};

    }
};