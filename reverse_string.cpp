#include <iostream>

class Solution {
public:
    std::string reverseString(std::string s) {
        int i=0, j=s.length()-1;
        while(i<j){
            std::swap(s[i++], s[j--]);
        }
        return s;
    }
};

int main(){
    Solution solution;
    std::string resultStr = solution.reverseString("Hello");
    return 0;
}

/*
class Solution {
public:
    std::string reverseString(std::string s) {
        std::reverse(s.begin(), s.end());
        return s;
    }
};
 */