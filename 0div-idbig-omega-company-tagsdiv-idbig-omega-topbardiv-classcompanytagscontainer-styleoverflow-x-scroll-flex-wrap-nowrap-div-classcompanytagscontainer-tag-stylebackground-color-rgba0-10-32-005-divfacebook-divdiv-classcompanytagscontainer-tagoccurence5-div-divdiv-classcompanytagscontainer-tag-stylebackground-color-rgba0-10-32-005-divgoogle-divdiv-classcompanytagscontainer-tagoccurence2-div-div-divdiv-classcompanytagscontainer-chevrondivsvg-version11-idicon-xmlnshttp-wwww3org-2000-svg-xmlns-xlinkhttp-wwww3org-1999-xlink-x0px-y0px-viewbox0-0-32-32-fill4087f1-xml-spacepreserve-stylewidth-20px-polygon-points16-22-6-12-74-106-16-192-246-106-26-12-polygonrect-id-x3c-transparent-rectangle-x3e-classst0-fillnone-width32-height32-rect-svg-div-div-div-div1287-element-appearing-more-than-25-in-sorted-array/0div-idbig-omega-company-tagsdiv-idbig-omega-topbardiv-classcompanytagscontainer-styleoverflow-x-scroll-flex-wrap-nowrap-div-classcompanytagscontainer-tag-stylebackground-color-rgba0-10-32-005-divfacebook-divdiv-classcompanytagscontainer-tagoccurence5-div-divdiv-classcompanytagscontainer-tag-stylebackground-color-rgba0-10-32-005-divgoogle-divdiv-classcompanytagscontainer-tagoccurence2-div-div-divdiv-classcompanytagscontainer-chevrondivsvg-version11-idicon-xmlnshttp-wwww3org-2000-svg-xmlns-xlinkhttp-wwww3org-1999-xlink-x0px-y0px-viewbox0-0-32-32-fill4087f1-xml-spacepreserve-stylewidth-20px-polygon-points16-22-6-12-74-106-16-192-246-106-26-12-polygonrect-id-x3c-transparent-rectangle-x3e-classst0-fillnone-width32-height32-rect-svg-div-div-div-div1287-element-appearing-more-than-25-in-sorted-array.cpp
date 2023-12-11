class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        if(arr.size() == 1)
            return arr[0];
        
        int reach = arr.size()/4;
        
        int count = 1;
        int ele = arr[0];
        
        for(int i = 1;i<arr.size();i++){
            
            if(ele != arr[i]){
                
                ele = arr[i];
                count = 1;
                
            }else{
                
                count++;
                
            }
            
                if(count > reach)
                    return ele;                        
        }
        
        return -1;
        
    }
};