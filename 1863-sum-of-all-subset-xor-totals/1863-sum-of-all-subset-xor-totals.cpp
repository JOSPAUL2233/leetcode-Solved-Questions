class Solution {
public:
    
    void solve(vector<int> &nums,int index,int &sum,int n){
        
        if(index==n){
            
            int x = 0;
            for(int i = 0;i<n;i++){
                x^=nums[i];
            }
            
            sum+=x;
            
            return;
            
        }
        
        solve(nums,index+1,sum,n);
        
        
        int temp = nums[index];
        nums[index] = 0;
        
        solve(nums,index+1,sum,n);
        
        nums[index] = temp;
        
        
    }
    
    int subsetXORSum(vector<int>& nums) {

        int index = 0;
        
        int sum = 0;
        
        int n = nums.size();
        
        solve(nums,index,sum,n);
        
        return sum;
        
    }
};