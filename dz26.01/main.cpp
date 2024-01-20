#include "LList.h"

int main() {
SetConsoleCP(1251);
SetConsoleOutputCP(1251);

    LinkedList<int> myList;

    myList.AddToHead(1);
    myList.AddToTail(2);
    myList.AddToTail(3);

    myList.Show();

    myList.DeleteFromHead();
    myList.Show();

    myList.DeleteFromTail();
    myList.Show();

    myList.DeleteAll();

    return 0;
}