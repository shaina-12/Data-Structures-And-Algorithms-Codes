class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //stack<int> s;
        int i=1, profit=0;
        while(i<prices.size()){
            if(prices[i]-prices[i-1]>0){
                profit+=(prices[i]-prices[i-1]);
            }
            i++;
        }
        return profit;
    }
};
