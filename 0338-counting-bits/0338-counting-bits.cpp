class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        int i;

        res[0]=0;
        for(int i=1; i<=n; i++){
            //i-1 : 111000: if i-1 is even , res[i]=res[i-1]+1;
            //i: is even: [11100]10, i-1:[11100]01, j:[11100]00=i&i-1, res[i]=res[j]+1
            res[i]=res[(i & i-1)]+1;
        }

        return res;
    }
};