#ifndef TEXTS_H
#define TEXTS_H

struct texts{
char* data;
int size;
int cap;
};
typedef struct texts texts;


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
#endif // TEXTS_H

