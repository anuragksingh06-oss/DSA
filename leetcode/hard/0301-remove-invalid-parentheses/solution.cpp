class Solution {
public:

    // Checks whether the string has valid parentheses
    bool isValid(string s) {

        int balance = 0;

        for (char ch : s) {

            // Opening bracket increases balance
            if (ch == '(') {
                balance++;
            }

            // Closing bracket must have a matching '('
            else if (ch == ')') {

                balance--;

                // More ')' than '(' at any point -> invalid
                if (balance < 0)
                    return false;
            }
        }

        // All '(' must also be matched
        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        // BFS queue: stores strings at current removal level
        queue<string> q;

        // Prevent processing the same string again
        unordered_set<string> visited;

        // Start with original string
        q.push(s);
        visited.insert(s);

        while (!q.empty()) {

            int size = q.size();

            // Check every string at this removal level
            for (int i = 0; i < size; i++) {

                string curr = q.front();
                q.pop();

                // If valid, this is a minimum-removal answer
                if (isValid(curr)) {
                    ans.push_back(curr);
                }

                // If we already found valid strings,
                // don't generate the next level.
                if (!ans.empty())
                    continue;

                // Generate strings by removing one character
                for (int j = 0; j < curr.length(); j++) {

                    // We only need to remove parentheses
                    if (curr[j] != '(' && curr[j] != ')')
                        continue;

                    // Remove character at index j
                    string next = curr.substr(0, j) +
                                  curr.substr(j + 1);

                    // Process this string only once
                    if (visited.find(next) == visited.end()) {

                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // If valid answers were found,
            // minimum removal level is complete.
            if (!ans.empty())
                break;
        }

        return ans;
    }
};