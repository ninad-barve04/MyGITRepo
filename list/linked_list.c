#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

void init_list(List *list) {
    *list = NULL;
}

int count_list(List list) {
    int count = 0;
    node *p = list;
    if (list != NULL) {
        do {
            count = count + 1;
            p = p->next;
        } while (p != NULL);
    }
    return count;
}

void traverse(List list) {
    node *p = list;
    if (p == NULL) {
        printf("List is empty!\n");
        return;
    }
    do {
        printf("%d ==> ", p->data);
        p = p->next;

    } while (p != NULL);
    printf("NULL\n");
    printf("\n");
    return;
}

node *search_list(List list, int dat) {
    node *snode = list;
    while (snode != NULL && snode->data != dat) {
        snode = snode->next;
    }
    return snode;
}

void append_list(List *list, int dat) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = dat;
    newnode->next = NULL;

    if (*list == NULL) {
        *list = newnode;
    } else {
        node *p = *list;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newnode;
    }
    return;
}

void replace_node(List *list, int list_data, int replace_data) {
    node *nnode = *list;
    node *listdata = search_list(nnode, list_data);

    listdata->data = replace_data;
}

void insert_after_data(List *list, int list_data, int insert_data) {
    node *snode = search_list(*list, list_data);
    if (snode == NULL) {
        printf("Node not found!\n");
        return;
    }
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = insert_data;
    newnode->next = NULL;
    if (snode->next == NULL) {
        snode->next = newnode;
    } else {
        node *p = snode->next;
        newnode->next = p;
        snode->next = newnode;
    }
    return;
}

void insert_before_data(List *list, int list_data, int insert_data) {
    node *snode = search_list(*list, list_data);
    if (snode == NULL) {
        printf("Node not found!\n");
        return;
    }
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = insert_data;
    newnode->next = snode;
    node *p = *list;
    while (p->next != snode) {
        p = p->next;
    }
    p->next = newnode;
    return;
}

void insert_at_head(List *list, int insert_data) {
    node *head = *list;
    node *newhead = (node *)malloc(sizeof(node));
    newhead->data = insert_data;
    newhead->next = head;
    
    *list = newhead;

}

void insert_at_index(List *list, int insert_data, int index) {
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
		node *p = *list;
		for (int i = 1; i < index; i++) {
			p = p->next;
		}
		node *q = p->next;
		node *newnode = (node *)malloc(sizeof(node));
		
		newnode->data = insert_data;
		newnode->next = q;

		p->next = newnode;
	}
	
	return;
}

void remove_node(List *list, int dat) {
	node *snode = search_list(*list, dat);
	if (snode != NULL) {
        node *p = *list;
        while (p->next != snode) {
            p = p->next;
        }

		p->next = snode->next;
		free(snode);
	}  
	else{
		printf(" node with data %d not found in list\n", dat);
	}
	return;
	
}


int main(int argc, char const *argv[])
{
    List list;
    init_list(&list);
    for (int i = 1; i < 16; i++) {
        append_list(&list, i);
    }
    traverse(list);
    node *x = search_list(list, 12);
    printf("%d\n", x->data);

    insert_at_index(&list, 123, 5);

    insert_before_data(&list, 3, 45);
    insert_after_data(&list, 3, 41);
    insert_at_head(&list, 100);


    traverse(list);

    remove_node(&list, 123);
    traverse(list);
    

    return 0;
}


