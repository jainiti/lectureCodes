#include<iostream>
using namespace std;

int knapsack(int *wts,int *prices,int n,int capacity)
{
	if(n==0 || capacity==0)
	{
		return 0;
	}

     int inc=0,exc=0;
	if(wts[n-1]<=capacity)
	{
       inc=prices[n-1]+knapsack(wts,prices,n-1,capacity-wts[n-1]);
	}

	exc=0+knapsack(wts,prices,n-1,capacity);

	return max(inc,exc);
}

int bottomup(int *wts,int *prices,int n,int capacity)
{
   int dp[100][100]={0};
   for(int item=0;item<=n;item++)
   {
   	 for(int c=0;c<=capacity;c++)
   	 {
   	 	if(item==0 || c==0)
   	 	{
   	 		dp[item][c]=0;
   	 	}

   	 	else
   	 	{
   	 		int inc=0,exc=0;
   	 		if(wts[item-1]<=c)
   	 		{
   	 			inc=prices[item-1]+dp[item-1][c-wts[item-1]];
   	 		}

   	 		exc=0+dp[item-1][c];
   	 		dp[item][c]=max(inc,exc);
   	 	}
   	 }
   }

   for(int item=0;item<=n;item++)
   {
   	 for(int c=0;c<=capacity;c++)
   	 {
   	 		cout<<dp[item][c]<<" ";
   	 }
   	 cout<<endl;
   }

   
   return dp[n][capacity];



}


int topdown(int *wts,int *prices,int n,int capacity,int dp[][100])
{
	if(n==0 || capacity==0)
	{
		dp[n][capacity]=0;
		return dp[n][capacity];
	}

	if(dp[n][capacity]!=-1)
	{
		return dp[n][capacity];
	}
    
    int inc=0,exc=0;
	if(wts[n-1]<=capacity)
	{
       inc=prices[n-1]+topdown(wts,prices,n-1,capacity-wts[n-1],dp);
	}

	exc=0+topdown(wts,prices,n-1,capacity,dp);

	dp[n][capacity]=max(inc,exc);
	return dp[n][capacity];


}



int main()
{
	int wts[]={7,4,4};
	int prices[]={10,20,20};
	int n=sizeof(wts)/sizeof(int);
	int capacity;
	cin>>capacity;
	int dp[100][100];
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			dp[i][j]=-1;
		}
	}
	cout<<topdown(wts,prices,n,capacity,dp)<<endl;
	cout<<bottomup(wts,prices,n,capacity)<<endl;
	cout<<knapsack(wts,prices,n,capacity)<<endl;
	return 0;
}