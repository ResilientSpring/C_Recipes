#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {

	const char* name;

	struct Node* next;

};

typedef struct Node Node;

void display(Node* node);
int menu(void);

int main() {

	Node* start;
	Node* provisional;

	int selection;

	do
	{
		selection = menu();

		switch (selection)
		{
		case 1:
			start = (Node*) malloc(sizeof(Node));
			provisional = start;

		default:
			break;
		}


	} while (selection != 4);


}

void display(Node* node) {

	int flag = 1;

	do
	{
		printf("Node's name is: %s.\n", node->name);



		if (node->next == NULL) {
			flag = 0;
		}

		node = node->next; // Moved this statement after if(node->next == NULL)

	} while (flag == 1);

}

int menu(void) {

	int selection;

	do
	{
		printf("\nSelect the desired operation:\n");
		printf("Enter 1 to create a linked list. \n");
		printf("Enter 2 to insert a node in linked list.\n");
		printf("Enter 3 to delete a node from linked list.\n");
		printf("Enter 4 to end the session.\n");

		printf("\nNow enter a number(1, 2, 3, or 4): ");
		scanf("%d", &selection);

	} while ((selection < 1) || (selection > 4));

}