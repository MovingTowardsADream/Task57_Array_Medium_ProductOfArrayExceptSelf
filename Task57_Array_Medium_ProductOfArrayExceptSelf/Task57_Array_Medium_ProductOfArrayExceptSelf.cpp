#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> result(nums.size());
        result[0] = 1;
        for (int i = 1;i < nums.size();i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        int tmp = 1;
        for (int i = nums.size() - 2;i >= 0;i--) {
            tmp *= nums[i + 1];
            result[i] = result[i] * tmp;
        }
        return result;
    }
};

int main()
{
    std::vector<int> nums = { 1,2,3,4 };
    for (int& i : Solution::productExceptSelf(nums)) {
        std::cout << i << " ";
    }
}
