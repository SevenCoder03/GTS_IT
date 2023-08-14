#include "Stack.h"

template <class T>
Stack<T>::Stack(int _size) {
    top = -1;
    size = _size;
    arrElement = new T[size];
}

template <class T>
bool Stack<T>::isEmpty() {
    return (top == -1) ? true : false;
}

template <class T>
bool Stack<T>::isFull() {
    return (top >= size - 1) ? true : false;
}

template <class T>
void Stack<T>::push(T a) {
    if (!isFull()) {
        top++;
        *(arrElement + top) = a;
        cout << "\n\t\t\t\t\t\t\t\t\t\t    Push successfully!!! Press any key to continue. . .";
    }
    else {
        cout << "\n\t\t\t\t\t\t\t\t           Stack's full. Push unsuccessfully!!! Press any key to continue. . .";
    }
}

template <class T>
void Stack<T>::pop() {
	if (!isEmpty()) {
		T firstElement = *(arrElement + top);
		top--;
		cout << "\n\n\t\t\t\t\t\tStack's top's element after pop is: " << firstElement;
	}
	else {
		cout << "\n\n\t\t\t\t      Can't pop. Stack is empty! Press any key to continue. . .";
	}
}

template <class T>
int Stack<T>::getSize() {
	return size;
}

template <class T>
int Stack<T>::getTop() {
    if(!isEmpty()) {
        return *(arrElement + top);
    }
	else {
		return NULL;
	}
}

template <class T>
Stack<T>::~Stack() {
    delete []arrElement;
}

