#include <stdlib.h>
#include <stdio.h>

#include "doubly_linked_list.h"

int main(int argc, char const *argv[])
{
    dlist list = NULL;
	dnode *head = NULL;
	int var = 999;
	printf("Doubly Linked List assignment:\n");
	printf("Operations available:\n");
	printf(" 1: Create a list\n");
	printf(" 2: Traverse a list\n");
	printf(" 3: Append a list(insert at end)\n");
	printf(" 4: Count elements in a list\n");
	printf(" 5: Replace element in a list\n");
	printf(" 6: Insert node after existing node\n");
	printf(" 7: Insert node before existing node\n");
	printf(" 8: Insert at specific index\n");
	printf(" 9: Insert at head of list\n");
	printf("10: Remove existing node\n");
	printf("11: Cleanup list\n");
	printf(" 0: Exit from program\n");


	int size, number, element, ele1, ele2, x, index;

	while (var != 0) {
		printf("\nEnter operation: ");
		scanf("%d", &var);

		switch (var) {
			case 1:
				printf("Create a list\n");
				printf("Enter no. of elements in list: ");
				scanf("%d", &size);
				printf("Enter integers:\n");
				for (int i = 0; i < size; i++) {
					scanf("%d", &number);
					append_list(&list, number);
				}
				break;
			case 2:
				printf("Traverse a list\n");
				traverse(list);
				break;

			case 3:
				printf("Append a list(insert at end)\n");
				printf("Enter element to append: ");
				scanf("%d", &element);
				append_list(&list, element);
				printf("List after append: ");
				traverse(list);
				break;

			case 4:
				printf("Count elements in a list\n");
				x = count_list(list);
				printf("No of elements in list are: %d\n", x);
				break;

			case 5:
				printf("Replace element in a list\n");
				printf("Enter element in list: ");
				scanf("%d", &ele1);
				printf("Enter new element: ");
				scanf("%d", &ele2);
				replace_node(&list, ele1, ele2);
				printf("List after replacing element: ");
				traverse(list);
				break;
			case 6:
				printf("Insert node after existing node\n");
				printf("Enter element to insert: ");
				scanf("%d", &ele1);
				printf("Enter element in list to insert after: ");
				scanf("%d", &ele2);
				insert_after_data(&list, ele1, ele2);
				printf("List after inserting element: ");
				traverse(list);
				break;
			case 7:
				printf("Insert node before existing node\n");
				printf("Enter element to insert: ");
				scanf("%d", &ele1);
				printf("Enter element of list to insert before:");
				scanf("%d", &ele2);
				insert_before_data(&list, ele1, ele2);
				printf("List after inserting element: ");
				traverse(list);
				break;
			case 8:
				printf("Insert at specific index\n");
				printf("Enter element to insert: ");
				scanf("%d", &element);
				printf("Enter index to insert: ");
				scanf("%d", &index);
				insert_at_index(&list, element, index);
				printf("List after inserting element: ");
				traverse(list);
				break;
			case 9:
				printf("Insert at head of list\n");
				printf("Enter element to insert: ");
				scanf("%d", &element);
				insert_at_head(&list, element);
				printf("List after inserting element: ");
				traverse(list);
				break;
			case 10:
				printf("Remove existing node\n");
				printf("Enter element to remove: ");
				scanf("%d", &element);
				remove_node(&list, element);
				printf("List after removing element: ");
				traverse(list);
				break;
			case 11:
				printf("Cleanup List\n");
				cleanup_list( &list );
				break;
		}

	}
	return 0;
    return 0;
}


dlist init_list( int size ) {
        dnode *head = NULL;
        dlist list = NULL;

        for (int i = 0; i < size; i++) {
                struct dnode *node = (dnode*)malloc(sizeof(dnode));
                if (head != NULL) {
                        node->data = 0;
                        node->prev = head;
                        node->next = NULL;

                        head->next = node;
                        head = node;

                } else {
                        node->data = 0;
                        node->next = NULL;
                        node->prev = NULL;

                        head = node;
                        list = head;
                }
        }
        return list;

}


/*  function returns number of nodes in the list */

int count_list(dlist list) {
	int count = 0;
	dnode *p = list;
	if (list != NULL) {
		do {
			count = count + 1;
			p = p->next;
		} while (p != NULL);
	}
	return count;
}


/*  function traversed the list and prints the data at each node */

