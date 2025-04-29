class Solution {
public:
    //Lets store sum till j in vector, since num is pos, sum is incresing so bs is applicable
    //for each j find a number i in vector using bs such that num i > sumj-k
    //store minimum length if found

    int bs(vector<int> & arr, int target){
        //Bs to find greatest elt <=target: T,T,T',F,F
        int lo=0, hi=arr.size()-1,mid;

        while(lo<hi){
            mid=lo+(hi-lo+1)/2;
            if(arr[mid]<=target)
                lo=mid;
            else
                hi=mid-1;
        }

        if (arr[lo]<=target) return lo;
        return -1;
        
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        //
        vector<int> arr;
        int n=nums.size(), sumTillj=0, len=INT_MAX,targetPrime, i;
        //For i=0 ie subarray 0 to j, arr shift right by 1 
        arr.push_back(0);

        for(int j=0; j<n; j++){
            sumTillj+=nums[j];
            targetPrime=sumTillj-target;
            i=bs(arr, targetPrime);
            if(i!=-1){
                len=min(len,j-i+1);
            } 

            arr.push_back(sumTillj);

        }

        return len==INT_MAX?0:len;



        
    }
};