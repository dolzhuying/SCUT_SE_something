/*
template <typename E> class LList: public List<E>{
	private:
  		Link<E>* head; 
  		Link<E>* tail; 
		Link<E>* curr; 
	 	int cnt;      
		void init()
    	{  curr = tail = head = new Link<E>; cnt =0;}		
		void removeall() 
		{   while(head != NULL) { 
                 curr=head; head=head->next; delete curr;
              }
        }
    public:
	  void insert(const E& it) {
		curr->next = new Link<E>(it, curr->next);  	
  		if (tail == curr) tail = curr->next; 
		cnt++;
	  }

	  void append(const E& it) {
  		tail = tail->next = new Link<E>(it, NULL);
  		cnt++;
  	  }

      E remove() {
		E it = curr->next->element;
		Link<E> *ltemp = curr->next; 删除curr-》next
		if (tail == curr->next) 
			tail =curr; // Reset tail
		curr->next = curr->next->next;       //remove element
		delete ltemp;  
		cnt--;	  
		return it;
	}

    void next() { // no change if already at end
 		if (curr != tail) { curr = curr->next;}
	}

	void prev() {
      if (curr == head) return; // No previous element
      Link<E>* temp = head;
	  while (temp->next!=curr) temp=temp->next;
  	  curr = temp;
    }

}

*/