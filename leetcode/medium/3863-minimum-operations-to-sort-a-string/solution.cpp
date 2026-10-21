class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Step 1: Check if already sorted
        bool sorted = true;

        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) {
                sorted = false;
                break;
            }
        }

        if (sorted)
            return 0;

        // With 2 characters, we cannot change their order
        if (n == 2)
            return -1;

        char smallest = s[0];
        char largest = s[0];

        // Find smallest and largest character
        for (int i = 1; i < n; i++) {
            if (s[i] < smallest)
                smallest = s[i];

            if (s[i] > largest)
                largest = s[i];
        }

        // One operation is enough
        if (s[0] == smallest || s[n - 1] == largest)
            return 1;

        // Check the middle characters
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == smallest || s[i] == largest)
                return 2;
        }

        // Otherwise, it needs 3 operations
        return 3;
    }
};