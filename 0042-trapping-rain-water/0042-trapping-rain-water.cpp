class Solution {
public:
    //Method 1: Calculate Suffix sum of Maximum height at i for right
    // Traverse from left to right evaluating currMax left height
    // Take smaller of both and subtract i : if > 0 add to water
    int trap(vector<int>& height) {

        //Calculating Suffix Sum yet
        int currMax=INT_MIN, n=height.size(),ans=0;
        vector<int> suffix_right_max(n,0);
        for(int i=n-1; i>=0;i--){
            if(height[i]>currMax) currMax=height[i];
            suffix_right_max[i]=currMax;
        }

        currMax=0;
        for(int i=0; i<(n-1);i++){
            if(currMax<height[i]) currMax=height[i];
            if(min(currMax,suffix_right_max[i+1])>height[i]){
                ans+=min(currMax,suffix_right_max[i+1])-height[i];
            }
        }
        return ans;
    }
};