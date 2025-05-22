class Solution {
public:
    int getSum(vector<int>&arr, int val){
        int currSum=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>val)
                currSum+=val;
            else
                currSum+=arr[i];
        }
        return currSum;
    }

    int findBestValue(vector<int>& arr, int target) {
        //SS: 1 to maxElt
        //p(x):sum<=Target
        //TTT*FFF*

        int n=arr.size(), i, maxElt=INT_MIN, lo, mid, hi;

        for(i=0; i<n;i++){
            maxElt=max(maxElt, arr[i]);
        }

        lo=0, hi=maxElt;

        while(lo<hi){
            mid=lo+(hi-lo+1)/2;
            if(getSum(arr,mid)<=target){
                lo=mid;
            }else{
                hi=mid-1;
            }
        }

        int ans1=getSum(arr,lo);
        int ans2=getSum(arr,lo+1);

        return abs(target-ans1)<=abs(target-ans2)?lo:lo+1;




    }
};