#include<iostream>
using namespace std;

class Knapsack
{
private:
	int maxW, numItem;
	int* wList;
	int* vList;
public:
		Knapsack(int num1, int num2);
int		max(int num1, int num2);
int		knapSackCall();
void	arrayList();
void	arrayShow();
int knapSack(int num1, int* num2, int* num3, int num4);
};

	Knapsack::Knapsack(int size,int W)
{
	numItem	=	size;
	maxW	=	W;

	vList = new int [numItem];
	wList = new int [numItem];
}

void	Knapsack::arrayList()
{
	cout<<"Enter the value of item"<<endl;
	for(int i=1;i<=numItem;i++)
	{
		cin>>this->vList[i];
	}

	cout<<"Enter the Weight of item"<<endl;
	for(int i=1; i<=numItem;i++)
	{
	
		cin>>this->wList[i];
	}
}

int		Knapsack::knapSackCall()
{
	
	cout<<"Maximum Profit="<<knapSack(maxW,wList,vList,numItem)<<endl;
}

void	Knapsack::arrayShow()
{
	cout<<"Your item value"<<endl;
	for(int i=1;i<=numItem;i++)
	{
		cout<<vList[i]<<endl;
	}
	cout<<"Weight of item"<<endl;
	for(int i=1;i<=numItem;i++)
	{
		cout<<wList[i]<<endl;
	}
}

int Knapsack::max(int a, int b)
{

	return (a > b) ? a : b;

}

     
int Knapsack::knapSack(int mW, int wtL[], int valL[], int nV)

{
	cout<<"value of mW="<<mW<<endl;
    if (nV == 0 || mW == 0)
	{
		return 0;
    }
	if (wtL[nV - 1] > mW)
	{
		return knapSack(mW, wtL, valL, nV - 1);
	}
	else
	{
		return max(valL[nV - 1] + knapSack(mW - wtL[nV - 1], wtL, valL, nV - 1),knapSack(mW, wtL, valL, nV - 1));
	}
}

     

int main()
{
	int size,W;
	cout<<"enter number of item, Maximum Weight "<<endl;
	cin>>size;cout<<endl;
	cin>>W;cout<<endl;
	Knapsack obj(size,W);
	obj.arrayList();
	obj.arrayShow();
	obj.knapSackCall();
}
