
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0;
        int ans = 0;

        map<char, int> mp;

        for (int right = 0; right < s.size(); right++) {

            mp[s[right]]++;

            while (mp[s[right]] > 1) {

                mp[s[left]]--;

                if (mp[s[left]] == 0)
                    mp.erase(s[left]);

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};   //trying to push on git hub

   