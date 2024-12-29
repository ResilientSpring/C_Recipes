/* This program implements a simple linear linked list. */

/* Function malloc() is used to create the components of list. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct members {

	char name[20];
	struct members* next;

};

typedef struct members node;

void display(node* start);

main() {

	node* start;

	start = (node*) malloc(sizeof(node));
	strcpy(start->name, "lina");
	start->next = (node*) malloc(sizeof(node));
	strcpy(start->next->name, "mina");
	start->next->next = (node*) malloc(sizeof(node));
	strcpy(start->next->next->name, "bina");
	start->next->next->next = (node*)malloc(sizeof(node));
	strcpy(start->next->next->next->name, "tina");
	start->next->next->next->next = NULL;

	printf("Names of all the members: \n");
	display(start);

}

void display(node* start) {

	int flag = 1;

	do
	{


	} while (flag);

}