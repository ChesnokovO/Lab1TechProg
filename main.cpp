#pragma once
#include <conio.h>
#include <iostream>
#include "base_queue.h"

using namespace std;

int real_main(int choice)
{
	char command;
	base_queue* copyQueue = 0;
	base_queue* queue = new public_queue;
	base_queue* tmp;
	switch (choice)
	{
	case 1:
		delete queue;
		queue = new public_queue;
		break;
	case 2:
		delete queue;
		queue = protected_queue::get_ptr();
		break;
	case 3:
		delete queue;
		queue = private_queue::get_ptr();
		break;
	}

	cout << "Enter command(0-7):" << endl;
	cout << "0 - Help" << endl;
	cout << "1 - Push a element to queue" << endl;
	cout << "2 - Pop a element from queue" << endl;
	cout << "3 - Show Queue" << endl;
	cout << "4 - Calculate" << endl;
	cout << "5 - Copy" << endl;
	cout << "6 - Merge Queues" << endl;
	cout << "7 - Exit" << endl;
	for (;;)
	{
		try
		{
			switch ((command = _getch()) - '0')
			{
			case 0:
				cout << "0 - Help" << endl;
				cout << "1 - Push a element to queue" << endl;
				cout << "2 - Pop a element from queue" << endl;
				cout << "3 - Show Queue" << endl;
				cout << "4 - Calculate" << endl;
				cout << "5 - Copy" << endl;
				cout << "6 - Merge Queues" << endl;
				cout << "7 - Exit" << endl;
				break;
			case 1:
				cout << "Push element" << endl;
				int Value;
				cout << "Enter value" << endl;
				cin >> Value;
				*queue + new elem(Value);
				break;
			case 2:
				cout << "Pop element" << endl;
				queue->pop();
				break;
			case 3:
				cout << "Show original queue" << endl;
				cout << queue;
				break;
			case 4:
				cout << "Calcul" << endl;
				cout << "Result = " << queue->calcul() << endl;
				break;
			case 5:
				cout << "Create copy" << endl;
				tmp = queue->copy();
				delete copyQueue;
				copyQueue = tmp;
				cout << "Copy create" << endl;
				break;
			case 6:
				cout << "Merge two queues" << endl;
				*queue + copyQueue;
				cout << "Queues merge competed" << endl;
				break;
			case 7:
				delete queue;
				delete copyQueue;
				return 0;

			default:
				cout << "Value " << command << " out of range" << endl;
				cout << "command 0 - help" << endl;
			}
			cout << "Please enter comand" << endl;
		}
		catch (myException Exception)
		{
			cout << Exception;
		}

	}
	return 0;
}

int main()
{
	int choice;
	do {
		cout << "Select Queue:" << endl;
		cout << "1. PublicQueue" << endl;
		cout << "2. ProtectedQueue" << endl;
		cout << "3. PrivateQueue" << endl;
		cout << "0. Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			real_main(choice);
			break;
		case 2:
			real_main(choice);
			break;
		case 3:
			real_main(choice);
			break;
		case 0:
			break;

		default:
			cout << "Value " << choice << " out of range" << endl;
			cin >> choice;
			break;
		}
	} while (choice != 0);
}