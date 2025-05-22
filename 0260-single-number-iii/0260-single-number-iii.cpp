class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //take xor 
        int xorab=0;

        for(auto elt :nums){
            xorab=xorab ^ elt;
        }
        int mask,setMask=0;
        //find first non nonzero bit in xorab and partition arry in 2 parts on that basis
        for(int i=0; i<32; i++){
            mask=1<<i;
            if(xorab & mask){
                setMask=mask;
                break;
            }
        }

        int ans1=0, ans2=0;

        for(auto elt:nums){
            if(elt & mask )
                ans1=ans1^elt;
            else
                ans2=ans2^elt;
        }

        return {ans1,ans2};
    }
};