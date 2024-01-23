#include "LList.h"

int main() {
    LinkedList<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Original Stack:" << endl;
    stack.display();

    LinkedList<int> clonedStack = stack.clone();
    cout << "Cloned Stack:" << endl;
    clonedStack.display();

    LinkedList<int> combinedStack = stack + clonedStack;
    cout << "Combined Stack:" << endl;
    combinedStack.display();

    LinkedList<int> intersectedStack = stack * clonedStack;
    cout << "Intersected Stack:" << endl;
    intersectedStack.display();

    return 0;
}