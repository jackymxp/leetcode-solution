#include <iostream>
#include <vector>
#include <numeric> //accumulate

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int len = A.size();
        int sum = accumulate(A.begin(), A.end(), 0);
        if(sum % 3 != 0)
            return false;
        int target = sum / 3;

        //[0, left), [left, right), [right, len)
        int left = 1, right = len-1;
        int leftSum{A[0]}, rightSum(A[right]);
        while(left < right)
        {
            //int leftSum =  accumulate(A.begin(), A.begin()+left, 0);
            //int rightSum = accumulate(A.begin()+right, A.end(), 0);
            if(leftSum ==  target &&
               rightSum == target)
               return true;
            if(leftSum != target)
                leftSum += A[left++];
                
            if(rightSum != target)
                rightSum += A[--right];
        }

        return false;
    }
};

int main(void)
{
    vector<int> arr = {0,2,1,-6,6,-7,9,1,2,0,1};
    Solution s;
    auto res = s.canThreePartsEqualSum(arr);
    cout << res << endl;
}