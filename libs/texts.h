#ifndef TEXTS_H
#define TEXTS_H

struct texts{
char* data;
int size;
};
typedef struct texts texts;


void get_texts(texts* text, const char* input_text);
void print_texts(texts* text);
void print_texts_range(texts* text, int total_chars);
void print_texts_char(texts* text, int char_idx);

char get_texts_char(texts* text, int char_idx);

int check_texts_have_char(texts* text, char tagret_char);
int check_texts_have_char_bulk(texts* text, texts* tagret_char_list);

int check_texts_present_only_this_char(texts* text, char tagret_char);
int check_texts_present_only_this_char_bulk(texts* text, texts* tagret_char_list);

int get_texts_char_repeat_count(texts* text, char tagret_char);
#endif // TEXTS_H

