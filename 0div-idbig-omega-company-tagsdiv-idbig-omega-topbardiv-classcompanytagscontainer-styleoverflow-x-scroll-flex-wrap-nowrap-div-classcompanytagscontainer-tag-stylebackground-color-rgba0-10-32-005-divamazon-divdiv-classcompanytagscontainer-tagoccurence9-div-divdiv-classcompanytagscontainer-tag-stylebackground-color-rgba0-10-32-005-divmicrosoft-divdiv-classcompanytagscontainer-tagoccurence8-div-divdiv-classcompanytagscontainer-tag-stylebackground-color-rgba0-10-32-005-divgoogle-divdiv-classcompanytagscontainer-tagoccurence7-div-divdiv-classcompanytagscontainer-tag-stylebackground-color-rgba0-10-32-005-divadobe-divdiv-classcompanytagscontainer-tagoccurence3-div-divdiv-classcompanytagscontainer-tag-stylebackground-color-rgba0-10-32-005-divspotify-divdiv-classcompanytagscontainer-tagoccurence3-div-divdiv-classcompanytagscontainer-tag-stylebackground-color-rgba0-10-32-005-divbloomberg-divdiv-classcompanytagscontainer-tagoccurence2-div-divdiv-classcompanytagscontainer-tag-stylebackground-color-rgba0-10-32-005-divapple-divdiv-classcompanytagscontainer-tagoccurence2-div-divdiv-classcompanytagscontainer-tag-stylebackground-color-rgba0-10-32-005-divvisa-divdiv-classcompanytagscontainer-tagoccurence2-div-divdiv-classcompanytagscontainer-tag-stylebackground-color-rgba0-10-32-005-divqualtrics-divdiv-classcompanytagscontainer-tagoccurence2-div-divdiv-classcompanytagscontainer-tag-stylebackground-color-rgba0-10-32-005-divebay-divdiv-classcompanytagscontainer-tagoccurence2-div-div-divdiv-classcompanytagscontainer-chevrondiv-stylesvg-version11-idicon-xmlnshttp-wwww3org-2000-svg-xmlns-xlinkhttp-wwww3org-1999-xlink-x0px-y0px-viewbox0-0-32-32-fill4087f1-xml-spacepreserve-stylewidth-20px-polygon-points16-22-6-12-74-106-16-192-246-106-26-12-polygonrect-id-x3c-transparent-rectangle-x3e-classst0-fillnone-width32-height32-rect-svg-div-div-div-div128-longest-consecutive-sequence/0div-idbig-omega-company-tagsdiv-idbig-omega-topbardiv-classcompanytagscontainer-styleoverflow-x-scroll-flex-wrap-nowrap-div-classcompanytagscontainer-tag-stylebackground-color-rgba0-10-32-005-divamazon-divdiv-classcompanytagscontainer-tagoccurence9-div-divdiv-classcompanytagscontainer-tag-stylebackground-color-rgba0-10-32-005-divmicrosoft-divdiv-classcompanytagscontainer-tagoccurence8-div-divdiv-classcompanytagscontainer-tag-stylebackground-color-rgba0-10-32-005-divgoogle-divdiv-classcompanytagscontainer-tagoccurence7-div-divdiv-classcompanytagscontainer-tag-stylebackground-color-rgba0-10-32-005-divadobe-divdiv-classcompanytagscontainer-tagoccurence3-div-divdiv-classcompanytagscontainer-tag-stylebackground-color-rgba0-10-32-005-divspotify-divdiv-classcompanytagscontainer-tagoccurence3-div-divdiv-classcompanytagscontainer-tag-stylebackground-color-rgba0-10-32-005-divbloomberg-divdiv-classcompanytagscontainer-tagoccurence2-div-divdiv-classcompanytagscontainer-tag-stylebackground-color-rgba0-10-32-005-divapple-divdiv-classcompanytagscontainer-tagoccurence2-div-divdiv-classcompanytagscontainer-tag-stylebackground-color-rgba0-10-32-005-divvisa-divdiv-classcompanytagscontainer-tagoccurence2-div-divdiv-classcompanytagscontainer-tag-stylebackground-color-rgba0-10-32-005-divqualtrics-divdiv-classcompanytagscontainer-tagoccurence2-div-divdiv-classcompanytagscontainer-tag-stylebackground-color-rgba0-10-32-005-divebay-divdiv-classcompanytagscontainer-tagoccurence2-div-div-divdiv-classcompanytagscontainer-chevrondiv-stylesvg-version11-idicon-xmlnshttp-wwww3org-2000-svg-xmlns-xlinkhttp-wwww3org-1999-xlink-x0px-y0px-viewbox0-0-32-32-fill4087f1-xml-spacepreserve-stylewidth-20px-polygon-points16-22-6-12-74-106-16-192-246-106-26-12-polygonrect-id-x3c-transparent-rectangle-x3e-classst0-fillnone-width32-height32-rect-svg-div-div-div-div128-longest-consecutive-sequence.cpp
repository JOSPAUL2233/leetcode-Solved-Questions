class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        //push all the elements to a set datastructure
        //so to search an element in nearly O(1) time complexity
        
        unordered_set<int> st;
        
        for(int i : nums)
            st.insert(i);
        
        //now, iterate through set and find the answer
        
        int longest = 0;
        
        for(auto i: st){
            
            if(st.find(i-1) == st.end()){//this operation to search is done in O(1) because of set
                
                int count = 1;
                int ele = i;
                
                while(st.find(ele+1) != st.end()){//if ele+1 is in the set
                    
                    count++;//keep a track of count
                    ele++;//keep incrementing the element
                    
                }
                
                longest = max(longest,count);
                
            }
            
        }
        
        return longest;
        
    }
};