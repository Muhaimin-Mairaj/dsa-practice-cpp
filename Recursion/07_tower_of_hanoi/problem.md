## Tower of Hanoi Algorithm
### Difficulty: _`Medium`_
---
### **Statement**
The `Tower of Hanoi` is a classic mathematical puzzle involving three rods (`A, B, and C`) and `n` disks of different sizes. Initially, all disks are stacked on the rod A in decreasing order of diameter - the largest disk at the bottom and the smallest at the top.  
Goal is to move the entire stack to another rod `(rod C)` while following these rules:

- Move only one disk at a time.
- At each step, you can take the top disk from any rod and place it on another rod.
- A disk can only be moved if it is the topmost disk of a rod.
- No larger disk may be placed on top of a smaller rod.
---
### **Example**
- Input: `3`
- Output:    
             `Disk 1 moved from A to C`<br>
             `Disk 2 moved from A to B`<br>
             `Disk 1 moved from C to B`<br>
             `Disk 3 moved from A to C`<br>
             `Disk 1 moved from B to A`<br>
             `Disk 2 moved from B to C`<br>
             `Disk 1 moved from A to C`<br>

