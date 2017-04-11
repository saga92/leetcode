#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
            else if(st.empty())
                return false;
            else if((s[i]==')'&&st.top()!='(')||
                    (s[i]=='}'&&st.top()!='{')||
                    (s[i]==']'&&st.top()!='['))
                return false;
            else
                st.pop();
        }
        if(!st.empty())
            return false;
        return true;
    }
};

int main(){
    Solution solution;
    bool isValid=solution.isValid("([)]");
    return 0;
}