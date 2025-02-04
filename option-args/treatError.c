#include <stdio.h>
#include <getopt.h>

int main(int argc, char* argv[]){

	int option;

	while((option = getopt(argc, argv, ":a:b:")) != -1){
		if (option == 'a')
			printf("Argument for option a: %s\n", optarg);
		else
			if (option == 'b')
				printf("Argument for option b: %s\n", optarg);
			else
				if (option == '?')
					printf("Unknow option: %c\n", optopt);
				else
					if (option == ':')
						printf("Missing option for: %c\n", optopt);
	}
}
