#include <unistd.h>

void print_error(char** argv){
	int n = 0;
	while(argv[i][n++]);
	write(2, "No such command: ",17);
	write(2, argv[i], n);
	write(2, "\n", 1);
	_exit(-1);
}


int main(int argc, char** argv){
	if(argc < 2) do { write(1,"y\n",2); } while(1);
	for(char i = 0; i < argc; ++i){
		switch(argv[i][0]){
			case '-':
				switch(argv[i][1]){
					case '-':
						if(argv[i][2] == 0 || argv[i][3] == 0 || argv[i][4] == 0 || argv[i][5] == 0 ){
							print_error(argv);
						}else if(argv[i][2] == 'h' && argv[i][3] == 'e' && argv[i][4] == 'l' && argv[i][5] == 'p'){
							write(1,"help\n",5);
							_exit(0);
						}else if(argv[i][6] == 0 || argv[i][7] == 0 || argv[i][8] == 0){
							print_error(argv);
						}else if(argv[i][2] == 'v' && argv[i][3] == 'e' && argv[i][4] == 'r' && argv[i][5] == 's' && argv[i][6] == 'i' && argv[i][7] == 'o' && argv[i][8] == 'n'){
							write(1,"version\n",8);
							_exit(0);
						}else{
							print_error(argv);
						}
					default:
						print_error(argv);
				}
			default:
				break;
		}
	}
	do{
		int word = 0;
		int counter = 0;
		while(argv[++word]){
			while(argv[word][counter++]);
			write(1,argv[word],counter);
			write(1," ",1);
			counter = 0;
		}
		write(1,"\n",1);
	}while(1);
	_exit(-1);
}
