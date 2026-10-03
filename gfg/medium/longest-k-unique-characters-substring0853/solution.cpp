class Solution {
  public:
int longestKSubstr(string &s, int k) {

    int low = 0, high = 0;          // Sliding window: [low ... high]
    int res = INT_MIN;              // Store maximum length
    int n = s.size();               // String length

    unordered_map<char, int> f;     // Character -> frequency

    // Expand window using high
    for (high = 0; high < n; high++) {

        f[s[high]]++;               // Add current character

        // If unique characters > k, shrink from left
        while (f.size() > k) {

            f[s[low]]--;             // Remove left character

            low++;                   // Move left pointer

            // If frequency became 0, remove character from map
            if (f[s[low - 1]] == 0)
                f.erase(s[low - 1]);
        }

        // Window has exactly k unique characters
        if (f.size() == k) {

            int len = high - low + 1; // Current window length

            res = max(res, len);      // Keep maximum length
        }
    }

    // No substring with exactly k unique characters
    if (res == INT_MIN)
        return -1;

    return res;
}
};