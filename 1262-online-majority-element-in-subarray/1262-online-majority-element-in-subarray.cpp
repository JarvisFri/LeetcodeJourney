class MajorityChecker {
public:
    unordered_map<int, vector<int>> elt_idxs;
    vector<int> nums;
    MajorityChecker(vector<int>& arr) {
        //Copy arr in nums
        nums=arr;
        for(int i=0; i<nums.size();i++){
            elt_idxs[nums[i]].push_back(i);
        }
    }
    //Keep an unordered map of elt as key and value as indexes 
    //For each query look for left and right most idx in idx array
    //array say 50 times and check if its majority if yes, return that elt or -1 if false
    //apply bs to check majority

    //Search for idx >=left
    int  bs_left(int elt,int left ){
        int n=elt_idxs[elt].size();
        int lo=0, hi=n-1, mid;
        while(lo<hi){
            mid=lo+(hi-lo)/2;

            if(elt_idxs[elt][mid]<left){
                lo=mid+1;
            }else{
                hi=mid;
            }
        }
        if(elt_idxs[elt][lo]>=left)
            return lo;
        return -1;
    }
    int  bs_right(int elt,int right ){
        int n=elt_idxs[elt].size();
        int lo=0, hi=n-1, mid;
        while(lo<hi){
            mid=lo+(hi-lo+1)/2;

            if(elt_idxs[elt][mid]>right){
                hi=mid-1;
            }else{
                lo=mid;
            }
        }
        if(elt_idxs[elt][lo]<=right)
            return lo;
        return -1;
    }

    int majority_helper(int idx,int left, int right){
        //Find the left most and right most elts
        int elt=nums[idx];
        int lo=bs_left(elt,left);
        if(lo==-1)
            return 0;
        int hi=bs_right(elt,right);
        return hi-lo+1;


    }

    int query(int left, int right, int threshold) {
        //Pick a random elt in betwwen left and right
        srand(time(0));

        int idx;
        for(int i=0; i<100; i++){
            //Pick random idx between left and right
            idx=left+rand()%(right-left+1);
            //Check if that idx elt is majority ie greater than threshold
            if(majority_helper(idx,left,right)>=threshold)
                return nums[idx];

            

        }

        return -1;

        
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */