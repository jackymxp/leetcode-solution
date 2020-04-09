#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> B;
        while(K)
        {
            B.push_back(K % 10);
            K /= 10;
        }
        reverse(B.begin(), B.end());
        
        int i = A.size()-1, j = B.size()-1, flag = 0;
        vector<int> res;
        while(i >= 0 || j >= 0)
        {
            int a = i >= 0 ? A[i] : 0;
            int b = j >= 0 ? B[j] : 0;
            int sum = a + b + flag;
            flag = sum / 10;
            res.push_back(sum % 10);
            i--, j--;
        }
        if(flag)
            res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};