class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        map<int,int> freq;
        set<int> st;
        
        for(int i : arr)
            freq[i]++;
        
        for(auto p : freq){
            
            if(st.find(p.second) != st.end())
                return false;
            
            st.insert(p.second);
            
        }
        
        return true;
        
    }
};