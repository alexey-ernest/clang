#ifndef SWAP
#define SWAP(t, x, y) { \
t tmp; \
tmp = x; \
x = y; \
y = tmp; \
}
#endif