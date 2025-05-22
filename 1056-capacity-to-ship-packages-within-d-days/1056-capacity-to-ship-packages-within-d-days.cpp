class Solution {
public:
    int daysReqWithCapacity(vector<int>& weights, int capacity){
        int daysReq=0, currWeight=0;
        for(int i=0; i<weights.size(); i++){
            if (weights[i]>capacity){
                return INT_MAX;
            }

            currWeight+=weights[i];
            if(currWeight>capacity){
                daysReq++;
                currWeight=weights[i];
            }
        }
        if(currWeight>0) daysReq++;

        return daysReq;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        //SS: Capacity: 0 to Sum of weights
        //p(x):daysReqWithGivenCapacity<days
        //FFF*TTT* : First T
        int n=weights.size(), i, lo, hi, mid, sumWeight=0;
        for(i=0; i<n; i++)
            sumWeight+=weights[i];
        
        lo=0, hi=sumWeight;

        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(daysReqWithCapacity(weights, mid)<=days){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }

        return lo; 
        
    }
};