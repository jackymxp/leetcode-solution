#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mapping;
        for(auto i : arr1)
            mapping[i]++;
        vector<int> res;
        for(auto i : arr2)
        {
            for(int j = 0; j < mapping[i]; j++)
                res.push_back(i);
            mapping[i] = 0;
        }
        
        for(auto i : mapping)
        {
            while(i.second--){
                res.push_back(i.first);
            }
        }
        return res;
    }
};

int main(void)
{
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19}, arr2 = {2,1,4,3,9,6};
    Solution s;
    auto res = s.relativeSortArray(arr1, arr2);
    for(auto i : res)
        cout << i << "  " ;
    cout << endl; 
    return 0;
}