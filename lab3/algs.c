voidd sc(Node* pageTable, int page){
	//find first node without lifeline and replace
	Node* temp = pageTable->head;
	while(temp->next != NULL){
		if(temp->sc == 0){
			updatePage(temp, page);
			free(temp);
			return;
		}
		updateSC(temp, 0);
	}
	free(temp);
	fprintf(stderr, "something went wrong in sc");
	exit(-1);
	}
