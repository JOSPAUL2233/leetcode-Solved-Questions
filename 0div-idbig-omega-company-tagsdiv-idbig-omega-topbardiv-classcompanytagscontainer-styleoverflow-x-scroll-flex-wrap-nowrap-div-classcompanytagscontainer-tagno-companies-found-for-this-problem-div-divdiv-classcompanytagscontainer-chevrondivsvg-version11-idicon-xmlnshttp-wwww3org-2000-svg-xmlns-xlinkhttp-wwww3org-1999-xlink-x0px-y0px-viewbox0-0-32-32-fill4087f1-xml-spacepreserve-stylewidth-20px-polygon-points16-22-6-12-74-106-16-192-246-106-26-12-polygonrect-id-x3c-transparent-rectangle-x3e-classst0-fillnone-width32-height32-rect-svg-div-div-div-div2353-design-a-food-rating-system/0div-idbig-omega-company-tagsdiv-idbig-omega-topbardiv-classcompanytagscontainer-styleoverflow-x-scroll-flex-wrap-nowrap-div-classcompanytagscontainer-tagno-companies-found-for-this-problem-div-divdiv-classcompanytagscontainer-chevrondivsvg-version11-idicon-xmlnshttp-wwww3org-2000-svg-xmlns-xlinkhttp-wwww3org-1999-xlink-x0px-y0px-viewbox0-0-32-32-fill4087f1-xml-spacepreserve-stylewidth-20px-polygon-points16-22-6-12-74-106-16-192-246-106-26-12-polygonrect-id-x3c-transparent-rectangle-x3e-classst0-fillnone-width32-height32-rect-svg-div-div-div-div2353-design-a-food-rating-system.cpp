class FoodRatings {
public:
    
    unordered_map<string, set<pair<int,string>>> cuisineToRating;
    unordered_map<string,string> foodToCuisine;
    unordered_map<string,int> foodToRating;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        for(int i = 0;i<foods.size();i++){
            
            cuisineToRating[cuisines[i]].insert({-ratings[i],foods[i]});
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            
        }
        
    }
    
    void changeRating(string food, int newRating) {
        
        auto &cuisine = foodToCuisine[food];//gets the correstponding cuisine
        
        int oldRating = foodToRating[food];
        
        cuisineToRating[cuisine].erase({-oldRating,food});
        cuisineToRating[cuisine].insert({-newRating,food});
        
        foodToRating[food] = newRating;
        
    }
    
    string highestRated(string cuisine) {
        
        return (*cuisineToRating[cuisine].begin()).second;
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */