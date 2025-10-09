#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define QUEUE_SIZE 5

int front = -1;
int rear = -1;
int queue[QUEUE_SIZE];


int is_full() {
	return front == (rear + 1) % QUEUE_SIZE;
}

int is_empty() {
	return front == -1;
}


void enqueue(int data) {
	if (is_full()) {
		fprintf(stderr, "queue is full\n");
		return;
	}

	if (is_empty()) {
		front = rear = 0;
	} else {
		rear = (rear + 1) % QUEUE_SIZE;
	}
	queue[rear] = data;
}


int dequeue() {
	if (is_empty()) {
		fprintf(stderr, "empty queue\n");
		return -1;
	}

	int data = queue[front];
	queue[front] = 0;
	if (front == rear) {
		front = rear = -1;
	} else {
		front = (front + 1) % QUEUE_SIZE;
	}
	return data;
}



void display() {
	while (front != -1) {
		printf("%d ", dequeue());
	}

	printf("\n");
}


int main() {


	enqueue(12);
	enqueue(54);
	enqueue(65);

	display();

}
