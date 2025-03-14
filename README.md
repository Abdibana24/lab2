# Lab 2: Memory and Structures

## Description
This program dynamically manages part records using C structures and dynamic memory allocation. It implements manual memory resizing without using `realloc()` for extra credit.

## Features
- Uses `malloc()` and `free()` to dynamically allocate memory.
- Supports adding, deleting, and displaying records.
- Provides a user-friendly menu interface.

## Functionality
1. **Print all records** - Displays stored part records.
2. **Print number of records** - Shows the total count of records.
3. **Print database size** - Shows the memory used in bytes.
4. **Add record** - Prompts the user to enter a new part record.
5. **Delete record** - Removes the last record and updates memory.
6. **Exit** - Frees allocated memory and exits the program.

## Memory Management
- **Uses `malloc()`** for new memory allocations.
- **Manually resizes memory** (without `realloc()`) for extra credit.
- **Frees memory** properly to prevent leaks.

## Compilation & Execution
```sh
gcc -o lab2 main.c database.c
./lab2
