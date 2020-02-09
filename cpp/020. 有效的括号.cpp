#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        int len = s.size();
        if(len == 0)
            return true;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                if(st.empty())
                    return false;
                if(s[i] == ')' && st.top() != '(')
                    return false;
                if(s[i] == ']' && st.top() != '[')
                    return false;
                if(s[i] == '}' && st.top() != '{')
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main(void)
{
    cout << "020 is successful" << endl;
    return 0;
}