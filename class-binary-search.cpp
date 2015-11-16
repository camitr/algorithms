#include<iostream>

using namespace std;

class Binary{

private:
	int l,item,sizeofarray,mid;
	int* arrayPointer;
public:
		Binary(int l,int num);
void	arrayInput();
void	showMessg();
int		binarySort(int l,int sizeofarray,int item);

};

Binary::Binary(int l,int num)
{
	l=l;
	sizeofarray = num;
	arrayPointer = new int[num];
}

void Binary::arrayInput()
{
	for(int i=0;i<sizeofarray;i++)
	{
		cout<<"enter the "<<i<<"th element of array"<<endl;
		cin>>this->arrayPointer[i];
	}
}

void Binary::showMessg()
{	
	cout<<"Welcome to the Binary search"<<endl;
	cout<<"please enter the sorted element in the array"<<endl;
}

int Binary::binarySort(int l,int sizeofarray,int item)
{
	
	mid = (l + sizeofarray)/2;
	if(item == arrayPointer[mid])
		{
			cout<<"item found at "<<mid+1<<" position";
			
		}
	else if(item < arrayPointer[mid])
		{
			sizeofarray = mid-1;
			return binarySort(l,sizeofarray,item);
		}
	else
		{
			l = mid+1;
			return binarySort(mid+1,sizeofarray,item);
		}
}

int main()
{
	int size,num;
	cout<<"please enter the number of elements for array"<<endl;
	cin>>size;
	
	Binary obj(0,size);
	obj.arrayInput();
	cout<<"enter the element to search in the List"<<endl;
	cin>>num;
	obj.binarySort(0,size,num);

}
