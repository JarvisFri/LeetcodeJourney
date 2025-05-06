class Solution {
public:
    //Keep maxFronEnd Suffix array
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), maxPrice=0, res=0, temp;
        vector<int> maxFromEnd(n);
        for(int i=n-1; i>0; i--){
            maxPrice=max(maxPrice,prices[i]);
            maxFromEnd[i]=maxPrice;
        }

        for(int i=0; i<n-1; i++){
            temp=maxFromEnd[i+1]-prices[i];
            res=max(res,temp);
        }

        return res;
    }
};