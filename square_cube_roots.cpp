#include<iostream>
using namespace std;

int square_root(int n)
{
if(n==0 || n==1) return n;
int start=1,end = n,ans;
while(start<=end)
{
int mid = (start+end)/2;
if(mid*mid == n)
return mid;
else if(mid*mid<n)
{
start = mid+1;
ans = mid;
}
else
end = mid-1;
}
return ans;
}
int cube_root(int n)
{
if(n==0 || n==1) return n;
int start = 1, end = n,ans;
while(start<=end)
{
int mid = (start+end)/2;
int val = mid*mid*mid;
if(val==n)
return mid;
if(val<mid)
{
ans = val;
start = mid+1;
}
else
end = mid-1;
}
return ans;
}
main()
{
int n = 9;
cout<<square_root(n)<<" "<<cube_root(64);
}


