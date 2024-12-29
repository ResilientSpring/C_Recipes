#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	char* name;

	Node* next;

} Start, Node;


int main() {

	Node start;

	start.name = "Sherry";
	start.next = (Node*) malloc(sizeof(Node));

	start.next->name = "Peter";
	start.next->next = (Node*) malloc(sizeof(Node));

	start.next->next->name = "Jimmy";
	start.next->next->next = (Node*) malloc(sizeof(Node));

	start.next->next->next->name = "Tim";
	start.next->next->next->next = NULL;



}

void display(Node node) {

	int flag = 1;

	do
	{
		printf("Node's name is: %s.\n", node.name);

		node = node.next;

	} while (flag == 1);

}