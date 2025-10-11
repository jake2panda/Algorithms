#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct Node {
	int id;
	struct Node *next;
	struct Node *prev;
}Node;


Node *create_node(int id) {
	Node *new_node = calloc(1, sizeof(Node));
	if (!new_node) {
		perror("calloc new_node");
		return NULL;
	}

	new_node->id = id;
	new_node->next = new_node->prev = NULL;

	return new_node;
}


int has_duplicate(Node *head, int id) {
	Node *curr = head;
	while(curr) {
		if (curr->id == id) {
			return 1;
		}
		curr = curr->next;
	}

	return 0;
}



void front_insert(Node **head, int id) {

	if (has_duplicate(*head, id)) {
		fprintf(stderr, "[!] Sorry id : %d already exist\n", id);
		return;
	}

	Node *new_kid = create_node(id);
	if (!new_kid) {
		fprintf(stderr, "new_child error\n");
		return;
	}

	if (!*head) {
		*head = new_kid;
		return;
	}

	new_kid->next = (*head);
	(*head)->prev = new_kid;
	*head = new_kid;

}


void between_insert(Node **head, int first, int second, int id) {

	if (has_duplicate(*head, id)) {
		fprintf(stderr, "[!] Sorry id : %d already exist\n", id);
		return;
	}

	if (!*head) {
		*head = create_node(id);
		return;
	}

	Node *curr = *head;
	Node *prev = NULL, *next = NULL;

	while (curr && curr->next) {
		if (curr->id == first && curr->next->id == second) {
			Node *new_kid = create_node(id);
			if (!new_kid) {
				fprintf(stderr, "new kid problem\n");
				return;
			}
			prev = curr;
			next = curr->next;
			prev->next = new_kid;
			new_kid->prev = prev;
			new_kid->next = next;
			next->prev = new_kid;
			return;
		}

		curr = curr->next;
	}

	fprintf(stderr, "[!] sorry no adjacency found\n");
}


void end_insert(Node **head, int id) {
	if (has_duplicate(*head, id)) {
		fprintf(stderr, "[!] Sorry id : %d already exist\n", id);
		return;
	}

	Node *new_kid = create_node(id);
	if (!new_kid) {
		fprintf(stderr, "new_kid issue\n");
		return;
	}

	if (!*head) {
		*head = new_kid;
		return;
	}

	Node *curr = *head;
	Node *tmp = NULL;
	while (curr != NULL) {
		tmp = curr;
		curr = curr->next;
	}

	new_kid->prev = tmp;
	tmp->next = new_kid;

}

void reverse_doubly_linked_list(Node **head) {
	if (!head || !*head) {
		fprintf(stderr, "list does not exist\n");
		return;
	}

	Node *curr = *head;
	Node *next_node = NULL, *prev_node = NULL;

	while (curr) {
		next_node = curr->next;
		curr->next = prev_node;
		curr->prev = next_node;
		prev_node = curr;
		curr = next_node;
	}

	*head = prev_node;
}


void delete_node(Node **head, int id) {
	Node *curr = *head;
	Node *prev_node = NULL, *next_node = NULL, *tmp = NULL;

	while(curr) {
		if (curr->id == id) {
			if (curr->prev && curr->next) {
				prev_node = curr->prev;
				next_node = curr->next;
				prev_node->next = next_node;
				next_node->prev = prev_node;
			} else if (!curr->prev && curr->next) {
				next_node = curr->next;
				*head = next_node;
				next_node->prev = NULL;
			} else if (!curr->next && curr->prev) {
				prev_node = curr->prev;
				prev_node->next = NULL;
			} else {
				// in case of one node
				*head = NULL;
			}
			tmp = curr;
			break;
		}
		curr = curr->next;
	}

	free(tmp);

}


void show_nodes(Node *head) {
	Node *curr = head;
	while (curr) {
		printf("<- [ %d ] ->", curr->id);
		curr = curr->next;
	}

	printf("\n");
}


void free_nodes(Node **head) {
	Node *curr = *head;
	Node *tmp = NULL;
	while(curr) {
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}

	*head = NULL;
}


int main() {

	Node *head = create_node(12);

	front_insert(&head, 43);
	front_insert(&head, 54);

	end_insert(&head, 87);
	end_insert(&head, 90);

	between_insert(&head, 54, 43, 77);
	between_insert(&head, 54, 12, 19);
	end_insert(&head, 87);

	show_nodes(head);
	delete_node(&head, 90);
	show_nodes(head);
	reverse_doubly_linked_list(&head);
	show_nodes(head);





	free_nodes(&head);
}
