class Solution {
public:
    int totalFruit(vector<int>& a) {
        
        unordered_map<int, int> f;  // fruit type -> frequency
        
        int low = 0, high = 0;
        int n = a.size();
        int res = INT_MIN;
        
        for (high = 0; high < n; high++) {
            
            // Add current fruit to the window
            f[a[high]]++;
            
            // More than 2 fruit types -> shrink window
            while (f.size() > 2) {
                
                // Remove leftmost fruit
                f[a[low]]--;
                
                // If no more of this fruit exists, remove its type
                if (f[a[low]] == 0) {
                    f.erase(a[low]);
                }
                
                // Move left pointer
                low++;
            }
            
            // Current valid window length
            int len = high - low + 1;
            
            // Update maximum length
            res = max(res, len);
        }
        
        return res;
    }
};