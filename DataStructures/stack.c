#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
	int top;
	int *stack_list;
	int capacity;
}Stack;


Stack *create_stack(int max_size) {
	Stack *new_stack = calloc(1, sizeof(Stack));
	if (!new_stack) {
		perror("calloc");
		return NULL;
	}
	new_stack->top = -1;
	new_stack->stack_list = calloc(max_size, sizeof(int));
	if (new_stack->stack_list == NULL) {
		perror("stack_list calloc");
		return NULL;
	}

	new_stack->capacity = max_size;

	return new_stack;
}



int is_full(Stack *stack) {
	if (stack->top == stack->capacity -1) {
		return 1;
	} else {
		return 0;
	}
}



void push_value(Stack *stack, int data) {
	int *stack_list = stack->stack_list;
	if (is_full(stack)) {
		fprintf(stderr, "sorry stack is full\n");
		return;
	}

	stack->top++;
	stack_list[stack->top] = data;
}


int is_empty(Stack *stack) {
	if (stack->top == -1) {
		return 1;
	} else {
		return 0;
	}
}


int pop_value(Stack *stack) {
	if (is_empty(stack)) {
		printf("sorry stack is empty\n");
		return -1;
	}

	int data = stack->stack_list[stack->top];
	stack->top--;
	return data;
}


void free_stack(Stack *stack) {
	if (!stack) return;
	free(stack->stack_list);
	free(stack);
}



int main() {



	Stack *st = create_stack(5);

	push_value(st, 12);
	push_value(st, 42);
	// push_value(st, 45);
	// push_value(st, 50);
	// push_value(st, 54);

	display_stack(st);


	// printf("pop : %d\n", pop_value(st));
	// printf("pop : %d\n", pop_value(st));

	free_stack(st);


}