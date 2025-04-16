class Solution {
public:
    // n=1, ans= 9 (no. of unique digit)
    // n=2, ans= _9 * _9  1st place: 1-9 2nd place 0-10 -1=9
    // n=3, ans= _9 * _9 * _8 1st place: 1-9 2nd place 0-9 -1=9 3d place: 1-10 -2=8...
    // n ans = _9 *_(10-1)* _(10-2)...
    int countNumbersWithUniqueDigits(int n) {
        int ans=1, res=1;
        if(n==0) return res;


        for(int i=0; i<n; i++){
            if(i==0) ans=9;

            if(i>0) ans*=(10-i);

            res+=ans;

        }

        return res;
        
    }
};