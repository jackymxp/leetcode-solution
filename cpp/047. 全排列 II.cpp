#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        permuteUnique(nums, 0, nums.size() - 1);
        
        return res;
    }
    void permuteUnique(vector<int> nums, int left, int right)
    {
        if(left == right)
        {
            res.push_back(nums);
            return ;
        }
        for(int i = left; i <= right; i++)
        {
            if(i != left && nums[i] == nums[left]) continue;
            swap(nums[left], nums[i]);
            permuteUnique(nums, left+1, right);
            //swap(nums[left], nums[i]);
        }
    }
};

int main(void)
{
    Solution s;
    vector<int> arr = {1,2,3,4,5,6,7, 8, 9};
    auto res = s.permuteUnique(arr);
    for(auto i : res)
    {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
}