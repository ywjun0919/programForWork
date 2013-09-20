#include<iostream>
#include<cmath>
using namespace std;

int foo(int x)
{
	return 1 & -1;
}

int main()
{
	cout<<foo(pow(2,31)-3);
}