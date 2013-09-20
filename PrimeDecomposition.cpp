#include<iostream>
#include<vector>
#include<iterator>
#include<cmath>
using namespace std;

bool ISPrime(int num)
{
	for(int i=2;i<=sqrt(num);i++)
		if(num%i==0)
			return false;
	return true;
}

void PrimeDecomposition(int n)
{

	vector<int> output;
	int i=2;
	while(i<=n)
	{
		while(n%i==0 && ISPrime(i) ) 
		{
			output.push_back(i);
			n =n/i;
		}
		i++;
	}
	copy(output.begin(),output.end(),ostream_iterator<int,char>(cout,"*"));
	cout<<endl;
}

int main()
{
	cout<<"输入正整数：";
	int n;
	cin>>n;
	PrimeDecomposition(n);
	return 0;
}