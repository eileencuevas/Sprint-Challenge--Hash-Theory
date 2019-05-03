#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  Answer *result = malloc(sizeof(Answer));
  // YOUR CODE HERE

  // go through the array of weights,
  for (int i = 0; i < length; i++)
  {
    hash_table_insert(ht, weights[i], i); //add weights as key, pair value (weight : index)
  }
  // go through the array of weights again
  for (int i = 0; i < length; i++)
  {
    // subtract weight from limit
    int difference = limit - weights[i];
    // see if difference exists in hash table
    int other_index = hash_table_retrieve(ht, difference);
    if (other_index != -1)
    {
      // if exists, put into answer struct
      if (other_index > i)
      {
        result->index_1 = other_index;
        result->index_2 = i;
      }
      else
      {
        result->index_1 = i;
        result->index_2 = other_index;
      }
      return result;
    }
  }

  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL)
  {
    printf("%d %d\n", answer->index_1, answer->index_2);
  }
  else
  {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{

  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1); // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer *answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2); // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer *answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3); // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer *answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4); // {6, 2}

  return 0;
}
#endif
