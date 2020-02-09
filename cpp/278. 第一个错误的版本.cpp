#include <iostream>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1) == true)
            return 1;
        int left = 2;
        int right = n;
        while(left <= right)
        {
            int mid = ((right - left) >> 1 ) + left;
            cout << "mid = " << mid << "is" << isBadVersion(mid) << endl;
            if(isBadVersion(mid) == true)
            {
                if(isBadVersion(mid-1) == false)
                    return mid;
                else
                    right = mid-1;
            }
            else 
            {
                left = mid + 1 ;
            }
            
        }
        return -1;
    }
};

int main(void)
{
    cout << "278 is successful " << endl;
    return 0;
}