/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_linkedlist
*/

#ifndef MY_LINKEDLIST_H_
    #define MY_LINKEDLIST_H_

    #define GET_DATA(node, type) ((type *)(node_t *)(node)->data)

typedef struct node_t node_t;
struct node_t {
    void *data;
    node_t *next;
    node_t *prev;
};

node_t *create_node(void *data);
void append_node(node_t **head, node_t *node);
node_t *remove_node(node_t **head, node_t *node);
void delete_node(node_t **head, node_t *node);
void free_linked_list(node_t **head);
int my_listlen(node_t **head);

#endif /* !MY_LINKEDLIST_H_ */
