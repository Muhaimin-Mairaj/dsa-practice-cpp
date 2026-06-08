#include <iostream>

// This solution runs in O(n^2) average time complexity. However, the worst-case time complexiy is O(n^3) but this is extremely rare.

char rec_dup(std::string &s, int i){
    if(i == s.length()-1) return s[i];

    char curr = s[i];
    if(s[i] == rec_dup(s,i+1)){
        s.erase(i,1);
        if(curr == s[i]) s.erase(i,1);
    }
    return curr;
}

void rem_duplicates(std::string &s){
    while(s.length()){
        int len = s.length();
        rec_dup(s,0);
        int newlen = s.length();
        if(len == newlen) break;
    }

}

int main(){
    std::string s = "mississippi";
    rem_duplicates(s);
    std::cout << "Final string: " << s << std::endl;

    std::string s2 = "abccbccba";
    rem_duplicates(s2);
    std::cout << "Final string_2: " << s2 << std::endl;
    
    return 0;
}