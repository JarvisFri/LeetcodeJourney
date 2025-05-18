class Solution {
public:

    int findKthDigit(int x, int total, int k){
        int divisor=pow(10, total-k);
        return (x/divisor)%10;
    }

    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return true;

        int kDigit=0, t=x;

        while(t>0){
            t=t/10;
            kDigit++;
        }

        int m,n;
        for(int i=1, j=kDigit; i<j; i++, j--){

            m=findKthDigit(x,kDigit,i);
            n=findKthDigit(x,kDigit,j);

            if(m!=n) return false;

        }

        return true;
        
    }
};