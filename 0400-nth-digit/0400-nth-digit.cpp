class Solution {
public:
    //calculate i ie no digits of num where nth digit lies
    //sumDigit+=i*9*pow(10,i)
    int findNthDigit(int n) {
        long long i=0, sum_digit=0, n_rem=0,digit=0,ans=0;

        while(sum_digit<n){
            i++;
            sum_digit+=i*9*pow(10,i-1);
        }
        //here sum_digit> n so
        sum_digit-=i*9*pow(10,i-1);
        //now
        n_rem=n-sum_digit;
        int mod=n_rem%i;
        if(mod==0){
            digit=pow(10,i-1)+n_rem/i-1;
            ans=digit%10;
        }else{
            digit=pow(10,i-1)+n_rem/i ;
            
            ans=digit/(pow(10,i-mod));
            ans=ans%10;
        }

        return ans;
    }
};