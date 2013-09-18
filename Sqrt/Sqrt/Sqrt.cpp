#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
double MySqrt(double A,double precision)
//A为待开方的数，precision为精度，牛顿迭代法
{
	if(A<0)
		throw "不能为负数！";
	double X=1;
	while(abs(A-X*X)>precision)
	{
		X = X +(A/X-X)/2;
	}
	return X;
}

double MySqrtPartion(double A,double precision)//二分法
	{
		 if(A<0)
			throw "不能为负数";
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
	cout<<"输入被开方数数的整数：";
	cin>>a;
	cout<<MySqrt(a,0.001)<<endl;
	cout<<MySqrtPartion(a,0.001)<<endl;
	return 0;
}
