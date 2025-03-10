#include <stdio.h>
#include "database.h"

void menu() {
    int choice;
    
    do {
        printf("\nMENU\n======\n");
        printf("1. Print all records\n");
        printf("2. Print number of records\n");
        printf("3. Print size of database\n");
        printf("4. Add record\n");
        printf("5. Delete record\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: print_all_records(); break;
            case 2: print_num_records(); break;
            case 3: print_db_size(); break;
            case 4: add_record(); break;
            case 5: delete_record(); break;
            case 6: 
                printf("Exiting...\n");
                free_memory();
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}
