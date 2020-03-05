#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int left = candies;
        int n = 1;
        int index = 0;
        while(n <= left)
        {
            res[index] +=n;
            left -= n;
            n++;
            index = (index+1) % num_people; 
        }
        res[index] += left;
        return res;
    }
};