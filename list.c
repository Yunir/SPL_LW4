#include <stdlib.h>
#include <malloc.h>
#include "list.h"

struct node readNumbers(struct node **head_ref) {
	int nextNumber;
    while(scanf("%d", &nextNumber) == 1) {
		if(nextNumber == 0) break;
		pushNode(nextNumber, head_ref);
    }
}

void pushNode(int new_data, struct node **head_ref) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->value = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct node *head) {
	struct node *temp = head;
    while(temp != NULL) {
        printf("%d  ", temp->value);
        temp = temp->next;
    }
	printf("\n");
}

int sumOfList(struct node *head) {
	int result = 0;
	struct node *temp = head;
	while (temp != NULL) {
		result += temp->value;
		temp = temp->next;
	}
	return result;
}

void findNode(struct node *head) {
	int counter;
	struct node *temp = head;
	if(scanf("%d", &counter) == 1) {
		while (temp != NULL) {
			if(counter == 0) {
				printf("The value of that index: %d\n", temp->value);
				break;
			}
			temp = temp->next;
			--counter;
		}
		if(counter < 0 || temp == NULL) {
			printf("Sorry, but linked list don't have such index\n");
		}
	} else {
		printf("You write not an integer number\n");
	}
}

void freeMemory(struct node *head) {
	struct node *temp = head;
	while (temp != NULL) {
		free(temp);
		temp = temp->next;
	}
}
