#include<iostream>
using namespace std;

int toh(int n,char s,char d,char m,int ct)
{
if(n==0)return ct;
ct = toh(n-1,s,m,d,ct);
ct++;
ct+=toh(n-1,m,d,s,ct);
}
main()
{
int n = 3;
int ct = 0;
ct = toh(n,'s','d','m',ct);
cout<<ct;
}
