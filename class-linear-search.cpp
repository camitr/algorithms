#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

class LinearSearch{
private:
int	num,sizeofarray;
int* arrayList;
public:
		LinearSearch(int num);
void	randomArray(int num);
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


int main()
{
	int size;
	cout<<" enter the size of array "<<endl;
	cin>>size;
	
	LinearSearch obj(size);
	obj.randomArray(size);

}
