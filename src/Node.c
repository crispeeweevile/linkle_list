#include "Node.h"
#include "GenUtils.h"

Node *create_node(Data *data) {
    if (!data) {return NULL;}
    Node *nNode = smalloc(sizeof(Node));

    nNode->data = data;
    nNode->next = NULL;
    nNode->prev = NULL;

    return nNode;
}

int free_node (Node *node, bool freeData) {
    if (!node) {return -1;}
    if (freeData) {
        if (!node->data) {return -2;}
        free_data(node->data);
    }

    node->data = NULL;
    node->next = NULL;
    node->prev = NULL;
    free(node);
    
    return 0;
}
