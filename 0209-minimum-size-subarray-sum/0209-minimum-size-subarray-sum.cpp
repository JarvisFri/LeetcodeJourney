class Solution {
public:
    //Lets store sum till j in vector, since num is pos, sum is incresing so bs is applicable
    //for each j find a number i in vector using bs such that num i > sumj-k
    //store minimum length if found

    int bs(unordered_map<int,int> &sumIdx, int target, int lo, int hi){
        //Bs to find greatest elt <=target: T,T,T',F,F
        // int lo=0, hi=arr.size()-1;
        int mid;

        while(lo<hi){
            mid=lo+(hi-lo+1)/2;
            if(sumIdx[mid]<=target)
                lo=mid;
            else
                hi=mid-1;
        }

        if (sumIdx[lo]<=target) return lo;
        return -2;
        
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        //
        // vector<int> arr;//Give memory limit
        unordered_map<int, int> sumIdx;//key is idx value is sum

        int n=nums.size(), sumTillj=0, len=INT_MAX,targetPrime, i;
        //For i=0 ie subarray 0 to j, arr shift right by 1 
        // arr.push_back(0);
        //Store idx 0 for sum 0
        sumIdx[-1]=0;

        for(int j=0; j<n; j++){
            sumTillj+=nums[j];
            targetPrime=sumTillj-target;
            i=bs(sumIdx, targetPrime, -1, j-1);
            if(i!=-2){
                len=min(len,j-i);


            } 

            // arr.push_back(sumTillj);
            sumIdx[j]=sumTillj;

        }

        return len==INT_MAX?0:len;



        
    }
};