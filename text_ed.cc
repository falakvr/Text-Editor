#include <stdio.h>
#include <stdlib.h>

#define debug 0

struct text_t {
	int key;
	struct text_t *left;
	struct text_t *right;
	int height;
};

text_t * create_text() {
	text_t *tmp_node;
	tmp_node = (text_t *) malloc(sizeof(text_t));
	tmp_node->left = NULL;
	tmp_node->right = NULL;
	tmp_node->key = 0;
	tmp_node->height = 0;

	return tmp_node;
}

void left_rotation(text_t *n) {
	text_t *tmp_node;
//	key_t tmp_key;
	tmp_node = n->left;
//	tmp_key = n->key;
	n->left = n->right;
//	n->key   = n->right->key;
	n->right = n->left->right;
	n->left->right = n->left->left;
	n->left->left = tmp_node;
	//n->left->key = tmp_key;

	n->left->key = n->left->left->key + n->left->right->key;
	//n->right->key = n->right->left->key + n->right->right->key;
}

void right_rotation(text_t *n) {
	text_t *tmp_node;
//  key_t        tmp_key;
	tmp_node = n->right;
//  tmp_key  = n->key;
	n->right = n->left;
	//n->key = n->left->key;
	n->left = n->right->left;
	n->right->left = n->right->right;
	n->right->right = tmp_node;
//  n->right->key   = tmp_key;

//n->left->key = n->left->left->key + n->left->right->key;
	n->right->key = n->right->left->key + n->right->right->key;
}

int length_text(text_t *txt) {
	text_t *temp = txt;
	if (txt == NULL) {
		return -1;
	} else if (temp->left == NULL) {
		return 0;
	} else {
		return txt->key;
	}
}

char * get_line(text_t *txt, int index) {
	char * line = "Pending";
	return line;
}

void append_line(text_t *txt, char * new_line) {
	text_t *tmp_node;
	int finished = 0;
	if (txt->left == NULL) {
		if (debug)
			printf("Inside append 0\n");
		txt->left = (text_t *) new_line;
		txt->key = 1;
		txt->height = 0;
		txt->right = NULL;
	} else {
		if (debug)
			printf("Inside append 1\n");
		text_t * path_stack[100];
		int path_st_p = 0;
		tmp_node = txt;
		while (tmp_node->right != NULL) {
			if (debug)
				printf("Inside append 1.1\n");
			tmp_node->key++;
			path_stack[path_st_p++] = tmp_node;
			tmp_node = tmp_node->right;
		}
		if (debug)
			printf("Inside append 2\n");
		text_t *old_leaf, *new_leaf;
		old_leaf = create_text();
		old_leaf->left = tmp_node->left;
		old_leaf->key = tmp_node->key;
		old_leaf->right = NULL;
		old_leaf->height = 0;
		new_leaf = create_text();
		new_leaf->left = (text_t *) new_line;
		new_leaf->key = 1;
		new_leaf->right = NULL;
		new_leaf->height = 0;
		tmp_node->left = old_leaf;
		tmp_node->right = new_leaf;
		tmp_node->key++;
		tmp_node->height = 1;
		while (path_st_p > 0 && !finished) {
			if (debug) printf("Inside append 3\n");
			int tmp_height, old_height;
			tmp_node = path_stack[--path_st_p];
			old_height = tmp_node->height;
			if (tmp_node->left->height - tmp_node->right->height == 2) {
				if (debug) printf("Inside append 3.1\n");
				if (tmp_node->left->left->height - tmp_node->right->height
						== 1) {
					if (debug) printf("Inside append 3.1.1\n");
					right_rotation(tmp_node);
					tmp_node->right->height = tmp_node->right->left->height + 1;
					tmp_node->height = tmp_node->right->height + 1;
				} else {
					if (debug) printf("Inside append 3.1.2\n");
					left_rotation(tmp_node->left);
					right_rotation(tmp_node);
					tmp_height = tmp_node->left->left->height;
					tmp_node->left->height = tmp_height + 1;
					tmp_node->right->height = tmp_height + 1;
					tmp_node->height = tmp_height + 2;
				}
			} else if (tmp_node->left->height - tmp_node->right->height == -2) {
				if (debug) printf("Inside append 3.2\n");
				if (tmp_node->right->right->height - tmp_node->left->height
						== 1) {
					if (debug) printf("Inside append 3.2.1\n");
					left_rotation(tmp_node);
					tmp_node->left->height = tmp_node->left->right->height + 1;
					tmp_node->height = tmp_node->left->height + 1;
				} else {
					if (debug) printf("Inside append 3.2.2\n");
					right_rotation(tmp_node->right);
					left_rotation(tmp_node);
					tmp_height = tmp_node->right->right->height;
					tmp_node->left->height = tmp_height + 1;
					tmp_node->right->height = tmp_height + 1;
					tmp_node->height = tmp_height + 2;
				}
			} else /* update height even if there was no rotation */
			{
				if (debug) printf("Inside append 3.3\n");
				if (tmp_node->left->height > tmp_node->right->height)
					tmp_node->height = tmp_node->left->height + 1;
				else
					tmp_node->height = tmp_node->right->height + 1;
			}
			if (tmp_node->height == old_height)
				finished = 1;
		}
	}
}

char * set_line(text_t *txt, int index, char * new_line) {
	return new_line;
}

void insert_line(text_t *txt, int index, char * new_line) {

}

char * delete_line(text_t *txt, int index) {
	char *line = "Pending";
	return line;
}
