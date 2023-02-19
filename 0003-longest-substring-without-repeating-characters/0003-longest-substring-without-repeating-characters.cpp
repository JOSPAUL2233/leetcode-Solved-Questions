class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxCount = 0;
        
        if(s.size()==1)return 1;
        
        for(int i = 0;i<s.size();i++){
            
            int count = 1;
            set<int> st;
            st.insert(s[i]);
            
            for(int j = i+1;j<s.size();j++){
                
                if(st.count(s[j])){
                    maxCount = max(count,maxCount);
                    count = 0;
                    break;
                }
                
                st.insert(s[j]);
                count++;
                
            }
            maxCount = max(count,maxCount);
            
        }
        
        return maxCount;
        
    }
};