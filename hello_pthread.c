/*a multi-thread to print hello world program*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM 5

void *print_msg(void *);

int main()
{
    pthread_t t1, t2;
    /* Before returning, a successful call to pthread_create() stores  the  ID
     * of  the  new thread in the buffer pointed to by &t1 and &t2; this identifier
     * is used to refer to the thread in subsequent calls  to  other  pthreads
     * functions. 
     */
    pthread_create(&t1, NULL, print_msg, (void *)"hello");
    pthread_create(&t2, NULL, print_msg, (void *)"world\n");
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}

void *print_msg(void *msg)
{
    char *cp = (char *)msg;
    int i;
    for (i = 0; i < NUM; i++) {
        printf("%s",cp);
        fflush(stdout);
        sleep(1);
    }
    return NULL;
}
