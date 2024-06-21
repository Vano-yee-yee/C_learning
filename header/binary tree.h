#if !defined(BINARY_TREE_H)
#define BINARY_TREE_H

typedef struct Binary_tree_node BT_node;
/*значение больше - вправо, иначе -- влево*/

/**
* @brief 
* @param 
* @return 
*/
BT_node* find_node(BT_node* tree_, void* data);

/**
* @brief 
* @param 
* @return 1: 
0: иначе
*/
unsigned char insert_node(BT_node* tree_, void* data_);

/**
* @brief 
* @param 
* @return 
*/
unsigned char remove_node(BT_node* tree_, void* data_);
#endif