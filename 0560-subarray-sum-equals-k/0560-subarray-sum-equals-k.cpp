class Solution {
public:
    //Idea: Let Sum from 0 to j be K'
    //Lets try to calculate all such i for which array ends at j and sum is K
    //This is same as calculating all prefix subarrays of i with sum K'-K
    //Store in hashtable <sum, freq of sum>
    // Do above step for each j
    int subarraySum(vector<int>& nums, int k) {
        int sumTilli=0, sumTillj=0, count=0;

        unordered_map<int,int> sumFreq;
        sumFreq[0]=1;

        sumTilli=0;
        for(int j=0; j<nums.size(); j++){
            
            sumTillj+=nums[j];
            //Freq till one elt before j
            
            sumTilli=sumTillj-k;
            if(sumFreq.find(sumTilli)!=sumFreq.end())
            count+=sumFreq[sumTilli];
            
            
            sumFreq[sumTillj]++;
            // cout<<sumTillj<<" "<<sumTilli<<" "<<count<<endl;
   
        } 

        return count;
        
    }
};