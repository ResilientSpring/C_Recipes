#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {

	const char* name;

	struct Node* next;

};

typedef struct Node Node;

typedef enum {a1, b1, c1, d1} Selection;

void display(Node* node);

int main() {

	Node* start;
	Node* provisional;

	Selection selection;

	bool toggle = true; 

	do
	{



	} while (toggle);

	
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