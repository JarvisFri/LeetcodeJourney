class Solution {
public:

    //Decision: "a ab", "aa b"
    //Subproblem: Suffix array: f(arr, i) 
    //Recurrance: f(arr,i )= i U f(arr, i+1)+ i i+1 f(arr, i+2)...f(arr, n)
    //                      Check if i, i i+1 .. are palandrome
    //Base Case: i==n --> push curr to res

    //aaaab: [a] aaab

    bool isPalandrome(string s){
        int n=s.size();

        for(int i=0; i<(n/2); i++ ){
            if(s[i]!=s[n-1-i]) return false;
        }
        return true;
    }

    void f(string s, int i, vector<string> &curr, vector<vector<string>>& res){
        //Base Case
        int n=s.size();
        if(i==n){
            res.push_back(curr);
            return;
        }

        //Recurrance
        for(int j=i+1; j<=n; j++){
            if(isPalandrome(s.substr(i,j-i))){
                curr.push_back(s.substr(i,j-i));
                f(s,j,curr,res);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        f(s,0,curr,res);
        return res;
    }
};