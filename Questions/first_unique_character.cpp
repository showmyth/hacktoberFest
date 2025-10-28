// Given a string, return the index of the first non-repeating character. If it
// doesn’t exist, return -1.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int firstUniqChar(const string &s) {
    vector<int> freq(256, 0); // frequency of each character (ASCII)
    
    for (char c : s)
        freq[c]++;
    
    for (int i = 0; i < s.size(); i++)
        if (freq[s[i]] == 1)
            return i;
    
    return -1;
}

int main() {
    string s;
    cin >> s;
    cout << firstUniqChar(s);
    return 0;
}

