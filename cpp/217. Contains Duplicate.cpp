#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mapping;
        for(int& i : nums)
            mapping[i]++;
        for(auto it = mapping.begin(); it != mapping.end(); it++)
            if(it->second > 1)
                return true;
        return false;
    }
};

int main(void)
{
    Solution s;
    vector<int> arr1 = {1,2,3,1};
    cout << "res1 = " << s.containsDuplicate(arr1) << endl;
}