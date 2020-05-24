#include "Application.h"

void Application::Start()
{
	DoublyLinkedList<int> list;
	list.PushBack(10);
	list.PushBack(20);
	list.PushBack(30);
	list.PushBack(40);
	list.PushBack(50);
	list.PushBack(60);
	Interface(list);
}

void Application::Interface(DoublyLinkedList<int> &list)
{
	int user;

	do
	{
		PrintList(list);
		cout << "------------------------------------" << endl;

		PrintMenuInterface();
		cin >> user;

		ActionUserInterface(list, user);

	} while (user != 0);
}

void Application::PrintMenuInterface()
{
	cout << "[1] Добавить элемент;" << endl
		<< "[2] Удалить элемент;" << endl
		<< "[3] Вывести в обратном порядке;" << endl
		<< "[4] Поиск;" << endl
		<< "[5] Замена;" << endl
		<< "[0] Выход;" << endl
		<< "-> ";
}

void Application::ActionUserInterface(DoublyLinkedList<int>& list, int user)
{
	system("cls");

	switch (user)
	{
		case 1:
			AddElement(list);
			break;

		case 2:
			DeleteElement(list);
			break;

		case 3:
			OutputReverse(list);
			break;

		case 4:
			SearchElement(list, InputItem());
			break;

		case 5:
			ReplacementElement(list);
			break;
	}

	system("cls");
}

void Application::AddElement(DoublyLinkedList<int>& list)
{
	int user;

	do
	{
		PrintList(list);
		cout << "------------------------------------" << endl;

		PrintMenuAddElement();
		cin >> user;

		ActionUserAddElement(list, user);
	} while (user != 0);
}

void Application::PrintMenuAddElement()
{
	cout << "[1] Добавить в конец;" << endl
		<< "[2] Добавить в начало;" << endl
		<< "[3] Добавить по индексу;" << endl
		<< "[0] Выход" << endl
		<< "-> ";
}

void Application::ActionUserAddElement(DoublyLinkedList<int>& list, int user)
{
	system("cls");

	switch (user)
	{
		case 1:
			list.PushBack(InputItem());
			break;

		case 2:
			list.PushFront(InputItem());
			break;

		case 3:
			list.Push(InputItem(), InputIdx(list.GetCount()));
			break;
	}

	system("cls");
}

void Application::DeleteElement(DoublyLinkedList<int>& list)
{
	int user;
	
	do
	{
		PrintList(list);
		cout << "------------------------------------" << endl;

		PrintMenuDeleteElement();
		cin >> user;

		ActionUserDeleteElement(list, user);

	} while (user != 0);
}

void Application::PrintMenuDeleteElement()
{
	cout << "[1] Удалить с конца;" << endl
		<< "[2] Удалить с начала;" << endl
		<< "[3] Удалить по индексу;" << endl
		<< "[4] Удалить весь список;" << endl
		<< "[0] Выход" << endl
		<< "-> ";
}

void Application::ActionUserDeleteElement(DoublyLinkedList<int>& list, int user)
{
	system("cls");

	switch (user)
	{
		case 1:
			DeleteBackElement(list);
			break;

		case 2:
			DeleteFrontElement(list);
			break;

		case 3:
			DeleteElementIndex(list);			
			break;

		case 4:
			DeleteAllElements(list);
			break;
	}

	system("cls");
}

void Application::DeleteFrontElement(DoublyLinkedList<int>& list)
{
	try
	{
		list.DeleteFront();
	}
	catch (const EmptyListException & ex)
	{
		cout << ex.what() << endl;
		system("pause");
	}
}

void Application::DeleteBackElement(DoublyLinkedList<int>& list)
{
	try
	{
		list.DeleteBack();
	}
	catch (const EmptyListException & ex)
	{
		cout << ex.what() << endl;
		system("pause");
	}
}

void Application::DeleteElementIndex(DoublyLinkedList<int>& list)
{
	try
	{
		list.Delete(InputIdx(list.GetCount()));
	}
	catch (const EmptyListException & ex)
	{
		cout << ex.what() << endl;
		system("pause");
	}
}

void Application::DeleteAllElements(DoublyLinkedList<int>& list)
{
	try 
	{ 
		list.Clear(); 
	}
	catch (const EmptyListException & ex)
	{
		cout << ex.what() << endl;
		system("pause");
	}
}

void Application::OutputReverse(DoublyLinkedList<int>& list)
{
	system("cls");

	try 
	{ 
		list.ShowReverse(); 
	}
	catch (const EmptyListException & ex)
	{ 
		cout << ex.what() << endl; 
	}

	system("pause");
}

void Application::SearchElement(DoublyLinkedList<int>& list, int item)
{
	system("cls");
	cout << item << endl;

	if (list.Search(item))
		cout << "Данный элемент есть в списке" << endl;
	else
		cout << "Данного элемента нет в списке" << endl;

	system("pause");
}

void Application::ReplacementElement(DoublyLinkedList<int>& list)
{
	int currentItem, newItem;

	cout << "Введите значение текущего элемента" << endl;
	cout << "-> ";
	cin >> currentItem;

	cout << "Введите значение нового элемента" << endl;
	cout << "-> ";
	cin >> newItem;

	cout << "Количество замененных элементов: " << list.Replace(currentItem, newItem) << endl;
	system("pause");
}

void Application::PrintList(DoublyLinkedList<int>& list)
{
	try
	{
		list.Show();
	}
	catch (const EmptyListException &ex)
	{
		cout << ex.what() << endl;
	}
}

int Application::InputItem()
{
	int item;
	cout << "Введите значение элемента -> ";
	cin >> item;

	return item;
}

int Application::InputIdx(int border)
{
	if (border != 0)
	{
		int idx;
		cout << "Введите индекс -> ";

		while (true)
		{
			cin >> idx;

			if (CheсkCorrectnessIdx(idx, border))
				return --idx;
			else
				cout << "Повторите ввод -> ";
		}
	}
}

bool Application::CheсkCorrectnessIdx(int idx, int border)
{
	if (idx > border || idx < 0)
		return false;

	return true;
}
