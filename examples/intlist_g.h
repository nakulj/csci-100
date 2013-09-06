#ifndef INTLIST_H
#define INTLIST_H

typedef struct IntItem_s {
  int val;
  struct IntItem_s *next;
} IntItem;

//==================================================
// Description: Checks if the list is empty
// Return: 1 if list is empty, 0 if is is non-empty
//==================================================
bool is_empty();

//==================================================
// Description: Add 'new_val' to the end of the list
// Return: Nothing
//==================================================
void push_back(int new_val);

//==================================================
// Description: Remove the first item & update head
// Return: val of the first item that was removed
//         or -1 if list was empty
//==================================================
int pop_front();

//==================================================
// Description: Returns val of the first item
// Return: val of the first item or -1 if list is empty
//==================================================
int peek_front();

//==================================================
// Description: Print each val in the list separated
//              by spaces
// Return: Nothing
//==================================================
void print_list();

//==================================================
// Description: Checks if 'find_val' appears in the
//              list
// Return: Address of struct containing find_val if
//         present, NULL otherwise
//==================================================
IntItem *find(int find_val);

//==================================================
// Description: Checks if 'del_val' appears in the
//              list and removes that item, updating
//              the pointers of the list
// Return: 1 if item was found and removed, 0 otherwise
//==================================================
bool remove(int del_val);

//==================================================
// Description: Returns current size of list
// Return: number of items in the list
//==================================================
int list_size();

#endif
