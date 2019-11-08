#include <iostream>
#include <set>
#include <vector>

using namespace std; //

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> s1;
        for(int& i : nums1)
            s1.insert(i);
        set<int> s2;
        for(int& i : nums2)
        {
            if(s1.count(i))
                s2.insert(i);
        }
        for(auto it = s2.begin(); it != s2.end(); ++it)
            res.push_back(*it);
        return res;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
    auto res = s.intersection(nums1, nums2);
    for(auto& i : res)
        cout << i << "  ";
    cout << endl;
    return 0;
}