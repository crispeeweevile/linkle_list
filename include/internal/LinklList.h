#include "Node.h"

typedef struct LList LList;
struct LList {
    int index;
    int length;
    Node *current;
    Node *head;
    Node *tail;
};

LList *create_llist(Node *node);
GenericError free_llist(LList *list, bool freeData);
GenericError insert_at_tail(LList *list, Node *node);
GenericError insert_at_head(LList *list, Node *node);
Node *remove_tail(LList *list);
Node *remove_head(LList *list);

GenericError goto_next(LList  *list);
GenericError goto_prev(LList *list);
Node *get_next(LList *list);
Node *get_prev(LList *list);
