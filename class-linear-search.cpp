#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

class LinearSearch{
private:
int	num,sizeofarray,itemSrch;
int* arrayList;
public:
		LinearSearch(int num);
void	randomArray(int num);
void	search(int item);
};

LinearSearch::LinearSearch(int num)
{
	sizeofarray = num;
	
}

void LinearSearch::randomArray(int num)
{
	arrayList = new int[sizeofarray];

	srand((unsigned)time(NULL));
		for(int i = 0; i < sizeofarray; i++)
		{
			this->arrayList[i] = 1 + rand() % 100;
			cout<<arrayList[i]<<endl;
		}
}

void LinearSearch::search(int item)
{
	itemSrch = item;
	for(int i=0;i<sizeofarray;i++)
	{
		if(itemSrch == arrayList[i])
		{
			cout<<"Item found on "<<i+1<<"th position"<<endl;
			break;
		}
		else if (i==sizeofarray)
		{
			
			cout<<"Item is not found in the list"<<endl;
		}
	}
}
int main()
{
	int size,srchItem;
	cout<<" enter the size of array "<<endl;
	cin>>size;
	LinearSearch obj(size);
	obj.randomArray(size);
	cout<<"enter the item to search from array"<<endl;
	cin>>srchItem;
	clock_t begin = clock();
	obj.search(srchItem);
	clock_t end	  = clock();
	double total_time = double (end - begin);///CLOCKS_PER_SEC;
	cout<<"time taken by linear searcg = "<<total_time<<endl;

}	

