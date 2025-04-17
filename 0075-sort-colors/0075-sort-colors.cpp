class Solution {
public:
    void sortColors(vector<int>& nums) {
        int minIdx, temp;
        // for(int i=0; i<nums.size(); i++){
        //     minIdx=i;
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(nums[minIdx]>nums[j]) minIdx=j;

        //     }
        //     temp=nums[i];
        //     nums[i]=nums[minIdx];
        //     nums[minIdx]=temp;

        // }
        int countOnes=0 , countZeros=0, countTwos=0;

        for(int i=0; i<nums.size(); i++){
            switch(nums[i]){
                case 1: 
                    countOnes++;
                    break;
                case 2:
                    countTwos++;
                    break;
                case 0:
                    countZeros++;
                    

            }
        }
        for(int i=0; i<nums.size(); i++){
            
            if(countZeros){
                nums[i]=0;
                countZeros--;
            }
            else if(countOnes) {
                nums[i]=1;
                countOnes--;
                }
            else if(countTwos){
                nums[i]=2;
                countTwos--;
            }

        }
        
    }
};