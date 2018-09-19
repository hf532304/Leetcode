class Solution {
    public int maxProfit(int[] prices) {
        int res = 0;
        int cheapest_Price = Integer.MAX_VALUE;
        for(int i = 0; i < prices.length; i++){
            if(prices[i] < cheapest_Price){
                cheapest_Price = prices[i];
                continue;
            }
            else{
                if(prices[i] - cheapest_Price > res)
                    res = prices[i] - cheapest_Price;
            }
        }
        return res;
    }
}