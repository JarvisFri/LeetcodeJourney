class Solution {
public:
    //Lets keep two pointers j, j
    // i points to last last processed non zero elt
    // j points to current unprocessed elt
    // check j: if not 0: i++, swap(nums i, nums j), j++ 
    // else if 0: j++
    // at any time lets say arr: 1,2,3(i),0,0,0,0,8(j),0,9->i++: 1,2,3,0(i),0,0,0,8(j),0,9->swap:
    // 1,2,3,8(i),0,0,0,0(j),0,9-> j++ 1,2,3,8(i),0,0,0,0,0(j),9

    void moveZeroes(vector<int>& nums) {
        int i=-1, j=0;
        while(j<nums.size()){
            if(nums[j]==0) j++;
            else{
                i++;
                swap(nums[i],nums[j]);
                j++;
            }
        }

    }
};