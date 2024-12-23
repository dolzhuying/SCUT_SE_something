#include <iostream>

struct Stack {
    int *arr; 
    int capacity;  
    int top;  

    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool push(int value) {
        if (top >= capacity - 1) {
            return false;  // 栈满
        }
        arr[++top] = value;
        return true;
    }

    int pop() {
        if (top < 0) {
            return -1;  // 栈空
        }
        return arr[top--];
    }

    int topElement() const {
        if (top < 0) {
            return -1;  // 栈空
        }
        return arr[top];
    }

    bool isEmpty() const {
        return top == -1;
    }
};

//ppt
/* 链表实现栈
template <typename E> class LStack: public Stack<E> {
private:
	Link<E>* top;	//pointer to first element
	int size; 		//number of elements
public:
     LStack(int sz = defaultSize){ 	//Constructor            
           top = NULL; size = 0;
    }
    ~LStack()  { clear(); }		//Destructor
    void clear() {			//reinitialize
	  while (top != NULL) { 	//delete link nodes
	      Link<E>* temp = top; top = top->next; delete temp;
	  }
	  size = 0;
 }
 void push(const E& it) { 	//put “it” on the stack
	   top = new Link<E>(it, top); size++;
 }
 E pop() { 				//remove “it” from stack
	  Assert(top != NULL, “Stack is empty”);
	  E it = top->element;
	  Link<E>* ltemp = top->next;
	  delete top;  top = ltemp;  size--; return it;
 }
 const E& topValue() const { 	//return top value
	  Assert(top != 0, “Stack is empty”);
	  return top->element;
 }


*/