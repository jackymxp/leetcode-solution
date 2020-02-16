#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < len; i++){
            for(int j = 0; j < i; j++){
                matrix[i][j] = matrix[i][j] ^ matrix[j][i];
                matrix[j][i] = matrix[i][j] ^ matrix[j][i];
                matrix[i][j] = matrix[i][j] ^ matrix[j][i];
            }
        }
    }
};

int main(void)
{
    
}