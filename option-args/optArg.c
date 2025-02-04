#include <stdio.h>
#include <getopt.h>

int main(int argc, char* argv[]){

	int option;

	while((option = getopt(argc, argv, "a:b:X")) != -1){
		if (option == 'a')
			printf("Argument for option a: %s\n", optarg);
		else
			if (option == 'b')
				printf("Argument for option b: %s\n", optarg);
			else
				if (option == 'X')
					printf("Option X was provided!!!\n");
	}
}
