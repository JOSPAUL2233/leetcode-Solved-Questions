class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        //calculate the time taken by the moster to reach city
        //and store it in a vector
        
        vector<double> time(dist.size(),0);
        
        for(int i = 0;i<dist.size();i++){
            
            time[i] = (double)dist[i] / speed[i];

        }
        
        //sort the time in acending order, the nearest monster will be in front
        sort(time.begin(),time.end());
        
        int clock = 0;//keeping a track of current time(clock time)
        int count = 0;//keeping a track of monsters killed

        for(int i = 0;i<time.size();i++){
            
            //if the monster comes at the same time or before it
            if(time[i] <= clock){
                
                break;//we lost the game
                
            }
            
            count++;//kills one monster
            clock++;//increase the clock
            
        }
        
        return count;
        
    }
};