class Solution {
public:
    using ll = long long;
    
    ll totalWaviness(ll num1, ll num2) {
        return countUpTo(num2) - countUpTo(num1 - 1);
    }
    
private:
    string s;
    int n;
    // dp[pos][prev+1][prevPrev+1][tight][started] -> {count, sum}
    vector<vector<vector<vector<vector<pair<ll, ll>>>>>> dp;
    
    pair<ll, ll> dfs(int pos, int prev, int prevPrev, bool tight, bool started) {
        if (pos == n) {
            // We've formed one valid number (including 0)
            return {1, 0};
        }
        auto &res = dp[pos][prev+1][prevPrev+1][tight][started];
        if (res.first != -1) return res;
        
        int limit = tight ? s[pos] - '0' : 9;
        ll totalCnt = 0, totalSum = 0;
        
        for (int d = 0; d <= limit; ++d) {
            bool newTight = tight && (d == limit);
            bool newStarted = started || (d != 0);
            
            int newPrev, newPrevPrev;
            if (!started && d == 0) {
                // still no digit placed
                newPrev = -1;
                newPrevPrev = -1;
            } else if (!started && d != 0) {
                // first non-zero digit
                newPrev = d;
                newPrevPrev = -1;
            } else {
                // already started, shift window
                newPrev = d;
                newPrevPrev = prev;
            }
            
            // Contribution: the digit at 'prev' (which is now at position pos-1)
            // becomes a peak or valley? We need both neighbours: prevPrev and d.
            ll add = 0;
            if (prevPrev != -1) {
                if ((prevPrev < prev && prev > d) || (prevPrev > prev && prev < d))
                    add = 1;
            }
            
            auto [cnt, sum] = dfs(pos + 1, newPrev, newPrevPrev, newTight, newStarted);
            totalCnt += cnt;
            totalSum += sum + cnt * add;
        }
        
        return res = {totalCnt, totalSum};
    }
    
    ll countUpTo(ll x) {
        if (x < 0) return 0;
        if (x < 100) return 0; // no number with 3+ digits
        s = to_string(x);
        n = s.size();
        // Initialise dp with -1 (meaning uncomputed)
        dp.assign(n, vector<vector<vector<vector<pair<ll, ll>>>>>(11,
            vector<vector<vector<pair<ll, ll>>>>(11,
                vector<vector<pair<ll, ll>>>(2,
                    vector<pair<ll, ll>>(2, {-1, 0})))));
        auto [cnt, sum] = dfs(0, -1, -1, true, false);
        return sum;
    }
};