class Solution {
public:
    int minMoves2(vector<int>& nums) {

        // Step 1: Sort the array so we can find the median
        sort(nums.begin(), nums.end());

        // Step 2: Find the middle element (median)
        int n = nums.size();
        int median = nums[n / 2];

        // Step 3: Store the total number of moves
        int ans = 0;

        // Step 4: Calculate distance of every element from median
        for(int i = 0; i < n; i++) {

            // Number of moves needed to make nums[i] equal to median
            ans += abs(nums[i] - median);
        }

        // Step 5: Return minimum total moves
        return ans;
    }
};