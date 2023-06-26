//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int start = 0;
       int balance = 0;
       int deficit = 0;//we keep this to avoid visiting element twise
       
       //traverse through all the petrol pumps
       for(int i = 0;i<n;i++){
           
           balance += (p[i].petrol -  p[i].distance);
           
           if(balance < 0){
               
               //store the petrol which came dificit.
               deficit += balance;
               
               //balance will be getting from next iteration.
               balance = 0;
               
               //give a new start
               start = i+1;
           }
       }
       
       if(balance + deficit > 0){//if truct could complete a circle
           return start;
       }else{//if not
           return -1;
       }
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends