#include "include.h"

class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        // f[i] is the maximum sum of the subarray that ends at nums[i]
        int f = nums[0];
        // The solution is max(f[i]) where i = 0 to n-1
        int fMax = f;
        for (int i = 1; i < nums.size(); ++i) {
            // f[i] = f[i-1] < 0 ? nums[i] : f[i-1] + nums[i].
            f = f < 0 ? nums[i] : f + nums[i];
            fMax = max(fMax, f);
        }

        return fMax;
    }
};
