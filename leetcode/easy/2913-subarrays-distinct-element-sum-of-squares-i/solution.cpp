class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Fix the starting point
        for (int i = 0; i < n; i++) {

            set<int> st;  // stores distinct elements

            // Extend the subarray
            for (int j = i; j < n; j++) {

                st.insert(nums[j]);

                // Number of distinct elements
                int distinct = st.size();

                // Add square of distinct count
                ans += distinct * distinct;
            }
        }

        return ans;
    }
};