
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;

        for (int num : nums) {
            mp[num] = true;
        }

        int maxLen = 0;

        for (int num : nums) {
            // Check whether this is the start
            if (mp.find(num - 1) == mp.end()) {
                int curr = num;
                int len = 1;

                // Extend the sequence
                while (mp.find(curr + 1) != mp.end()) {
                    curr++;
                    len++;
                }

                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};
