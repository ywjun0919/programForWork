#include<iostream>
#include<vector>
#include<iterator>
#include<ctime>
#include <cstdlib> 
using namespace std;
using std::iterator;
vector<int> &Construct(int n,int m)
{
	vector<int> get;
	srand((unsigned) time(NULL));
	for(int i=0;i<n;i++)
	{
		if(rand()%(n-i)<=m&&m>=1)
		{
			get.push_back(i);
			m--;
		}
	}
}
int main()
{
	vector<int> get = Construct(10,5);
	copy(get.begin(),get.end(),ostream_iterator<int,char>(cout,"	"));
}