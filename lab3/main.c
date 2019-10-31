#include <stdio.h>
#include <stdlib.h>
#include "algs.h"
int parseSize(int argc, char *argv[]) {
    int tableSize;
    if(argc == 2 && (tableSize = atoi(argv[1]))) {
        return tableSize;
    }
    fprintf(stderr, "Wrong arguments. Pass tableSize as an argument\n");
    exit(-1);
}

int isInMemory(int pageRequest, List *pageTable, int alg) {
    if(pageTable == NULL){
	return 0;
    }
    Node* temp = pageTable->head;
    while(temp->next =! NULL) {
        if(temp->data == pageRequest) {
          if(alg == 2) temp->sc = 1;   //set lifeline to 1
		return 1;
        }
	temp = temp->next;
    }
    free(temp);
    return 0;
}
int parseAlg(int argc, char *argv[]){
 	if(argc == 2){
   		char* alg = argv[0];
		if(strcmp(alg,"-fifo")) return 0;
		if(strcmp(alg, "-lru")) return 1;
 		if(strcmp(alg, "-sc")) return 2;
 	    	fprintf(stderr, "%s is an undefined algorithm type.\n", alg);
		exit(-1);
	}

	fprintf(stderr, "Invalid number of arguments.");
	exit(-1);
}
int main(int argc, char *argv[]) {
    //argument parsing
    int alg = parseAlg(argc, argv);
    int tableSize = parseSize(argc, argv);
    //table creation
    int pageRequest, pageTableIndex = 0, numRequest = 0, numMisses = 0;
    List *pageTable = NULL;

    //file io creation
    char *input = NULL;
    FILE *access = fopen("./access.txt", "r");
    FILE *output = fopen("./output", "w");

    //io loop
    while(fgets(input, 5, access)) {
        pageRequest = atoi(input);
        if(pageRequest == 0) {
            continue;
        }
        numRequest++;
        if(!isInMemory(pageRequest, pageTable, alg)) {
            fprintf("Page %d caused a page fault.\n", pageRequest, output);
            numMisses++;
            if(pageTableIndex < tableSize) {
		            appendHead(pageTable, pageRequest);
            	  pageTableIndex++;
	          } else {
                switch(alg)
		                {
			                   case 0: //fifo -> if page fault, just replace the least recently used page
				                            replaceTail(pageTable, pageRequest);
			                   case 1: // lru -> functionally same as fifo
				                            replaceTail(pageTable, pageRequest);
			                   case 2: // sc -> do second chance stuff
				                            sc(pageTable, pageRequest);
		                }
            }
	       } else {// is in memory
           if(alg == 1){ // lru -> in memory, move to front of list(make most recent)
        	    delete(pageRequest, pageTable);
			        appendHead(pageTable, pageRequest);
		       }
           //isInMemory automatically updates the lifeline/second chance variable if the data is already in memory
        }
    }
    fpritntf("Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest, output);
    fclose(access);
    fclose(output);
    free(input);
    free(pageTable);
    return 0;
}
