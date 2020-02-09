class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size()-1, nums.size() -  k);
    }
    int findKthLargest(vector<int>& nums, int left, int right, int k)
    {
        int idx = partition(nums, left, right);
        if(idx == k)
            return nums[k];
        else if(idx > k)
            return findKthLargest(nums, left, idx-1, k);
        else
            return findKthLargest(nums, idx+1, right, k);
    }
    /*
    |---|--------|-----|---------------|----|--------|
    | v |   <v   | >=v |               | <v |   >=v  |
    |---|--------|-----|---------------|----|--------|
                    i                     j
    //[left+1, i) < v     nums[i] == v
    //(j, right]  >= v    nums[j] < v
    // 
    */
    int partition(vector<int>& nums, int left, int right)
    {
        swap(nums[left], nums[rand() % (right - left + 1) + left]);
        int v = nums[left];
        int i = left + 1;
        int j = right;
        while(1)
        {
            while(i <= right && nums[i] < v)
                i++;
            while(j >= left + 1 && nums[j] >= v) //这里有等号
                j--;
            if(i > j)
                break;
            swap(nums[i], nums[j]);
        }
        swap(nums[left], nums[j]);
        return j;
    }
};