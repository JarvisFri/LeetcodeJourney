class Solution {
public:
    //Recurcively divide k by n-1!-> k=k%n-1! by n-2!.. till (n-i)=1!
    int search(vector<int>&numset, int i){
        //return ith elt in list
        // int k=0;
        cout<<i<<" ";
        for(int j=1; j<10; j++){
            if(numset[j]==1){
                i--;
                if(i==0){
                    numset[j]=0;
                    return j;
                }
                
            }
        }
        return 0;
    }
    

    void f( vector<int>&numset, int n,int k, vector<int>&fact, string & ans){
        //Base
        if(n==0)
        return;

        //Recurrsion
        int order=k/fact[n-1];
        //search for string in order
        int a=search(numset,order+1);
        //Append a in ans
        ans+='0'+a;
        k=k%fact[n-1];
        f(numset,n-1,k,fact,ans);


    }
    string getPermutation(int n, int k) {
        k--;
        
        vector<int> numset(10,1);
        vector<int> fact;
        string ans="";
        int currF=1;
        for(int i=0; i<10; i++){
            
            if(i==0) fact.push_back(currF);
            else{
                currF*=i;
                fact.push_back(currF);
            }
        }

        f(numset,n,k,fact,ans);
        return ans;

    }
};