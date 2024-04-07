#include <stdio.h>
#include <stdlib.h>

//linked list are more dynamic than arrays with
//inserting and removing middle data points mid list
//no predefined initial size of list size
//however must always count from the first item onwards in the 'chain'
//so can get slow with big data
//linked chain looks like Head>Data>Pointer>Data>Pointer>Data>Pointer>Data>Null

typedef struct node {
	int data;
	struct node * pointer;
} node_chain;//node type name
//define list struct

void print_list(node_chain * head) {
	node_chain * current = head;

	while (current != NULL) {
		printf("%d\n", current->data);
		current = current->pointer;
	}
}

int pop_head(node_chain ** head) {
	int retval = -1;
	node_chain * next_node = NULL;

	if (*head == NULL) {
		return -1;
	}
	printf("popping off the head\n");
	next_node = (*head)->pointer;
	retval = (*head)->data;
	free(*head);
	*head = next_node;

	return retval;
}

int remove_last(node_chain * head) {
	int retval = 0;
	/* if only one item in the list, remove it */
	if (head->pointer == NULL) {
		retval = head->data;
		free(head);
		return retval;
	}

	/* get second to last node in the list */
	node_chain * current = head;
	while (current->pointer->pointer != NULL) {
		current = current->pointer;
	}

	/* current now points to the second to last item, so remove current->pointer */
	printf("removing tha last node\n");
	retval = current->pointer->data;
	free(current->pointer);
	current->pointer = NULL;
	return retval;

}

void push_last(node_chain * head, int data) {
	node_chain * current = head;
	while (current->pointer != NULL) {
		current = current->pointer;
	}

	/* now we can add a new variable */
	printf("pushing %d to the end\n", data);
	current->pointer = (node_chain *) malloc(sizeof(node_chain));
	current->pointer->data = data;
	current->pointer->pointer = NULL;
}
void push_first(node_chain ** head, int data) {
	node_chain * new_node;
	new_node = (node_chain *) malloc(sizeof(node_chain));

	printf("adding %d  as the new head\n", data);
	new_node->data = data;
	new_node->pointer = *head;
	*head = new_node;
}

int remove_by_index(node_chain ** head, int n) {
	int i = 0;
	int retval = -1;
	node_chain * current = *head;
	node_chain * temp_node = NULL;

	if (n == 0) {
		return pop_head(head);
	}

	for (i = 0; i < n-1; i++) {
		if (current->pointer == NULL) {
			return -1;
		}
		current = current->pointer;
	}

	if (current->pointer == NULL) {
		return -1;
	}
	printf("removing index %d...\n", n);
	temp_node = current->pointer;
	retval = temp_node->data;
	current->pointer = temp_node->pointer;
	free(temp_node);

	return retval;

}

int remove_by_value(node_chain ** head, int data) {
	node_chain * current = *head;
	node_chain * temp_node = NULL;

	//initial check for head
	if (current->data==data) {
		return pop_head(head);
	}

	int retval = -1;
	while (current->pointer != NULL) {
		if (current->pointer->data==data){
			printf("removing reference to value %d...\n", current->pointer->data);
			temp_node = current->pointer;
			retval = temp_node->data;
			current->pointer = temp_node->pointer;
			free(temp_node);
			break;
			}
		current = current->pointer;
	}
	return retval;
}

int main() {

	node_chain * My_linked_list = (node_chain *) malloc(sizeof(node_chain));
	My_linked_list->data = 1;
	My_linked_list->pointer = (node_chain *) malloc(sizeof(node_chain));
	My_linked_list->pointer->data = 2;
	My_linked_list->pointer->pointer = (node_chain *) malloc(sizeof(node_chain));
	My_linked_list->pointer->pointer->data = 3;
	My_linked_list->pointer->pointer->pointer = (node_chain *) malloc(sizeof(node_chain));
	My_linked_list->pointer->pointer->pointer->data = 4;
	My_linked_list->pointer->pointer->pointer->pointer = NULL;

	print_list(My_linked_list);
	remove_by_value(&My_linked_list, 3);
	remove_by_index(&My_linked_list, 2);
	//index #2 is the new 3rd entry after removing 3rd VALUE

	push_first(&My_linked_list, 15);
	push_last(My_linked_list, 45);
	print_list(My_linked_list);

	remove_last(My_linked_list);
	pop_head(&My_linked_list);
	print_list(My_linked_list);
}
