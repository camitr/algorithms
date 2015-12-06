#include<iostream>
#include<cstdlib>

using namespace std;

class Selection{
private:
	int sizeofarray;
	int* arrayList;
public:
		Selection(int num);
void	arrayRandom();
void	arrayInput();
void	selectionSort();
void	arrayShow();
int		selectionComp(int num1, int num2);
void	selectionSwap(int num1, int num2);
};

Selection::Selection(int num)
{
	sizeofarray = num;
}

void Selection::arrayRandom()
{
	arrayList = new int[sizeofarray];                                                                        
    srand((unsigned)time(NULL));                                                                              
        for(int i=0;i<sizeofarray;i++)                                                                        
        {                                                                                                     
            this->arrayList[i] = 1 + rand() %100;                                                            
            cout<<arrayList[i]<<endl;                                                                        
        }                                                                                                     
}       

void Selection::selectionSort()
{
	int swap =0,comp=0,compresult;
	if (sizeofarray ==1)
	{
		cout<<"array has only one element"<<endl;
		exit;
	}
	cout<<"size of array "<<sizeofarray<<endl;
	for(int i=0; i<sizeofarray; i++)
	{
		int min = i;
		for(int j=i+1;j<sizeofarray;j++)
		{
			compresult=selectionComp(arrayList[j],arrayList[min]);
			++comp;
			if(compresult==-1)
			{
				min = j;		
			}
	
		}
		if(min !=i)
		{
			swap = swap +1;
			selectionSwap(i,min);
		}
		arrayShow();
	}

	
cout<<"Number of swaps= "<<swap<<endl;
cout<<"Number of comparision= "<<comp<<endl;

}
void Selection::arrayShow()
{
	for(int i =0; i<sizeofarray; i++)
	{
		cout<<arrayList[i]<<"\t";
	}
	cout<<endl;
}

void Selection::arrayInput()
{
	arrayList = new int[sizeofarray];
	for(int i=0;i<sizeofarray;i++)
	{
		cout<<"enter the "<<i<<"th element of the array"<<endl;
		cin>>arrayList[i];
	}
}


int Selection::selectionComp(int a,int b)
{
	if(a<b)
	{
	return -1;
	}
}

void	Selection::selectionSwap(int i, int min)
{
	int temp		=	arrayList[i];
	arrayList[i]	=	arrayList[min];
	arrayList[min]	=	temp;
}
int main()
{
	int size;
	char opton;
	cout<<"enter the size of array"<<endl;
	cin>>size;
	Selection obj(size);
	cout<<"For random array press R"<<endl;
	cin>>opton;
	if(opton == 'R')
	{
		obj.arrayRandom();
	}
	else
	{
		obj.arrayInput();
	}
cout<<"Sorted array"<<endl;
	obj.selectionSort();

//	obj.arrayShow();
}

