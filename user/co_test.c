//------------------------------------ Task3 --------------------------------------
#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  printf("co_test: error tests\n");

  printf("self yield result: %d\n", co_yield(getpid(), 1));
  printf("bad pid result: %d\n", co_yield(99999, 1));

  int victim = fork();
  if(victim == 0){
    sleep(1000);
    exit(0);
  }

  kill(victim);
  sleep(2);
  printf("killed pid result: %d\n", co_yield(victim, 1));
  wait(0);

  printf("co_test: coroutine ping-pong\n");

  int parent = getpid();
  int child = fork();

  if(child == 0){
    for(;;){
      int value = co_yield(parent, 1);
      printf("Child received: %d\n", value);
    }
  } else {
    for(;;){
      int value = co_yield(child, 2);
      printf("Parent received: %d\n", value);
    }
  }

  exit(0);
}