class Solution {
public:

    int getSum(vector<int>& nums, int div){
        int n=nums.size(), i, res=0;

        for(i=0; i<n; i++){
            res+=ceil((double)nums[i]/div);
        }
        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        //We do BS on Divisor, SS is monotonically decresing
        //p(x): sum<=thereshold
        //FF*TT*: First T is minimum divisor ie ans
        //SS:Divisors belong to 1 to maxElt

        int n=nums.size(), i, maxElt=INT_MIN, lo, hi, mid;

        for(i=0; i<n; i++)
            maxElt=max(maxElt, nums[i]);
        
        lo=1, hi=maxElt;

        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(getSum(nums, mid)<=threshold){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }

        return lo;
    }
};