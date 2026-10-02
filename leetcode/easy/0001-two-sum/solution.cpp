class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Store: number -> its index
        unordered_map<int, int> mp;

        // Check each number one by one
        for (int i = 0; i < nums.size(); i++) {

            // Find the number required to make target
            int needed = target - nums[i];

            // If needed number is already stored, answer found
            if (mp.find(needed) != mp.end()) {
                return {mp[needed], i};
            }

            // Store current number and its index
            mp[nums[i]] = i;
        }

        // No pair found (normally won't happen due to problem constraint)
        return {};
    }
};