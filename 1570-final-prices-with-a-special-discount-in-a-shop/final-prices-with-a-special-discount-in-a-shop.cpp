class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            // Remove all greater elements
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }

            // If stack is empty, no discount
            if (st.empty())
                ans[i] = prices[i];
            else
                ans[i] = prices[i] - st.top();

            // Push current price
            st.push(prices[i]);
        }

        return ans;
    }
};