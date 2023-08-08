#include "GenUtils.h"
#include <error.h>

void *smalloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        // failed allocation. . .
        error(EXIT_FAILURE, -1, "Failed to allocate memory!");
        return NULL;
    }

    return ptr;
}
