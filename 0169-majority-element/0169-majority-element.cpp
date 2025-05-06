class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freqCount;
        int maxElt=nums[0];

        for(int i=0; i<nums.size(); i++){
            freqCount[nums[i]]++;
            if(freqCount[nums[i]]>freqCount[maxElt]) maxElt=nums[i];

        }

        return maxElt;
    }
};