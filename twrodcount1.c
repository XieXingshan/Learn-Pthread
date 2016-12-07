/* two threads count word for two files. Version1  */

#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#include <stdlib.h>

void *count_words(void *);

int total_words = 0;

int main(int argc, char **argv)
{
    pthread_t t1, t2;
    if (argc != 3) {
        printf("usage: %s file1 file2\n", argv[0]);
        exit(1);
    }
    pthread_create(&t1, NULL, count_words, (void *)argv[1]);
    pthread_create(&t2, NULL, count_words, (void *)argv[2]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("%5d: total words\n", total_words);
    return 0;
}

void *count_words(void *file)
{
    char *filename = (char *)file;
    FILE *fp;
    int nextc, prevc = '\0';

    if ((fp = fopen(filename, "r")) != NULL) {
        while ((nextc = getc(fp)) != EOF) {
            if (!isalnum(nextc) && isalnum(prevc))
                total_words++;
            prevc = nextc;
        }
        fclose(fp);
    } else
        perror(filename);
    return NULL;
}
