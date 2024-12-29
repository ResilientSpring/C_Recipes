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

}