void traverse(dnode *node){
	dnode *p = node;
    if( node == NULL ){
		printf("List is empty\n");
        return;
    }   
    do{ 
        printf("%d  ", p->data);
        p = p->next;
                    
    }while( p != NULL );
	printf("\n\n");
}


/* function searches the list and returns node containing the data 
 * return NULL if data not found*/

dnode *search_list(dlist list, int dat) {
        dnode *head = list;
        while ( head != NULL ) { 
                if (head->data == dat) 
                        break;
                head = head->next;
        }    
        return head;
}


/* replaces a node with data = list_data with data = replace_data */

void replace_node(dlist *list, int list_data, int replace_data) {
	dnode *node = *list;
	dnode *p = search_list(node, list_data);

	p->data = replace_data;
	return;
}

/*  function appends a node at the end with data = dat */

void append_list(dlist *list, int dat){
    dnode *nn = (dnode *)malloc(sizeof(dnode)); 
    nn->data =dat;

    if( *list == NULL ) { 
    	nn->next = NULL;
        nn->prev = NULL;
        *list = nn; 
	} else {
    	dnode *head= *list;
        while(head->next != NULL) {
        	head = head->next;
        }

        head->next= nn; 
        nn->prev= head;
	}
 
}


/* function inserts a node after a node with data = list_data
 * inserted node has data = insert_data */

void insert_after_data( dlist *list, int insert_data, int list_data ) {
	dnode *node = search_list(*list, list_data);
	if (node == NULL) {
		printf("node with data %d not found\n",list_data);
		return;
	}
	dnode *newnode = (dnode *)malloc(sizeof(dnode));
	newnode->data = insert_data;
	newnode->prev = node;
	if (node->next == NULL) {
		newnode->next = NULL;
		node->next = newnode;
	} else {
		dnode *p = node->next;

	    newnode->next = p;
	    node->next = newnode;
	    p->prev = newnode;
	    return;
	}
}


/* function inserts a node before node containing data = list_data */

void insert_before_data( dlist *list, int insert_data, int list_data ) {
	dnode *node = search_list(*list, list_data);
	if (node == NULL) {
		return;
	}
	
	dnode *newnode = (dnode *)malloc(sizeof(dnode));
	newnode->data = insert_data;
	newnode->next = node;
	
	if (node->prev == NULL) {
		newnode->prev = NULL;
		*list = newnode;
	} else {
	        dnode *p = node->prev;
	        newnode->prev = p;
		node->prev = newnode;
		p->next = newnode;
	        return;

	}
}


/* inserts new node at head, i.e. topmost position in list, 
 * with data = insert_data */

void insert_at_head( dlist *list, int insert_data ) {
	dnode *head = *list;

	dnode *newhead = (dnode *)malloc(sizeof(dnode));
	newhead->data = insert_data;
	newhead->prev = NULL;
	newhead->next = head;

	head->prev = newhead;
	*list = newhead;

}


/* inserts new node at specified index */

void insert_at_index( dlist *list, int insert_data, int index ) {
	int count = count_list(*list);
	if (count < index) {
		printf("Index out of bounds!\nRequested index is greater than length of list.\nFunction aborted!");
		return;
	} else if (count == index + 1) {
		append_list(list, insert_data);
	} else if ( index == 0 ) {
		/*  index 0 is head , hence call insert_at_head */
		insert_at_head( list, insert_data );
	} else {
		dnode *p = *list;
		for (int i = 1; i < index; i++) {
			p = p->next;
		}
		dnode *q = p->next;
		dnode *newnode = (dnode *)malloc(sizeof(dnode));
		
		newnode->data = insert_data;
		newnode->next = q;
		newnode->prev = p;

		p->next = newnode;
		q->prev = newnode;
	}
	
	return;
}


/* removes node containing data = dat */

void remove_node(dlist *list, int dat) {
	dnode *node = search_list(*list, dat);
	if( node != NULL ){
		dnode *p = node->prev;
		dnode *q = node->next;

		if( p != NULL ){
			p->next = q;
		}
		else {
			*list = q;
		}
		q->prev = p;
		free(node);
	}  
	else{
		printf(" node with data %d not found in list\n", dat);
	}
	return;
	
}


/*  function to cleanup all nodes in a list */

void cleanup_list( dlist *list ) {
	dnode *p = *list;
        if( p == NULL ){
                return;
        }   
        do{ 
		dnode *next_node= p->next;
		free( p );
                p = next_node;
        }while( p != NULL );
	*list = NULL;
}
