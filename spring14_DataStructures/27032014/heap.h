#ifndef HEAP_H
#define HEAP_H

extern int i, size;
void insertheap(int *, int);
void printheap(int *);
void shuffleup(int *);
int deletemin(int *);
void shuffledown(int *);

#endif
