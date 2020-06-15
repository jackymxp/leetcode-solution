#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        if(candies.empty())
            return {};
        //寻找最大值
        int max_cnt = candies[0];
        for(auto i : candies){
            max_cnt = max(max_cnt, i);
        }

        vector<bool> res(candies.size(), false);

        for(int i = 0; i < candies.size(); i++){
            res[i] = (candies[i]+extraCandies >= max_cnt);
        }
        return res;
    }
};