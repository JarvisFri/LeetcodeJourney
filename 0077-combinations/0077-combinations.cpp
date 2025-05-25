class Solution {
public:
    //All possible subsetsof size k
    //Decision: Include/Exclude
    //Subproblem: Suffix Array

    void f(int n, int k, vector<int> & currSet, vector<vector<int>> & res){
        //Base Case
        //Positive
        if(k==0){
            res.push_back(currSet);
            return;
        }
        //Negative
        if(n==0) return;
        if(k>n) return;

        //Recurance
        //Include
        currSet.push_back(n);
        f(n-1,k-1, currSet, res);
        currSet.pop_back();

        //Exclude
        f(n-1, k, currSet, res);

    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> currSet;
        f(n, k,currSet, res);

        return res;
    }
};