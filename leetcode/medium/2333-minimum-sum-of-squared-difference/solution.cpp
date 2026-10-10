class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        int maxDiff = 0;
        for (int i = 0; i < n; i++) {
            maxDiff = max(maxDiff, abs(nums1[i] - nums2[i]));
        }

        vector<long long> cnt(maxDiff + 1, 0);
        for (int i = 0; i < n; i++) {
            cnt[abs(nums1[i] - nums2[i])]++;
        }

        for (int d = maxDiff; d >= 1 && k > 0; d--) {
            if (cnt[d] == 0) continue;

            if (cnt[d] <= k) {
                // lower all elements at level d to d-1
                k -= cnt[d];
                cnt[d - 1] += cnt[d];
                cnt[d] = 0;
            } else {
                // only partially lower: k elements go to d-1
                cnt[d - 1] += k;
                cnt[d] -= k;
                k = 0;
            }
        }

        long long ans = 0;
        for (long long d = 0; d <= maxDiff; d++) {
            ans += cnt[d] * d * d;
        }
        return ans;
    }
};