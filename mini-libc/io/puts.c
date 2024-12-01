#include <stdio.h>
#include <internal/io.h>
#include <string.h>

int puts(const char *p) {
    long len = strlen(p);
    int err = write(1, p, len);
    if (err < 0) {
        return -1;
    }
    int err1 = write(1, "\n", 1);
    if (err1 < 0) {
        return -1;
    }
    return 0;
}
