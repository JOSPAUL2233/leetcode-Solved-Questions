class Solution {
   
    static int count(int num){
        
        int counter = 0;
        
        while(num != 0){
            
            counter++;
            num = num & (num-1);
            
        }
        
        return counter;
        
    }
    
    //This function tells if a comes before b or not
    static bool sorter(int a,int b){
        
        int ca = count(a);
        int cb = count(b);
        
        if(ca < cb)
            return true;
        else if(ca > cb)
            return false;
        else
            return a < b ? true : false;
        
    }
    
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(),arr.end(),sorter);
        
        return arr;
        
    }
};