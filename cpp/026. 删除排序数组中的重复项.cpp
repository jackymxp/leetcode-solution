#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int tmp = 0;
        //[0, tmp] 不重复区间
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != nums[tmp])
            {
                nums[++tmp] = nums[i];
            }
        }
        return tmp+1;
    }
};

int main(void)
{
    Solution s;
    vector<int> arr = {0,0,1,1,1,2,2,3,3,4};
    int res = s.removeDuplicates(arr);
    for(int i = 0; i < res; i++)
        cout << arr[i] << "  " << endl;
}