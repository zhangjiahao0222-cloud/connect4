/* Minimal C library for running the game in the browser.
   Output goes to js_write, input comes from js_getc (which stops the
   program while it waits for the player to type). */
#include <stdarg.h>
#include "stdio.h"
__attribute__((import_module("env"), import_name("js_write"))) void js_write(const char *p, int n);
__attribute__((import_module("env"), import_name("js_getc"))) int js_getc(void);
__attribute__((import_module("env"), import_name("js_exit"))) void js_exit(int code);
static char out[512]; static int on = 0;
static void flush(void) { if (on) { js_write(out, on); on = 0; } }
static void put(char c) { if (on == (int)sizeof(out)) flush(); out[on++] = c; }
static int peeked = -2;
static int nextc(void) { if (peeked != -2) { int c = peeked; peeked = -2; return c; } flush(); return js_getc(); }
static void unget(int c) { peeked = c; }
int getchar(void) { return nextc(); }
int putchar(int c) { put((char)c); flush(); return c; }
int puts(const char *s) { while (*s) put(*s++); put('\n'); flush(); return 0; }
void exit(int code) { flush(); js_exit(code); for (;;) {} }
int strcmp(const char *a, const char *b) { while (*a && *a == *b) { a++; b++; } return (unsigned char)*a - (unsigned char)*b; }
char *strcpy(char *d, const char *s) { char *r = d; while ((*d++ = *s++)) {} return r; }
void *memset(void *d, int c, unsigned long n) { unsigned char *p = d; while (n--) *p++ = (unsigned char)c; return d; }
void *memcpy(void *d, const void *s, unsigned long n) { unsigned char *p = d; const unsigned char *q = s; while (n--) *p++ = *q++; return d; }
static void pad(int n) { while (n-- > 0) put(' '); }
static int slen(const char *s) { int n = 0; while (s[n]) n++; return n; }
int printf(const char *f, ...) {
  va_list a; va_start(a, f);
  for (; *f; f++) {
    if (*f != '%') { put(*f); continue; }
    f++; int left = 0, w = 0;
    if (*f == '-') { left = 1; f++; }
    while (*f >= '0' && *f <= '9') w = w * 10 + (*f++ - '0');
    char buf[16]; const char *s = buf; int n = 0;
    if (*f == 'd') { int v = va_arg(a, int); unsigned u = v < 0 ? -(unsigned)v : (unsigned)v; char t[12]; int k = 0;
      do { t[k++] = '0' + u % 10; u /= 10; } while (u); if (v < 0) buf[n++] = '-'; while (k) buf[n++] = t[--k]; buf[n] = 0; }
    else if (*f == 'c') { buf[0] = (char)va_arg(a, int); buf[1] = 0; n = 1; }
    else if (*f == 's') { s = va_arg(a, const char *); n = slen(s); }
    else { buf[0] = *f; buf[1] = 0; n = 1; }
    if (!left) pad(w - n);
    for (int i = 0; i < n; i++) put(s[i]);
    if (left) pad(w - n);
  }
  va_end(a); flush(); return 0;
}
static int isspace_(int c) { return c == ' ' || c == '\n' || c == '\t' || c == '\r'; }
/* supports "%d" and "%Ns", the two formats the game uses */
int scanf(const char *f, ...) {
  va_list a; va_start(a, f); int got = 0;
  for (; *f; f++) {
    if (*f != '%') continue;
    f++; int w = 0; while (*f >= '0' && *f <= '9') w = w * 10 + (*f++ - '0');
    int c = nextc(); while (isspace_(c)) c = nextc();
    if (c == EOF) { va_end(a); return got ? got : EOF; }
    if (*f == 'd') {
      int neg = 0; if (c == '-' || c == '+') { neg = c == '-'; c = nextc(); }
      if (c < '0' || c > '9') { unget(c); va_end(a); return got; }
      long v = 0; while (c >= '0' && c <= '9') { if (v < 100000000L) v = v * 10 + (c - '0'); c = nextc(); }
      unget(c); *va_arg(a, int *) = neg ? -(int)v : (int)v; got++;
    } else if (*f == 's') {
      char *d = va_arg(a, char *); int n = 0; if (!w) w = 1 << 30;
      while (c != EOF && !isspace_(c) && n < w) { d[n++] = (char)c; c = nextc(); }
      d[n] = 0; unget(c); got++;
    }
  }
  va_end(a); return got;
}
