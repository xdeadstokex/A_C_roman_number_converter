#include <stdio.h>
#include <unistd.h>  // Include for usleep
#include <string.h> // memset

#include "texts.h"
/////////////////////////////////////////////////
#define MAX_ROMAN_NUMBER_SIZE 32


// custom func prototype
int get_decimal_from_roman_number(texts* r_number);
void get_roman_number_from_decimal(texts* r_number, int number);
void print_roman_number(texts* r_number);
/////////////////////////////////////////////////

/////////////////////////////////////////////////
void run(){

char user_input[32];
texts roman_text;

printf("Type q to quit !\n");
printf("##################################################################\n");
for(;;){

printf("Type roman number: ");
scanf("%32s", user_input);
//fgets(user_input, 32, stdin);

if(user_input[0] == 'q') break;


get_texts(&roman_text, user_input);
//printf("repeat %d\n", get_texts_char_repeat_count(&roman_text, 'I'));
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
/////////////////////////////////////////////////

/////////////////////////////////////////////////
///////////CUSTOM_FUNC_IMPLEMENT/////////////////
/////////////////////////////////////////////////


/////////////////////////////////////////////////
#define TOTAL_VALUE 7


#define TYPE_NORMAL 0
#define TYPE_SPECIAL 1
#define TYPE_TRIPLET 2

struct black_lists{
int value_I_count;
int value_I_special_count; // for IX
int value_I_triplet_count; // for III

int value_V_count;
int value_V_special_count; // same
int value_V_triplet_count; // same

int value_X_count;
int value_X_special_count; // same
int value_X_triplet_count; // same

int value_L_count;
int value_L_special_count; // same
int value_L_triplet_count; // same

int value_C_count;
int value_C_special_count; // same
int value_C_triplet_count; // same

int value_D_count;
int value_D_special_count; // same
int value_D_triplet_count; // same

int value_M_count;
int value_M_special_count; // same
int value_M_triplet_count; // same
};
typedef struct black_lists black_lists;

// helper func

void add_blacklists_count(black_lists* black_list, int value, int black_list_value, int type){
if(value == 1){
if(type == TYPE_NORMAL){ black_list->value_I_count += black_list_value; }
else if(type == TYPE_SPECIAL){ black_list->value_I_special_count += black_list_value; }
else if(type == TYPE_TRIPLET){ black_list->value_I_triplet_count += black_list_value; }
}

else if(value == 5){
if(type == TYPE_NORMAL){ black_list->value_V_count += black_list_value; }
else if(type == TYPE_SPECIAL){ black_list->value_V_special_count += black_list_value; }
else if(type == TYPE_TRIPLET){ black_list->value_V_triplet_count += black_list_value; }
}

else if(value == 10){
if(type == TYPE_NORMAL){ black_list->value_X_count += black_list_value; }
else if(type == TYPE_SPECIAL){ black_list->value_X_special_count += black_list_value; }
else if(type == TYPE_TRIPLET){ black_list->value_X_triplet_count += black_list_value; }
}

else if(value == 50){
if(type == TYPE_NORMAL){ black_list->value_L_count += black_list_value; }
else if(type == TYPE_SPECIAL){ black_list->value_L_special_count += black_list_value; }
else if(type == TYPE_TRIPLET){ black_list->value_L_triplet_count += black_list_value; }
}

else if(value == 100){
if(type == TYPE_NORMAL){ black_list->value_C_count += black_list_value; }
else if(type == TYPE_SPECIAL){ black_list->value_C_special_count += black_list_value; }
else if(type == TYPE_TRIPLET){ black_list->value_C_triplet_count += black_list_value; }
}

else if(value == 500){
if(type == TYPE_NORMAL){ black_list->value_D_count += black_list_value; }
else if(type == TYPE_SPECIAL){ black_list->value_D_special_count += black_list_value; }
else if(type == TYPE_TRIPLET){ black_list->value_D_triplet_count += black_list_value; }
}

else if(value == 1000){
if(type == TYPE_NORMAL){ black_list->value_M_count += black_list_value; }
else if(type == TYPE_SPECIAL){ black_list->value_M_special_count += black_list_value; }
else if(type == TYPE_TRIPLET){ black_list->value_M_triplet_count += black_list_value; }
}
}



int check_blacklists_count(black_lists* black_list, int value, int type){
if(value == 1){
if(type == TYPE_NORMAL){ return black_list->value_I_count; }
else if(type == TYPE_SPECIAL){ return black_list->value_I_special_count; }
else if(type == TYPE_TRIPLET){ return black_list->value_I_triplet_count; }
}

else if(value == 5){
if(type == TYPE_NORMAL){ return black_list->value_V_count; }
else if(type == TYPE_SPECIAL){ return black_list->value_V_special_count; }
else if(type == TYPE_TRIPLET){ return black_list->value_V_triplet_count; }
}

else if(value == 10){
if(type == TYPE_NORMAL){ return black_list->value_X_count; }
else if(type == TYPE_SPECIAL){ return black_list->value_X_special_count; }
else if(type == TYPE_TRIPLET){ return black_list->value_X_triplet_count; }
}

else if(value == 50){
if(type == TYPE_NORMAL){ return black_list->value_L_count; }
else if(type == TYPE_SPECIAL){ return black_list->value_L_special_count; }
else if(type == TYPE_TRIPLET){ return black_list->value_L_triplet_count; }
}

else if(value == 100){
if(type == TYPE_NORMAL){ return black_list->value_C_count; }
else if(type == TYPE_SPECIAL){ return black_list->value_C_special_count; }
else if(type == TYPE_TRIPLET){ return black_list->value_C_triplet_count; }
}

else if(value == 500){
if(type == TYPE_NORMAL){ return black_list->value_D_count; }
else if(type == TYPE_SPECIAL){ return black_list->value_D_special_count; }
else if(type == TYPE_TRIPLET){ return black_list->value_D_triplet_count; }
}

else if(value == 1000){
if(type == TYPE_NORMAL){ return black_list->value_M_count; }
else if(type == TYPE_SPECIAL){ return black_list->value_M_special_count; }
else if(type == TYPE_TRIPLET){ return black_list->value_M_triplet_count; }
}

return 0; // fallback for invalid value/type
}



int get_decimal_from_roman_number(texts* r_number){
// remember that roman num dont get over 3999, so make sure to check the final value

if(r_number->size >= MAX_ROMAN_NUMBER_SIZE){ return -1; } // roman num are not that long

// check for invalid symbol, what is not "I V X L C D M"
static texts text_white_list;
static int init_text_white_list = 0;
if(!init_text_white_list){ get_texts(&text_white_list, "IVXLCDM"); }

if(!check_texts_present_only_this_char_bulk(r_number, &text_white_list)){ return -1; }



black_lists black_list;
memset(&black_list, 0x00, sizeof(black_lists)); // zero'ed every value in blacklist
//add_blacklists_count(&black_list, 10, 100, TYPE_SPECIAL); // occured 1 time
//printf("bll %d\n", black_list.value_X_special_count);
//printf("bll %d\n", check_blacklists_count(&black_list, 10, TYPE_SPECIAL));

int value_black_list[TOTAL_VALUE]; // to prevent getting invalid values, 7 is from I to M total amount of value
for(int a = 0; a < TOTAL_VALUE; ++a){ value_black_list[a] = 0; }

int value_list[MAX_ROMAN_NUMBER_SIZE];
for(int a = 0; a < r_number->size; ++a){
char char_cur = get_texts_char(r_number, a);
if(char_cur == 'I'){ value_list[a] = 1; }
else if(char_cur == 'V'){ value_list[a] = 5; }
else if(char_cur == 'X'){ value_list[a] = 10; }
else if(char_cur == 'L'){ value_list[a] = 50; }
else if(char_cur == 'C'){ value_list[a] = 100; }
else if(char_cur == 'D'){ value_list[a] = 500; }
else if(char_cur == 'M'){ value_list[a] = 1000; }
}

int return_value = 0;
int last_value = 0;
int special_loop = 0;
for(int a = 0; a < r_number->size;){
int loop_skip = 1;

int value_cur = value_list[a];
int value_n = 0;
int value_nn = 0;

int value_final = 0;

if(a < r_number->size - 1){ value_n = value_list[a + 1]; }
if(a < r_number->size - 2){ value_nn = value_list[a + 2]; }

int bl_count_normal_before = check_blacklists_count(&black_list, value_cur, TYPE_NORMAL);
int bl_count_special_before = check_blacklists_count(&black_list, value_cur, TYPE_SPECIAL);
int bl_count_triplet_before = check_blacklists_count(&black_list, value_cur, TYPE_TRIPLET);

if(special_loop){ ++special_loop; goto check; }

// section prefix work: IX -> 9
if(value_cur < value_n){
if(value_cur == 5 || value_cur == 50 || value_cur == 500){ value_final = -1; } // midway value cant be prefix

else if(value_cur * 5 == value_n || value_cur * 10 == value_n){
// only accept value that is in this form: v0 < v1, v1 = v0 * 5 or v1 = v0 * 10 aka IV, IX, not IL, IC,...
add_blacklists_count(&black_list, value_cur, 1, TYPE_SPECIAL); // occured 1 time
add_blacklists_count(&black_list, value_n, 1, TYPE_SPECIAL); // occured 1 time
value_final = value_n - value_cur;
special_loop = 1;
loop_skip = 1;
}

else{ value_final = -1; } // wrong prefix
}

else if(value_cur == value_n && value_cur == value_nn && value_n == value_nn){
if(value_cur == 5 || value_cur == 50 || value_cur == 500){ 
add_blacklists_count(&black_list, value_cur, 3, TYPE_SPECIAL); // midway value are unique, cant be triplet
}
else{ add_blacklists_count(&black_list, value_cur, 1, TYPE_TRIPLET); }
value_final = value_cur * 3;
loop_skip = 3;
}

else{
if(value_cur == 5 || value_cur == 50 || value_cur == 500){ 
add_blacklists_count(&black_list, value_cur, 1, TYPE_SPECIAL); // midway value are unique, cant be normal
}
else{ add_blacklists_count(&black_list, value_cur, 1, TYPE_NORMAL); } // pass most test
value_final = value_cur;
}

check:

int bl_count_normal = check_blacklists_count(&black_list, value_cur, TYPE_NORMAL);
int bl_count_special = check_blacklists_count(&black_list, value_cur, TYPE_SPECIAL);
int bl_count_triplet = check_blacklists_count(&black_list, value_cur, TYPE_TRIPLET);

//printf("n %d s %d t%d\n", bl_count_normal, bl_count_special, bl_count_triplet); // debug

if(bl_count_triplet > 1){ value_final = -1; goto end; } // only 1 triplet
if(bl_count_special > 1){ value_final = -1; goto end; } // only 1 special
if(bl_count_normal > 2){ value_final = -1; goto end; } // only 0-2 normal
if(bl_count_triplet == 1 && bl_count_normal > 0){ value_final = -1; goto end; } // cant have both triplet and normal
if(bl_count_special_before == 1 && bl_count_normal - bl_count_normal_before != 0){ value_final = -1; goto end; } // cant have normal after special
if(bl_count_special_before == 1 && bl_count_triplet - bl_count_triplet_before != 0){ value_final = -1; goto end; } // cant have triplet after special

//special case since cant have III...IX or the like
if(value_cur == 1){ 
if(bl_count_normal > 0 && bl_count_special == 1){ value_final = -1; goto end; }
if(bl_count_special == 1 && bl_count_triplet == 1){ value_final = -1; goto end; }
}

//printf("l_v %d c_v %d\n", last_value, value_final);
if(last_value < value_final && last_value != 0){ value_final = -1; } // prevent larger numberal to be BEHIND like C-M...

if(last_value > value_final){
// midway cant coexist with same rank (10, 100, 1000) specialists, like CM-D 900 + 500
if(value_final == 5){
if(last_value <= 10){ value_final = -1; }
}
if(value_final == 50){
if(last_value <= 100){ value_final = -1; }
}
if(value_final == 500){
if(last_value <= 1000){ value_final = -1; }
}


}


end:
if(value_final == -1){ return_value = 0; break; } // basically wrong roman number format, cant calc

if(special_loop == 2){
special_loop = 0;
a += loop_skip;
continue;
}

return_value += value_final;
last_value = value_final;
a += loop_skip;
}

return return_value;
}

#undef TOTAL_VALUE

#undef TYPE_NORMAL
#undef TYPE_SPECIAL
#undef TYPE_TRIPLET
/////////////////////////////////////////////////


/////////////////////////////////////////////////
void get_roman_number_from_decimal(texts* r_number, int number){

}
/////////////////////////////////////////////////

/////////////////////////////////////////////////
void print_roman_number(texts* r_number){
//if(r_number->current_size > 0){ printf("roman number: %s\n", r_number->text); }
//else{ printf("invalid roman number\n"); }
}
/////////////////////////////////////////////////








