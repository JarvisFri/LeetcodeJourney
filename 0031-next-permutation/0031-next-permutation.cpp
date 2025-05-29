class Solution {
public:
    //1. Find LSD to replace : Start from least significant digit to find i <i-1
    //2. Find the num just greater then elt at i to swap with
    //3. After Swap sort the rest array for lowest permutation
    void nextPermutation(vector<int>& nums) {
        //Finding ith LSD digit to replace
        int n=nums.size();
        if (n==1) return;
        int curr=n-2, prev=n-1;
        while(curr>=0 && nums[curr]>=nums[prev]){
            prev=curr;
            curr--;
        }
        
        int i;
        if(curr >=0){
            
            for(i=curr+1; i<n; i++){
                if(nums[i]<=nums[curr]) break;
            }
            i--;
            swap(nums[i], nums[curr]);
        }

        reverse(nums.begin()+curr+1, nums.end());

        return ;

    }
};