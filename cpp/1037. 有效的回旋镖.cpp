#include <vector>
using namespace std;

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        vector<int> x = points[0];
        vector<int> y = points[1];
        vector<int> z = points[2];
/*
        x[1] - y[1]      x[1] - z[1]
        (x[0] - y[0])     x[0] - z[0]
*/
        return ((x[1] - y[1]) * (x[0] - z[0])) != ((x[0] - y[0]) * (x[1] - z[1]));
    }
};