// https://leetcode.com/problems/valid-parentheses/description/

#include <string>

using namespace std;

class Solution
{
public:
    struct Stack
    {
        char *arr;
        int top;
        int capacity;
    };

    bool isValid(string s)
    {
        Stack stack;
        stack.capacity = s.size();
        stack.top = -1;
        stack.arr = new char[stack.capacity];

        for (char c : s)
        {
            if (stack.top != -1)
            {
                if ((stack.arr[stack.top] == '(' && c == ')') || (stack.arr[stack.top] == '[' && c == ']') || (stack.arr[stack.top] == '{' && c == '}'))
                {
                    --stack.top;
                    continue;
                }
                else if (stack.top == -1 && (c == ')' || c == ']' || c == '}'))
                {
                    return false; // Unmatched closing bracket
                }
            }
            stack.arr[++stack.top] = c;
        }
        bool isValid = (stack.top == -1);
        delete[] stack.arr; // Clean up allocated memory
        return isValid;
    }
};