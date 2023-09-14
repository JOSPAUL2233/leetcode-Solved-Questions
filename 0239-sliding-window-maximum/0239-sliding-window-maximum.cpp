class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> ans;
        
        for(int i = 0;i<nums.size();i++){
            
            //remove the element which comes before the window size
            if(!dq.empty() && dq.front() == i-k)
                dq.pop_front();
            
            //remove all the elements that are smaller than current value
            //fron the back of queue and insert current index into dequeue
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            //start recording ans only after k-1 th iteration
            if(i >= k-1)
                ans.push_back(nums[dq.front()]);
            
        }
        
        return ans;
        
    }
};