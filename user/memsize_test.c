//-------------------------------------- Task2 ----------------------
#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  printf("Before malloc: %d bytes\n", memsize());

  void *arr = malloc(20 * 1024);
  if(arr == 0){
    printf("malloc failed\n");
    exit(1);
  }

  printf("After malloc: %d bytes\n", memsize());

  free(arr);

  printf("After free: %d bytes\n", memsize());

  exit(0);
}