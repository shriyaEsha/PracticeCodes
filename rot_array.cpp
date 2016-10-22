#include<iostream>
using namespace std;

int search(int a[],int ele,int beg,int end)
{
if(beg>end)
return -1;
int mid = beg+(end-beg)/2;
if(a[mid]==ele)
return mid;
else if(a[mid]>=a[end])
{
if(ele<a[mid] && ele>a[end])
return search(a,ele,beg,mid-1);
return search(a,ele,mid+1,end);
}
else
{
if(ele>a[mid] && ele<a[end])
return search(a,ele,beg,mid-1);
return search(a,ele,mid+1,end);

}
}

main()
{
int n=5,ele=2;
int a[] = {3,4,5,1,2};
int idx = search(a,ele,0,n-1);
cout<<"\nFound at: "<<idx;
}
