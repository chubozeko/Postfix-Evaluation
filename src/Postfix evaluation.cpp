#include <cstdlib>
#include <iostream>
#define STACKSIZE 20

struct stack{
    int items[STACKSIZE];
    int top;
};

void initStack(struct stack *s);
int is_empty(struct stack *s);
int is_full(struct stack *s);
void push(struct stack *s, char);
char pop(struct stack *s);
double calculate(int,int,char);
int checkNumber(int);

using namespace std;

int main(int argc, char *argv[])
{
	char symb[20];
	int num1, num2, temp; 
	double value;
	struct stack s;
	initStack(&s); //Initialize stack
	cout<<"Enter postfix equation: ";
	cin>>symb;
	int i=0;
	while(symb[i]!=NULL)
	{	// check if it's an operand
		if(symb[i]!='+' && symb[i]!='-' && symb[i]!='*' && symb[i]!='/' && 
			symb[i]!='$' && symb[i]!='(' && symb[i]!=')' && symb[i] != '[' && 
			symb[i]!='{' && symb[i]!=']' && symb[i]!='}') 
		{
			temp = checkNumber(symb[i]);
			push(&s, temp);
		}			
		else 
		{
			num2 = pop(&s);
			num1 = pop(&s);
			value = calculate(num1, num2, symb[i]);
			push(&s,value);
		}
		i++;	
	}
	value = pop(&s);
	cout<<"Result: "<<value<<endl;
    system ("PAUSE");
    return 0;
}

double calculate(int num1,int num2, char o)
{
	double result;
	switch (o)
	{
		case '+':	result = num1 + num2;	break;
		case '-':	result = num1 - num2;	break;
		case '*':	result = num1 * num2;	break;
		case '/':	result = num1 / num2;	break;
		default:	break;
	}
	return result;
}

int checkNumber(int x)
{
	int num;
	switch (x)
	{
		case '1':	num = 1;	break;
		case '2':	num = 2;	break;
		case '3':	num = 3;	break;
		case '4':	num = 4;	break;
		case '5':	num = 5;	break;
		case '6':	num = 6;	break;
		case '7':	num = 7;	break;
		case '8':	num = 8;	break;
		case '9':	num = 9;	break;
		case '0':	num = 0;	break;
		default:	break;
	}
	return num;
}

void initStack(struct stack *s)
{
        s->top = - 1;
}

int is_empty(struct stack *s)
{
        if(s->top == -1)
            return 1;
        else
            return 0;
}

int is_full(struct stack *s)
{
        if(s->top == STACKSIZE-1)
            return 1;
        else
            return 0;
}

void push(struct stack *s, char x)
{
    if(is_full(s))        
    {
        printf("Overflow: Stack is full");
        exit(1);
    }
    s->top++;
    s->items[s->top]=x;
}
char pop(struct stack *s)
{
    if(is_empty(s)==1)    
    {
        printf("Underflow: Stack is empty");
        exit(1);
    }
    return s->items[(s->top)--];
}

void printstack(struct stack *s)
{
    int x;
    struct stack temp;
    initStack(&temp);
     
    while (!is_empty(s))
    {
        x = pop(s);
        cout<<x<<" ";
        push(&temp,x);
    }
    while (!is_empty(&temp))
    {
        x = pop(&temp);
		push(s,x);
    }
    cout<<endl;
}


