//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        
        int minMoney = 0;
        int maxMoney = 0;
        
        sort(candies,candies+N);
        
        //find the minMoney spend to buy all the candies
        int buy = 0;
        int offer = N;
        
        while(buy < offer){
            
            minMoney +=  candies[buy];
            
            //update buy and offer pointer
            buy++;
            offer -= K;
            
        }
        
        //find the maxMoney spend to buy all the candies
        buy = N-1;
        offer = -1;
        
        while(offer < buy){
            
            maxMoney += candies[buy];
            
            //update buy and offer
            buy--;
            offer += K;
            
        }
        
        return {minMoney,maxMoney};
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends