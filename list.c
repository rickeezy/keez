// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h" 



int list_length(list_t *l) {
  node_t* temp = l->head;
  int counter = 0;
  while (temp != NULL) {
    counter++;
    temp = temp-> next;
  }
  return counter;
}



list_t *list_alloc() {
  list_t* newList = (list_t*)malloc(sizeof(list_t));
  newList->head = NULL;
  return newList;
}


void list_free(list_t *l) {
  node_t* temp;
  while (l->head != NULL){
    temp = l->head;
    l->head = l->head->next;
    free(temp);
  }
  free(l);
}

void list_print(list_t *l) {
  node_t* temp = l->head;
  while (temp != NULL) {
    printf("%d ", temp->value);
    temp = temp->next;
  }
  printf("\n");
}

// int list_length(list_t *l) {
//   node_t* temp = l->head;
//   int counter = 0;
//   while(temp != NULL){
//     counter++;
//     temp = temp-> next;
//   }
//   return counter;
// }

void list_add_to_back(list_t *l, elem value) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  newNode->value = value;
  newNode->next = NULL;
  if (l->head == NULL){
    l->head = newNode;
  } else {
    node_t* temp = l->head;
    while (temp->next != NULL){
      temp - temp->next;
    }
    temp->next = newNode;
  }
}
void list_add_to_front(list_t *l, elem value) {
  node_t* newNode = (node_t *) malloc(sizeof(node_t));
  newNode->value = value;
  newNode->next = l->head;
  l->head = newNode;
}
void list_add_at_index(list_t *l, elem value, int index) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  newNode->value = value;
  node_t* temp = l->head;
  int i;
  for (i = 0; i < index - 1; i++){
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}

elem list_remove_from_back(list_t *l) {
  if (l->head == NULL){
    return -1; //list is empty
  }

  node_t* second_last = NULL;
  node_t* last = l->head;

  while (last->next != NULL) {
    second_last = last;
    last = last->next;
  }

  elem value = last->value;
  free(last);

  if(second_last != NULL) {
    second_last->next = NULL;
  } else {
    l->head = NULL;
  }
  return value;
}

elem list_remove_from_front(list_t *l) {
  if(l->head == NULL) return -1;
  node_t *old_head = l->head;
  elem value = old_head->value;
  l->head = old_head->next;
  free(old_head);
  return value;
}

elem list_remove_at_index(list_t *l, int index) {
  if(index >= list_length(l) || index < 0) return -1; //If index out of bounds, return -1
  if(index == 0) return list_remove_from_front(l); //If index is at 0, remove from front.
  if(index == list_length(l)-1) return list_remove_from_back(l);//If index is at the end, remove from back.
  node_t *temp = l->head;
  node_t *remove = NULL;
  int i;
  for(i = 0; i < index-1; i++){
      temp = temp->next;
  }
  remove = temp->next; 
  elem value = remove->value;
  temp->next = remove->next;
  free(remove);
  return value;
}

bool list_is_in(list_t *l, elem value) {
  node_t *temp = l->head;
  while(temp != NULL) {
    if(temp->value == value) return true;
    temp = temp->next;
  }
  return false;
}
elem list_get_elem_at(list_t *l, int index) {
  if(index >= list_length(l) || index < 0) return -1;
  node_t *temp = l->head;
  int i;
  for(i = 0; i < index; i++){
    temp = temp->next;
  }
  return temp->value;
}
int list_get_index_of(list_t *l, elem value) {
  int index = 0;
  node_t *temp = l->head;
  while(temp != NULL) {
    if(temp->value == value) return index;
    temp = temp->next;
    index++;
  }
  return -1;
}

// 
char* get_list(list_t* list) {
    if (list == NULL || list->head == NULL) {
        return "NULL";
    }

    node_t* current = list->head;
    int length = 0;

    // Calculate the length of the list
    while (current != NULL) {
        length++;
        current = current->next;
    }

    // Create a string buffer to store the list representation
    char* buffer = malloc((length * 5 + 5) * sizeof(char));
    buffer[0] = '\0';  // Initialize buffer as an empty string

    current = list->head;
    while (current != NULL) {
        char num[5];  // Assuming the maximum number of digits in an element is 4
        snprintf(num, sizeof(num), "%d", current->value);
        strcat(buffer, num);
        strcat(buffer, "->");
        current = current->next;
    }

    strcat(buffer, "NULL");
    return buffer;
}

void print_list(list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        printf("%d->", current->value);
        current = current->next;
    }
    printf("NULL\n");
}
