class KthLargest {
public:
    
    int limit;
    //using min heap
    priority_queue<int,vector<int>,greater<int>> pq;
    
    
    KthLargest(int k, vector<int>& nums) {
        
        limit = k;
        
        for(int i = 0;i<nums.size();i++){
            
            pq.push(nums[i]);
            
            if(pq.size() > limit){
                
                pq.pop();
                
            }
            
        }
        
    }
    
    int add(int val) {
        
        //push the val to queue
        pq.push(val);
        
        //if the queue  is overflowed, remove one to keep the size as k
        if(pq.size() > limit)
            pq.pop();
        
        //return the kth largest value
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */