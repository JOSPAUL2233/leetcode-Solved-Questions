class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        
        if(pref.size() == 0)
            return {};
        
        vector<int> arr(pref.size(),0);
        arr[0] = pref[0];
        
        for(int i = 1;i<pref.size();i++){
            
            arr[i] = pref[i]^pref[i-1];
            
        }
        
        return arr;
        
    }
};