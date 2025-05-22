class Solution {
public:
    int hIndex(vector<int>& citations) {
        //paper's idx=0 to citations.size()-1;
        int lo=0, hi=citations.size()-1,mid,sizeCitn=citations.size();
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            //p(x): count of ppr must be greater equal then citation
            //For a particular paper,count of paper having citations grater equal then it:size-mid
            //minimum citation among them citation is citation of that ppr,incresing array 
            //p(x): size-mid >=citations[mid]: FFF*TTT* first T
            if((sizeCitn-mid)<=citations[mid])
                hi=mid;
            else
                lo=mid+1;
        }

        if((sizeCitn-lo)<=citations[lo])
            return sizeCitn-lo;
        return 0;

    }
};