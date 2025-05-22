class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size(), mask, count, temp,res=0;

        for(int i=0; i<32; i++){
            //Keep count of 1s at ith bit
            count=0;
            //Generate mask
            mask=1<<i;

            for(int j=0; j<n; j++){
                //Extract ith bit of nums[j]
                temp=nums[j] & mask;

                if(temp!=0)
                    count++;
            }

            //Generate res
            if(count%3==1){
                res=res|mask;
            }

        }

        return res;
    }
};