class Solution {
public:
    //Same as Kadanes decision
    int maxProduct(vector<int>& nums) {
        int res=1, prevMin, prevMax, currMin, currMax, n=nums.size();
        prevMin=nums[0];
        prevMax=nums[0];
        res=prevMin;

        for(int i=1; i<n; i++){
            currMin=min(min(prevMin*nums[i], prevMax*nums[i]),nums[i]);
            currMax=max(max(prevMin*nums[i], prevMax*nums[i]),nums[i]);

            res=max(currMax, res);

            prevMin=currMin;
            prevMax=currMax;


        }

        return res;
    }
};