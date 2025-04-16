class Solution {

public:
#define mod 1000000007
    //Lets take any valid pattern for k orders, lets find out in how many ways we can insert a k+1 
    //order, eg -p1-p2-p3-d1-d2-d3-:k=3: 2k+1=7 positions to insert: p1 at 0 so d1 at 1 to 6: 6 posible
    //similarly 7+6+5+3+4+2+1: sum of 2k+1 num: (2k+1)(k+1) for a given pattern 
    //lets say we have t such valid patterns for k so total : t*(above ans)
    int countOrders(int n) {
        long long ans=1, res=1;
        //i=1: ans =1
        if (n==0) return res;
        //i=2: 2(2+1)/2
        //-p1-d1-: 6



        for(int i=2; i<=n; i++){


            ans=(res*((i*((2*i-1)%mod))%mod))%mod;//for one case, res is total valid sol till i-1
            
            res =ans;
        }
        return ans;


        
    }
};