class Solution {
public:
    bool isPathCrossing(string path) {
        
        map<pair<int,int>,bool> visited;
        
        int x = 0;
        int y = 0;
        
        visited[{x,y}] = true;
        
        for(char c : path){
            
            switch(c){
                    
                case 'N': y--;
                    break;
                    
                case 'S': y++;
                    break;
                    
                case 'E': x++;
                    break;
                    
                case 'W': x--;
                    break;
                    
            }
            
            if(visited[{x,y}])
                return true;
            
            visited[{x,y}] = true;
            
        }
        
        return false;
        
    }
};