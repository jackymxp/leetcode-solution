#include <iostream>
#include <vector>

using namespace std;

//使用投影法，分别在x y轴上进行投影。
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool x_overlap = !(rec1[2] <= rec2[0] || rec1[0] >= rec2[2]);
        bool y_overlap = !(rec1[1] >= rec2[3] || rec1[3] <= rec2[1]);
        return x_overlap && y_overlap;
    }
};