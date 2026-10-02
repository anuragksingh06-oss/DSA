
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {

        vector<vector<int>> result;

        sort(a.begin(), a.end());

        int n = a.size();

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && a[i] == a[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            // a[left] + a[right] = -a[i]
            int sum = -a[i];

            while (left < right) {

                int s = a[left] + a[right];

                if (s == sum) {

                    result.push_back({
                        a[i],
                        a[left],
                        a[right]
                    });

                    left++;
                    right--;

                    // Skip duplicate left values
                    while (left < right && a[left] == a[left - 1])
                        left++;

                    // Skip duplicate right values
                    while (left < right && a[right] == a[right + 1])
                        right--;
                }

                else if (s < sum) {
                    left++;
                }

                else {
                    right--;
                }
            }
        }

        return result;
    }
};
   
