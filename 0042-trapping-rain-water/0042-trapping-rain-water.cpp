class Solution {
public:
    //Take two idx left and right and also left max and right max increment the one with lower max
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        
        int left=0,right=n-1,leftMax=0, rightMax=0;

        while(left<=right){
            if(leftMax<rightMax){
                if(height[left]<leftMax)
                    ans+=leftMax-height[left];
                else
                    leftMax=height[left];
                left++;
            }else{
                if(height[right]<rightMax)
                    ans+=rightMax-height[right];
                else
                    rightMax=height[right];
                right--;
            }
        }

        return ans;
    }
};