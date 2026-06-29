## Split a Circular Linked List Into Two Halves
### Difficulty: _`Medium`_
---
### **Statement**
Given a circular linked list, the task is to split it into two circular linked lists. If there are an odd number of nodes in the given circular linked list, then out of the resulting two halved lists, the first list should have one more node than the second list.

---
### **Example 1**
- Input: `List: 10 -> 4 -> 9 -> back to 10`
- Output:<br>
`List1: 10 -> 4 -> back to 10`<br> 
`List2: 9 -> back to itself`

### **Example 2**
- Input: `List: 10 -> 20 -> 30 -> 40 -> back to 10`
- Output:<br> 
`List1: 10 -> 20 -> back to 10`<br>
`List2: 30 -> 40 -> back to 30`