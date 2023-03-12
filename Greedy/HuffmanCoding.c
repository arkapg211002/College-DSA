#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 100

typedef struct HuffmanNode {
  char data;
  unsigned freq;
  struct HuffmanNode *left, *right;
} HuffmanNode;

typedef struct MinHeap {
  unsigned size;
  unsigned capacity;
  HuffmanNode** array;
} MinHeap;

typedef struct HuffmanCode {
  char character;
  char* code;
} HuffmanCode;

HuffmanNode* new_node(char data, unsigned freq) {
  HuffmanNode* node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
  node->left = node->right = NULL;
  node->data = data;
  node->freq = freq;
  return node;
}

MinHeap* create_min_heap(unsigned capacity) {
  MinHeap* min_heap = (MinHeap*)malloc(sizeof(MinHeap));
  min_heap->size = 0;
  min_heap->capacity = capacity;
  min_heap->array = (HuffmanNode**)malloc(min_heap->capacity * sizeof(HuffmanNode*));
  return min_heap;
}

void swap_nodes(HuffmanNode** a, HuffmanNode** b) {
  HuffmanNode* temp = *a;
  *a = *b;
  *b = temp;
}

void min_heapify(MinHeap* min_heap, int idx) {
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;
  if (left < min_heap->size && min_heap->array[left]->freq < min_heap->array[smallest]->freq)
    smallest = left;
  if (right < min_heap->size && min_heap->array[right]->freq < min_heap->array[smallest]->freq)
    smallest = right;
  if (smallest != idx) {
    swap_nodes(&min_heap->array[smallest], &min_heap->array[idx]);
    min_heapify(min_heap, smallest);
  }
}

HuffmanNode* get_min_node(MinHeap* min_heap) {
  HuffmanNode* min_node = min_heap->array[0];
  min_heap->array[0] = min_heap->array[min_heap->size - 1];
  --min_heap->size;
  min_heapify(min_heap, 0);
  return min_node;
}

void insert_node(MinHeap* min_heap, HuffmanNode* node) {
  ++min_heap->size;
  int i = min_heap->size - 1;
  while (i && node->freq < min_heap->array[(i - 1) / 2]->freq) {
    min_heap->array[i] = min_heap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  min_heap->array[i] = node;
}

int is_leaf_node(HuffmanNode* node) {
  return !(node->left) && !(node->right);
}

MinHeap* build_min_heap(char data[], unsigned freq[], int size) {
  MinHeap* min_heap = create_min_heap(size);
  for (int i = 0; i < size; ++i)
    min_heap->array[i] = new_node(data[i], freq[i]);
  min_heap->size = size;
  for (int i = size / 2 - 1; i >= 0; --i)
    min_heapify(min_heap, i);
  return min_heap;
}

/*HuffmanNode* build_huffman_tree(char data[], unsigned freq[], int size) {
  HuffmanNode *left, *right, *top;
  Min*/
HuffmanNode* build_huffman_tree(char data[], unsigned freq[], int size) {
  HuffmanNode *left, *right, *top;
  MinHeap* min_heap = build_min_heap(data, freq, size);
  while (min_heap->size > 1) {
    left = get_min_node(min_heap);
    right = get_min_node(min_heap);
    top = new_node('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    insert_node(min_heap, top);
  }
  HuffmanNode* root = get_min_node(min_heap);
  free(min_heap->array);
  free(min_heap);
  return root;
}

HuffmanCode* encode(HuffmanNode* root, char* code, int top) {
  static HuffmanCode huffman_codes[MAX_TREE_HT];
  if (root->left) {
    code[top] = '0';
    encode(root->left, code, top + 1);
  }
  if (root->right) {
    code[top] = '1';
    encode(root->right, code, top + 1);
  }
  if (is_leaf_node(root)) {
    huffman_codes[root->data].character = root->data;
    huffman_codes[root->data].code = (char*)malloc(sizeof(char) * (top + 1));
    for (int i = 0; i < top; ++i)
      huffman_codes[root->data].code[i] = code[i];
    huffman_codes[root->data].code[top] = '\0';
  }
  return huffman_codes;
}

char* decode(HuffmanNode* root, char* encoded_message) {
  char* decoded_message = (char*)malloc(sizeof(char) * (strlen(encoded_message) + 1));
  int i = 0;
  while (encoded_message[i]) {
    HuffmanNode* node = root;
    while (!is_leaf_node(node)) {
      if (encoded_message[i] == '0')
        node = node->left;
      else
        node = node->right;
      ++i;
    }
    decoded_message[i - 1] = node->data;
  }
  decoded_message[i] = '\0';
  return decoded_message;
}

void print_huffman_codes(HuffmanCode* huffman_codes, int size) {
  printf("Character\tHuffman Code\n");
  for (int i = 0; i < size; ++i) {
    if (huffman_codes[i].code) {
      printf("%c\t\t%s\n", huffman_codes[i].character, huffman_codes[i].code);
      free(huffman_codes[i].code);
    }
  }
}

int main() {
  char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  unsigned freq[] = {5, 9, 12, 13, 16, 45};
  int size = sizeof(data) / sizeof(data[0]);

  HuffmanNode* root = build_huffman_tree(data, freq, size);
  char code[MAX_TREE_HT];
  HuffmanCode* huffman_codes = encode(root, code, 0);

  print_huffman_codes(huffman_codes, size);

  char* encoded_message = "1010001111011110000111100001010100011";
  char* decoded_message = decode(root, encoded_message);
  printf("Encoded message: %s\n", encoded_message);
  printf("Decoded message: %s\n", decoded_message);

  free(decoded_message);
  free(root);

  return 0;
}




