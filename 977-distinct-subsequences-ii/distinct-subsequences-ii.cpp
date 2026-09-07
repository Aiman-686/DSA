class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        long long total = 1;
        vector<long long> last(26, 0);
        for(char c : s){
            long long previousTotal = total;

            total = (2 * total) % MOD;
            total = (total - last[c - 'a'] + MOD) % MOD;
            last[c - 'a'] = previousTotal;

        }return (total - 1 + MOD) % MOD;
    }
};