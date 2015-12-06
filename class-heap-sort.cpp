#include<iostream>
#include<cstdlib>

using namespace std;

class Heap{
private:
	int sizeofarray;
	int* arrayList;
public:
		Heap(int num);
void	arrayRandom();
void	arrayShow();
void	arrayInput();
void	heapBuild();
void	heapHeapify(int num1, int num2);
void	heapSort();
};

Heap::Heap(int num)
{
	sizeofarray	=	num;
}
void Heap::arrayRandom()                                                                                 
{                                                                                                             
    arrayList = new int[sizeofarray];                                                                         
    srand((unsigned)time(NULL));                                                                              
        for(int i=1;i<=sizeofarray;i++)                                                                        
        {                                                                                                     
            this->arrayList[i] = 1 + rand() %100;                                                             
            cout<<arrayList[i]<<endl;                                                                         
        }                                                                                                     
}                                                                                                             
    

void Heap::arrayShow()                                                                                   
{                                                                                                             
    for(int i =1; i<=sizeofarray; i++)                                                                         
    {                                                                                                         
        cout<<arrayList[i]<<"\t";                                                                             
    }                                                                                                         
    cout<<endl;                                                                                               
}                                                                                                             
                                                                                                              
void Heap::arrayInput()                                                                                  
{                                                                                                             
    arrayList = new int[sizeofarray];                                                                         
    for(int i=1;i<=sizeofarray;i++)                                                                            
    {                                                                                                         
        cout<<"enter the "<<i<<"th element of the array"<<endl;                                               
        cin>>arrayList[i];                                                                                    
    }                                                                                                         
}       

void Heap::heapBuild()
{
	for(int i=sizeofarray/2; i>=1; i--)
	{
		heapHeapify(i,sizeofarray);
	}
}

void Heap::heapHeapify(int pointer,int size)
{
	int j, temp;
	temp = arrayList[pointer];
	j	=	2 * pointer;
	while(j<=size)
	{
		if(j<size && arrayList[j+1] > arrayList[j])
			j+=1;
		if(temp > arrayList[j])
			break;
		else if(temp <= arrayList[j])
				{
					arrayList[j/2] =	arrayList[j];
					j	=2*j;
				}
	}
	arrayList[j/2]	= temp;
}

void	Heap::heapSort()
{
	for(int i=sizeofarray; i>=2; i--)
	{

		int temp	= arrayList[i];
		arrayList[i]	=	arrayList[1];
		arrayList[1]	=	temp;
		cout<<"arrayList["<<i<<"]= "<<arrayList[i]<<endl;
		heapHeapify(1,i-1);
	}
}

int main()                                                                                                    
{                                                                                                             
    int size;                                                                                                 
    char opton;                                                                                               
    cout<<"enter the size of array"<<endl;                                                                    
    cin>>size;                                                                                                
    Heap obj(size);                                                                                      
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
	obj.heapBuild();
	obj.heapSort();
	obj.arrayShow();
}
