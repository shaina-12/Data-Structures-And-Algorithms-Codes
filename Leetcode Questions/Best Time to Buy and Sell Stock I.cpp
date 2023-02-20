class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //stack<int> s;
        int profit=0, val;
        int ele = prices[0];
        //s.push(prices[0])
        int i=1;
        while(i<prices.size()){
            if(prices[i]<ele){
                ele=prices[i];
            }
            else{
                profit = max(profit,prices[i]-ele);
            }
            i++;
        }
        return profit;
    }
};
