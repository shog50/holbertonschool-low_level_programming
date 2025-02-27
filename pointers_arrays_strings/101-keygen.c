#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

// Function to generate a random valid password
void generate_password(char *password, int length) {
// Define the character set for the password
const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int charset_size = sizeof(charset) - 1;

// Seed the random number generator with the current time
srand(time(NULL));

// Generate a random password
for (int i = 0; i < length; i++) {
int random_index = rand() % charset_size;
password[i] = charset[random_index];
}

// Null-terminate the password
password[length] = '\0';
}

int main() {
char password[PASSWORD_LENGTH + 1];

// Generate a random valid password
generate_password(password, PASSWORD_LENGTH);

// Print the generated password
printf("Generated password: %s\n", password);

return (0);
}

