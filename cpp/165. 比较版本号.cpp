#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1 = str2vecint(version1);
        auto v2 = str2vecint(version2);
        for(auto i : v1)
            cout << i << "  ";
        cout << endl;
        for(auto i : v2)
            cout << i << "  ";
        cout << endl;
        int i = 0, j = 0;
        int len1 = v1.size();
        int len2 = v2.size();
        while(i < len1 || j < len2)
        {
            int a = i < len1 ? v1[i] : 0;
            int b = j < len2 ? v2[j] : 0;
            if(a < b)       return -1;
            else if(a > b)  return 1;
            else{
            }
            i++, j++;
        }
        return 0;
    }
    vector<int> str2vecint(const string& str)
    {
        vector<int> pos;
        pos.push_back(-1);
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == '.')
                pos.push_back(i);
        }
        pos.push_back(str.size());
        vector<int> res;
        for(int i = 1; i < pos.size(); i++)
        {
            string v(str.begin()+1+pos[i-1], str.begin()+pos[i]);
            res.push_back(atoi(v.c_str()));
        }
        return res;
    }
};