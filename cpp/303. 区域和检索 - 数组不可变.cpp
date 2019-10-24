#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        if(nums.size() == 0)
            data = vector<int>(0);
        else
        {
            data = nums;
            tree = vector<int>(nums.size() * 4 + 1, 0);
            buildSegment(0, 0, nums.size() - 1);
        }
    }
    
    int sumRange(int i, int j) {
        if(data.size() == 0)
            return 0;
        assert(i >= 0 && i < data.size());
        assert(j >= 0 && j < data.size());
        assert(i <= j);
        return sumRange(0, 0, data.size() - 1, i, j);
    }
private:
    int sumRange(unsigned long index, unsigned long left, unsigned long right, unsigned long i, unsigned long j)
    {
        //cout << "index = " << index << "left = " << left << "right = " << right << "i = " << i << "j = " << j << endl;
        if(i == left && j == right)
            return tree[index];
        
        unsigned long mid = ((right - left) >> 1) + left;
        unsigned long leftChild = 2 * index + 1;
        unsigned long rightChild = 2 * index + 2;
        if(j <= mid)
            return sumRange(leftChild, left, mid, i, j);
        else if(i >= mid + 1)
            return sumRange(rightChild, mid+1, right, i, j);

        int leftRes = sumRange(leftChild, left, mid, i, mid);
        int rightRes = sumRange(rightChild, mid+1, right, mid+1, j);
        return leftRes + rightRes;
    }
    void buildSegment(unsigned long index, unsigned long left, unsigned long right)
    {
        if(left == right)
        {
            tree[index] = data[left];
            return ;
        }
        unsigned long mid = ((right - left) >> 1) + left;
        unsigned long leftChild = 2 * index + 1;
        unsigned long rightChild = 2 * index + 2;
        buildSegment(leftChild, left, mid);
        buildSegment(rightChild, mid+1, right);
        tree[index] = tree[leftChild] + tree[rightChild];
    }
    vector<int> data;
    vector<int> tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */



int main(void)
{
    //vector<int> arr = {-2, 0, 3, -5, 2, -1};
    vector<int> arr = {};
    NumArray s(arr);
    cout << s.sumRange(0, 0) << endl;
    vector<int> aaa(0);

}