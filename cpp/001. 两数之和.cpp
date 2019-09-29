#include <iostream> 
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        map<int, int> mapping;
        for (int i = 0; i < len;i++)
        {
            if(mapping.find(target-nums[i]) != mapping.end())
            {
                return {mapping[target-nums[i]], i};
            }
            mapping[nums[i]] = i;
        } 
        return {};
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = s.twoSum(nums, target);
    for(auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}