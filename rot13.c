#include <stdio.h>
#define UPPER_START 65
#define UPPER_END 90
#define LOWER_START 97
#define LOWER_END 122

char encodeChar(char letter) {
    if (letter >= UPPER_START && letter <= UPPER_END) {
        return (letter - UPPER_START + 13) % 26 + UPPER_START;
    } else if (letter >= LOWER_START && letter <= LOWER_END) {
        return (letter - LOWER_START + 13) % 26 + LOWER_START;
    }
    return letter; 
}

int main() {
    int i;
    char pt[256], ct[256];
    printf("Enter message to be encrypted/decrypted (max 256 chars): ");
    fgets(pt, sizeof(pt), stdin);
    for (i = 0; pt[i] != '\0' && pt[i] != '\n'; i++) ct[i] = encodeChar(pt[i]);
    ct[i] = '\0'; 
    printf("PT: %sCT: %s\n", pt, ct);
    return 0;
}