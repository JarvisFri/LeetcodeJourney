class Solution {
public:
    //Decision: Include or exclude
    //Subproblem: Suffix array

    void f(vector<int>& nums, int i, vector<int>& currSet, set<vector<int>> &ans){
        int n=nums.size();
        //Base case
        if(i==n){
            ans.insert(currSet);
            return;
        }

        //Recurrance
        //Include
        currSet.push_back(nums[i]);
        f(nums, i+1, currSet, ans);
        currSet.pop_back();

        //Exclude
        f(nums, i+1, currSet,ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> currSet;
        sort(nums.begin(), nums.end());

        f(nums,0, currSet, ans);

        vector<vector<int>> res;
        for(auto subset: ans){
            res.push_back(subset);
        }

        return res;

    }
};