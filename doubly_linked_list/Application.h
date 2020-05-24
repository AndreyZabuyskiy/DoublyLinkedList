#pragma once
#include "DoublyLinkedList.h"

class Application
{
public: static void Start();

private:
	static void Interface(DoublyLinkedList<int> &list);
	static void PrintMenuInterface();
	static void ActionUserInterface(DoublyLinkedList<int>& list, int user);

	static void AddElement(DoublyLinkedList<int>& list);
	static void PrintMenuAddElement();
	static void ActionUserAddElement(DoublyLinkedList<int>& list, int user);

	static void DeleteElement(DoublyLinkedList<int>& list);
	static void PrintMenuDeleteElement();
	static void ActionUserDeleteElement(DoublyLinkedList<int>& list, int user);

	static void DeleteFrontElement(DoublyLinkedList<int>& list);
	static void DeleteBackElement(DoublyLinkedList<int>& list);
	static void DeleteElementIndex(DoublyLinkedList<int>& list);
	static void DeleteAllElements(DoublyLinkedList<int>& list);

	static void OutputReverse(DoublyLinkedList<int>& list);
	static void SearchElement(DoublyLinkedList<int>& list, int item);
	static void ReplacementElement(DoublyLinkedList<int>& list);

	static void PrintList(DoublyLinkedList<int>& list);

	static int InputItem();
	static int InputIdx(int border);
	static bool CheñkCorrectnessIdx(int idx, int border);
};