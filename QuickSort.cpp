#include<iostream>
#include<iterator>
using namespace std;

int Partition(int *H,int low ,int high)
{
	int pivotkey = H[low];
 	while(low<high)
	{
		while(low<high&& H[high]>=pivotkey) high--;
		swap(H[low],H[high]);
		while(low<high&& H[low]<=pivotkey) low++;
		swap(H[low],H[high]);
	}
	return low;
}

void Qsort(int *H ,int low,int high)
{
	if(low<high)
	{
		int index = Partition(H,low,high);
		Qsort(H,low,index-1);
		Qsort(H,index+1,high);
	}
}

void QuickSort(int *H,int length)
{
	Qsort(H,0,length-1);
}

int main()
{
	int H[] = {49,38,65,97,76,13,27,49};
	QuickSort(H,8);
	copy(H,H+8,ostream_iterator<int ,char>(cout,"	"));
	cout<<endl;
}