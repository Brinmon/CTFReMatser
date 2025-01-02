#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/base64.h"

int main() {
    const char *data = "Hello, World!";
    char *encoded = base64_encode(data);
    printf("Encoded: %s\n", encoded);

    char *decoded = base64_decode(encoded);
    printf("Decoded: %s\n", decoded);

    free(encoded);
    free(decoded);
    return 0;
}

