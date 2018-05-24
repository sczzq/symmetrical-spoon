/*************************************************************************
	> File Name: malloc.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Thu 03 May 2018 09:54:12 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>
#include <malloc.h>

/* Prototype for our hooks. */
static void my_init_hook(void);
static void *my_malloc_hook(size_t, const void *);
static void my_free_hook(void *, const void *);

void *(*old_malloc_hook)(size_t, const void *);
void (*old_free_hook)(void *, const void *);

static void
my_init(void)
{
	old_malloc_hook = __malloc_hook;
	old_free_hook = __free_hook;
	__malloc_hook = my_malloc_hook;
	__free_hook = my_free_hook;
}

static void
my_restore(void)
{
	__malloc_hook = old_malloc_hook;
	__free_hook = old_free_hook;
}

static void *
my_malloc_hook(size_t size, const void *caller)
{
	void *result;
	/* Restore all old hooks */
	__malloc_hook = old_malloc_hook;
	__free_hook = old_free_hook;
	/* Call recursively */
	result = malloc(size);
	/* Save underlying hooks */
	old_malloc_hook = __malloc_hook;
	old_free_hook = __free_hook;
	/* printf might call malloc, so protect it too. */
	printf("malloc (%u) return %p\n", (unsigned int) size, result);
	/* Restore our own hooks */
	__malloc_hook = my_malloc_hook;
	__free_hook = my_free_hook;
	return result;
}

static void
my_free_hook(void *ptr, const void *caller)
{
	/* Restore all old hooks */
	__malloc_hook = old_malloc_hook;
	__free_hook = old_free_hook;
	/* Call recursively */
	free(ptr);
	/* Save underlying hooks */
	old_malloc_hook = __malloc_hook;
	old_free_hook = __free_hook;
	/* printf might call free, so protect it too. */
	printf("freed pointer %p\n", ptr);
	/* Restore our own hooks. */
	__malloc_hook = my_malloc_hook;
	__free_hook = my_free_hook;
}

/*
void fn_handle(mcheck_status stat)
{
	fprintf("mcheck return stats: %d\n", stat);
	abort();
}
*/
/*
struct mallinfo
{
  int arena;    
  int ordblks;  
  int smblks;   
  int hblks;    
  int hblkhd;   
  int usmblks;  
  int fsmblks;  
  int uordblks; 
  int fordblks; 
  int keepcost; 
};*/
void show_mallinfo()
{
	my_restore();
	struct mallinfo mi = mallinfo();
	printf("-----------------------------------------------------\n");
	printf("/* non-mmapped space allocated from system */, arena: %d\n", mi.arena);
	printf("/* number of free chunks */, ordblks: %d\n", mi.ordblks);
	printf("/* number of fastbin blocks */, smblks: %d\n", mi.smblks);
	printf("/* number of mmapped regions */, hblks: %d\n", mi.hblks);
	printf("/* space in mmapped regions */, hblks: %d\n", mi.hblkhd);
	printf("/* maximum total allocated space */, usmblks: %d\n", mi.usmblks);
	printf("/* space available in freed fastbin blocks */, fsmblks: %d\n", mi.fsmblks);
	printf("/* total allocated space */, uordblks: %d\n", mi.uordblks);
	printf("/* total free space */, fordblks: %d\n", mi.fordblks);
	printf("/* top-most, releasable (via malloc_trim) space */, keepcost: %d\n", mi.keepcost);
	printf("-----------------------------------------------------\n");
	my_init();
}

int main()
{
	/*
	if(mcheck(NULL) != 0){
		fprintf(stderr, "mcheck error\n");
		exit(EXIT_FAILURE);
	}
	*/
	my_init();

	char *a = malloc(20);
	a[20] = 20;

	show_mallinfo();

	free(a);
//	free(a);

	show_mallinfo();
	return 0;
}


