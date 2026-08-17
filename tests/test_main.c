#include <stdio.h>
#include <assert.h>
#include "avector.h"

void test_avector_push_back() {
    vector* vec = avec_new(sizeof(int), 2);
    assert(vec != NULL);

    int a = 10, b = 20, c = 30;
    avec_push_back(vec, &a);
    avec_push_back(vec, &b);

    assert(avec_size(vec) == 2);
    assert(avec_capacity(vec) == 2);

    avec_push_back(vec, &c);
    assert(avec_size(vec) == 3);
    assert(avec_capacity(vec) == 4);

    avec_free(vec);
    printf("[OK] test_avector_push_back\n");
}

int main() {
    test_avector_push_back();

    printf("\nAll tests passed successfully\n");
    return 0;
}
