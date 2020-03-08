#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0] >= target)
            return 0;
        if(nums[nums.size()-1] < target)
            return nums.size();
        int left = 1; 
        int right = nums.size()-1;
        int mid;
        while(left <= right)
        {
            mid = ((right-left) >> 1) + left;
            if(mid && nums[mid-1] < target && nums[mid] >= target)
                return mid;
            if(nums[mid] >= target)
                right = mid-1;
            else if(nums[mid] < target)
                left = mid+1;
        }
        return mid;
    }
};


int main(void)
{
    Solution s;
    vector<int> arr = {1,3,5,6};
    int target = 2;
    int res = s.searchInsert(arr, target);
    cout << res << endl;
}