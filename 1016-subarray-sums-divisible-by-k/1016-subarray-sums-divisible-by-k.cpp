class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(), count=0,mod, currSum=0;

        //Lets keep modulo as key, and count as value
        vector<int> freqMod(k,0);
        
        freqMod[0]++;// Empty array 

        for(int j=0; j<n; j++){
            currSum+=nums[j];

            mod=currSum%k;
            if(mod<0) mod+=k;

            count+=freqMod[mod];
            freqMod[mod]++;
        }

        return count;

        
    }
};