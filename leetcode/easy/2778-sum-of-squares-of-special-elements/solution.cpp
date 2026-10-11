class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            // If i divides n, position i is special
            if (n % i == 0) {
                // i is 1-based, so array index is i-1
                ans += nums[i - 1] * nums[i - 1];
            }
        }

        return ans;
    }
};