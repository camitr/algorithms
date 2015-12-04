#include<iostream>
#include<cstdlib>

using namespace std;

class Bubble{
private:
	int sizeofarray;
	int* arrayList;
public:
		Bubble(int num);
void	arrayRandom();
void	arrayInput();
void	bubbleSort();
void	arrayShow();
};

Bubble::Bubble(int num)
{
	sizeofarray = num;
}

void Bubble::arrayRandom()
{
	arrayList = new int[sizeofarray];                                                                        
    srand((unsigned)time(NULL));                                                                              
        for(int i=0;i<sizeofarray;i++)                                                                        
        {                                                                                                     
            this->arrayList[i] = 1 + rand() %100;                                                            
            cout<<arrayList[i]<<endl;                                                                        
        }                                                                                                     
}       

void Bubble::bubbleSort()
{
	int count =0;
	if (sizeofarray ==1)
	{
		cout<<"array has only one element"<<endl;
		exit;
	}
	cout<<"size of array "<<sizeofarray<<endl;
	for(int i=0; i<sizeofarray-1; i++)
	{
		for(int j=0; j<sizeofarray-1; j++)
		{
			if(arrayList[j] > arrayList[j+1])
			{
				count			= count + 1;
				int temp		= arrayList[j];
				arrayList[j]	= arrayList[j+1];
				arrayList[j+1]	= temp;
			}
		}
		if(count == 0)
		{
			cout<<"allready sorted array"<<endl;
			break;
		}
	}
}
void Bubble::arrayShow()
{
	cout<<"sorted array"<<endl;
	for(int i =0; i<sizeofarray; i++)
	{
		cout<<arrayList[i]<<endl;
	}
}

void Bubble::arrayInput()
{
	arrayList = new int[sizeofarray];
	for(int i=0;i<sizeofarray;i++)
	{
		cout<<"enter the "<<i<<"th element of the array"<<endl;
		cin>>arrayList[i];
	}
}


int main()
{
	int size;
	char opton;
	cout<<"enter the size of array"<<endl;
	cin>>size;
	Bubble obj(size);
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

	obj.bubbleSort();
	obj.arrayShow();
}

