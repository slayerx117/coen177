void sc(list* pagetable, int page){
	//find first page that isnt protected by sc, and replace it
	//dont need to do all the linkedlist conditional stuff cus this function is only ever called when the list is full.
	Node* current = pagetable->head;
	while(current){
		if(current->sc){
			//iterate through list, use every second chance
			current->sc = 0;
		}
		else{
			//first one without a second chance is turned into the new data
			current->data = page;
			return;
		}
		//if every list element has a second chance, set them all to 0, loop back to the beginning
		pagetable->head->data = page;
	}
}
