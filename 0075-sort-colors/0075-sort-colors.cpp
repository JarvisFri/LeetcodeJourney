class Solution {
public:
    void sortColors(vector<int>& nums) {
        int minIdx, temp;
        for(int i=0; i<nums.size(); i++){
            minIdx=i;
            for(int j=i+1; j<nums.size(); j++){
                if(nums[minIdx]>nums[j]) minIdx=j;

            }
            temp=nums[i];
            nums[i]=nums[minIdx];
            nums[minIdx]=temp;

        }
        
    }
};