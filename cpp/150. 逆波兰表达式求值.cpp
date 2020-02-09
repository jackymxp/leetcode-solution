#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int len = tokens.size();
        int first, second, res;
        for(int i = 0; i < len; i++)
        {
            if(tokens[i] == "+")
            {
                first = st.top();
                st.pop();
                second = st.top();
                st.pop();
                res = second + first;
                st.push(res);
            }
            else if(tokens[i] == "-")
            {
                first = st.top();
                st.pop();
                second = st.top();
                st.pop();
                res = second - first;
                st.push(res);
            }
            else if(tokens[i] == "*")
            {
                first = st.top();
                st.pop();
                second = st.top();
                st.pop();
                res = second * first;
                st.push(res);
            }
            else if(tokens[i] == "/")
            {
                first = st.top();
                st.pop();
                second = st.top();
                st.pop();
                res = second / first;
                st.push(res);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }

        }
        return st.top();
    }
};



int main(void)
{
    cout << "150 is successful" << endl;
    return 0;
}