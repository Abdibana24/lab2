#ifndef DATABASE_H   // Prevents multiple inclusions
#define DATABASE_H

// Structure for Part records
typedef struct {
    int part_number;
    char part_name[50];   // Character array for part name
    float part_size;
    char part_size_metric[10]; // Character array for size unit
    float part_cost;
} Part;

// Function Prototypes
void print_all_records();  // Prints all records
void print_num_records();  // Prints the number of records
void print_db_size();      // Prints memory size of the database
void add_record();         // Adds a new record
void delete_record();      // Deletes the last record
void free_memory();        // Frees allocated memory before exiting

#endif  // DATABASE_H
