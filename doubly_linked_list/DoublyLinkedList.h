#pragma once
#include <iostream>
using namespace std;

class EmptyListException : public exception 
{
public: EmptyListException(const char* msg) : exception(msg) {}
};

template<typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

	DoublyLinkedList<T>& operator = (DoublyLinkedList<T> *&other)
	{
		Clear();

		for (int i = 0; i < GetCount(); ++i)
		{
			PushBack(other->GetData(i));
		}

		return *this;
	}

	int GetCount()
	{
		return count;
	}
	T GetData(const int idx)
	{
		if (count / 2 > idx)
			return GetDataFromBegin(idx);
		else
			return GetDataFromEnd(idx);
	}

	void PushBack(const T value)
	{
		head == nullptr ? AddFirstElement(value) : AddBack(value);
		++count;
	}
	void PushFront(const T value)
	{
		head == nullptr ? AddFirstElement(value) : AddFront(value);
		++count;
	}
	void Push(const T value, const int idx)
	{
		if (idx == 0)
			AddFront(value);
		else if (count / 2 >= idx)
			AddFromBegin(value, idx);
		else
			AddFromEnd(value, idx);

		++count;
	}

	void Show()
	{
		if (head == nullptr)
			throw EmptyListException("Список пуст");

		Node<T>* current = head;

		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
	void ShowReverse()
	{
		if (tail == nullptr)
			throw EmptyListException("Список пуст");

		Node<T>* current = tail;

		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->prev;
		}
	}

	bool Search(const T value)
	{
		Node<T>* current = head;

		while (current != nullptr)
		{
			if (current->data == value) 
				return true;

			current = current->next;
		}

		return false;
	}
	int Replace(const T presentValue, const int newValue)
	{
		Node<T>* current = head;
		int numberItemsChanged = 0;

		while (current != nullptr)
		{
			if (current->data == presentValue)
			{
				current->data = newValue;
				++numberItemsChanged;
			}

			current = current->next;
		}

		return numberItemsChanged;
	}

	void DeleteBack()
	{
		if (tail == nullptr)
			throw EmptyListException("Список пуст");

		tail->prev != nullptr ? DeleteEnd() : DeleteTail();
		--count;
	}
	void DeleteFront()
	{
		if (head == nullptr)
			throw EmptyListException("Список пуст");
		
		head->next != nullptr ? DeleteBegin() : DeleteHead();
		--count;
	}
	void Delete(const int idx)
	{
		if (head == nullptr)
			throw EmptyListException("Список пуст");

		DeleteOneElement(idx);
	}
	void Clear()
	{
		if (count == 0)
			throw EmptyListException("Список пуст");

		int amountElements = count;
		for (int i = 0; i < amountElements; ++i)
		{
			DeleteFront();
		}
	}

private:
	template<typename T>
	struct Node
	{
		Node* next;
		Node* prev;
		T data;

		Node(T value = T(0), Node* prev = nullptr, Node* next = nullptr)
		{
			this->data = value;
			this->prev = prev;
			this->next = next;
		}
	};

	Node<T>* head;
	Node<T>* tail;
	int count;

	T GetDataFromBegin(const int idx)
	{
		Node<T>* current = head;

		for (int i = 0; i < idx; ++i)
		{
			current = current->next;
		}

		return current->data;
	}
	T GetDataFromEnd(const int idx)
	{
		Node<T>* current = tail;
		int numberItaretion = count - idx - 1;
		
		for (int i = 0; i < numberItaretion; ++i)
		{
			current = current->prev;
		}

		return current->data;
	}

	void AddFirstElement(const T value)
	{
		head = tail = new Node<T>(value);
	}
	void AddBack(const T value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* current = head;

		while (current->next != nullptr)
		{
			current = current->next;
		}

		current->next = newNode;
		newNode->prev = current;
		tail = newNode;

		newNode = nullptr;
		current = nullptr;
	}
	void AddFront(const T value)
	{
		Node<T>* newNode = new Node<T>(value);

		head->prev = newNode;
		newNode->next = head;
		head = newNode;

		newNode = nullptr;
	}

	void AddFromBegin(const T value, const int idx)
	{
		Node<T> *newNode = new Node<T>(value);
		Node<T> *current = head;
		int iterator = 0;

		while (iterator != idx - 1)
		{
			current = current->next;
			++iterator;
		}

		newNode->next = current->next;
		newNode->prev = current;
		current->next->prev = newNode;
		current->next = newNode;

		newNode = nullptr;
		current = nullptr;
	}
	void AddFromEnd(const T value, const int idx)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* current = tail;
		int numberIterations = count - idx - 1;
		int iterator = 0;

		while (iterator != numberIterations)
		{
			current = current->prev;
			++iterator;
		}

		newNode->next = current;
		newNode->prev = current->prev;
		current->prev->next = newNode;
		current->prev = newNode;

		newNode = nullptr;
		current = nullptr;
	}

	void DeleteOneElement(const int idx)
	{
		if (idx == 0)
			DeleteFront();
		else if (idx == count - 1)
			DeleteBack();
		else if (count / 2 >= idx)
			DeleteElementFromBegin(idx);
		else
			DeleteElementFromEnd(idx);
	}
	void DeleteElementFromBegin(const int idx)
	{
		Node<T>* current = head;
		int iterator = 0;

		while (iterator != idx)
		{
			current = current->next;
			++iterator;
		}

		current->prev->next = current->next;
		current->next->prev = current->prev;

		delete current;
		current = nullptr;

		--count;
	}
	void DeleteElementFromEnd(const int idx)
	{
		Node<T>* current = tail;
		int numberIteration = count - idx - 1;
		int iterator = 0;

		while (iterator != numberIteration)
		{
			current = current->prev;
			++iterator;
		}

		current->prev->next = current->next;
		current->next->prev = current->prev;

		delete current;
		current = nullptr;

		--count;
	}

	void DeleteHead()
	{
		delete head;
		head = tail = nullptr;
	}
	void DeleteTail()
	{
		delete tail;
		head = tail = nullptr;
	}
	void DeleteBegin()
	{
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	}
	void DeleteEnd()
	{
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
};