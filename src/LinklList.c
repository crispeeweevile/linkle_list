#include "GenUtils.h"
#include "LinklList.h"

GenericError generic_add_item(LList *list, bool beforeCurrent);
GenericError generic_remove_item(LList *list, bool beforeCurrent);

LList *create_llist(Node *node) {
    if (!node) {return METHOD_FAILURE;}
    LList *nList = smalloc(sizeof(LList));

    nList->index = 0;
    nList->length = 1;
    nList->current = node;
    nList->head = node;
    nList->tail = node;

    return nList;
}

GenericError free_llist(LList *list, bool freeData) {
    return -1;
}

GenericError insert_at_tail(LList *list, Node *node) {
    if (!list || !node) {return -1;}
    generic_add_item(list, false);

    Node *oldTail = list->tail;
    oldTail->next = node;
    node->prev = oldTail;
    list->tail = node;

    return 0;
}

GenericError insert_at_head(LList *list, Node *node) {
    if (!list || !node) {return -1;}
    generic_add_item(list, true);

    Node *oldHead = list->head;
    oldHead->prev = node;
    node->next = oldHead;
    list->head = node;

    return 0;
}

Node *remove_tail(LList *list) {
    if (!list || !list->current || !list->tail) {return METHOD_FAILURE;}
    Node *curNode = list->current;
    Node *tailNode = list->tail;

    if (tailNode == curNode) {
        generic_remove_item(list, true);
        goto_prev(list);
    } else {generic_remove_item(list, false);}

    Node *tailPrev = tailNode->prev;
    if (!tailPrev) {return METHOD_FAILURE};
    tailPrev->next = NULL;
    tailNode->prev = NULL;
    list->tail = tailPrev;

    return tailNode;
}

Node *remove_head(LList *list) {
    if (!list || !list->current || !list->head) {return METHOD_FAILURE;}
    Node *curNode = list->current;
    Node *headNode = list->head;

    if (headNode == curNode) {
        generic_remove_item(list, false);
        goto_next(list);
    } else {generic_remove_item(list, true);}

    Node *headNext = headNode->next;
    if (!headNext) {return METHOD_FAILURE};
    headNext->prev = NULL;
    headNode->next = NULL;
    list->head = headNext;

    return headNode;
}



GenericError goto_next(LList  *list) {
    return -1;
}

GenericError goto_prev(LList *list) {
    return -1;
}

Node *get_next(LList *list) {
    return METHOD_FAILURE;
}

Node *get_prev(LList *list) {
    return METHOD_FAILURE;
}

GenericError generic_add_item(LList *list, bool beforeCurrent) {
    if (!list) {return -1;}
    if (beforeCurrent) {list->index++;}

    list->length++;
    return 0;
}

GenericError generic_remove_item(LList *list, bool beforeCurrent) {
    if (!list) {return -1;}
    if (beforeCurrent) {list->index--;}

    list->length--;
    return 0;
}
