#include <stdio.h>

#include "texts.h"
#include "roman_number_converter.h"

/////////////////////////////////////////////////
void run(){

int mode = 0;
char user_input[32];
texts roman_text;

printf("Type q to quit !\n");
printf("Type m to change mode !\n");
printf("Current mode roman->decimal !\n");
printf("##################################################################\n");


for(;;){
if(!mode){
printf("Type input: ");
scanf("%32s", user_input); // input from terminal
if(user_input[0] == 'q'){ break; }
if(user_input[0] == 'm'){ mode = 1; continue; }

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
}

if(mode){
printf("Type input: ");
scanf("%32s", user_input); // input from terminal
if(user_input[0] == 'q'){ break; }
if(user_input[0] == 'm'){ mode = 0; continue; }
int num = get_int_from_string(user_input);

texts roman_text = get_roman_number_from_decimal(num);
if(roman_text.size > 0){
printf("Roman text: ");
print_texts(&roman_text);
printf("\n");
}
else{
printf("ONLY INPUT NUMBER FROM 1 -> 3999 !\n");
}

texts_reset(&roman_text);
}



printf("##################################################################\n");
}


/*
int unmatch_count = 0;
//int match_size_count = 0;
for(int a = 0; a < 4000; ++a){
texts roman_text = get_roman_number_from_decimal(a);
printf("roman text: ");
print_texts(&roman_text);
printf(" ");

int final_dec_value = get_decimal_from_roman_number(&roman_text);
if(final_dec_value > 0){ printf("decimal value: %d", final_dec_value); }
else{
printf("INVALID ROMAN NUMBER: ");
print_texts(&roman_text);
}

if(a == final_dec_value){ printf(" MATCH "); }
else{ unmatch_count++; printf(" UNMATCH "); }

//if(roman_text.size <= 3){
//++match_size_count;
//print_texts(&roman_text);
//printf("\n");
//}

printf("\n");

texts_reset(&roman_text);
}

printf("UNMATCH COUNT: %d \n", unmatch_count);
//printf("MATCH SIZE COUNT: %d \n", match_size_count);
*/


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









