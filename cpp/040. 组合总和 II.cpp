#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> list;
        sort(candidates.begin(), candidates.end());
        combinationSum2(candidates, 0, target, list);
        //return vector<vector<int>>(res.begin(), res.end());
        return tmp;
    }
    set<vector<int>> res;
    vector<vector<int>> tmp;
    void combinationSum2(vector<int>& candidates, int index, int target, vector<int>& list)
    {
        if(target < 0)
            return ;
        if(target == 0)
        {
            //res.insert(list);
            tmp.push_back(list);
            return ;
        }
        for(int i = index; i < candidates.size(); i++)
        {
            if(candidates[i] > target)
                return ;
            if(i != index && candidates[i] == candidates[i-1])
                continue;
            list.push_back(candidates[i]);
            combinationSum2(candidates, i+1, target - candidates[i], list);
            list.pop_back();
        }
    } 
};


int main(void)
{
    Solution s;
    vector<int> candidates = {2,5,2,1,2};
    int target = 8;
    auto res = s.combinationSum2(candidates, target);
    for(auto i : res)
    {
        for(auto j : i)
            cout << j << "  ";
        cout << endl;
    }
}