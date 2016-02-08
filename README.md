
## NOTE

### The macro PTHREAD_MUTEX_INITIALIZER cannot fail to initialize static mutex

The Posix standard says that PTHREAD_MUTEX_INITIALIZER is sufficient initialization, and that it cannot fail (because it can be used to initialize static variables in C, which is compile time initialization). A pthread_mutex_t initialized with PTHREAD_MUTEX_INITIALIZE is sufficiently initialized for all of the functions which use the pthread_mutex_t to have defined behavior, as if the mutex had been initialized with all default values. Beyond that, you should always verify that the other functions worked as well, regardless of how the mutex was initialized. –  James Kanze Apr 29 '14 at 9:06