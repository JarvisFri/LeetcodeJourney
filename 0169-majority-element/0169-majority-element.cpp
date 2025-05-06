class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Method 2: Moores Algo
        
        int voteCount=0, candidate;
        for(auto i : nums){
            if(voteCount==0){
                candidate=i;
                voteCount++;
            }else{
                if(candidate==i) voteCount++;
                else voteCount--;
            }
        }
        return candidate;
        
        //Method 1
        // unordered_map<int,int> freqCount;
        // int maxElt=nums[0];

        // for(int i=0; i<nums.size(); i++){
        //     freqCount[nums[i]]++;
        //     if(freqCount[nums[i]]>freqCount[maxElt]) maxElt=nums[i];

        // }

        // return maxElt;


    }
};