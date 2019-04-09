#include <string.h>
#include "stack.h"

int main() {
    int max_line = 105000;
	char input_buffer[max_line];
	int input_len = 0;	
	int answer=0;

	fgets(input_buffer, max_line, stdin);	
	input_buffer [strcspn (input_buffer, "\r\n")] = '\0';  //remove end-of-line characters

    input_len = strlen(input_buffer);
    printf("%d characters were read.\n",input_len);
    // printf("The input was: '%s'\n",input_buffer);
	fflush(stdout);
    Stack * opening_brackets_stack = createStack(max_line); 
    for (int position = 0; position < input_len; ++position) {
        char next = input_buffer[position];
        Bracket new;
        new.position=position;
        if (next == '(' || next == '[' || next == '{') {
            if (next=='(')
                new.type=ROUND;
            else if (next=='[')
                new.type=SQUARE;
            else
                new.type=CURLY;
            push(opening_brackets_stack, new);
            // Process opening bracket, write your code here
        }

        if (next == ')' || next == ']' || next == '}') {
            if (isEmpty(opening_brackets_stack)){
                answer=new.position+1;
                break;
            }
            Bracket last=pop(opening_brackets_stack);
            if ((last.type==ROUND && next!=')') || (last.type==SQUARE && next!=']')||(last.type==CURLY && next!='}')){
                answer=new.position+1;
                //printf("spec:%d\n",new.position+1);
                break;
            }
            // Process closing bracket, write your code here
        }
    }
    if (!isEmpty(opening_brackets_stack) && answer==0)
        answer=(opening_brackets_stack->array[opening_brackets_stack->top].position)+1;
    // Printing answer, write your code here
	printf("My result is:\n");
    if (answer==0)
        printf("Success\n");
    else
        printf("%d\n",answer);
    
    return 0;
}
