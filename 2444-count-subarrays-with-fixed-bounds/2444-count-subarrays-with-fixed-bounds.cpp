class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long res = 0;
        
        int b = -1, li = -1, ri = -1;

        for (int i = 0; i < nums.size(); ++i) {
            
            if (!(minK <= nums[i] && nums[i] <= maxK)) {
                b = i;
            }

            if (nums[i] == minK) {
                li = i;
            }

            if (nums[i] == maxK) {
                ri = i;
            }
            
            res += max(0, min(li, ri) - b);
        }

        return res;
    }
};