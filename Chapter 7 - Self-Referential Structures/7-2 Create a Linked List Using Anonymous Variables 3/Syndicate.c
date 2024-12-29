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

}