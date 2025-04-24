class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=INT_MAX, second=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>second) return true;
            if(nums[i]>first) second=nums[i];
            else first=nums[i];
        }
        return false;
    }
};