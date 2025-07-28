// https://leetcode.com/problems/palindrome-number/description/

#include <cmath>
#include <string>
#include <limits.h>

using namespace std;

class Solution
{
public:
    string ito(int x)
    {
        string s = "";
        if (x == INT_MIN)
            return "-2147483648"; // Handle edge case for INT_MIN
        else if (x == 0)
            return "0";
        else if (x < 0)
        {
            s = "-";
            x = -x;
        }

        while (x > 0)
        {
            s = (char)(x % 10 + '0') + s;
            x /= 10;
        }
        return s;
    }

    bool isPalindrome(int x)
    {
        string s = ito(x);
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }
};