#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	void * my_calloc(size_t num, size_t size) {
    		void* ptr = malloc(num * size);
    		if (!ptr) return NULL;
    		memset(ptr, 0, num * size);
    		return ptr;
	}

	int main() {
		int * arr = (int *)my_calloc(5, sizeof(int));
		if (!arr) return -1;

		for(int i = 0; i < 5; i++) 
			printf("%d", arr[i]);

		puts("");

		free(arr);

		return 0;
	}
