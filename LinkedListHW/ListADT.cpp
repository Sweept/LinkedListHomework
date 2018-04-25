#include "ListADT.h"

ListADT::ListADT()
{
	size = 0;
	head = nullptr;
}

ListADT::ListADT(int val)
{
	head = new Node;
	head->data = val;
	head->next = nullptr;
	size = 1;
}

ListADT::ListADT(const ListADT& clone)
{
	size = 0;
	head = nullptr;
	if (clone.head)
	{
		Node *currentnode = clone.head;
		while (currentnode != nullptr)
		{
			push_back(currentnode->data);
			currentnode = currentnode->next;
		}
	}
}

ListADT& ListADT::operator= (const ListADT & clone)
{
	size = 0;
	head = nullptr;
	if (clone.head)
	{
		Node *currentnode = clone.head;
		while (currentnode != nullptr)
		{
			push_back(currentnode->data);
			currentnode = currentnode->next;
		}
	}
	return *this;
}

ListADT::~ListADT()
{
	struct Node* tempNode;
	while (head != NULL)
	{
		tempNode = head->next;
		delete head;
		head = tempNode;
	}
}

void ListADT::push_back(int val)
{
	Node *newNode = new Node;
	if (nullptr == newNode)
	{
		return;
	}
	newNode->data = val;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		Node *last = head;
		while (last->next != nullptr)
		{
			last = last->next;
		}
		last->next = newNode;
	}
	size++;
}

void ListADT::push_front(int val)
{
	Node *newNode = new Node;
	if (nullptr == newNode)
	{
		return;
	}
	newNode->data = val;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	size++;
}

void ListADT::pop_back()
{
	if (head) {
		if (head->next == nullptr) {
			delete head;
			head = nullptr;
		}
		else
		{
			Node* prevnode = head;
			Node *currentnode = head->next;
			while (currentnode->next != nullptr)
			{
				prevnode = currentnode;
				currentnode = currentnode->next;
			}
			delete currentnode;
			prevnode->next = nullptr;
		}
		size--;
	}
}

void ListADT::pop_front()
{
	Node * toPop = head;
	if (head != nullptr)
	{
		head = head->next;
	}
	if (toPop)
	{
		delete toPop;
	}
	size--;
}

int ListADT::operator[](const int index)
{
	int retVal = -1;
	if (index < size && head)
	{
		Node *currentNode = head;
		for (int i = 0; i < index; i++)
		{
			currentNode = currentNode->next;
		}
		retVal = currentNode->data;
	}
	return retVal;
}

void ListADT::print(std::ostream& stream)
{
	if (head == nullptr)
	{
		stream << "The list is empty" << endl;
	}
	Node *currentNode = head;
	while (currentNode != nullptr)
	{
		if (currentNode != head)
		{
			stream << ',';
		}
		stream << currentNode->data << endl;
		currentNode = currentNode->next;
	}
	stream << endl;

}

std::ostream& operator << (std::ostream& stream, ListADT& list)
{
	list.print(stream);
	return stream;
}

int ListADT::length() const
{
	return size;
}