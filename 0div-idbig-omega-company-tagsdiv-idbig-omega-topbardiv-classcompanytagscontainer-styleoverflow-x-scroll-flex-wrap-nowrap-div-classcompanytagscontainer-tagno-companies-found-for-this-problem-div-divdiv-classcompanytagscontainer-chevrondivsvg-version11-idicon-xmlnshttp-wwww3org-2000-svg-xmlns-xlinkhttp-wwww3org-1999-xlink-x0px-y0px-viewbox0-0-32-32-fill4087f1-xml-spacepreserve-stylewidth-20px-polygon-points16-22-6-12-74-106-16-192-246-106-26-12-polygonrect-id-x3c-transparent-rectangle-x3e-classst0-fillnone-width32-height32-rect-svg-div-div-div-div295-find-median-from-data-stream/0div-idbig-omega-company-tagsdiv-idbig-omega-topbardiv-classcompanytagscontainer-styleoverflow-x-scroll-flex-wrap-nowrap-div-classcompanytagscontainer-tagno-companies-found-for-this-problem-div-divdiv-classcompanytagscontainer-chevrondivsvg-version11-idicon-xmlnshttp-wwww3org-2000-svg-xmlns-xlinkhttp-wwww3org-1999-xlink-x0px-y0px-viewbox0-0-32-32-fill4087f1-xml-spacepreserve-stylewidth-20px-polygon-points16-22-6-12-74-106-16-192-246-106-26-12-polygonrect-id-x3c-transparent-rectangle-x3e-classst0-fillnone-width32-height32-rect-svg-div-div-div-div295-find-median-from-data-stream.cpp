class MedianFinder {
public:
    
    //make a max-heap for the left part and min-heap for the right part
    priority_queue<int> maxHp;
    priority_queue<int,vector<int>,greater<int>> minHp;
    
    MedianFinder() {
        
        //we can leave this empty or we can make maxHp and minHp emtpy
        //using maxHp = priority_queue<double>();
        
    }
    
    void addNum(int num) {
        
        //step 1 : put the number into the left/right side under conditions
        
        //if any of the heap is empty,put num in any of the side
        if(maxHp.empty() || minHp.empty()){
            
            maxHp.push(num);
            
        }else{
            
            //if two heaps are not empty, then put num by comparing the top values
            //of left and right side
            if(maxHp.top() < num)
                minHp.push(num);
            else
                maxHp.push(num);
            
        }
        
        //step 2 : balance both the sides by checking their size differences
        
        int diff = minHp.size() - maxHp.size();
        
        if(diff == 2){
            
            //minHp is having one extra element,
            //so shift one element to maxHp
            maxHp.push(minHp.top());
            minHp.pop();
            
        }else if(diff == -2){
            
            //maxHp is having one extra element,
            //so shift one element to minHp
            minHp.push(maxHp.top());
            maxHp.pop();
            
        }
        
    }
    
    double findMedian() {
        
        int minSize = minHp.size();
        int maxSize = maxHp.size();
        
        //if the total number of elements are even
        if(minSize == maxSize){
            
            return ((double)minHp.top() + (double)maxHp.top())/ 2.0;//return double value
            
        }else if(minSize > maxSize){
            
            return (double)minHp.top();
            
        }else{
            
            return (double)maxHp.top();
            
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */