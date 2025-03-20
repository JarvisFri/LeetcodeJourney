class Solution {
public:
    int bs(vector<int>&arr){
        int lo=0, hi=arr.size()-2;//arr.size()>2
        int mid;

        while(lo<hi){
            mid=lo+(hi-lo)/2;

            if(arr[mid]>arr[mid+1]){
                hi=mid;
                

            }else{
                lo=mid+1;
            }
        }
        int last_elt=arr[arr.size()-1];
        if(arr[lo]<last_elt){
            return arr.size()-1;
        }
        return lo;

    }
    int peakIndexInMountainArray(vector<int>& arr) {

        return bs(arr);
        
    }
};