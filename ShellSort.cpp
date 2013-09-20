#include<iostream>
#include<iterator>
using namespace std;

void ShellSort(int *H,int Hlen,int dlta[],int dlen);
void SSort(int *H,int Hlen,int dk);

void ShellSort(int *H,int Hlen,int dlta[],int dlen)
{
	for(int i=0;i<dlen;i++)
		SSort(H,Hlen,dlta[i]);
}

void SSort(int *H,int Hlen,int dk)
{
	for(int i=dk;i<Hlen;i++)
		if(H[i-dk]>H[i])
		{
			int temp = H[i];
			int j=0;
			for(j=i-dk;j>=0&&H[j]>temp;j -= dk)//此处j>=0
				H[j+dk]=H[j];
			H[j+dk]=temp;
		}
}

int main()
{
	int H[] = {49,38,65,97,76,13,27,49};
	int dlta[]={3,2,1};//增量数组最好为素数
	ShellSort(H,8,dlta,3);
	copy(H,H+8,ostream_iterator<int ,char>(cout,"	"));
	cout<<endl;
}