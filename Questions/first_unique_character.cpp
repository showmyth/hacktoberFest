// Given a string, return the index of the first non-repeating character. If it
// doesn’t exist, return -1.

#include <unordered_map>
#include <string>

class Solution {
public:
    int firstUniqChar(const std::string& s) {
        if (s.empty()) {
            return -1;
        }
        
        std::unordered_map<char, int> freq;  
        // Count frequency of each character
        for (char c : s) {
            ++freq[c];
        }
        
        
        // Find first character with frequency 1
        
        for (int i = 0; i < s.length(); ++i) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};