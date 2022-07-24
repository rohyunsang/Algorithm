#include <iostream>

typedef struct LinkedListStack {
	int data;
	struct LinkedListStack* next;
} Stack;

int IsEmptyStack(Stack* Top)
{
	return (Top == NULL);
}

void push(Stack** Top, int data) {
	Stack* newNode = NULL;

	newNode = (Stack*)malloc(sizeof(Stack));
	if (newNode == NULL)
	{
		std::cout << "Stack is full" << std::endl;
		return;
	}

	newNode->data = data;
	newNode->next = *Top;
	*Top = newNode;

	std::cout << data << "pushed to stack" << std::endl;
}

int pop(Stack** Top) {
	Stack* temp = NULL;
	int data = 0;
	if (IsEmptyStack(*Top)) {
		std::cout << "Stack is Empty";
		return INT_MIN;
	}
	else {
		temp = *Top;
		*Top = temp->next;
		data = temp->data;
		free(temp);
	}
	return data;
}

/*void printStack(Stack** Top) {

}
*/
int main(void) {
	Stack* S = NULL;
	push(&S, 1);
	push(&S, 2);
	push(&S, 3);
	push(&S, 4);
	push(&S, 5);

	std::cout << pop(&S) << "popped from stack" << std::endl;
	std::cout << pop(&S) << "popped from stack" << std::endl;

	//printStack(&S);
}