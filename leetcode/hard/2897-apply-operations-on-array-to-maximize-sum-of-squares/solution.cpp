class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<long long> cnt(31, 0);

        // Count how many numbers contain each bit
        for (int x : nums) {
            for (int b = 0; b < 31; b++) {
                if (x & (1LL << b))
                    cnt[b]++;
            }
        }

        vector<long long> a(k, 0);

        // Build k largest numbers using highest bits first
        for (int b = 30; b >= 0; b--) {
            for (int i = 0; i < k && cnt[b] > 0; i++) {
                a[i] |= (1LL << b);
                cnt[b]--;
            }
        }

        long long ans = 0;

        // Sum of squares
        for (long long x : a)
            ans = (ans + x * x) % MOD;

        return ans;
    }
};