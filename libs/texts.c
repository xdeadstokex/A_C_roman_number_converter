#include "texts.h"

#include <stdio.h> // printf
#include <stdlib.h> // malloc
#include <string.h> //memcpy

//#############################################################################
void texts_get(texts* text, const char* input_text){
text->size = 0;
for(int a = 0; input_text[a] != 0; ++a){ ++text->size; }
text->cap = text->size * 2 + 1;
text->data = malloc(text->cap);
memcpy(text->data, input_text, text->size);
}

texts texts_create(int cap){
texts text;
text.data = malloc(cap);
text.cap = cap;
text.size = 0;
return text;
}
//#############################################################################
void texts_append(texts* text, const char* input_text, int size){
if(text->size + size > text->cap){
text->cap = text->size * 2 + size + 1;
char* temp_data = malloc(text->cap);
memcpy(temp_data, text->data, text->size);
free(text->data);
text->data = temp_data;
}

memcpy(text->data + text->size, input_text, size);
text->size += size;
}






//#############################################################################

void print_texts(texts* text){
printf("%.*s", text->size, text->data);
}

void print_texts_range(texts* text, int total_chars){
printf("%.*s", (total_chars > text->size) ? text->size : total_chars, text->data);
}

void print_texts_char(texts* text, int char_idx){
if(char_idx < text->size){ printf("%c",text->data[char_idx]); }
}

char get_texts_char(texts* text, int char_idx){
if(char_idx < text->size){ return text->data[char_idx]; }
return 0;
}

int check_texts_have_char(texts* text, char tagret_char){

}

int check_texts_have_char_bulk(texts* text, texts* tagret_char_list){
for(int a = 0; a < text->size; ++a){
for(int b = 0; b < tagret_char_list->size; ++b){
if(text->data[a] == tagret_char_list->data[b]){ return 1; }
}
}
return 0;
}



int check_texts_present_only_this_char(texts* text, char tagret_char){

}

int check_texts_present_only_this_char_bulk(texts* text, texts* tagret_char_list){
for(int a = 0; a < text->size; ++a){

register int b = 0;
for(; b < tagret_char_list->size; ++b){
if(text->data[a] == tagret_char_list->data[b]){ break; }
}

if(b == tagret_char_list->size){ return 0; }
}
return 1;
}



int get_texts_char_repeat_count(texts* text, char tagret_char){
int a = 0;
for(; a < text->size; ++a){
if(text->data[a] != tagret_char){ break; }
}
return a;
}


