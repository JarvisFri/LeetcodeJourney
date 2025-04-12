class Solution {
public:
    //Method2: 2Pointer: leftMax, rightMax
    //Whichever is smaller increment that, left++, right--
    
    int trap(vector<int>& height) {
        int leftMax=0,rightMax=0,left=0,right=height.size()-1,ans=0;
        if(height.size()<=1)return 0;
        leftMax=height[left];
        rightMax=height[right];
        
        // left++;
        // right--;

        while(left<=right){
            if(leftMax<rightMax){
                if(height[left]>leftMax)
                    leftMax=height[left];
                else ans+=leftMax-height[left];
                left++;
            }else{
                if(height[right]>rightMax)
                    rightMax=height[right];
                else ans+=rightMax-height[right];
                right--;
            }
        }

        return ans;

       
        
    }
};