
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        // Maximum profit when holding a stock
        int hold = -prices[0];

        // Maximum profit when NOT holding a stock
        int cash = 0;

        // Day 0 is already handled
        for (int i = 1; i < prices.size(); i++) {

            // Save yesterday's states
            int oldHold = hold;
            int oldCash = cash;

            // Today I want to HOLD:
            // 1. Keep holding
            // 2. Buy today
            hold = max(
                oldHold,
                oldCash - prices[i]
            );

            // Today I want CASH:
            // 1. Keep cash
            // 2. Sell today and pay fee
            cash = max(
                oldCash,
                oldHold + prices[i] - fee
            );
        }

        return cash;
    }
};
