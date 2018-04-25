#include "VectorADT.h"
#include "ListADT.h"
using namespace std;

int main()
{
	VectorADT emptyVector;

	cout << emptyVector;
	cout << "the capacity is " << emptyVector.curr_capacity() << "." << endl;

	emptyVector.push_back(5.6);
	cout << "the capacity is " << emptyVector.curr_capacity() << "." << endl;

	cout << emptyVector;
	ListADT emptyList;
	cout << emptyList;
	cout << "the capacity is " << emptyVector.curr_capacity() << "." << endl;
	emptyList.push_back(1);
	cout << "the capacity is " << emptyVector.curr_capacity() << "." << endl;
	emptyList.push_front(4);
	emptyList.push_front(2);
	cout << "the capacity is " << emptyVector.curr_capacity() << "." << endl;
	emptyList.pop_back();
	cout << "the capacity is " << emptyVector.curr_capacity() << "." << endl;
	emptyList.push_back(8);
	emptyList.pop_front();
	cout << "the capacity is " << emptyVector.curr_capacity() << "." << endl;

	return 0;
}