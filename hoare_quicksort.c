/*
 * Hoare Partition Scheme implementation
 * https://en.wikipedia.org/wiki/Quicksort
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define TEST_ARRAY_SIZE 10

int partition(int *array, size_t lo, size_t hi);
void quicksort(int *array, size_t lo, size_t hi);
void print_array(int *array, size_t size);

int main(void) {
  int test[TEST_ARRAY_SIZE] = {8, 5, 62, 10, 440, 12, 1999, 30, 3, 776};

  printf("=== ARRAY BEFORE QUICKSORT ===\n");
  print_array(test, TEST_ARRAY_SIZE);

  quicksort(test, 0, TEST_ARRAY_SIZE - 1);

  printf("\n=== ARRAY AFTER QUICKSORT ===\n");
  print_array(test, TEST_ARRAY_SIZE);

  return 0;
}

int partition(int *array, size_t lo, size_t hi)
{
  const int idx = (int)floor(((double)hi + (double)lo) / 2);
  // pivot
  int pvt = array[idx];

  // left index
  int lfidx = lo - 1;
  // right index
  int rgidx = hi + 1;

  while (true) {
    do {
      lfidx += 1;
    } while (array[lfidx] < pvt);

    do {
      rgidx -= 1;
    } while (array[rgidx] > pvt);

    if (lfidx >= rgidx) {
      return rgidx;
    }

    int tmp = array[lfidx];
    array[lfidx] = array[rgidx];
    array[rgidx] = tmp;
  }

  return -1;
}

void quicksort(int *array, size_t lo, size_t hi)
{
  if (lo >= 0 && hi >= 0 && lo < hi) {
    int ptn = partition(array, lo, hi);
    quicksort(array, lo, ptn);
    quicksort(array, ptn + 1, hi);
  }
}

void print_array(int *array, size_t size)
{
  for (int i = 0; i < size; i++) {
    printf("%d", array[i]);
    if (i < size - 1) {
      printf(", ");
    }
  }

  printf("\n");
}
