## LRU Cache Implementation Using Doubly Linked List + Hash Map
### Difficulty: _`Hard`_
---
### **Statement**
Design a data structure that works like **LRU(Least Recently Used)** Cache. The LRU Cache class has two methods **get()** and **put()** which are defined as follows.
- **LRUCache (Capacity c):** Initialize LRU cache with positive size capacity **c**.
- **get(key)**: Returns the value of the key if it already exists in the cache, otherwise returns -1.
- **put(key, value)**: If the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity, it should remove the key-value pair with the lowest priority.  

---
### **Example 1**
- Input:<br>
`LRUCache cache(2)`<br>
`put(1,1)`<br>
`put(2,2)`<br>
`get(1)`<br>
`put(3,3)`<br>
`get(2)`<br>
`put(4,4)`<br>
`get(1)`<br>
`get(3)`<br>
`get(4)`<br>
- Output: `1 -1 -1 3 4`

