class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    
        
        // ----- EASY APROACH-----
//         sort(nums.begin(),nums.end());
        
//         return nums[nums.size()-k];
        
        //PRIORITY QUEUE APROACH-----
        
        priority_queue <int> que;
        
        for(int i = 0;i<nums.size();i++){
            
            que.push(nums[i]);
            
        }
        
        for(int i = 0;i<k-1;i++){ // pop out k-1 elements
            
            que.pop();
            
        }
        
        return que.top();
    }
};