// https://leetcode.com/problems/roman-to-integer/description/

#include <string>

using namespace std;

class Solution
{
public:
    enum RomanNumerals
    {
        I = 1,
        V = 5,
        X = 10,
        L = 50,
        C = 100,
        D = 500,
        M = 1000
    };

    int romanToInt(string s)
    {
        int total = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'I' && i + 1 < s.size() &&
                (s[i + 1] == 'V' || s[i + 1] == 'X'))
            {
                total -= RomanNumerals::I;
                continue;
            }
            else if (s[i] == 'X' && i + 1 < s.size() &&
                     (s[i + 1] == 'L' || s[i + 1] == 'C'))
            {
                total -= RomanNumerals::X;
                continue;
            }
            else if (s[i] == 'C' && i + 1 < s.size() &&
                     (s[i + 1] == 'D' || s[i + 1] == 'M'))
            {
                total -= RomanNumerals::C;
                continue;
            }
            else if (s[i] == 'I')
            {
                total += RomanNumerals::I;
                continue;
            }
            else if (s[i] == 'V')
            {
                total += RomanNumerals::V;
                continue;
            }
            else if (s[i] == 'X')
            {
                total += RomanNumerals::X;
                continue;
            }
            else if (s[i] == 'L')
            {
                total += RomanNumerals::L;
                continue;
            }
            else if (s[i] == 'C')
            {
                total += RomanNumerals::C;
                continue;
            }
            else if (s[i] == 'D')
            {
                total += RomanNumerals::D;
                continue;
            }
            else if (s[i] == 'M')
            {
                total += RomanNumerals::M;
                continue;
            }
        }
        return total;
    }
};