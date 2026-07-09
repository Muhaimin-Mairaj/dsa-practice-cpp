## Hash Table With Chaining Implementation

### **Statement**
The task is to implement the `hash table` and its basic functions from scratch with chaining as collision resolution technique.

- **Insert(key, value):** This function inserts key-value pair at calculated hash index. if key already exists, it simply updates its value.

- **Delete(key):** This function deletes the key-value pair at its corresponding hash index. If Node does not exists, it simply returns `-1`

- **Search(key):** This function searches for key-value pair for corresponding key. If it does not exists, it simply returns `-1`

- **Rehash():** This function simply doubles the size of hash table and relink all nodes according to their new hash indices if load factor exceeds the default load factor (often 0.75) to maintain the efficiency of hash table.

