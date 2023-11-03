class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        int ind = 0;
        vector<string> vec;
        
        for(int i = 1;i<=n && ind < target.size();i++){
            
            if(target[ind] == i){
                
                vec.push_back("Push");
                ind++;
                
            }else{
                
                vec.push_back("Push");
                vec.push_back("Pop");
            }
            
            
        }
        
        return vec;
        
    }
};