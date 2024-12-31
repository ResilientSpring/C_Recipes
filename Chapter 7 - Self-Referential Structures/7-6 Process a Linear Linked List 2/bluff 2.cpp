#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {

	const char* name;

	struct Node* next;

};

typedef struct Node Node;

void display(Node* node);

int main() {

	Node* start;
	Node* provisional;


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