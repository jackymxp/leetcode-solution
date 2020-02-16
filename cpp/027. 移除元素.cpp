#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //[0, k)
        int k = 0;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            if(nums[i] != val)
                nums[k++] = nums[i];
        }
        return k;
    }
};

int main(void)
{
    Solution s;
    vector<int> arr = {0,1,2,2,3,0,4,2};
    int val = 2;
    int res = s.removeElement(arr, val);
    for(int i = 0; i < res; ++i)
        cout << arr[i] << "  " ;
    cout << endl;
    return 0;
}