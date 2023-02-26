class Solution {
public:
    int minSteps(string s, string t) {
        
        vector<int> arr(26,0);
        int counter = 0;
        
        for(int i = 0;i<s.size();i++){
            
            arr[ s[i]-'a']++;
            arr[ t[i]-'a']--;
            
        }
        
        for(int i = 0;i<26;i++){
            if(arr[i] > 0)counter+=arr[i];
        }
        
        return counter;
        
    }
};