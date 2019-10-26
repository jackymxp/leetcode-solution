#include <iostream>
#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> data;
    vector<int> tree;
    void buildSegment(int index, int left, int right)
    {
        if(left == right)
        {
            tree[index] = data[left];
            return ;
        }
        int mid = ((right - left) >> 1) + left;
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        buildSegment(leftIndex, left, mid);
        buildSegment(rightIndex, mid+1, right);
        tree[index] = tree[leftIndex] + tree[rightIndex];
    }
    int query(int index, int left, int right, int i, int j)
    {
        if(left == i && right == j)
        {
            return tree[index];
        }
        int mid = ((right - left) >> 1) + left;
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        if(i >= mid+1)
            return query(rightIndex, mid+1, right, i, j);
        else if(j <= mid)
            return query(leftIndex, left, mid, i, j);
        int leftRes = query(leftIndex, left, mid, i, mid);
        int rightRes = query(rightIndex, mid+1, right, mid+1, j);
        return leftRes + rightRes;
    }
    void update(int treeIndex, int left, int right, int index, int val)
    {
        if(left == right)
        {
            tree[treeIndex] = val;
            return ;
        }
        int mid = ((right - left) >> 1) + left;
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        if(index <= mid)
            update(leftIndex, left, mid, index, val);
        else if(index >= mid + 1)
            update(rightIndex, mid+1, right, index, val);
        tree[treeIndex] = tree[leftIndex] + tree[rightIndex];
    }
public:
    NumArray(vector<int>& nums) {
        if(nums.size() == 0)
        {
            data = nums;
        }
        else
        {
            data = nums;
            tree = vector<int>(nums.size() * 4);
            buildSegment(0, 0, data.size() - 1);
        }
    }
    
    void update(int i, int val) {
        update(0, 0, data.size() - 1, i, val);
    }
    
    int sumRange(int i, int j) {
        if(data.size() == 0)
            return 0;
        return query(0, 0, data.size() - 1, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

int main(void)
{
    vector<int> arr = {-2, 0, 3, -5, 2, -1};
    NumArray s(arr);
    cout << s.sumRange(0, 3) << endl;
    cout << s.sumRange(2, 5) << endl;
    s.update(0, 4);
    cout << s.sumRange(0, 3) << endl;
    return 0;
}