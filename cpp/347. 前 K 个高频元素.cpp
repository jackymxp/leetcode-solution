#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Solution {
private:
    struct cmp
    {
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            return a.second > b.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //统计频次
        map<int, int> mapping;
        for(auto i : nums)
            mapping[i]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        

        for(auto i : mapping)
        {
            pq.push(i);
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> res;
        while(!pq.empty())
        {
            pair<int, int> p = pq.top();
            cout << "first = " << p.first << "second = " << p.second << endl; 
            res.push_back(p.first);
            pq.pop();
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    vector<int> arr = {1,1,1,2,2,3};
    int k = 2;
    auto res = s.topKFrequent(arr, k);
    for(auto i : res)
        cout << i << "  ";
    cout << endl;

    return 0;
}