#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.empty() || str2.empty())
            return "";
        if(str1+str2 != str2+str1)
            return "";
        
        
        string tmp = str1.substr(0, gcd(str1.size(), str2.size()));
        if(isgcd(str1, tmp) && isgcd(str2, tmp))
            return tmp;
        return "";
        
    }
private:
    int gcd(int a, int b)
    {
        //return __gcd(a, b);
        if(a == 0 || b == 0)
            return a ? a : b;
        if(a == b)
            return a;
        else if(a < b)
            return gcd(b, a);
        else if(a > b)
        {
            if((a&0x1) && (b&0x1))
                return gcd(b, a-b);
            else if(!(a&0x1) && (b&0x1))
                return gcd(a>>1, b);
            else if((a&0x1) && !(b&0x1))
                return gcd(a, b>>1);
            else if(!(a&0x1) && !(b&0x1))
                return gcd(a>>1, b>>1) << 1;
        }
    }
    bool isgcd(const string& S, const string& T)
    {
        if(S.empty() || T.empty())
            return false;
        string tmp = T;
        int len = S.size();
        while(tmp.size() <= len)
        {
            if(tmp.size() < len)
                tmp += T;
            else if(tmp.size() == len)
                return tmp == S;
            else if(tmp.size() > len)
                return false;
        }
        assert(1 == 2);
        return false;
    }
};


int main(void)
{
    Solution s;
    string str1 = "ABCABC", str2 = "ABC";

    string res = s.gcdOfStrings(str1, str2);
    cout << "res = " << res << endl;
}