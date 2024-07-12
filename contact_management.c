#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 100
#define PHONE_SIZE 20
#define EMAIL_SIZE 100
#define FILE_NAME "contacts.csv"

typedef struct {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
    char email[EMAIL_SIZE];
} Contact;

void addContact();
void viewContacts();
void editContact();
void deleteContact();
void saveContact(Contact contact);
void loadContacts(Contact **contacts, int *contactCount);
void saveAllContacts(Contact *contacts, int contactCount);

int main() {
    int choice;

    while (1) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                editContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addContact() {
    Contact contact;
    
    printf("Enter name: ");
    scanf(" %[^\n]", contact.name);
    printf("Enter phone number: ");
    scanf(" %[^\n]", contact.phone);
    printf("Enter email address: ");
    scanf(" %[^\n]", contact.email);

    saveContact(contact);
    printf("Contact added successfully!\n");
}

void viewContacts() {
    Contact *contacts = NULL;
    int contactCount = 0;

    loadContacts(&contacts, &contactCount);

    printf("\nContact List:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s, %s, %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    free(contacts);
}

void editContact() {
    Contact *contacts = NULL;
    int contactCount = 0;
    int contactIndex;

    loadContacts(&contacts, &contactCount);

    printf("\nContact List:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s, %s, %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    printf("Enter the number of the contact to edit: ");
    scanf("%d", &contactIndex);
    contactIndex--;

    if (contactIndex < 0 || contactIndex >= contactCount) {
        printf("Invalid contact number!\n");
        free(contacts);
        return;
    }

    printf("Enter new name: ");
    scanf(" %[^\n]", contacts[contactIndex].name);
    printf("Enter new phone number: ");
    scanf(" %[^\n]", contacts[contactIndex].phone);
    printf("Enter new email address: ");
    scanf(" %[^\n]", contacts[contactIndex].email);

    saveAllContacts(contacts, contactCount);
    printf("Contact edited successfully!\n");
    free(contacts);
}

void deleteContact() {
    Contact *contacts = NULL;
    int contactCount = 0;
    int contactIndex;

    loadContacts(&contacts, &contactCount);

    printf("\nContact List:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s, %s, %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    printf("Enter the number of the contact to delete: ");
    scanf("%d", &contactIndex);
    contactIndex--;

    if (contactIndex < 0 || contactIndex >= contactCount) {
        printf("Invalid contact number!\n");
        free(contacts);
        return;
    }

    for (int i = contactIndex; i < contactCount - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    contactCount--;

    saveAllContacts(contacts, contactCount);
    printf("Contact deleted successfully!\n");
    free(contacts);
}

void saveContact(Contact contact) {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Could not open file for writing");
        return;
    }

    fprintf(file, "%s,%s,%s\n", contact.name, contact.phone, contact.email);
    fclose(file);
}

void loadContacts(Contact **contacts, int *contactCount) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        *contacts = NULL;
        *contactCount = 0;
        return;
    }

    Contact temp;
    *contactCount = 0;
    while (fscanf(file, " %99[^,],%19[^,],%99[^\n]", temp.name, temp.phone, temp.email) == 3) {
        (*contactCount)++;
    }

    fseek(file, 0, SEEK_SET);
    *contacts = (Contact *)malloc(sizeof(Contact) * (*contactCount));
    int i = 0;
    while (fscanf(file, " %99[^,],%19[^,],%99[^\n]", (*contacts)[i].name, (*contacts)[i].phone, (*contacts)[i].email) == 3) {
        i++;
    }

    fclose(file);
}

void saveAllContacts(Contact *contacts, int contactCount) {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Could not open file for writing");
        return;
    }

    for (int i = 0; i < contactCount; i++) {
        fprintf(file, "%s,%s,%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    fclose(file);
}
