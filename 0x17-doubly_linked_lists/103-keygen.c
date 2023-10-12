#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_largest_char(char *username, int length) {
    char largest_char = *username;
    int i;

    for (i = 0; i < length; i++) {
        if (largest_char < username[i]) {
            largest_char = username[i];
        }
    }

    srand(largest_char ^ 14);
    return rand() & 63;
}

int square_sum(char *username, int length) {
    int sum = 0;
    int i;

    for (i = 0; i < length; i++) {
        sum += username[i] * username[i];
    }

    return (unsigned int)(sum ^ 239) & 63;
}

int generate_random_char(char *username) {
    int num = *username;
    int i;

    for (i = 0; i < *username; i++) {
        num = rand();
    }

    return (unsigned int)(num ^ 229) & 63;
}

int main(int argc, char **argv) {
    char keygen[7];
    int len,ch;
    long alph[] = {
        0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
        0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
        0x723161513346655A, 0x6b756f494b646850
    };
    
    (void) argc;
    
    for (len = 0; argv[1][len]; len++);
    
    keygen[0] = ((char *)alph)[(len ^ 59) & 63];
    keygen[1] = ((char *)alph)[(square_sum(argv[1], len) ^ 79) & 63];
    keygen[2] = ((char *)alph)[(square_sum(argv[1], len) ^ 85) & 63];
    keygen[3] = ((char *)alph)[find_largest_char(argv[1], len)];
    keygen[4] = ((char *)alph)[square_sum(argv[1], len)];
    keygen[5] = ((char *)alph)[generate_random_char(argv[1])];
    keygen[6] = '\0';
    
    for (ch = 0; keygen[ch]; ch++) {
        printf("%c", keygen[ch]);
    }
    
    return 0;
}
