class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        //sol

        int ans = 0;

        for(int i = 0;i<32;i++){

            int countone = 0;

            for(int j = 0;j<nums.size();j++){

                if((1<<i)&nums[j]){
                        countone++;
                }

            }

            if(countone%3){

                ans = ans|(1<<i);

            }

        }

        return ans;
        
    }
};