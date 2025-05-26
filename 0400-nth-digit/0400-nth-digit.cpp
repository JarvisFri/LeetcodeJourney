class Solution {
public:
    int findNthDigit(int n) {
        //Find in how many digit no does n lie
        //1-9: 9, 10-99: 90*2, ..
        int currDigit=1;
        long long numTillDigit=0;
        while(numTillDigit<n){
            numTillDigit+=9*(pow(10,currDigit-1))*currDigit;
            currDigit++;
        }
        currDigit--;//Now it points to currDigit for numTillDigit
        //Now numTillDigit > n
        //So we reduce once
        numTillDigit-=9*(pow(10, currDigit-1))*currDigit;
        int rem=n-numTillDigit;
        // So n lies in rem which has currDigit digits
        //Which num contains n?
        int num=pow(10,currDigit-1) +(rem-1)/currDigit;
        //Which place from left in num?
        int place=(rem-1)%currDigit;
        int ans=0;
        for(int j=currDigit; j>place; j--){
            ans=num%10;
            num=num/10;
        }
        return ans;

    }
};