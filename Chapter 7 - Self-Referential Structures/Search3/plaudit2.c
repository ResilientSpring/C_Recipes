#define _CRT_SECURE_NO_WARNINGS
// #define _NO_CRT_STDIO_INLINE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {

	// const char* name;    To avoid scanf("%[^\n]", start->name); overflow.

	char name[20];

	struct Node* next;

};

typedef struct Node Node;

void display(Node* node);
int menu(void);
void create(Node* start);
Node* insert(Node* start);
Node* location(Node* start, char target[]);
Node* delete(Node* start);
Node* search(Node* start);

int main() {

	Node* start = 0;
	Node* provisional;

	int selection;

	do
	{
		selection = menu();

		switch (selection)
		{
		case 1:

			start = (Node*)malloc(sizeof(Node));
			provisional = start;
			create(start);
			start = provisional;
			display(start);
			continue;

		case 2:

			if (start == NULL) {

				printf("\nList is empty! Select the option 1.\n");

				continue;

			}

			start = insert(start);
			display(start);
			continue;

		case 3:

			if (start == NULL) {

				printf("\nList is empty! Select the option 1.\n");

				continue;

			}

			start = delete(start);
			display(start);
			continue;

		case 5:

			if (start == NULL) {

				printf("\nList is empty! Select the option 1.\n");

				continue;

			}

			start = search(start);
			display(start);
			continue;

		default:
			printf("\nEnd of session.\n");
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
		printf("Enter 5 to search for a node.\n");

		printf("\nNow enter a number(1, 2, 3, 4, or 5): ");
		scanf("%d", &selection);

		if ((selection < 1) || (selection > 5))
			printf("Invalid Number! Please try again. \n");

	} while ((selection < 1) || (selection > 5));

	return selection;
}

void create(Node* start) {

	int flag = 1;

	char ch;

	printf("Enter name: ");

	do
	{
		scanf(" %[^\n]", start->name);    // Left a blank in front of %.

		printf("Anymore name? (y/n): ");

		scanf(" %c", &ch); // Left a blank in front of %.

		if (ch == 'n') {
			flag = 0;
			start->next = NULL;
		}
		else {

			start->next = (Node*)malloc(sizeof(Node));
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
		printf("%s\n", start->name);

		if (start->next == NULL) {

			flag = 0;
		}

		start = start->next;

	} while (flag);
}

Node* insert(Node* start) {

	int flag = 1;
	Node* newNode;
	Node* before;
	Node* provisional;
	char newName[20];
	char target[20];

	printf("Enter name to be inserted: ");

	// Format specifier %[^\n] is used when scanf() is used to read a string, 
	// not character.
	scanf(" %[^\n]", newName);  // newName is the same as &newName[0]

	printf("Before which name to place? Type \"last\" if last: ");
	scanf(" %[^\n]", target);

	if (strcmp(target, "last") == 0) {

		provisional = start;

		do
		{
			start = start->next;

			if (start->next == NULL) {

				newNode = (Node*)malloc(sizeof(Node));

				strcpy(newNode->name, newName);

				start->next = newNode;

				newNode->next = NULL;

				flag = 0;
			}

		} while (flag);

		start = provisional;

		return start;
	}

	if (strcmp(start->name, target) == 0) {

		newNode = (Node*)malloc(sizeof(Node));
		strcpy(newNode->name, newName);
		newNode->next = start;
		start = newNode;
	}
	else {

		before = location(start, target);

		if (before == NULL) {
			printf("\nInvalid entry! Please try again\n");
		}
		else {
			newNode = (Node*)malloc(sizeof(Node));
			strcpy(newNode->name, newName);
			newNode->next = before->next;
			before->next = newNode;
		}
	}

	return start;
}

Node* location(Node* start, char target[]) {

	int flag = 1;

	if (strcmp(start->next->name, target) == 0)
		return start;
	else if (start->next == NULL)
		return NULL;
	else {
		do
		{
			start = start->next;

			if (strcmp(start->next->name, target) == 0)
				return(start);

			if (start->next == NULL) {

				flag = 0;

				printf("Invalid entry. Please try again.\n");
			}

		} while (flag);
	}

	return NULL;

}

Node* delete(Node* start) {

	Node* before;
	Node* provisional;
	char target[20];

	printf("\nEnter name to be deleted: ");
	scanf(" %[^\n]", target);

	if (strcmp(start->name, target) == 0)

		if (start->next == NULL) {
			free(start);
			start = NULL;
		}
		else {

			provisional = start->next;
			free(start);
			start = provisional;
		}
	else {

		before = location(start, target);

		if (before == NULL)
			printf("\nInvalid entry. Please try again.\n");
		else {

			provisional = before->next->next;
			free(before->next);
			before->next = provisional;

		}
	}
	return start;
}

Node* search(Node* start) {

	int flag = 1;
	int position = 0;
	char target[20];
	Node* start_at_first = start;

	printf("\nEnter name to search for: ");
	scanf(" %[^\n]", target);

	do
	{
		if (strcmp(start->name, target) == 0) {

			printf("%s is at position %d!\n", target, position);

		}

		if (start->next == NULL) {

			flag = 0;
		}

		start = start->next;

		position++;

	} while (flag);

	return start;
}