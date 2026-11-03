#ifndef TEXTS_H
#define TEXTS_H
#include <stdio.h> // printf
#include <stdlib.h> // malloc
#include <string.h> //memcpy

//void text_rewrite(void* text, int type_size, const char* input);
//void text_overide(void* text, int type_size, const char* input, int begin_offset);
//void text_print(void* text, int type_size);

//#define SET_TEXT(t) ((t)->cap = sizeof((t)->data), (t)->size = 0)

typedef struct {
//int cap;
int size;
char data[256];
} text_256;



typedef struct {
//int cap;
int size;
char data[1024];
} text_1024;

typedef struct {
//int cap;
int size;
char data[4096];
} text_4096;


#define text_write(t, input) \
_text_write(t, input, sizeof((t)->data))

static void _text_write(void* text, const char* input, int cap){
int* size = (int*) text;
char* data = (char*)(text) + sizeof(int);

register int input_size = strlen(input);
input_size = (input_size < cap) ? input_size : cap;
//memset(data, 0x00, cap);
memcpy(data, input, input_size);
*size = input_size;
return;
}


#define text_append(t, input) \
_text_append(t, input, sizeof((t)->data))

static void _text_append(void* text, const char* input, int cap){
int* size = (int*) text;
char* data = (char*)(text) + sizeof(int);

register int input_size = strlen(input);
input_size = (input_size < cap - *size) ? input_size : cap - *size;
memcpy(data + *size, input, input_size);
*size += input_size;
return;
}


#define text_print(t, len) \
_text_print(t, len, sizeof((t)->data))

static void _text_print(void* text, int len, int cap){
int size = *(int*) text;
if(len >= 0 && len <= size){ size = len; }
char* data = (char*)(text + sizeof(int));
printf("%.*s", (size < cap) ? size : cap, data);
}



static int get_int_from_chars(const char* string){
return atoi(string);
}


#define text_copy(dst, src, dst_offset, len) \
_text_copy(dst, src, dst_offset, len, sizeof((dst)->data))

static void _text_copy(void* dst, void* src, int dst_offset, int len, int dst_cap){
int* dst_size = (int*) dst;
int* src_size = (int*) src;
char* dst_data = (char*)(dst) + sizeof(int);
char* src_data = (char*)(src) + sizeof(int);
if(dst_offset < 0 || dst_offset >= dst_cap){ return; }

int copy_size = len;
if(copy_size < 0 || copy_size > *src_size){ copy_size = *src_size; }
if(copy_size > dst_cap - dst_offset){ copy_size = dst_cap - dst_offset; }

if(dst_offset > *dst_size){
memset(dst_data + *dst_size, ' ', dst_offset - *dst_size);
}
memcpy(dst_data + dst_offset, src_data, copy_size);

if(dst_offset + copy_size <= *dst_size){ return; } // keep old size
*dst_size = dst_offset + copy_size;
return;
}



#define text_get(dst, src, src_offset, len) \
_text_get(dst, src, src_offset, len, sizeof((dst)->data))

static void _text_get(void* dst, void* src, int src_offset, int len, int dst_cap){
int* dst_size = (int*) dst;
int* src_size = (int*) src;
char* dst_data = (char*)(dst) + sizeof(int);
char* src_data = (char*)(src) + sizeof(int);
if(src_offset < 0 || src_offset >= *src_size){ return; }

int copy_size = len;
if(copy_size < 0 || copy_size > *src_size - src_offset){ copy_size = *src_size - src_offset; }
if(copy_size > dst_cap){ copy_size = dst_cap; }

memcpy(dst_data, src_data + src_offset, copy_size);

*dst_size = copy_size;
return;
}


static int text_find(void* dst, void* src){
int* dst_size = (int*) dst;
int* src_size = (int*) src;
char* dst_data = (char*)(dst) + sizeof(int);
char* src_data = (char*)(src) + sizeof(int);

int first_found_i = -1;
int src_i = 0;
for(int dst_i = 0; dst_i < *dst_size; dst_i += 1){
//printf("dst_i %d\n", dst_i);

if(src_data[src_i] != dst_data[dst_i]){
//printf("dif dst %c src %c\n", src_data[src_i], dst_data[dst_i]);
first_found_i = -1;
src_i = 0;

if(src_data[src_i] != dst_data[dst_i]){ continue; }
}

if(first_found_i < 0){ first_found_i = dst_i; }
src_i += 1;
//if(src_i >= *dst_size && src_i < *src_size){ return -1; }
if(src_i >= *src_size){ return first_found_i; }
}

return -1;
}



static int get_int_from_string(const char* string){
return atoi(string);
}





/*
get text from  num
char canva_zoom_text[5];
int canva_zoom_text_len = sprintf(canva_zoom_text, "%d", (int)(canva_zoom * 100));

*/
/*
void _text_write(void* text, const char* input, int offset, int cap){
int* size = (int*) text;
char* data = (char*)(text + sizeof(int));
if(offset < 0 || offset >= cap){ return; }
data += offset;
register int data_size_remain = cap - offset;

register int input_size = strlen(input);
input_size = (input_size < data_size_remain) ? input_size : data_size_remain;
memcpy(data, input, input_size);

if(*size < offset + input_size){ *size = offset + input_size; }
return;
}
*/

//#############################################################################



/*
// consider return all copy value, aka the so called "mighty" stateless, since texts is extremely light weight.
// get all name to conventional texts_...

void texts_get(texts* text, const char* input_text);
texts texts_create(int cap); // blank texts

void texts_empty(texts* text); // Fast data, size clear, keep memory allocated, keep cap
void texts_reset(texts* text); // Full wipe, deallocate data, zero'ed fields
void texts_free(texts* text); // FREE the heap texts and the data inside

void texts_append(texts* text, const char* input_text, int size);
void texts_append_char(texts* text, const char input_char);

void print_texts(texts* text);
void print_texts_range(texts* text, int total_chars);
void print_texts_char(texts* text, int char_idx);

char get_texts_char(texts* text, int char_idx);

int check_texts_have_char(texts* text, char tagret_char);
int check_texts_have_char_bulk(texts* text, texts* tagret_char_list);

int check_texts_present_only_this_char(texts* text, char tagret_char);
int check_texts_present_only_this_char_bulk(texts* text, texts* tagret_char_list);

int get_texts_char_repeat_count(texts* text, char tagret_char);

int get_int_from_string(const char* string);
*/




/*
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




void texts_empty(texts* text){
memset(text->data, 0x00, text->cap);
text->size = 0;
}


void texts_reset(texts* text){
free(text->data);
text->data = NULL;  // Prevent double-free accidents
text->size = 0;
text->cap = 0;
}


void texts_free(texts* text){
free(text->data);
free(text);
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



void texts_append_char(texts* text, const char input_char){
if(text->size + 1 > text->cap){
text->cap = text->size * 2 + 1 + 1;
char* temp_data = malloc(text->cap);
memcpy(temp_data, text->data, text->size);
free(text->data);
text->data = temp_data;
}

memcpy(text->data + text->size, &input_char, 1);
text->size += 1;
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



*/











#endif // TEXTS_H

