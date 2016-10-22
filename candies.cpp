/*
Alice is a kindergarden teacher. She wants to give some candies to the children in her class.  All the children sit in a line ( their positions are fixed), and each  of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. Alice wants to save money, so she needs to minimize the total number of candies given to the children.

Input Format

The first line of the input is an integer N, the number of children in Alice's class. Each of the following N lines contains an integer that indicates the rating of each child.

Constraints

Output Format

Output a single line containing the minimum number of candies Alice must buy.

Sample Input

3  
1  
2  
2
Sample Output

4
Explanation

Here 1, 2, 2 is the rating. Note that when two children have equal rating, they are allowed to have different number of candies. Hence optimal distribution will be 1, 2, 1.

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void *a,const void *b)
    {
    return *(int*)a - *(int*)b;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long int n;
    cin>>n;
    long int a[n],b[n],sum = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i] = 1;
    }
    
    for(int i=0;i<n-1;i++)
        {
            if(a[i+1]>a[i])
                b[i+1] = b[i]+1;
            else if(a[i+1] <= a[i])
                b[i+1] = 1;
            
    }
    for(int i=n;i>=1;i--)
        {
        if(a[i]<a[i-1] && b[i-1]<=b[i])
            b[i-1] = b[i]+1;
    }
    for(int i=0;i<n;i++)
        sum+=b[i];
    cout<<sum;
    return 0;
}

