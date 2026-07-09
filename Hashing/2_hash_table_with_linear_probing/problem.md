## Hash Table With Linear Probing Implementation

### **Statement**
The task is to implement the `hash table` and its basic functions from scratch with linear probing as collision resolution technique.

- **Insert(key, value):** This function inserts key-value pair at calculated hash index. if key already exists, it simply updates its value.

- **Delete(key):** This function marks `(-1, -1)` at its corresponding hash index so that searching does not stop prematurely. If Node does not exists, it simply returns `-1`

- **Search(key):** This function searches for key-value pair for corresponding key. If it does not exists, it simply returns `-1`

- **Rehash():** This function simply doubles the size of hash table and insert all nodes at their new hash indices if load factor exceeds the default load factor (often 0.75) to maintain the efficiency of hash table.

