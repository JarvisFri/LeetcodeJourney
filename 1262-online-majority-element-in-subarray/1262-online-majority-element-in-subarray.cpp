class MajorityChecker {
public:
    map< int , vector<int>> freqArray;
    vector<int> & array;
    MajorityChecker(vector<int>& arr):array(arr) {
        for(int i=0; i<arr.size(); i++){
            freqArray[arr[i]].push_back(i);
        }
        
        
    }
    //Function to find of index equal or greater then left
    int bsLeft(vector<int> & nums, int left ){

        int lo=0, hi=nums.size()-1,mid;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(nums[mid]>=left){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        if(nums[lo]>=left) return lo;
        return -1;

    }
    //Function to find of index equal or smaller then right
    int bsRight(vector<int> &nums, int right){
        int lo=0, hi=nums.size()-1,mid;
        while(lo<hi){
            mid=lo+(hi-lo+1)/2;
            if(nums[mid]<=right){
                lo=mid;
            }else{
                hi=mid-1;
            }
        }
        if(nums[lo]<=right) return lo;
        return -1;
    }
    int isMajority(int left, int right, int threshold, int n){
        int leftIdx,rightIdx;
        // for(auto freq:freqArray){
            
            leftIdx=bsLeft(freqArray[n],left);
            rightIdx=bsRight(freqArray[n], right);
            // cout<<leftIdx<< " "<<rightIdx;
            if(rightIdx!=-1 && leftIdx!=-1)
            if((rightIdx-leftIdx+1)>=threshold) return n;

        // }
        return -1;
    }
    
    void printFreqArray() {
            for (const auto& pair : freqArray) {
                std::cout << "Element: " << pair.first << " Indices: ";
                for (int index : pair.second) {
                    std::cout << index << " ";
                }
                std::cout << std::endl;
            }
    }

    int query(int left, int right, int threshold) {

        int randElt,ans;
        srand(time(0));

        for (int i=0; i<50; i++){
            randElt=left+rand()%(right-left+1);
            ans=isMajority(left,right,threshold,array[randElt]);
            if(ans!=-1) return ans;

        }
        return -1;

        
        // printFreqArray();
        
        
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */