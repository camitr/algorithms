#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Quick{

private: 
	int sizeofarray;
	int* arrayList;
public:
		Quick(int num);
void	quickArray();	
void	quickSort(int num1,int num2);
int		quickPartition(int num1,int num2);
void	quickShow();
//void	array(int num);
//void	swap(int num,int num);
};

Quick::Quick(int num)
{
	sizeofarray = num;
}

void Quick::quickArray()
{
	arrayList = new int[sizeofarray];
	
	srand((unsigned)time(NULL));
		for(int i=0;i<sizeofarray;i++)
		{
			this->arrayList[i] = 1 + rand() %10000;
			cout<<arrayList[i]<<endl;
		}
/*
	for(int i=0;i<sizeofarray;i++)
	{
		cout<<"enter array element"<<endl;
		cin>>this->arrayList[i];
	}*/
}

void Quick::quickSort(int start, int end)
{
	if(start < end)
	{
		int pivot = quickPartition(start,end);
		quickSort(start,pivot-1);
		quickSort(pivot+1,end);
	}
}


int Quick::quickPartition(int start, int end)
{
	
	int pivot = arrayList[start],i = start, j = end;
	while(i < j)
	{
		do
		{
			i++;
		}while(arrayList[i] < pivot);
		
		while(arrayList[j] > pivot)
		{
			j--;
		}
		if(i < j)
		{
			int temp = arrayList[i];	
			arrayList[i] = arrayList[j];
			arrayList[j] = temp;
		}

	}
	
	int temp			=	arrayList[start];
	arrayList[start]	=	arrayList[j];
	arrayList[j]		=	temp;
	return j;
}

void Quick::quickShow()
{
	cout<<"sorted Array"<<endl;
	for(int i=0;i<sizeofarray;i++)
	{
		cout<<arrayList[i]<<endl;
	}
}
int main()
{
	int size;
	cout<<"enter the size of the array"<<endl;
	cin>>size;
	Quick obj(size);
	obj.quickArray();
	clock_t begin; 
	begin = clock();
	obj.quickSort(0,size-1);
	float	time_taken	= (double)(clock() - begin)/CLOCKS_PER_SEC;
	obj.quickShow();
	cout<<"time take by quick sort="<<time_taken<<endl;

}
