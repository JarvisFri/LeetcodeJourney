class Solution {
public:
    //Decision: Include/Exclude, Subsets which include first elt and which dont
    //Subproblem: Suffix array: f(arr, i)
    //Recurrance relation:f(arr,i)=f(arr,i+1) U f(arr,i+1)
    //Base case: i=n 

    void f(vector<int>& nums, int startIdx, vector<int> &currSet, vector<vector<int>>& result){
        //Base case
        int n=nums.size();
        if(startIdx==n){
            result.push_back(currSet);
            return;
        }

        //Recurrive step:
        //Include:
        currSet.push_back(nums[startIdx]);
        f(nums, startIdx+1,currSet,result);
        currSet.pop_back();

        //Exclude:
        f(nums, startIdx+1,currSet, result);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> currSet;

        f(nums, 0, currSet, result);

        return result;
    }
};