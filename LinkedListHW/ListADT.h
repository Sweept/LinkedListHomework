#pragma once
#include <iostream>
using namespace std;

class ListADT
{
private:
	struct Node
	{
		int data;
		Node* next;
	};
	int size;
	Node* head;

public:
	~ListADT();

	ListADT();
	ListADT(const ListADT & clone);
	ListADT& operator= (const ListADT & clone);

	ListADT(int val);

	void push_back(int val);

	void push_front(int val);

	void pop_back();

	void pop_front();

	int operator[](const int index);

	void print(std::ostream& stream);
	friend std::ostream& operator<< (std::ostream& stream,  ListADT& list);

	int length() const;
};
