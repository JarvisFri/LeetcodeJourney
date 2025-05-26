class Solution {
public:
    //1,1,2,5,6,7,10
    //Decision: Set of soln starting with nums[i] and not starting with nums[i]
    //Subproblem: Suffix array

    void f(vector<int>& candidates, int i, int target, vector<int>& currSet, vector<vector<int>>& res){ 
        int n=candidates.size();
        //Base
        //Positive
        if(target==0){
            res.push_back(currSet);
            return;
        }
        //Negative
        if(target<0 || i>=n) return;

        //Recurrance
        //Include
        currSet.push_back(candidates[i]);
        f(candidates, i+1, target-candidates[i], currSet, res);
        currSet.pop_back();

        //Exclude
        int j=i;
        while(j<n && candidates[j]==candidates[i] ) j++;
        f(candidates, j, target, currSet, res);

        return;

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> currSet;

        f(candidates, 0,target,currSet,res);

        return res;
    }
};