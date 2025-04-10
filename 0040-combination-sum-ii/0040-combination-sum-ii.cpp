class Solution {
public:
    //Decision: Two types of Solutions: Starting with arr[i] and not Starting with arr[i]
    // Starts with arr[i]: Subproblem: cuur.push(arr [i]) , f(arr, i+1, target-arr[i])
    //Else: f(arr, next elt, target)
    //Base:
    //Positive target=0, neg, tart<0 , n=i;



    void f(vector<int>& arr, int i, int target, vector<int>& curr, vector<vector<int>>& res){
        //Base
        //Positive
        if(target==0){
            res.push_back(curr);
            return;
        }
        //Negative
        if(target<0) return;
        int n=arr.size();
        if(n==i) return;

        //Recurrsive Step:
        //Solutions starting with arr[i]
        curr.push_back(arr[i]);
        f(arr, i+1,target-arr[i],curr,res);
        curr.pop_back();

        //Solutions not starting with arr[i]
        int prev=arr[i];
        while(i<n){
            if(prev==arr[i]){
                i++;
            }else{
                break;
            }
        }
        f(arr,i,target,curr, res);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());
        f(candidates,0,target, curr, res);
        return res;
    
        
    }
};