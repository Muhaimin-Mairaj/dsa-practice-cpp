## Union Of Two Linked Lists
### Difficulty: _`Medium`_
---
### **Statement**
Given two singly linked lists, create a new linked list that contains the union of elements present in both lists.
- Each element should appear only once in the resulting list(no duplicates allowed).
- The order of elements in the resulting list should be, all distinct nodes of the first list then remaining distinct nodes (nodes that are not in first) of the second list.

---
### **Example 1**
- Input:<br>
`List1: 9 -> 6 -> 4 -> 3 -> 8`<br> 
`List2: 1 -> 2 -> 8 -> 6 -> 2`
- Output: `9 -> 6 -> 4 -> 3 -> 8 -> 1 -> 2`

### **Example 2**
- Input:<br>
`List1: 1 -> 5 -> 1 -> 2 -> 2 -> 5`<br> 
`List2: 4 -> 5 -> 6 -> 7 -> 1`
- Output: `1 -> 5 -> 2 -> 4 -> 6 -> 7`
