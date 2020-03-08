#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    int char2int(char c)
    {
        int t = 0;
        switch(c){
            case 'I': t = 1; break;
            case 'V': t = 5; break;
            case 'X': t = 10; break;
            case 'L': t = 50; break;
            case 'C': t = 100; break;
            case 'D': t = 500; break;
            case 'M': t = 1000; break;
        }
        return t;
    }
public:
    int romanToInt(string s) {
        int len = s.size();
        if(len == 0)
            return 0;
        int res = 0;
        for(int i = 0; i < len; i++)
        {
            char c = s[i];
            char n = ' ';
            if(i+1 < len)
                n = s[i+1];
            int a = char2int(c);
            if(c == 'I' && (n == 'V' || n == 'X'))
                res -= a;
            else if(c == 'X' && (n == 'L' || n == 'C'))
                res -= a;
            else if(c == 'C' && (n == 'D' || n == 'M'))
                res -= a;
            else
                res += a;
        }
        return res;
    }
};