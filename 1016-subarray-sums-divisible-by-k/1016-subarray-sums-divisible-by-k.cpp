class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(), count=0,mod, currSum=0;

        //Lets keep modulo as key, and count as value
        unordered_map<int,int> freqMod;
        
        freqMod[0]++;// Empty array 

        for(int j=0; j<n; j++){
            currSum+=nums[j];

            mod=currSum%k;
            if(mod<0) mod+=k;

            if(freqMod.find(mod)!=freqMod.end())
            count+=freqMod[mod];
            freqMod[mod]++;
        }

        return count;

        
    }
};