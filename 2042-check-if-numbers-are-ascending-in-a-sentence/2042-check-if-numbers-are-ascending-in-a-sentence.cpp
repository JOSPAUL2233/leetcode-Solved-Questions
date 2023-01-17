class Solution {
public:
    bool areNumbersAscending(string s) {
        
        vector<int> nums;
        
        for(int i = 0;i<s.size();i++){ 
            
            if(isdigit(s[i])){
                
                int temp = 0;
            
            int j = i;

        
            while(isdigit(s[j])){
                
                
                temp = temp*10 + (s[j]-'0');

                j++;
                
                
            }
            
            nums.push_back(temp);
            i = j;
                
            }
            
        }
        
        for(int i = 0;i<nums.size()-1;i++){
                
                cout<<"nums[i]: "<<nums[i]<<endl<<"nums[i+1]: "<<nums[i+1]<<endl;
                if(nums[i]>=nums[i+1])return false;
            
        }
        return true;
        
        
    }
};