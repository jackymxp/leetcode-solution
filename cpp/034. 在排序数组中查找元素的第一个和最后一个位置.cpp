#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        if(nums.empty())
            return res;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int mid = ((right-left) >> 1) + left;
            nums[mid] < target ? left = mid + 1 : right = mid - 1;
        }
        if(left >=0 && left < nums.size() && nums[left] == target)
            res[0] = left;

        left = 0, right = nums.size()-1;
        while(left <= right)
        {
            int mid = ((right-left) >> 1) + left;
            nums[mid] > target ? right = mid - 1 : left = mid + 1;     
        }
        if(right < nums.size() && right >= 0 && nums[right] == target)
            res[1] = right;

        return res;
    }

};
int main(void)
{
    return 0;
}