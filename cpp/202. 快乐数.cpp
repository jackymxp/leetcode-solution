class Solution {
public:
    bool isHappy(int n) {
        if(n <= 0)
            return false;
        auto fast = n, slow = n;
        do{
            slow = bitSquareSum(slow);
            fast = bitSquareSum(bitSquareSum(fast));
        }while(fast != slow);
        return slow == 1;
    }

private:
    int bitSquareSum(int n) {
        int sum = 0;
        while(n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
};