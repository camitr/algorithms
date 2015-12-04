#include<iostream>
#include<cstdlib>

using namespace std;

class Insertion{
private:
	int sizeofarray;
	int* arrayList;
public:
		Insertion(int num);
void	arrayRandom();
void	arrayInput();
void	insertionSort();
void	arrayShow();
};

Insertion::Insertion(int num)
{
	sizeofarray = num;
}

void Insertion::arrayRandom()
{
	arrayList = new int[sizeofarray];                                                                        
    srand((unsigned)time(NULL));                                                                              
        for(int i=0;i<sizeofarray;i++)                                                                        
        {                                                                                                     
            this->arrayList[i] = 1 + rand() %100;                                                            
            cout<<arrayList[i]<<endl;                                                                        
        }                                                                                                     
}       

void Insertion::insertionSort()
{
	int swap =0;
	if (sizeofarray ==1)
	{
		cout<<"array has only one element"<<endl;
		exit;
	}
	cout<<"size of array "<<sizeofarray<<endl;
	for(int i=1; i<sizeofarray; i++)
	{
		int j=i;
		while(j>0&&arrayList[j-1] > arrayList[j])
		{
			swap = swap + 1;
			int temp = arrayList[j-1];
				arrayList[j-1] = arrayList[j];
				arrayList[j] = temp;
			j = j-1;
		}
	}

	
cout<<"Number of swaps= "<<swap<<endl;
}
void Insertion::arrayShow()
{
	cout<<"sorted array"<<endl;
	for(int i =0; i<sizeofarray; i++)
	{
		cout<<arrayList[i]<<endl;
	}
}

void Insertion::arrayInput()
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
	Insertion obj(size);
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

	obj.insertionSort();
	obj.arrayShow();
}

