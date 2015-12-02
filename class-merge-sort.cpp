#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Merge{

private: 
	int sizeofarray;
	int* arrayList1;
	int* arrayList2;
public:
		Merge(int num);
void	mergeArray();	
void	mergeShow();
void	mergeSort(int low, int high);
void	merging(int low, int mid, int high);
};

Merge::Merge(int num)
{
	sizeofarray = num;
}

void Merge::mergeArray()
{
	arrayList1 = new int[sizeofarray];
	arrayList2 = new int[sizeofarray];
	srand((unsigned)time(NULL));
		for(int i=0;i<sizeofarray;i++)
		{
			this->arrayList1[i] = 1 + rand() %100;
			cout<<arrayList1[i]<<endl;
		}
}

void Merge::mergeSort(int low, int high)
{
	if(low < high)
	{
		int mid = (low + high)/2;
		mergeSort(low,mid);
		mergeSort(mid+1,high);
		merging(low,mid,high);
	}
}
void Merge::merging(int low, int mid, int high)
{
	int h = low, i=low,j=mid+1;
	while(h<=mid && j<=high)
	{
		if(arrayList1[h] <= arrayList1[j])
		{
			arrayList2[i]=arrayList1[h];
			h = h+1;
		}
		else 
		{
			arrayList2[i] = arrayList1[j];
			j = j+1;
		}
		i = i+1;
	}

	if (h>mid)
	{
		for(int k = j;k<=high;k++)
		{
			arrayList2[i] = arrayList1[k];
			i = i+1;
		}
	}
	else
	{
		for(int k = h;k<=mid;k++)
		{
			arrayList2[i] = arrayList1[k];
			i = i+1;
		}
	}

	for(int k=low;k<=high;k++)
	{
		arrayList1[k] = arrayList2[k];
	}
}

void Merge::mergeShow()
{
	cout<<"sorted Array"<<endl;
	for(int i=0;i<sizeofarray;i++)
	{
		cout<<arrayList1[i]<<endl;
	}
}
int main()
{
	int size;
	cout<<"enter the size of the array"<<endl;
	cin>>size;
	Merge obj(size);
	obj.mergeArray();
	obj.mergeSort(0,size-1);
	obj.mergeShow();


}
