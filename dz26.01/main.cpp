#include "LList.h"

int main() {
    LinkedList<int> myList;

    myList.AddToHead(1);
    myList.AddToTail(2);
    myList.AddToTail(3);

    myList.Show();

    myList.InsertAtPosition(4, 1); 
    myList.Show();

    myList.DeleteAtPosition(2); 
    myList.Show();

    int position = myList.Find(2); 
    cout << "Position of 2: " << position << endl;

    int replaceCount = myList.Replace(2, 5); 
    cout << "Replaced " << replaceCount << " occurrences of 2 with 5." << endl;
    myList.Show();

    myList.Reverse();\
    myList.Show();

    myList.DeleteAll();

    return 0;
}