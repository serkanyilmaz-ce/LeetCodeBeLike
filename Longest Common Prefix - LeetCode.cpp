#include <string>
#include <vector>
#include <limits>
#include <climits>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_length = INT_MAX;
        for (const string& str : strs) {
            min_length = min(min_length, static_cast<int>(str.length()));
        }
        
        string prefix;
        for (int i = 0; i < min_length; ++i) {
            char current_char = strs[0][i];
            for (const string& str : strs) {
                if (str[i] != current_char) {
                    return prefix;
                }
            }
            prefix += current_char;
        }
        return prefix;
    }
};