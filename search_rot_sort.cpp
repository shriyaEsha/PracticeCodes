#include<iostream>
#include<math.h>
#include<string>
#include<vector>
using namespace std;

void print(vector<int> nums)
{
int n = nums.size();
for(int i=0;i<n;i++)
cout<<nums[i]<<" ";
cout<<endl;
}
int pivot_(vector<int> nums,int start,int end)
{
if(start>end) return -1;
if(start==end) return start;
int mid = (end+start)/2;
if(mid<end && nums[mid]>=nums[mid+1])
return mid;
if(mid>start && nums[mid-1] > nums[mid])
return mid-1;
if(nums[start]>=nums[mid])
return pivot_(nums,start,mid-1);
return pivot_(nums,mid+1,end);
}
int bs(vector<int>nums,int start,int end,int target)
{
if(start>end)return -1;
int mid = (start+end)/2;
if(nums[mid]==target)
return mid;
if(nums[mid]>target)
return bs(nums,start,mid-1,target);
return bs(nums,mid+1,end,target);
}

int search_(vector<int> nums,int target,int start,int end)
{
int p = pivot_(nums,start,end);
cout<<"\np: "<<p;
if(p==-1)
return bs(nums,start,end,target);
if(nums[p] == target)
return p;
if(nums[start]>target)
return bs(nums,p+1,end,target);
return bs(nums,start,p-1,target);
}

int search(vector<int>& nums, int target) {

	return search_(nums,target,0,nums.size());

}
main()
{
	int target=1;
	int a[] = {3,4,5,1,2},n=sizeof(a)/sizeof(a[0]);
	vector<int> nums;
	for(int i=0;i<n;i++)
		nums.push_back(a[i]);
	print(nums);
	cout<<endl<<search(nums,target);
}
