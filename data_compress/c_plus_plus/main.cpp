#include <iostream>

#include "huffman_code.h"


int main() {
    const char *str = "this is an example for huffman encoding";
    char buf[1024];

    init(str);
    for (int i = 0; i < 128; i++)
        if (code[i]) printf("'%c': %s\n", i, code[i]);

    encode(str, buf);
    printf("encoded: %s\n", buf);

    printf("decoded: ");
    decode(buf, q[1]);

    return 0;
}