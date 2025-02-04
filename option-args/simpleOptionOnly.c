#include <stdio.h>
#include <getopt.h>

int main(int argc, char* argv[]){

	int option;

	while((option = getopt(argc, argv, "ab")) != -1){
		if (option == 'a')
			printf("a");
		else
			if (option == 'b')
				printf("b");

	}
}
