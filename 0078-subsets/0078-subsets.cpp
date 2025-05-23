class Solution {
public:

    //Decision: to include to exclude first elt
    //SubProblem: Suffix array f(arr,i)
    //f(arr, i)=f(arr,i+1)+i U f(arr, i+1)
    //base i==n

    void f(vector<int> &nums,int startIdx, vector<int>&curr,vector<vector<int>> &res ){
        int n=nums.size();
        //Base
        if(startIdx==n){
            res.push_back(curr);
            return;
        }

        //Recurrsive
        //Include
        curr.push_back(nums[startIdx]);
        f(nums, startIdx+1, curr, res);
        curr.pop_back();

        //Exclude
        f(nums,startIdx+1, curr, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        f(nums, 0, curr, res);

        return res;
    }
};