class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //Best :O(1) space and O(n) time
        // int first=INT_MAX, second=INT_MAX;
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i]>second) return true;
        //     if(nums[i]>first) second=nums[i];
        //     else first=nums[i];
        // }
        // return false;

        //Method 2: O(n): Time and Space
        //Track Second elt:  First keep min, Third store max in suffix array

        //Max preprocessing:
        //Suffix array: A[j]: max(A[j]..A[n])
        int n=nums.size();
        vector<int> maxArray(n, INT_MIN);
        maxArray[n-1]=nums[n-1];
        cout<<"n:"<<n<<" ";
        for(int j=n-2; j>=0; j--){
            cout<<"j:"<<j<<" ";
            maxArray[j]=max(nums[j], maxArray[j+1]);
        }
        int firstMin=nums[0];

        for(int i=1; i<n; i++){
            if(firstMin<nums[i]){
                if(i+1<n && nums[i]<maxArray[i+1]) return true;
            }
            firstMin=min(nums[i],firstMin);
        }
        return false;
    }
};