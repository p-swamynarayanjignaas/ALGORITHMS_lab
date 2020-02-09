////////////////////////
//header file for STACK to store characters
//contains functions push,pop,peek,display,overflow,underflow
//to use this header file initialize a variable with datatype stack
//eg:-stack s;
//initialize top =-1
//eg:-s.top=-1;



#define MAX 10

typedef struct{
	char item[MAX];
	int top;
}stack;

void push(stack *s,char c);
char pop(stack *s);
char peek(stack *s);
int isEmpty(stack *s);
int isFull(stack *s);
void stack_display(stack *s);

//push function
//pushes the element into stack
void push(stack *s,char c){
	if(!isFull(s)){
		s->top++;
		s->item[s->top]=c;
	}
}

//pop function
//deletes the top element in stack
char pop(stack *s){
	if(!isEmpty(s)){
		return s->item[s->top--];
	}
}

//peek function
//enables to look into the element at top in stack
char peek(stack *s){
	if(!isEmpty(s)){
		return s->item[s->top];
	}
}

//isEmpty function
//tells if stack is empty(UnderFlow)
int isEmpty(stack *s){
	if(s->top==-1){
		return 1;
	}
	return 0;
}

//isFull function
//tells if stack is full(OverFlow)
int isFull(stack *s){
	if(s->top>=MAX-1){
		return 1;
	}
	else
		return 0;
}

//display function
//displays the elements in stack
void stack_display(stack *s){
	for(int i=s->top;i>=0;i--){
		printf("%c",s->item[i]);
	}
}
