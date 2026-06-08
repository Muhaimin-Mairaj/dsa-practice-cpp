## Coin Change - Count Ways to Make Sum
### Difficulty: _`Medium`_
---
### **Statement**
- Given an integer array `coins[]` representing different denominations of currency and an integer `sum`. We need to find the number of ways we can make `sum` by using different combinations from `coins[]`.

- `Note:` Assume that we have an `infinite` supply of each type of coin. Therefore, we can use any coin as many times as we want.

---
### **Example 1**
- Input: `sum = 4, coins[] = [1, 2, 3]`
- Output: `4`
- Explanation: `There are four solutions: [1, 1, 1, 1], [1, 1, 2], [2, 2] and [1, 3]`

### **Example 2**
- Input: `sum =10, coins[] = [2, 5, 3, 6]`
- Output: `5`
- Explanation: `There are five solutions: [2, 2, 2, 2, 2], [2, 2, 3, 3], [2, 2, 6], [2, 3, 5] and [5, 5]`