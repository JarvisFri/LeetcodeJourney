class Solution {
public:
    //Cue: Subarray and i and j are monotonus wrt to freq
    //To prove: Cant prove-not true
    //But atmost K can be calculated using tp
    //Ans:Atmost k -Atmost k-1= Exactly K
    //Algo:count subarray with atmost k distinct
    //-for i=0 to n; for each i check if sub

    int subArrayWithAtmostKDistinct(vector<int> & nums, int k){
        int countSubarray=0, n=nums.size(), j=0;
        unordered_map<int,int> freq;
        


        for(int i=0; i<n; i++){
            while(j<n){
                //Count subarray with atmost k distinct
                //Check if nums[j] exist in freq, if true increment its freq, check if freq.size<k
                if(freq.find(nums[j])==freq.end()){
                    if(freq.size()<k){
                        freq[nums[j]]=1;

                        // countSubarray++;
                        // cout<<countSubarray<<" ";
                    }else{
                        break;
                    }
                }else{
                    freq[nums[j]]++;
                    // countSubarray++;
                    // cout<<countSubarray<<" ";
                }
                j++;
            }
            countSubarray+=j-i;
            cout<<endl;
            freq[nums[i]]--;
            if(!freq[nums[i]]) freq.erase(nums[i]);
            
            // for (const auto& pair : freq) {
            //         std::cout << pair.first << ": " << pair.second << std::endl;
            //     }



            // while(numSet.size()<=k){
            //     if(numSet.find(nums[j])==numset.end()){
            //         numset[]
            //     }
            // }


        }

        return countSubarray;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if (k-1==0)
        return subArrayWithAtmostKDistinct(nums,k);
        return subArrayWithAtmostKDistinct(nums,k)-subArrayWithAtmostKDistinct(nums,k-1);

        
    }
};