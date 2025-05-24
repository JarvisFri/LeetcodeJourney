class Solution {
public:
    //Decision: Include or exclude
    //Subproblem: Suffix array

    void f(vector<int>& nums, int i, vector<int>& currSet, vector<vector<int>> &ans){
        int n=nums.size();
        //Base case
        if(i>n) return;
        // if(i==n){
            ans.push_back(currSet);
            // return;
        // }

        //Recurrance
        //All elt starting with i , i+1.. given all nums i uniquwe will avoid duplicates
        for(int j=i; j<n; j++){
            if(j!=i && nums[j]==nums[j-1]) continue;
            currSet.push_back(nums[j]);
            f(nums,j+1, currSet,ans);
            currSet.pop_back();
        }
        // //Include
        // currSet.push_back(nums[i]);
        // f(nums, i+1, currSet, ans);
        // currSet.pop_back();

        // //Exclude
        // f(nums, i+1, currSet,ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currSet;
        sort(nums.begin(), nums.end());

        f(nums,0, currSet, ans);
        return ans;

        // vector<vector<int>> res;
        // for(auto subset: ans){
        //     res.push_back(subset);
        // }

        // return res;

    }
};