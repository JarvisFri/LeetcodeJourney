class Solution {
public:
    //Decision: Loop through the string and call recurrsive function for all valid substring to 
    //partition from given partition and call recurrsive function
    //Subproblem: Suffix array
    //Prb and subprob: submission of partition
    //Base Case: i=n;

    bool isPalindrome(string &s, int start, int end ){
        while(start<end){
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }


    void f(string &s, int i, vector<string> &currStr, vector<vector<string>> &res){
        int n=s.size();
        //Base
        if(i==n){
            res.push_back(currStr);
            return;
        }

        //Recurrsive
        for(int j=i+1; j<=n; j++){
            if(isPalindrome(s,i,j-1)){
                currStr.push_back(s.substr(i,j-i));
                f(s,j, currStr,res);
                currStr.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> currSet;

        f(s,0,currSet,res);

        return res;
    }
};