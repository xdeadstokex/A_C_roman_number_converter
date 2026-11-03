/*
API:
int get_decimal_from_roman_number(text_1024* r_number)
text_1024 get_roman_number_from_decimal(int number)
*/

#ifndef ROMAN_NUMBER_CONVERTER_H
#define ROMAN_NUMBER_CONVERTER_H

#include "texts.h"
#include <stdio.h>
#include <string.h> // memset

#define MAX_ROMAN_NUMBER_SIZE 32

#define TYPE_NORMAL 0
#define TYPE_SPECIAL 1
#define TYPE_TRIPLET 2

typedef struct {
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
} black_lists;

/////////////////////////////////////////////////
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
/////////////////////////////////////////////////

/////////////////////////////////////////////////
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
/////////////////////////////////////////////////

/////////////////////////////////////////////////
int get_decimal_from_roman_number(text_1024* r_number){
if(r_number->size >= MAX_ROMAN_NUMBER_SIZE){ return -1; } // roman num are not that long


static text_1024 text_white_list;
static int init_text_white_list = 0;
if(!init_text_white_list){
init_text_white_list = 1;
text_write(&text_white_list, "IVXLCDM");
}

// check for invalid symbol, what is not "I V X L C D M"
for(int i = 0; i < r_number->size; i += 1){
text_1024 temp;
text_get(&temp, r_number, i, 1);
if(text_find(&text_white_list, &temp) == -1){ return -1; }
}



black_lists black_list;
memset(&black_list, 0x00, sizeof(black_lists)); // zero'ed every value in blacklist

// preparing value list table
int value_list[MAX_ROMAN_NUMBER_SIZE];
for(int a = 0; a < r_number->size; ++a){
char char_cur = r_number->data[a];
if(char_cur == 'I'){ value_list[a] = 1; }
else if(char_cur == 'V'){ value_list[a] = 5; }
else if(char_cur == 'X'){ value_list[a] = 10; }
else if(char_cur == 'L'){ value_list[a] = 50; }
else if(char_cur == 'C'){ value_list[a] = 100; }
else if(char_cur == 'D'){ value_list[a] = 500; }
else if(char_cur == 'M'){ value_list[a] = 1000; }
}

// process the roman text
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
if(bl_count_special > 1){
if(value_cur == 1 || value_cur == 5 || value_cur == 50 || value_cur == 500 || value_cur == 1000){ value_final = -1; goto end; } // I M and midway have one special
else if(bl_count_special > 2){ value_final = -1; goto end; } // other special <= 2
}
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
if(last_value < value_final && last_value != 0){ value_final = -1; goto end; } // prevent larger numberal to be BEHIND like C-M...

if(last_value > value_final){
// midway cant coexist with same rank (10, 100, 1000) specialists, like CM-D 900 + 500
if(value_final == 5 && last_value < 10){ value_final = -1; goto end; }
if(value_final == 50 && last_value < 100){ value_final = -1; goto end; }
if(value_final == 500 && last_value < 1000){ value_final = -1; goto end; }
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

#undef TYPE_NORMAL
#undef TYPE_SPECIAL
#undef TYPE_TRIPLET
/////////////////////////////////////////////////


/////////////////////////////////////////////////
// helper func
void _append_roman_rank(text_1024* text, int rank, const char* bottom_value, const char* mid_value, const char* top_value){
if(rank >= 10){ return; }

// ex: IX
if(rank == 9){
text_append(text, bottom_value);
text_append(text, top_value);
return;
}

// ex: VI, VII, VIII
if(rank >= 5 && rank < 9){
text_append(text, mid_value);
for(int a = 0; a < rank - 5; ++a){ text_append(text, bottom_value); }
return;
}

// ex: IV
if(rank == 4){
text_append(text, bottom_value);
text_append(text, mid_value);
return;
}

// ex: I, II, III
if(rank < 4){
for(int a = 0; a < rank; ++a){ text_append(text, bottom_value); }
return;
}

return;
}


text_1024 get_roman_number_from_decimal(int number){
// init text space
text_1024 text_return;
text_return.size = 0;
// roman num dont get over 3999
if(number <= 0 || number > 3999){ return text_return; }

int thousand_rank = (int)(number / 1000) * 1000;						// ex: 1234 -> 1000
int unit_rank = number - (int)(number / 10) * 10;						// ex: 1234 - 1230
int decimal_rank = number - unit_rank - (int)(number / 100) * 100;		// ex: 1234 - 4 - 1200
int hundred_rank = number - unit_rank - decimal_rank - thousand_rank;	// ex: 1234 - 4 - 30 - 1000

thousand_rank = thousand_rank / 1000;
for(int a = 0; a < thousand_rank; ++a){ text_append(&text_return, "M"); }

_append_roman_rank(&text_return, hundred_rank / 100, "C", "D", "M");
_append_roman_rank(&text_return, decimal_rank / 10, "X", "L", "C");
_append_roman_rank(&text_return, unit_rank, "I", "V", "X");

//printf("num: %d %d %d %d ", thousand_rank, hundred_rank, decimal_rank, unit_rank);

return text_return;
}




















#endif // ROMAN_NUMBER_CONVERTER_H

