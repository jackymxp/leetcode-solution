#include <iostream> 

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
#if 1
        if(x < 0)
            return -1;
        if(x == 0)
            return 0;
        
        int left = 1;
        int right = x;
        while(left <= right)
        {
            int mid = (right-left)/2+left;
            if(mid <= x / mid && (mid+1) > x / (mid+1))
                return mid;
            if(mid > x / mid)
                right = mid-1;
            if(mid < x / mid)
                left = mid+1;
        }
        return -1;
#else
        if(x < 0)
            return -1;
        if(x == 0)
            return 0;    
        for(int i = 1; i <= x; i++)
        {
            if(i <= x/i && (i+1) > x/(i+1))
                return i;            
        }
        return -1;
#endif
    }
};

int main(void)
{
    Solution s;
    
    for(int i = 1; i < 100; i++)
    {
        int t = s.mySqrt(i);
        if(!(t * t <= i && (t+1)*(t+1)>i))
            cout << "error " << endl;
    }
    cout << "accepted" << endl;

}