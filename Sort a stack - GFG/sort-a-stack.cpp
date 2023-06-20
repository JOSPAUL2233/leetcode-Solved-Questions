//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insertSort(stack<int> &s,int ele){
    
    //base case
    if(s.empty()|| s.top() < ele){
        
        s.push(ele);
        return;
        
    }
        
        
    int element = s.top();
    s.pop();
    insertSort(s,ele);
    s.push(element);
    
}

void solve(stack<int> &s){
    
    //base case
    if(s.empty())
        return;
        
    int ele = s.top();
    s.pop();
    
    solve(s);
    
    insertSort(s,ele);
        
}

void SortedStack :: sort()
{
   
   solve(s);
   
}