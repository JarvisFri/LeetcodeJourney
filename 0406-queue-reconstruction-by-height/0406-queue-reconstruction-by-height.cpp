class Solution {
public:
    //Algo:
    //Sort array in decresing height, if same height then incresing k
    //Now insert in above order at kth index in ans and shift all elt to right if kth pos is not empty
    //This makes sure for every ith insertion : All elt in left are are larger so you are inserting at  correct postion and if any future elt inserts before curent elt that future elt is guranteed to be smaller so the codition for curr elt holds.

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),[](vector<int>& a, vector<int>&b){
            if (a[0]==b[0]) return a[1]<b[1];
            return a[0]>b[0];
        });

        int n=people.size();
        vector<vector<int>> ans(n,{-1,-1});
        vector<int> curr={0,0}, next={0,0};
        for(auto person:people){
            if(ans[person[1]][0]==-1){
                ans[person[1]]=person;
            }else{
                // curr[0]=person[0];
                // curr[1]=person[1];
                curr=person;
                int j;
                for(j=person[1]; j<n && ans[j][0]!=-1; j++){
                    // next[0]=ans[j][0];
                    // next[1]=ans[j][1];
                    next=ans[j];
                    ans[j]=curr;
                    curr=next;
                    // ans[j][0]=curr[0];
                    // ans[j][0]=curr[1];
                    

                }
                if(j<n){
                    ans[j]=curr;
                }
            }

        }

    return ans;
    }
    

    
};
//