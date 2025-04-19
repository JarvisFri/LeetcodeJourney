class Solution {
public:

    //Sort the array
    //Keep two pointers i pointing to first elt and j pointing to last elt of array
    //-If sum equals target return
    //-If Sum is more: j--: I know keeping j as fixed for i++ sum increses so there is no other i for which Sum ==target we reduced  an entire iteration for that j, compare to brute force
    //-If sum is less: i++: I know keeping i as fixed for j-- sum decreses so there is no other j for which Sum == target here we reduced  an entire iteration for that i, compare to brute force.

    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<vector<int>> newNums(nums.size(),vector<int>(2,0));
        for(int k=0; k<nums.size(); k++){
            newNums[k][0]=nums[k];
            newNums[k][1]=k;
        }
        sort(newNums.begin(), newNums.end(), [](vector<int> & a, vector<int> & b){
            return a[0]<b[0];
        });

        int i=0,j=newNums.size()-1, sum;
        while(i<j){
            sum=newNums[i][0]+newNums[j][0];
            if(sum==target) return {newNums[i][1],newNums[j][1]};
            else if( sum>target) j--;
            else i++;
        }
        return {};
    }
};