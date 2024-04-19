#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>  

void print_help(char *program_name) {
    printf("Vigenere Cypher by Leonardo Militz\n\n");
    printf("Usage:\n\t%s [-d | -e] PLAINTEXT KEY\n\n\t-e: encrypt mode\n\t-d: decrypt mode", program_name);
}

bool check_valid_value(char *message) {
    char whitelist[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int i, j;
    for (i = 0; i < strlen(message); i++) {
        bool valid = false;
        for (j = 0; j < strlen(whitelist)-1; j++) {
            if (toupper(message[i]) == whitelist[j]) {
                valid = true;
                break;
            }
        }
        if (!valid)
            return false;
    }

    return true;
}

bool handle_args(int argc, char *argv[]) {
    if (argc == 4) {
        if (strcmp(argv[1], "-e") == 0 || strcmp(argv[1], "-d") == 0) {
            return true;
        }        
    }

    print_help(argv[0]);
    return false;
}

void encrypt(char* plaintext, char* key) {
     int i, j;
     for (i = 0, j = 0; i < strlen(plaintext); i++, j++) {  
        if (j >= strlen(key)) {  
            j = 0;  
        }  
        int shift = toupper(key[j]) - 'A';  
        char encryptedChar = ((toupper(plaintext[i]) - 'A' + shift) % 26) + 'A';  
        printf("%c", encryptedChar);  
    }
}

void decrypt(char* ciphertext, char* key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(ciphertext); i++, j++) {  
        if (j >= strlen(key)) {  
            j = 0;  
        }  
        int shift = toupper(key[j]) - 'A';  
        char decryptedChar = ((toupper(ciphertext[i]) - 'A' - shift + 26) % 26) + 'A';  
        printf("%c", decryptedChar);  
    }  
}

int main(int argc, char *argv[])  {
    if (!handle_args(argc, argv))
        return 1;
    
    char *mode = argv[1];
    char *message = argv[2];
    char *key = argv[3];

    if (!check_valid_value(message)) {
        printf("\nerror: Invalid MESSAGE. Only use alphabetic characters.");
        return 1;
    }

    if (!check_valid_value(key)) {
        printf("\nerror: Invalid KEY. Only use alphabetic characters.");
        return 1;
    }

    if (strlen(key) > strlen(message)) {
        printf("\nerror: KEY value should not be longer than the MESSAGE value.");
        return 1;
    }

    if (strcmp(mode, "-e") == 0) {
        encrypt(message, key);
    }

    if (strcmp(mode, "-d") == 0) {
        decrypt(message, key);;
    }

    return 0;
}