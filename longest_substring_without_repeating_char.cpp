#include<iostream>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int i=0,j=0,lasti=0;
        int longestLen=1;
        if(s.length() < 2)
            return s.length();
        for(j=1; j<s.length(); ++j){
            lasti=i;
            for(int k=i; k<j; ++k){
                if(s.at(k) == s.at(j)){
                    i=k+1;
                }
            }
            if(i == lasti){
                longestLen=max(longestLen,j-i+1);
            }
        }
        return longestLen;
    }

    int max(int a, int b){
        return a>b?a:b;
    }

};

int main(){
    Solution solution;
    std::cout<<solution.lengthOfLongestSubstring("abcabcbb")<<std::endl;
}

