class Solution {
public:

    //Enumeration: Backtracking
    //Decision: Either we include the ith elt in our curr set or not
    //Subproblem: Solutions that include ith elt in sub set and ones that dont
    //Problem and subproblem relation: f(nums, i)=i+f(nums, i+1) U f(nums, i+1)
    //Base case i=n

    vector<vector<int>> f(vector<int>&nums, int i){
        int n=nums.size();
        //Base Case
        if(i==n)
        return {{}};//Empty set

        //Recurrance
        
        vector<vector<int>> temp=f(nums, i+1);
        //Exclude ith elt
        vector<vector<int>> ans=temp;

        //Include ith elt
        for(auto subset:temp ){
            subset.push_back(nums[i]);
            ans.push_back(subset);
        }

        return ans;

    }



    vector<vector<int>> subsets(vector<int>& nums) {
        return f(nums, 0);
    }
};