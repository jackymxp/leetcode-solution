#include <iostream> 
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int l = 0, r = len - 1;
        int res = 0;
        while(l < r){
            int area = (r-l) * min(height[l], height[r]);
            if(height[l] < height[r])
                l++;
            else 
                r--; 
            res = max(res, area);
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> v1 = {1,8,6,2,5,4,8,3,7};
    cout << "v1====" << s.maxArea(v1) << endl;
    return 0;
}