#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> list;
        combinationSum(candidates, 0, target, list);
        return res;
    }
private:
vector<vector<int>> res;
    void combinationSum(vector<int>& candidates, int index, int target, vector<int>& list)
    {
        if(target < 0)
            return;
        if(target == 0)
        {
            res.push_back(list);
            return;
        }
        for(int i = index; i < candidates.size(); i++)
        {
            list.push_back(candidates[i]);
            combinationSum(candidates, i, target - candidates[i], list);
            list.pop_back();
        }
    }
};

int main(void)
{
    Solution s;
    vector<int> candidates = {2,3,5};
    int target = 8;
    auto res = s.combinationSum(candidates, target);
    for(auto i : res)
    {
        for(auto j : i)
            cout << j << "  ";
        cout << endl;
    }

}