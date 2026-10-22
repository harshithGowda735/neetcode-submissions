class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char , int>freq;
        unordered_map<char, int>value;
        if(s.size()!=t.size()){
            return false;
        }
         for(char c : s){
            freq[c]++;
         }
         for(char i:t){
            value[i]++;
         }
         return freq==value;
    }
};
