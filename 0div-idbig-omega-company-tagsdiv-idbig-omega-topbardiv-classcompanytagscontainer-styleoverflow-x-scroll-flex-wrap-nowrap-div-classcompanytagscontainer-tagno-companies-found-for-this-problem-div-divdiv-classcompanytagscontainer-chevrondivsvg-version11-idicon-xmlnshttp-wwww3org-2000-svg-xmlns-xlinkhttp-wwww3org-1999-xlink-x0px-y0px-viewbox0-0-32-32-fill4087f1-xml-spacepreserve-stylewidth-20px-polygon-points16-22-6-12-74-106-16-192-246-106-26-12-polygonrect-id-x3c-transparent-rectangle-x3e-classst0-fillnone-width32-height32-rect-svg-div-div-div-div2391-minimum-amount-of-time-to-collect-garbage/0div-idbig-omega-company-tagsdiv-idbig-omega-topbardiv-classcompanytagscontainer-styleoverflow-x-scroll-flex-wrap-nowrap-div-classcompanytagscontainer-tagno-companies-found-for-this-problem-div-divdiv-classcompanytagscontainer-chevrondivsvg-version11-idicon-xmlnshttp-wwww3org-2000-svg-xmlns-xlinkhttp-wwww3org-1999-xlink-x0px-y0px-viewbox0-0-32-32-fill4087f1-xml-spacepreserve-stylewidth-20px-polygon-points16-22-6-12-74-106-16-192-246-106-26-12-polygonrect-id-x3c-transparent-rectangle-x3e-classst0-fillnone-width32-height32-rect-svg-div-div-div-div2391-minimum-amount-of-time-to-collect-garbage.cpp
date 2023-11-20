class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int glass,paper,metal,glassEnd,paperEnd,metalEnd;
        glass = paper = metal = glassEnd = paperEnd = metalEnd = 0;
        
        
        //FINDING THE LAST INDEX TILL WHERE ONE TRUCK HAVE TO MOVE
        
        for(int i = garbage.size()-1;i>=0;i--){
            
            string s = garbage[i];
            
            for(int j = 0;j<s.size();j++){
                
                if(s[j]=='G' && glassEnd==0)glassEnd = i;
                
                if(s[j]=='P' && paperEnd==0)paperEnd = i;
                
                if(s[j]=='M' && metalEnd==0)metalEnd = i;
                
            }
            
        }
        
        //TRAVEL TIME TAKEN FOR ALL THE TRUCKS
        
        //glass
        for(int i = 0;i<glassEnd;i++){
            glass+=travel[i];
        }
        
        //paper
        for(int i = 0;i<paperEnd;i++){
            paper+=travel[i];
        }
        
        //metal
        for(int i = 0;i<metalEnd;i++){
            metal+=travel[i];
        }
        
        //COLLECT THE GARBAGES
        
        //glass
        
        for(int i = 0;i<=glassEnd;i++){
            
            string s = garbage[i];
            for(int j = 0;j<s.size();j++){
                
                if(s[j]=='G')glass++;
                
            }
            
        }
        
        //paper
         for(int i = 0;i<=paperEnd;i++){
            
            string s = garbage[i];
            for(int j = 0;j<s.size();j++){
                
                if(s[j]=='P')paper++;
                
            }
            
        }
        
        //metal
         for(int i = 0;i<=metalEnd;i++){
            
            string s = garbage[i];
            for(int j = 0;j<s.size();j++){
                
                if(s[j]=='M')metal++;
                
            }
            
        }
        
        return(paper+glass+metal);
    }
};