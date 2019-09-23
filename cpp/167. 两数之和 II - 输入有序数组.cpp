#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        assert(len >= 2);
            
        int l = 0, r = len - 1;
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                vector<int> ret = {l+1, r+1};
                return ret;
            }
            else if(numbers[l] + numbers[r] > target)
                r--;
            else if(numbers[l] + numbers[r] < target)
                l++;
        }
        throw invalid_argument("the input has no solution.");
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {2,7, 11, 15};
    int target = 9;
    vector<int> res = s.twoSum(arr1, target);
    for(auto i : res)
        cout << i << " ";
    return 0;
}