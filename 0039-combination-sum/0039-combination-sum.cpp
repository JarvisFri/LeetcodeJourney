class Solution {
public:
    //Decision: Include or Exclude ith idx
    //Subproblem: Suffix array
    //Problem: Include Subproblem + Exclude Subproblem
    //Base: Positive: Sum equals target, Negative: Sum greater then target or i==n
    
    void f(vector<int>& candidates,int i, int target, vector<int> & currSet, vector<vector<int>> &res){
        int n=candidates.size();
        //Base
        //Positive
        if(target==0){
            res.push_back(currSet);
            return;
        }
        //Negative
        if(target<0 || i==n ){
            return;
        }

        //Recurrsive
        //Include
        currSet.push_back(candidates[i]);
        f(candidates,i,target-candidates[i],currSet, res);
        currSet.pop_back();

        //Exclude
        f(candidates, i+1, target, currSet, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> currSet;

        f(candidates,0, target, currSet, res);

        return res;
    }
};