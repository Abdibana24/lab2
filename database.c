#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

// Global variables
Part *database = NULL;  // Pointer to the dynamically allocated database
int num_records = 0;    // Number of records in the database

// Print all records
void print_all_records() {
    if (num_records == 0) {
        printf("No records to display.\n");
        return;
    }
    for (int i = 0; i < num_records; i++) {
        printf("\nRecord %d:\n", i + 1);
        printf("Part Number: %d\n", database[i].part_number);
        printf("Part Name: %s\n", database[i].part_name);
        printf("Part Size: %.2f %s\n", database[i].part_size, database[i].part_size_metric);
        printf("Part Cost: $%.2f\n", database[i].part_cost);
    }
}

// Print number of records
void print_num_records() {
    printf("Total records: %d\n", num_records);
}

// Print database memory size
void print_db_size() {
    printf("Database size: %lu bytes\n", num_records * sizeof(Part));
}

// Add a new record
void add_record() {
    // Allocate new memory manually (not using realloc() for extra credit)
    Part *new_memory = malloc((num_records + 1) * sizeof(Part));

    if (new_memory == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Copy existing records to the new memory
    for (int i = 0; i < num_records; i++) {
        new_memory[i] = database[i];
    }

    // Free old memory
    free(database);

    // Point database to new memory
    database = new_memory;

    // Get new record details from user
    printf("Enter Part Number: ");
    scanf("%d", &database[num_records].part_number);
    getchar();  // Consume newline left in input buffer

    printf("Enter Part Name: ");
    fgets(database[num_records].part_name, 50, stdin);
    database[num_records].part_name[strcspn(database[num_records].part_name, "\n")] = '\0';  // Remove newline

    printf("Enter Part Size: ");
    scanf("%f", &database[num_records].part_size);

    printf("Enter Part Size Metric (e.g., mm): ");
    scanf("%s", database[num_records].part_size_metric);

    printf("Enter Part Cost: ");
    scanf("%f", &database[num_records].part_cost);

    num_records++;
    printf("Record added successfully!\n");
}

// Delete last record
void delete_record() {
    if (num_records == 0) {
        printf("No records to delete.\n");
        return;
    }

    num_records--;

    if (num_records == 0) {
        free(database);
        database = NULL;
    } else {
        Part *new_memory = malloc(num_records * sizeof(Part));

        if (new_memory == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }

        // Copy existing records (except last) to new memory
        for (int i = 0; i < num_records; i++) {
            new_memory[i] = database[i];
        }

        free(database);
        database = new_memory;
    }

    printf("Last record deleted successfully!\n");
}

// Free allocated memory before exiting
void free_memory() {
    if (database != NULL) {
        free(database);
    }
}
