#include <stdio.h>
#include <cstdint>
#include <arpa/inet.h>
#include <fstream>
using namespace std;

int ReadFile(const char* filename){
	FILE* file;
	uint32_t num;
	
	file=fopen(filename, "rb");
	if(file!=NULL){
		size_t readSize = fread(&num, 1, sizeof(uint32_t), file);

		if(readSize < sizeof(uint32_t)){
			printf("file is too small(under 4byte)\n");
			return 0;
		}
	}
	else printf("cannot open file\n");
	fclose(file);
	return ntohl(num);
}

int main(int argc, char* argv[]){
	int numbers[10]= {};
	uint32_t sum=0;

	for(int i=1; i<argc; i++){
		numbers[i]=ReadFile(argv[i]);
		printf("%d(0x0000%04x)", numbers[i], numbers[i]);
		sum+=numbers[i];
		if(i!=argc-1){
			printf(" + ");
		}
	}
	printf(" = %d(0x0000%04x)", sum, sum);
	
}
