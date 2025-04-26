class Solution {
public:
    //Backtracking enumeration
    //Decision: take one or two digit
    //Base: validation, pos,neg

    bool checkValid(string s, int startIdx, int endIdx){
        int ans=0;
        while(startIdx<=endIdx){
            ans*=10;
            ans+=s[startIdx]-'0';
            startIdx++;
        }
        if(ans>0 && ans<=26) return true;
        return false;
    }

    int countDecoding(string &s, int startIdx, int endIdx, vector<pair<int,int>> &dp){
        
        int n=s.size();
        if(s[startIdx]-'0' ==0) return 0;
        if(endIdx>=n) return 0;
        //Base Check valid
        if(!checkValid(s,startIdx,endIdx)) return 0;
        //Base
        if(endIdx==n-1) return 1;
        
        //DP lookup
        if(startIdx==endIdx && dp[startIdx].first!=-1) return dp[startIdx].first;
        else if(dp[startIdx].second!=-1) return dp[startIdx].second;
        //Recurrance
        
        int count1=countDecoding(s,endIdx+1, endIdx+1, dp);
        int count2=countDecoding(s,endIdx+1, endIdx+2, dp);

        if(startIdx==endIdx) dp[startIdx].first=count1+count2;
        else dp[startIdx].second=count1+count2;
        return count1+count2;
    }
    int numDecodings(string s) {
        int n=s.size();
        // vector<pair<int,int>> dp(n,{-1,-1});
        
        //Bottomup 
        //DnC : f(s,i)=f(s,i-1)+f(s,i-2) //i-1: single digit, i-2: double digit
        //Subproblem: prefix subarray
        vector<int> dp(n,0);

        dp[0]=s[0]=='0'?0:1;
        if(n==1) return dp[0];
        //Single:
        if(s[1]!='0') dp[1]+=dp[0];

        if(s[0]=='1' || (s[0]=='2' && s[1]<='6')) dp[1]+=1;


        for(int i=2; i<n; i++){
            //Single digit
            if(s[i]!='0')
                dp[i]+=dp[i-1];
            //Double gigit
            if(s[i-1]=='1')
                dp[i]+=dp[i-2];
            if(s[i-1]=='2' && s[i]<='6')
                dp[i]+=dp[i-2];
        }

        return dp[n-1];



        // return countDecoding(s,0,0,dp)+countDecoding(s,0,1,dp);
        
    }
};