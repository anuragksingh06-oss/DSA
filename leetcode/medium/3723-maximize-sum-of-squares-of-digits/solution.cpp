class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num || sum <= 0)
            return "";

        string ans;

        while (sum >= 9 && ans.size() < num) {
            ans += '9';
            sum -= 9;
        }

        if (sum > 0 && ans.size() < num) {
            ans += char('0' + sum);
            sum = 0;
        }

        while (ans.size() < num) {
            ans += '0';
        }

        return ans;
    }
};