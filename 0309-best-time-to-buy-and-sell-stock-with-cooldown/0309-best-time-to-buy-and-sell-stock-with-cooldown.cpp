class Solution {
public:
    //dp_buy(i) stores the maximum profit till i given last transaction done was i buy
    //dp_sell(i) stores the maximum profit till i given last transaction done was i sell
    int maxProfit(vector<int>& prices) {
    int  n=prices.size();
    vector<int> dp_buy(n,0),dp_sell(n,0);

    if(n<=1) return 0;

    dp_buy[0]=-prices[0];//we need to buy since last transaction need to be buy
    dp_sell[0]=0;

    dp_buy[1]=max(-prices[0],-prices[1]);
    dp_sell[1]=max(0,dp_buy[0]+prices[1]);

    for(int i=2; i<n; i++){
        dp_buy[i]=max(dp_buy[i-1], dp_sell[i-2]-prices[i]);
        dp_sell[i]=max(dp_sell[i-1], dp_buy[i-1]+prices[i]);
    }

    return dp_sell[n-1];

    }
};