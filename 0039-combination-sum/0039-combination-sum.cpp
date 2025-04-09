class Solution {
public:
    //Decision: Include : f(arr, i, target1, curr,res)
    //          Exclude : f(arr,i+1, target2,curr,res)
    //Subproblem/ Recurrsive step:
    //          Include: curr.pushback(i) -> f(arr, i, target-i,curr res)
    //          Exclude: f(arr, i+1, target)
    //Reccurrance:
    //          f(arr,i, target-i)=include +exclude
    //Base Case:
    //  `       if(target=0)-> ans.push(curr)
    //          if(target<0)-> return
    //          if(i==n)-> return //target ==0 is handled already
    //Prunning: 
    //          If currSum > target
    void f(vector<int> & arr, int i, int target, vector<int> &curr,vector<vector<int>>&res, int sum, int original_target){

        //Base Case
        int n=arr.size();
        //Positive
        if(target==0){
            res.push_back(curr);
            return;
        }

        //Negative
        if(i==n || target<0){
            return;
        }

        //Prunning
        if(sum>original_target) return;

        //Recurrance
        //Exclude
        f(arr, i+1,target, curr, res, sum, original_target);
        //Include
        curr.push_back(arr[i]);
        sum+=arr[i];
        // cout<<"Sum"<<sum<<endl;
        // for(auto k:curr){
        //     cout<<k<<" ";
        // }
        // cout<<endl;

        f(arr,i,target-arr[i],curr,res,sum, original_target);
        // sum-=arr[i];
        curr.pop_back();

        return;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>res;
        vector<int>curr;
        
        f(candidates,0,target,curr,res,0,target);
        return res;

    }
};

