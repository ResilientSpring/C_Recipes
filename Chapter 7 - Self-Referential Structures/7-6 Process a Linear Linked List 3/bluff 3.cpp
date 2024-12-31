#define _CRT_SECURE_NO_WARNINGS
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
void display(Node* start);

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

		if ((selection < 1) || (selection > 4))
			printf("Invalid Number! Please try again. \n");

	} while ((selection < 1) || (selection > 4));

	return selection;
}

void create(Node* start) {

	int flag = 1;

	char ch;

	printf("Enter name: ");

	do
	{
		scanf(" %[^\n]", start->name);

		printf("Anymore name? (y/n): ");
		scanf(" %c", &ch);

		if (ch == 'n') {
			flag = 0;
			start->next = NULL;
		}
		else {

			start->next = (Node*) malloc(sizeof(Node));
			start = start->next;
			printf("Enter name: ");
		}

	} while (flag);

}

void display(Node* start) {

	int flag = 1;

	if (start == NULL) {
		printf("\nList is empty! Select the option 1.\n");
		return;
	}

	printf("\nNames of all the members in the list: \n");

	do
	{
		printf("%s\n", start->next);

		if (start->next == NULL) {

			flag = 0;
		}

		start = start->next;

	} while (flag);
}