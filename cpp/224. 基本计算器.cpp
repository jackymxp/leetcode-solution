#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        //将字符串转换成一个vector<string>
        vector<string> tmp1 = string2vectorstr(s);

        //中缀转后缀
        vector<string> tmp2 = mid2last(tmp1);
       
        int res = evalRPN(tmp2);
        return res;
    }
private:
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

    vector<string> mid2last(const vector<string>& s)
    {
        vector<string> res;
        stack<string> st;
        for(auto& i : s)
        {
            if(i.size() == 1 && i[0] == '(')
                st.push(i);
            else if(i.size() == 1 && i[0] == ')')
            {
                while(!st.empty() && ((st.top())[0]) != '(') 
                {
                    res.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else if(i.size() == 1 && is_operator(i[0]))
            {

                while(!st.empty() && st.top()[0] != '(' && operator2int((st.top())[0]) >= operator2int(i[0]))
                {
                    res.push_back(st.top());
                    st.pop();
                }
                st.push(i);
            }
            else
            {
                res.push_back(i);
            }
            
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }

    bool is_digit(char c){return c >= '0' && c <= '9';}
    bool is_space(char c){return c == ' ';}
    bool is_operator(char c) {return c == '+' || c == '-' || c == '*' || c == '/' || c == 'x' || c == 'X';}
    int operator2int(char c) {
        if(c == '+' || c == '-')
            return 1;
        else if(c == '*' || c == '/')
            return 2;
        else
            return -1;
    }
    vector<string> string2vectorstr(const string& s)
    {
        vector<string> res;
        int i = 0;
        int len = s.size();
        while(i < len)
        {     
            if(is_digit(s[i]))
            {
                long long tmp = 0;
                while(true)
                {
                    if(is_digit(s[i]))
                    {
                        tmp = tmp * 10 + s[i] - '0';
                    }
                        
                    else if(is_space(s[i]))
                    {
                    }
                    else if(i == len || is_operator(s[i]) || s[i] == '(' || s[i] == ')')
                    {
                        res.push_back(to_string(tmp));
                        break;
                    }
                    else
                    {
                        //cout << "fuck this char" << endl;
                    }
                    i++;
                }
            }
            else if(is_space(s[i]))
            {
                i++;
            }
            else if(is_operator(s[i]) || s[i] == '(' || s[i] == ')')
            {
                res.push_back(string{s[i]});
                i++;
            }
            else
            {
                cout << "i = " << i << "  str = " << s[i] << endl;
            }
        }
        return res;
    }
};



int main(void)
{
    cout << "224 is successful" << endl;
    return 0;
}