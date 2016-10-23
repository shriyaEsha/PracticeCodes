#include<iostream>
#include<algorithm>
using namespace std;

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int compare(const void *a,const void *b)
{
return *(int*)a-*(int*)b;
}
void subset_sum(int s[],int t[],int size,int tsize,int idx,int target_sum,int cur_sum)
{
	if(cur_sum==target_sum)
	{
		print(t,tsize);
		if(idx<size-1 && cur_sum-s[idx]+s[idx+1]<=target_sum)
			subset_sum(s,t,size,tsize-1,idx+1,target_sum,cur_sum-s[idx]);
		return;
	}

	else
	{
		if(idx<size && cur_sum+s[idx]<=target_sum)
		{
			for(int i=idx;i<size;++i)
			{
				t[tsize] = s[i];
				if(cur_sum+s[i]<=target_sum)
					subset_sum(s,t,size,tsize+1,i+1,target_sum,cur_sum+s[i]);
			}
		}
	}
}

void subsets(int s[],int size,int target)
{
	int t[size],tsize=0,cur=0,idx=0;
qsort(s,size,sizeof(int),compare);
	subset_sum(s,t,size,tsize,idx,target,cur);
}

main()
{
	int weights[] = {15,20,25,10,5,30};
	int target = 30;

	int size = sizeof(weights)/sizeof(weights[0]);
	subsets(weights,size,target);
}

