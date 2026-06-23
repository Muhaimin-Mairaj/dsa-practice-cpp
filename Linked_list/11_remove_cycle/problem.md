## Remove Loop in a Linked List
### Difficulty: _`Medium`_
---
### **Statement**
Given the head of a linked list that may contain a loop. A loop means that the `last node` of the linked list is connected back to a node in same list. The task is to `remove` the loop from the linked list (`if it exists`).

---
### **Example 1**
- Input: `List: 1 -> 3 -> 4 -> back to 3`
- Output: `1 -> 3 -> 4`

### **Example 2**
- Input: `List: 1 -> 8 -> 3 -> 4`
- Output: `1 -> 8 -> 3 -> 4`
- Explanation: `There is no loop`

