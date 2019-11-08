#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    static bool cmp(pair<string, int>& a, pair<string, int>& b)
    {
        if(a.second == b.second)
            return a.first < b.first;
        else
            return a.second > b.second;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mapping;
        for(string& word : words)
            mapping[word]++;
        vector<pair<string, int>> vmap(mapping.begin(), mapping.end());
        
        sort(vmap.begin(), vmap.end(), cmp);
        
        for(auto i : vmap)
            cout << "i->first = " << i.first << "  i->second = " << i.second << endl;

        vector<string> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(vmap[i].first);
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    vector<string> arr = {"i", "love", "leetcode", "i", "love", "coding"};
    auto  res = s.topKFrequent(arr, 2);
    for(string ss : res)
        cout << ss << endl;
}