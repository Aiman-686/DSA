
class Solution {
    
    void dfs(int i, int cost,
             vector<int>& toppingCosts,
             int target, int& ans) {

        // 1. All toppings have been considered
        if (i == toppingCosts.size()) {

            // Is this dessert closer to target?
            if (abs(cost - target) < abs(ans - target)) {
                ans = cost;
            }

            // If equally close, choose smaller cost
            else if (abs(cost - target) == abs(ans - target)) {
                ans = min(ans, cost);
            }

            return;
        }

        // 2. Try 0, 1, and 2 quantities of current topping
        for (int take = 0; take <= 2; take++) {

            // 3. Move to the next topping
            dfs(i + 1,
                cost + take * toppingCosts[i],
                toppingCosts,
                target,
                ans);
        }
    }

public:

    int closestCost(vector<int>& baseCosts,
                    vector<int>& toppingCosts,
                    int target) {

        // 4. Initially, no best answer exists
        int ans = INT_MAX;

        // 5. Exactly one base must be selected
        for (int base : baseCosts) {

            // Start exploring toppings from index 0
            dfs(0, base, toppingCosts, target, ans);
        }

        return ans;
    }
};
