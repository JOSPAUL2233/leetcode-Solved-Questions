class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int reach = arr.size()/4;
        
        for(int i = 0;i<arr.size();i++){
            
            if(arr[i] == arr[i+reach])
                return arr[i];
                                
        }
        
        return -1;
        
    }
};