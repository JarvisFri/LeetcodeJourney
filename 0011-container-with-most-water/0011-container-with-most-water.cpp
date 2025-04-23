class Solution {
public:
    // Cue : pair i ,j : tp
    // Algo: Start from i=0 and j=n-1;
    // take min of (nums i, nums j): calculate area
    int area(vector<int> & height, int i, int j){
        return min(height[i],height[j])*abs(j-i);
    }
    int maxArea(vector<int>& height) {

        int i=0, j=height.size()-1, maxArea=0;
        int i_max=i, j_max=j;        
        while(i<j){
            if(maxArea<area(height, i,j)){
                    maxArea=area(height, i,j);
                }

            
            height[i]<height[j]?i++:j--;
        }
        
        return maxArea;
    }
};