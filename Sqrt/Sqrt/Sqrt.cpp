#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
double MySqrt(double A,double precision)
//AΪ������������precisionΪ���ȣ�ţ�ٵ�����
{
	if(A<0)
		throw "����Ϊ������";
	double X=1;
	while(abs(A-X*X)>precision)
	{
		X = X +(A/X-X)/2;
	}
	return X;
}

double MySqrtPartion(double A,double precision)//���ַ�
	{
		 if(A<0)
			throw "����Ϊ����";
		double min =0,max = A;
		double result = (min+max)/2;
		while(abs(A-result*result)>precision)
		{
			//X = X +(A/X-X)/2;
			if(A-result*result>0)
				min =result;
			else
				max = result;
			result =(min+max)/2;
		}
		return result;
	}
int main()
{
	double a;
	cout<<"���뱻����������������";
	cin>>a;
	cout<<MySqrt(a,0.001)<<endl;
	cout<<MySqrtPartion(a,0.001)<<endl;
	return 0;
}
