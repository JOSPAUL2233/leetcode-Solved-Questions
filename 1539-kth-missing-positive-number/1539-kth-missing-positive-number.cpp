class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int i = 1;
        int index = 0;
        
        while(k>0 && index<arr.size()){
            
            if(i != arr[index]){
                
                k--;
                                
            }else{
                index++;
            }
            
            i++;
        }
        
        if(k>0)return arr[arr.size()-1]+k;
        
        return i-1;
        

    }

};