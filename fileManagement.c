#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH_OF_NAME 50
#define USER_FILE_NAME "users.txt"

typedef struct {
    int id;
    char name[MAX_LENGTH_OF_NAME];
    int age;
} User;

void function_to_create_file_if_not_exists() {
    FILE *file = fopen(USER_FILE_NAME, "a");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    fclose(file);
}

bool check_is_Id_unique(int id) {
    FILE *file = fopen(USER_FILE_NAME, "r");
    if (!file) return true;

    User user;
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3) {
        if (user.id == id) {
            fclose(file);
            return false;
        }
    }
    fclose(file);
    return true;
}

int getInteger(const char *prompt) {
    int value;
    printf("%s", prompt);
    if (scanf("%d", &value) != 1) {
        printf("Error: Invalid input. Only integers are allowed.\n");
        exit(1);
    }
    return value;
}

void getString(const char *prompt, char *output, int maxLength) {
    printf("%s", prompt);
    getchar(); // Consume any leftover newline character from previous input
    if (fgets(output, maxLength, stdin) == NULL) {
        printf("Error: Invalid input.\n");
        exit(1);
    }
    output[strcspn(output, "\n")] = 0; // Remove trailing newline
}

void addUser() {
    User user;
    user.id = getInteger("Enter User ID: ");

    if (!check_is_Id_unique(user.id)) {
        printf("Error: User ID already exists.\n");
        return;
    }

    getString("Enter Name (with spaces): ", user.name, MAX_LENGTH_OF_NAME);
    user.age = getInteger("Enter Age: ");

    FILE *file = fopen(USER_FILE_NAME, "a");
    if (!file) {
        printf("Error: Unable to open file.\n");
        return;
    }

    fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
    fclose(file);
    printf("User added successfully.\n");
}

void displayUsers() {
    FILE *file = fopen(USER_FILE_NAME, "r");
    if (!file) {
        printf("No data available.\n");
        return;
    }

    User user;
    int count = 0;
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3) {
        printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
        count++;
    }

    if (count == 0) {
        printf("No data available.\n");
    }

    fclose(file);
}

void updateUser() {
    int id = getInteger("Enter User ID to update: ");

    FILE *file = fopen(USER_FILE_NAME, "r");
    if (!file) {
        printf("No data available for update.\n");
        return;
    }

    User user;
    bool found = false;
    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        printf("Error: Unable to create temporary file.\n");
        fclose(file);
        return;
    }

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3) {
        if (user.id == id) {
            found = true;
            getString("Enter new Name (with spaces): ", user.name, MAX_LENGTH_OF_NAME);
            user.age = getInteger("Enter new Age: ");
        }
        fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(USER_FILE_NAME);
        rename("temp.txt", USER_FILE_NAME);
        printf("User updated successfully.\n");
    } else {
        remove("temp.txt");
        printf("User ID not found.\n");
    }
}

void deleteUser() {
    int id = getInteger("Enter User ID to delete: ");

    FILE *file = fopen(USER_FILE_NAME, "r");
    if (!file) {
        printf("No data available for deletion.\n");
        return;
    }

    User user;
    bool found = false;
    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        printf("Error: Unable to create temporary file.\n");
        fclose(file);
        return;
    }

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3) {
        if (user.id == id) {
            found = true;
        } else {
            fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(USER_FILE_NAME);
        rename("temp.txt", USER_FILE_NAME);
        printf("User deleted successfully.\n");
    } else {
        remove("temp.txt");
        printf("User ID not found.\n");
    }
}

int main() {
    function_to_create_file_if_not_exists();

    int choice;
    while (1) {
        printf("\n1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        choice = getInteger("");

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                displayUsers();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                exit(1);
        }
    }

    return 0;
}
