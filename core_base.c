#include <stdio.h>

#include "texts.h"
#include "roman_number_converter.h"

/////////////////////////////////////////////////
void run(){
/*
char user_input[32];
texts roman_text;

printf("Type q to quit !\n");
printf("##################################################################\n");
for(;;){

printf("Type roman number: ");
scanf("%32s", user_input); // input from terminal

if(user_input[0] == 'q') break;

texts_get(&roman_text, user_input);

printf("confirmed roman number: ");
print_texts(&roman_text);
printf(" size %d \n", roman_text.size);

int final_dec_value = get_decimal_from_roman_number(&roman_text);
if(final_dec_value > 0){ printf("decimal value: %d\n", final_dec_value); }
else{
printf("INVALID ROMAN NUMBER: ");
print_texts(&roman_text);
printf("\n");
}
printf("##################################################################\n");
}
*/
for(int a = 0; a < 4000; ++a){
texts roman_text = get_roman_number_from_decimal(a);
printf("roman text: ");
print_texts(&roman_text);
printf("       ");
if((a + 1) % 4 == 0){ printf("\n"); }
}
return;
}
/////////////////////////////////////////////////


/////////////////////////////////////////////////
// Entry point - completely self-contained
int main(int argc, char** argv){
(void)argc; (void)argv; // suppress unused warnings
run();
return 0;
}









