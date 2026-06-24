## Design Browser History
### Difficulty: _`Medium`_
---
### **Statement**
You have a browser of one tab where you start on the homepage and and you can visit another `URL`, get back in the history number of steps or move forward in the history number of steps. The task is to design a data structure and implement the functionality of visiting a `URL` starting from the homepage and moving back and forward in the history. The following functionalities should be covered:
- **visit(url) :** Visits a URL given as a string.
- **forward(steps) :** Takes `steps` forward.
- **back(steps) :** Takes `steps` backward.

**Note:** The starting page of the tab will always be the homepage.


---
### **Example**
- **Input:**<br>
`homepage = "gfg.org"`<br>
`visit("google.com");`<br>
`visit("facebook.com");`<br>
`visit("youtube.com");`<br>
`back(1);`<br>
`back(1);`<br>
`forward(1);`<br>
`visit("linkedin.com");`<br>
`forward(2);`<br>
`back(2);`<br>
`back(7);`<br>


- **Output:**<br>
`facebook.com`<br>
`google.com`<br>
`facebook.com`<br>
`linkedin.com`<br>
`google.com`<br>
`gfg.org`<br>



