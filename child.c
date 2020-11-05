#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool simple(int  x){
	if (x == 1){
		return true;
	}
	if (x == 0){
		return false;
	}
	for (int i = 2; i <= sqrt(x); i++){
		if (x % i == 0){
			return false;
		}
		return true;
	}
}

int main(int argc, char *argv[]){
	int x;
	bool prime = false;
	while(1){
		scanf("%d", &x);
		if (!simple(x) || x < 0){
			printf("%d\n",x);
			fflush(stdout);
		}
		else{
			prime = true;
			return 1;
		}
	}
}
