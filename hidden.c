#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 'X'  // XOR Key (Keep it secret)

void encrypt_decrypt(char *input, char *output) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        output[i] = input[i] ^ KEY; // XOR encryption
    }
    output[len] = '\0'; // Null-terminate the string
}

void save_password() {
    char password[100], encrypted[100];
    
    printf("Enter your password: ");
    scanf("%s", password);

    encrypt_decrypt(password, encrypted);

    FILE *file = fopen("passwords.enc", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%s\n", encrypted);
    fclose(file);

    printf("Password saved securely!\n");
}

void read_password() {
    char encrypted[100], decrypted[100];

    FILE *file = fopen("passwords.enc", "r");
    if (file == NULL) {
        printf("No password file found!\n");
        return;
    }

    fgets(encrypted, 100, file);
    fclose(file);

    encrypt_decrypt(encrypted, decrypted);
    printf("Decrypted Password: %s\n", decrypted);
}

int main() {
    int choice;
    printf("1. Save Password\n2. Retrieve Password\nChoose an option: ");
    scanf("%d", &choice);

    if (choice == 1) {
        save_password();
    } else if (choice == 2) {
        read_password();
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
