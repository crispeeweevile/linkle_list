#include "ErrorSys.h"

typedef struct Data Data;
struct Data {
    int money;
    int items;
    int debt;
};

Data *create_data(int money, int items, int debt);
GenericError free_data(Data *data);
