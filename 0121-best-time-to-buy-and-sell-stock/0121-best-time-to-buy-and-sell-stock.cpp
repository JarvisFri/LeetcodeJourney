class Solution {
public:
    //Keep maxFronEnd Suffix array
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), maxPrice=0, res=0, temp;
        
        for(int i=n-1; i>=0; i--){
            maxPrice=max(maxPrice,prices[i]);
            
            temp=maxPrice-prices[i];
            res=max(res,temp);
        }

        
        return res;
    }
};