class Solution {
public:


    int longestValidParentheses(string s) {
        int n=s.size(), maxValid=0, count;
        stack<char> temp;
        for(int i=0; i<n; i++ ){
            count=0;
            
            while (!temp.empty()) {
                    temp.pop();
                }

            for(int j=i; j>=0; j--){
                if(s[j]==')'){
                    temp.push(')');
                    count++;
                    // cout<<count<<" )  \n";
                }     
                else{
                    if(!temp.empty()){
                        temp.pop();
                        count++;
                        // cout<<count<<" ( \n";
                        if(temp.empty()) maxValid=max(count,maxValid);
                    }else break; 

                }
                
            }
        }

        return maxValid;
    }
};