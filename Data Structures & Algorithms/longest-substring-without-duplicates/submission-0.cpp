class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left =0;
        int maxlen =0;
        unordered_set<char>seen;
        for(int r =0;r<n;r++){
            while(seen.count(s[r])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[r]);
            maxlen =max(maxlen ,r - left+1);
        }
        return maxlen;
    }
};
