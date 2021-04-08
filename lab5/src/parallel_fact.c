#include <stdint.h>
#include <errno.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/types.h>

int common = 1;
uint32_t k = 0;
uint32_t pnum = 0;
uint32_t mod = 0;

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

struct Fact
{
    int current;
    int begin;
    int end;
};

void *Factorial(struct Fact* args)
{
    for (int i = args->begin + 1; i < args->end + 1; ++i)
    {
        pthread_mutex_lock(&mut);
        common = (common * (i % mod)) % mod;
        printf("fact = %d\n", common);
        pthread_mutex_unlock(&mut);
    }
    common %= mod;
    args->current = common;
}

void *ThreadFact(void *args) {
  struct Fact *fact_args = (struct Fact *)args;
  return (void *)(size_t)Factorial(fact_args);
}


int main(int argc, char **argv)
{
  pthread_mutex_init(&mut, NULL);
  pthread_t threads[pnum]; 
    int current_optind = optind ? optind : 1;

    static struct option options[] = {{"k", required_argument, 0, 0},
                                      {"pnum", required_argument, 0, 0},
                                      {"mod", required_argument, 0, 0},
                                      {0, 0, 0, 0}};

    int option_index = 0;
    while (true) {
    int c = getopt_long(argc, argv, "f", options, &option_index);
    if (c == -1) break;
    switch (c) {
      case 0:
        switch (option_index) {
          case 0:
            k = atoi(optarg);
            // your code here
            // error handling
            if(k < 0)
            {
                printf("k is a positive number\n");
                return 1;
            }
            break;
          case 1:
            pnum = atoi(optarg);
            // your code here
            // error handling
            if(pnum <= 0)
            {
                printf("pnum is a positive number\n");
                return 1;
            }
            break;
          case 2:
            mod = atoi(optarg);
            // your code here
            // error handling
            if(mod <= 0)
            {
                printf("mod is a positive number\n");
                return 1;
            }
            break;
          default:
            printf("Index %d is out of options\n", option_index);
        }
        break;
      default:
        printf("getopt returned character code 0%o?\n", c);
    }
  }
  if (optind < argc) 
  {
          printf("Has at least one no option argument\n");
          return 1;
  }
  if (k == -1 || pnum == -1 || mod == -1) 
  {
          printf("Usage: %s --k \"num\" --pnum \"num\" --mod \"num\" \n", argv[0]);
          return 1;
  }

  struct Fact args[pnum];

  for (uint32_t i = 0; i < pnum; i++) 
  {
        args[i].current = i*k/pnum;
		args[i].begin = i*k/pnum;
		args[i].end = (i == (pnum - 1)) ? k : (i+1)*k/pnum;
  }

  for (uint32_t i = 0; i < pnum; i++)
  {
      if (pthread_create(&threads[i], NULL, ThreadFact, (void *)&args[i]))
      {
          printf("Error: pthread_create failed!\n");
          return 1;
      }
  }


  for (uint32_t i = 0; i < pnum; i++) 
  {
      pthread_join(threads[i], NULL);
  }

  printf("Total fact: %d\n", common);
    return 0;
}