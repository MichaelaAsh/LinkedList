#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>

#define SUCCESS 0
#define FAIL -1
int main (int argc, char *argv[]) {

  int max_nodes;
  printf("Enter an integer greater than 5: ");
  scanf ("%d", &max_nodes);

  if (max_nodes <= 5) {
    printf("Error number must be greater than 5\n");
    return (FAIL);
  }

  Node *head = NULL;
  Node *sort1_head = NULL;
  Node *sort2_head = NULL;

  head = create_list (max_nodes);
  printf("Before:\n");
  display_list(head);
  putchar('\n');


  printf("After sort1:\n"); /*sort the list based on key1 in ascending order */
  sort1_head = ascend_sort1 (head);
  display_sort1(sort1_head);
  putchar('\n');

  printf("After sort2:\n"); /*sort the list based on key1 in ascending order */
  sort2_head = ascend_sort2 (head);
  display_sort2 (sort2_head);
  putchar('\n');

  printf("Before (value x 10):\n");
  change_value(head);
  display_list(head);
  putchar('\n');

  printf("After sort1:\n"); /*sort the list based on key1 in ascending order */
  sort1_head = ascend_sort1 (head);
  display_sort1(sort1_head);
  putchar('\n');

  printf("After sort2:\n"); /*sort the list based on key1 in ascending order */
  sort2_head = ascend_sort2 (head);
  display_sort2 (sort2_head);
  putchar('\n');


   return (SUCCESS);
}
