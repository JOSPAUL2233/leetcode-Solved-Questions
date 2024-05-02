class Solution {
public:
    int findMaxK(vector<int>& nums) {

        vector<int> visited(2001,0);
        int ans = -1;

        for(int i = 0;i<nums.size();i++){

            int curr = nums[i] + 1000;
            int oppo = -nums[i] + 1000;

            if(visited[oppo])
                ans = max(ans,abs(nums[i]));

            visited[curr] = 1;

        }

        return ans;
        
    }
};



