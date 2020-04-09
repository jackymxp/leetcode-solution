func thirdMax(nums []int) int {
    max1, max2, max3 := (-1) << 63, (-1) << 63, (-1) << 63

    for i := 0; i < len(nums); i++{
        c := nums[i]
        if c > max1 {
            max3 = max2
            max2 = max1
            max1 = c
        }
        if c > max2 && c < max1{
            max3 = max2
            max2 = c
        }
        if c > max3 && c < max2{
            max3 = c
        }
    }
    if max3 != (-1) << 63{
        return max3
    }
    return max1
}