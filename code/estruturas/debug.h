// Header de utilidade para printar informações de debug

#ifdef DEBUG
#include <stdio.h>
#define LOGF(...) printf(__VA_ARGS__)
#else
#define LOGF(...)
#endif