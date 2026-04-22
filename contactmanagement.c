#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
    struct Contact* next;
    struct Contact* prev;
};

struct Contact* head = NULL;

// Create contact
struct Contact* createContact(char name[], char phone[]) {
    struct Contact* newNode = (struct Contact*)malloc(sizeof(struct Contact));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }

    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = newNode->prev = NULL;

    return newNode;
}

// Add contact
void addContact(char name[], char phone[]) {
    struct Contact* newNode = createContact(name, phone);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Contact* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Contact added successfully!\n");
}

// Display contacts
void displayForward() {
    if (head == NULL) {
        printf("No contacts available!\n");
        return;
    }

    struct Contact* temp = head;
    printf("\nContact List:\n");

    while (temp != NULL) {
        printf("Name: %s | Phone: %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

// Search contact
void searchContact(char name[]) {
    struct Contact* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Found: %s - %s\n", temp->name, temp->phone);
            return;
        }
        temp = temp->next;
    }

    printf("Contact not found!\n");
}

int main() {
    int choice;
    char name[50], phone[15];

    while (1) {
        printf("\n===== CONTACT MENU =====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                 printf("Enter name: ");
                 scanf(" %[^\n]", name);   // supports full name

                printf("Enter phone: ");
                scanf(" %[^\n]", phone);  // optional (if phone may include spaces)

    addContact(name, phone);
    break;

            case 2:
                displayForward();
                break;

            case 3:
                 printf("Enter name to search: ");
                scanf(" %[^\n]", name);
                searchContact(name);
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}