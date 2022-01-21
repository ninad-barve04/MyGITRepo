typedef struct dnode{
		int data;
		struct dnode* next;
		struct dnode* prev;
}dnode;

typedef dnode* dlist;

dlist init_list( int size );
int count_list(dlist list);
void traverse(dnode *node);
dnode *search_list( dlist list, int dat );
void replace_node(dlist *list, int list_data, int replace_data);
void append_list(dlist *list, int dat);
void insert_after_data( dlist *list, int insert_data, int list_data );
void insert_before_data( dlist *list, int insert_data, int list_data );
void insert_at_index( dlist *list, int insert_data, int index );
void insert_at_head(dlist *list, int insert_data);
void remove_node(dlist *list, int dat);
void cleanup_list( dlist *list );