#include <stdio.h>
#include <stdlib.h>
#include <pbar.h>


int main(int argc, char *argv[]) {
	int n;

	pbar(0, 100, 5);
	for(int i = 0; i <= 100; i ++ ){
		pbar(i, 100, 5);
	}

	return 0;
}
