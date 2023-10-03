class Twitter {
public:
    
    //keep a track of friends of a userId
    map<int,set<int>> friends;
    
    //keep track of current time
    int curr = 0;
    
    //keeps track of different timeline of different tweets
    //it sorts according to the time --> vector {time,tweetId,userId}
    priority_queue<vector<int>> timeline;
    
    Twitter() {
        
        //keep it all empty
        friends.clear();
        curr = 0;
        timeline = priority_queue<vector<int>>();
        
    }
    
    void postTweet(int userId, int tweetId) {
        
        //push the current tweet into timeline along with the
        //current time, tweet id and user id
        timeline.push({curr++, tweetId, userId});
        
    }
    
    void follow(int followerId, int followeeId) {
        
        //make changes in friends of followerId
        friends[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        
        //nake changes in friends of followerId
        friends[followerId].erase(followeeId);
        
    }    
    vector<int> getNewsFeed(int userId) {
        
        //THIS PART NEEDS TO BE UNDERSTOOP PROPERLY----
        
        vector<int> ans;
        
        //make a copy of timeline
        priority_queue<vector<int>> userTimeline = timeline;
        
        //get 10 most recent tweet IDs in the user's news feed
        int count = 0;
        
        while(!userTimeline.empty() && count<10){
            
            //takeout the top of userTimeline and pop it out
            vector<int> topTweet = userTimeline.top();
            userTimeline.pop();
            
            //check if the topTweet is done by user itself or users friend
            if(topTweet[2] == userId || friends[userId].count(topTweet[2])){
                
                //store the tweetId and update count
                ans.push_back(topTweet[1]);
                count++;
                
            }
            
        }
        
        return ans;
        
    }
    
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */