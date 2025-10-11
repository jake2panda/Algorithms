#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Node {
	int id;
	struct Node *next;
}Node;


Node *create_node(int key) {
	Node *new_node = calloc(1, sizeof(Node));
	if (!new_node) {
		perror("new_node calloc");
		return NULL;
	}
	new_node->id = key;
	new_node->next = NULL;

	return new_node;
}


void insert_front(Node **head, int key) {
	if (!*head) {
		fprintf(stderr, "head is null assigning new node to head\n");
		*head = create_node(key);
		return;
	}


	Node *child_node = create_node(key);
	if (!child_node) {
		fprintf(stderr, "child node issue\n");
		return;
	}

	child_node->next = *head;
	*head = child_node;

}



void between_insert(Node **head, int first, int second, int key) {
	Node *curr = *head;
	while (curr && curr->next) {
		if (curr->id == first && curr->next->id == second) {
			Node *new_one = create_node(key);
			if (!new_one) {
				fprintf(stderr, "new_one calloc\n");
				return;
			}
			new_one->next = curr->next;
			curr->next = new_one;
			return;
		}

		curr = curr->next;
	}

	fprintf(stderr, "no matching adjacent found\n");
}


void insert_end(Node **head, int key) {

	Node *new_one = create_node(key);
	if (!new_one) {
		fprintf(stderr, "unexpected error\n");
		return;
	}

	if (!*head) {
		*head = new_one;
		return;
	}
	Node *curr = *head;

	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next =new_one;

}




void reverse_list(Node **head) {
	if (!*head) {
		printf("head null\n");
		return;
	}

	Node *curr = *head;
	Node *next_one;
	Node *prev = NULL;

	while (curr != NULL) {
		next_one = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next_one;
	}

	*head = prev;

}


void show_nodes(Node *head) {

	Node *curr = head;

	while(curr != NULL) {
		printf("[ %d ] -> ", curr->id);
		curr = curr->next;
	}

	printf("\n");
}



void free_nodes(Node *head) {

	Node *curr = head;
	Node *tmp;
	while (curr) {
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}


int main() {

	Node *head = create_node(12);
	insert_front(&head, 98);
	insert_front(&head, 43);
	insert_front(&head, 38);
	insert_front(&head, 54);
	insert_front(&head, 98);

	insert_end(&head, 32);
	insert_end(&head, 76);
	insert_end(&head, 77);

	between_insert(&head, 38, 43, 455);
	between_insert(&head, 455, 43, 120);

	insert_front(&head, 76);

	insert_end(&head, 57);



	show_nodes(head);

	free_nodes(head);




	return 0;






}