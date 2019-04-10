#include<iostream>
using namespace std;

int mincost(int cost[][10],int i,int j)
{
	if(i==0 && j==0)
	{
		return cost[i][j];
	}

	else if(i==0 && j>0)
	{
		return mincost(cost,i,j-1)+cost[i][j];
	}

	else if(i>0 && j==0)
	{
		return mincost(cost,i-1,j)+cost[i][j];
	}
	else
	{
		int op1=mincost(cost,i-1,j);
		int op2=mincost(cost,i,j-1);
		return min(op1,op2)+cost[i][j];
	}
}

int bottomup(int cost[][10],int i,int j)
{
	int dp[100][100]={0};

	for(int k=0;k<=i;k++)
	{
		for(int l=0;l<=j;l++)
		{
			if(k==0 && l==0)
			{
				dp[k][l]=cost[k][l];
			}

			else if(k==0 && l>0)
			{
				dp[k][l]=cost[k][l]+dp[k][l-1];
			}

			else if(k>0 && l==0)
			{
				dp[k][l]=cost[k][l]+dp[k-1][l];
			}

			else
			{
				int op1=cost[k][l]+dp[k-1][l];
				int op2=cost[k][l]+dp[k][l-1];
				dp[k][l]=min(op1,op2);
			}
		}
	}

	for(int k=0;k<=i;k++)
	{
		for(int l=0;l<=j;l++)
		{
			cout<<dp[k][l]<<" ";
		}
		cout<<endl;
	}

	return dp[i][j];
}



int main()
{
	int cost[][10]={
	{1,2,5,1},
	{8,3,6,2},
	{0,1,3,3},
	{4,1,7,2} };

    int i,j;
    cin>>i>>j;
    
    cout<<bottomup(cost,i,j)<<endl;
    cout<<mincost(cost,i,j)<<endl;
    return 0;
}