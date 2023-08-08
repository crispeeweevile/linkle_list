#include "Data.h"
#include "GenUtils.h"

Data *create_data(int money, int items, int debt) {
    Data *nData = smalloc(sizeof(Data));
    nData->money = money;
    nData->items = items;
    nData->debt = debt;

    return nData;
}

int free_data(Data *data) {
    if (!data) {return -1;}

    free(data);
    return 0;
}
