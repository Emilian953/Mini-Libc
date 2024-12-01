#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec sec = {seconds, 0};
    int err = nanosleep(&sec, NULL);
    return err;
}
