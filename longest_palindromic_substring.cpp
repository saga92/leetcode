#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        if(s.size()==1) return s;
        int min_start=0,max_len=1;
        for(int i=0;i<s.size();){
            if(s.size()-i<=max_len/2) break;
            int j=i,k=i;

        }
    }
};

int main(){
    Solution solution;
    string res=solution.longestPalindrome("babad");
    return 0;
}