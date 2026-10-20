#ifndef SHIM_STDIO_H
#define SHIM_STDIO_H
#define NULL ((void*)0)
#define EOF (-1)
int printf(const char *fmt, ...);
int scanf(const char *fmt, ...);
int getchar(void);
int putchar(int c);
int puts(const char *s);
#endif
