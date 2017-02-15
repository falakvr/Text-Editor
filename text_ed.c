#include <stdio.h>
#include <stdlib.h>

typedef struct text_t {
	int key;
	struct text_t *left;
	struct text_t *right;
	int height;
} text_t;

text_t * create_text(){
	text_t *tmp_node;
	tmp_node = (text_t *)malloc(sizeof(text_t));
	tmp_node->left = NULL;
	tmp_node->right = NULL;
	tmp_node->key = 0;
	tmp_node->height = 0;

	return tmp_node;
}

int length_text(text_t *txt){
	text_t *temp = txt;
	if (txt == NULL){
		return -1;
	} else if (temp->left == NULL){
		return 0;
	} else {
		return txt->key;
	}
}
