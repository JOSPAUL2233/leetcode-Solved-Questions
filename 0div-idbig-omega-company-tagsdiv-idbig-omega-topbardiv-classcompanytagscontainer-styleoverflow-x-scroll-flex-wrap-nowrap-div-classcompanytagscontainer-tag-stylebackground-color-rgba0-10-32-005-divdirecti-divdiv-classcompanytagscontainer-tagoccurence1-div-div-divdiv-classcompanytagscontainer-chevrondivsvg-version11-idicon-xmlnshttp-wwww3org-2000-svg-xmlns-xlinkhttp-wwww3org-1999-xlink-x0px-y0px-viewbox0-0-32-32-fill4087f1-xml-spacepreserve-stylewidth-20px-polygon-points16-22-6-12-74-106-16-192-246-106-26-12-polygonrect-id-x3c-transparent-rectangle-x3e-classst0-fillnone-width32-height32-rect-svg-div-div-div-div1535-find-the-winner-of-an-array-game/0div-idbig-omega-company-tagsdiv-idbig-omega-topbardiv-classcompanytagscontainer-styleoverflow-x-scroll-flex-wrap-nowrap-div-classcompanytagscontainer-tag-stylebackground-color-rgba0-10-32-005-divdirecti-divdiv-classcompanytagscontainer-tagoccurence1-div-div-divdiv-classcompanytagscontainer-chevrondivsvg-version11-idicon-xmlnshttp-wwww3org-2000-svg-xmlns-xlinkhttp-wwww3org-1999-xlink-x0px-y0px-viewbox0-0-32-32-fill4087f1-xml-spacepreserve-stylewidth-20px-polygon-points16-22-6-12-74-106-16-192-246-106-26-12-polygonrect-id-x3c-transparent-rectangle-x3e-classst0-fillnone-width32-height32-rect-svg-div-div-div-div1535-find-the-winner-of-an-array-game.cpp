class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        int count = 0;
        int winner = arr[0];
        
        for(int i = 1;i<arr.size();i++){
            
            if(arr[i] <= winner){
                
                count++;
                
            }else{
                
                winner = arr[i];
                count = 1;
                
            }
            
            if(count == k)
                return winner;
            
        }
        
        //if we didn't get any winner winning k consecutive times,
        //return the greater value that winner stores.
        return winner;
        
    }
};