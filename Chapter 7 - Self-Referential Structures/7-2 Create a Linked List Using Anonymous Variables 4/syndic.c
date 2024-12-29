#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	char* name;

	Node* next;

} Start, Node;

void display(Node* node);

int main() {

	Node* start;

	start->name = "Sherry";
	start->next = (Node*)malloc(sizeof(Node));

	start->next->name = "Peter";
	start->next->next = (Node*)malloc(sizeof(Node));

	start->next->next->name = "Jimmy";
	start->next->next->next = (Node*)malloc(sizeof(Node));

	start->next->next->next->name = "Tim";
	start->next->next->next->next = NULL;



}

void display(Node* node) {

	int flag = 1;

	do
	{
		printf("Node's name is: %s.\n", node->name);

		node = node->next;

		if (node->next == NULL) {
			flag = 0;
		}

	} while (flag == 1);

}