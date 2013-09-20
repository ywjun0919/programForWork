#include<iostream>
#include<iterator>
using namespace std;

void HeapAjust(int *H,int index,int length)
{
	int temp = H[index]; 
	for(int j = 2*index+1;j<length;j*=2)//注意这里是2*index+1，当H的第一个结点的下标是0时，第i个结点的左右孩子结点是2*i+1及2*i+2
	{
		if(j<length && H[j]< H[j+1]) ++j;// j总是指向左孩子和右孩子中较小者
		if(temp>H[j]) break;
		H[index] = H[j];	//temp的值应该插入到位置index上	
		index = j;		//index总是当前左右孩子结点的根节点的下标
	}
	H[index] = temp;
}

void Heap(int *H,int length)
{
	for(int i =(length-1)/2;i>=0;i--)//这里i大于等于0
		HeapAjust(H,i,length);
	for(int i =length-1;i>0;i--)//这里i大于0
	{
		swap(H[0],H[i]);
		HeapAjust(H,0,i-1);	
	}
}

int main()
{
	int H[] = {49,38,65,97,76,13,27,49};
	Heap(H,8);
	copy(H,H+8,ostream_iterator<int ,char>(cout,"	"));
	cout<<endl;
}