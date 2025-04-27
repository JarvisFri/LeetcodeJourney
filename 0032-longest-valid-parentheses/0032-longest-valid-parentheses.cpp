class Solution {
public:


    int longestValidParentheses(string s) {

        //s(i)= 0 if ')'
        //else s(i)=s(i-1)+2+s(s(i-2)-2)

        int n=s.size(), res=0;

        vector<int> dp(n,0);

        if(n==0) return 0;


        dp[0]=0;
        for(int i=1; i<n; i++){

            if(s[i]==')' && (i-dp[i-1]-1)>=0 && s[i-dp[i-1]-1]=='('){
                dp[i]+=dp[i-1]+2;
                if((i-dp[i-1]-2)>=0)
                    dp[i]+=dp[i-dp[i-1]-2];
            }
            

            res=max(res, dp[i]);
            // cout<<dp[i]<<" ";
        }
        
        return res;
        

        //Method 1: o(n^2)
        // int n=s.size(), maxValid=0, count;
        // stack<char> temp;
        // for(int i=0; i<n; i++ ){
        //     count=0;
            
        //     while (!temp.empty()) {
        //             temp.pop();
        //         }

        //     for(int j=i; j>=0; j--){
        //         if(s[j]==')'){
        //             temp.push(')');
        //             count++;
        //             // cout<<count<<" )  \n";
        //         }     
        //         else{
        //             if(!temp.empty()){
        //                 temp.pop();
        //                 count++;
        //                 // cout<<count<<" ( \n";
        //                 if(temp.empty()) maxValid=max(count,maxValid);
        //             }else break; 

        //         }
                
        //     }
        // }

        // return maxValid;
    }
};