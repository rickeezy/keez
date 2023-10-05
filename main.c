#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
  int x;
  printf("Write your Tests for your linked list implementation\n");
  list_t *mylist;
  mylist = list_alloc();
  list_print(mylist);
  printf("this it ^^\n");
  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);

  list_print(mylist);
  list_add_to_front(mylist, 40);
  list_add_to_front(mylist, 50);
  list_add_to_front(mylist, 60);
  list_add_to_front(mylist, 70);
  list_add_to_front(mylist, 80);
  list_add_to_front(mylist, 90);
  list_add_to_front(mylist, 100);
  list_print(mylist);

  if(strcmp("100->90->80->70->60->50->40->30->20->10->NULL",get_list(mylist)) == 0)
  {
        printf("list_add_to_front : Passed well\n"); //test1
  }

  list_print(mylist);
  list_remove_at_index(mylist, 3);
  list_print(mylist);

  if(strcmp("100->90->80->60->50->40->30->20->10->NULL",get_list(mylist)) == 0)
  {
        printf("list_remove_at_index : Passed Well Kid\n"); //test2
  }

  list_remove_at_index(mylist, 20); //no change out of index
  list_print(mylist);
  list_remove_at_index(mylist, 0); // 100 hsould be gone
  list_print(mylist);
  list_remove_at_index(mylist, 6); // 20 should be gone 
  list_print(mylist);

  if(strcmp("100->90->80->60->50->40->20->10->NULL",get_list(mylist)) != 0)
  {
        printf("list_remove_at_index : Ok Now Girl Gone Head\n"); //test3
  }
  return 0;
}

