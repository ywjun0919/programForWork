#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

void Merge(int *H,int low,int middle,int high)
{
	vector<int> cp;
	int i,j;
	for( i=low,j=middle+1;i<=middle&&j<=high;)
	{
		if(H[i]>H[j]) cp.push_back(H[j++]);
		else cp.push_back(H[i++]);
	}
	while(i<=middle) cp.push_back(H[i++]);
	while(j<=high) cp.push_back(H[j++]);
	copy(cp.begin(),cp.end(),H+low);
}

void MSort(int *H,int low,int high)
{
	if(low<high)
	{
		int middle =(low+high)/2;
		MSort(H,low,middle);
		MSort(H,middle+1,high);
		Merge(H,low,middle,high);
	}
}

void MergeSort(int *H,int length)
{
	MSort(H,0,length-1);
}

int main()
{
	int H[] = {49,38,65,97,76,13,27,49};
	MergeSort(H,8);
	copy(H,H+8,ostream_iterator<int ,char>(cout,"	"));
	cout<<endl;
}