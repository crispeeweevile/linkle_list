#include "Data.h"
#include "stdbool.h"

typedef struct Node Node;
struct Node {
    Data *data;
    Node *prev;
    Node *next;
};

Node *create_node(Data *data);
GenericError free_node(Node *node, bool freeData);


