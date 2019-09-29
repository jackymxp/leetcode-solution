#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        int len = nums.size();
        permute(nums, 0, len - 1);
        return res;
    }
private:
    vector<vector<int>> res;
    void permute(vector<int>& nums, int index, int right)
    {
        if(index > right)
        {
            res.push_back(nums);
            return;
        }
        for(int i = index; i <= right; i++)
        {
            swap(nums[i], nums[index]);
            permute(nums, index+1, right);
            swap(nums[i], nums[index]);
        }   
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = s.permute(nums);
    for(auto v : res)
    {
        for(auto i : v)
            cout << i << " " ;
        cout << endl;
    }
}