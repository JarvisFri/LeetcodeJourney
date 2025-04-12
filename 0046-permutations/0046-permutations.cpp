class Solution {
public:
    //Decision: N different type of Solution for N elt in array
    //Divide problem in n solution: s(i) has a(i) as first elt and so on.
    //create a visited array and i
    //Base case:i==n

    void f(vector<int>& nums, int i, vector<int> &visited, vector<int> &curr, vector<vector<int>> &res ){
        //Base case
        int n=nums.size();
        if(i==n){
            res.push_back(curr);
            return;
        }
        //Recurrance
        for(int j=0; j<n; j++){
            if(!visited[j]){
                visited[j]=1;
                curr.push_back(nums[j]);
                f(nums, i+1, visited,curr, res);
                curr.pop_back();
                visited[j]=0;
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res; 
        vector<int> curr;

        vector<int> visited(nums.size(),0);


        f(nums, 0, visited,curr,res);
        return res;
        
    }
};