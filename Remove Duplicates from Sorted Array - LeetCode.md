# Intuition
The problem requires removing duplicates from a sorted array in-place. Since the array is already sorted, all duplicates will be adjacent. This property allows us to efficiently identify and overwrite duplicates with unique elements as we traverse the array.

# Approach
Use two pointers: one (`i`) to iterate over the entire array and another (`k`) to track the position for placing the next unique element.  
- Initialize `k` to 0.
- Traverse the array with `i`.  
  - If it's the first element (`i == 0`) or `nums[i] != nums[i - 1]`, assign `nums[k] = nums[i]` and increment `k`.
- After the loop, the first `k` elements of the array will be the deduplicated result.  
- Return `k` as the new length.

# Complexity
- Time complexity:  
  $$O(n)$$  
  Each element is visited once.

- Space complexity:  
  $$O(1)$$  
  The operation is performed in-place with constant extra space.

# Code
```cpp []
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == 0 || nums[i] != nums[i - 1])
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
```