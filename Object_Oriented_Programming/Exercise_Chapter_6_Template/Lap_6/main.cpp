#include "Stack.h"
#include "Stack.cpp"
#include <conio.h>
void showMainMenu() {
	system("cls");
	cout << "\n\n";
	cout << "\n\n\t\t\t\t\t\t================================================ STACK MANAGEMENT PROGRAM ================================================";
	cout << "\n\n\t\t\t\t\t\t                             0. Exit                     1. Push                     2. Pop                               ";
	cout << "\n\n\t\t\t\t\t\t                                    3. Check empty stack          4. Check full stack                                     ";
	cout << "\n\n\t\t\t\t\t\t                                     5. Get stack's size         6. Get stack's top                                       ";
	cout << "\n\n\t\t\t\t\t\t==========================================================================================================================";
}
int main() {
	Stack <int> intStack;
	while (true) {
		showMainMenu();
		int selection;
    	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t      Please enter your selection: ";
    	cin >> selection;
    	if (selection == 1) {
			int number;
			cout << "\n\n\t\t\t\t\t\tEnter a integer number you want to push: ";
			cin >> number;
			intStack.push(number);
			getch();
			showMainMenu();
    	}
    	else if (selection == 2) {
			intStack.pop();
			cout << "\n\n\t\t\t\t                                                              Press any key to continue. . .";
			getch();
			showMainMenu();
    	}
		else if (selection == 3) {
			if (!intStack.isEmpty()) {
				cout << "\n\n\t\t\t\t\t\tStack isn't empty! Press any key to continue. . .";
			}
			else {
				cout << "\n\n\t\t\t\t\t\tStack is empty! Press any key to continue. . .";
			}
			getch();
			showMainMenu();
    	}
		else if (selection == 4) {
			if (!intStack.isFull()) {
				cout << "\n\n\t\t\t\t\t\tStack isn't full! Press any key to continue. . .";
			}
			else {
				cout << "\n\n\t\t\t\t\t\tStack is full! Press any key to continue. . .";
			}
			getch();
			showMainMenu();
    	}
		else if (selection == 5) {
			cout << "\n\n\t\t\t\t\t\tStack's size is " << intStack.getSize() << "! Press any key to continue. . .";
			getch();
			showMainMenu();
    	}
		else if (selection == 6) {
			cout << "\n\n\t\t\t\t\t\tStack's top is " << intStack.getTop() << "! Press any key to continue. . .";
			getch();
			showMainMenu();
    	}
    	else {
			cout << "\n\n\t\t\t\t\t\tProgram ended!";
			exit(0);
    	}
	}
	return 0;
}

