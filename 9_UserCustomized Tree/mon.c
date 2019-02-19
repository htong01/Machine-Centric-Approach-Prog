#include "mon.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Element* create_left(Element* root, char* data)
{
  if(root == NULL){                  // if no input
  	return NULL;
  }
  if(root->left_child != NULL){      // if already have a left child
  	return NULL;
  }

  Element* left = (Element*)malloc(sizeof(Element));
  left->name = data;                 // left child of root, and it's name is data
  left->left_child = NULL;
  left->right_child = NULL;
  root->left_child = left;           // left child of root points to left

  return left;
}


Element* create_right(Element* root, char* data)  // same as curete_left()
{
  if(root == NULL){
  	return NULL;
  }
  if(root->right_child != NULL){
  	return NULL;
  }

  Element* right = (Element*)malloc(sizeof(Element));
  right->name = data;
  right->left_child = NULL;
  right->right_child = NULL;
  root->right_child = right;

  return right;
}


void free_tree(Element* root)
{
  if(root != NULL){
    free_tree(root->right_child);      // recurvisely free the subtree(right child)
    free(root->name);                  // if data was heap allocated, need to free it
    free_tree(root->left_child);       // recurvisely free the subtree(left child)
    free(root);
  }
}


int write_tree(FILE* f, Element* e)
{
  if(e == NULL){
  	fprintf(f,"NULL ");               // end case is when element e is NULL
  }
  else {
  	fprintf(f,"{");
  	write_tree(f, e->left_child);     // when element is not null, recursively write for it's left child
  	write_tree(f, e->right_child);    // for right child
  	fprintf(f,"%s",e->name);          // name of element e after finding it's left and right child
  	fprintf(f,"}");                   // print '}' means end of an element structure
  }
  
  return 0;
}


Element* load_tree(FILE* f)
{

  if(f == NULL){                       // NULL file
  	return NULL;
  }

  int count = 0;
  char buff[256];
  const int MaxSize = 50;
  char ch;
  Element* stack[MaxSize];             // initialize the stack to store the structure Element
  Element* p = (Element*)malloc(sizeof(Element));

  int top = -1;                        // top is pointer for stack
  int k = 0;                           // k works as flag
  
  int c = 0;
  while(fgets(buff, 255, f) != NULL){
  	for(int i=1;i<strlen(buff);i++){
    	switch(buff[i])
		{
			case '{':                     // '{' marks the begining of a subtree
				top++;
				stack[top] = p;           // put element to the stack
				k = 1;   
				break;
			case ' ':                     // each element seperates by space
			  switch(c)
			  {
			  	case '1':
			  	  k = 2;
			      c++;  
			    case '2':
			      k = 3;
			      c = 0;
			  }

				break;
			case '}':                      // '{' marks the end of a subtree
			    top--; 
				break; 
		}

		switch(k)
	    {
	    	case 1:
	    		p->left_child = stack[top];
	    		printf("left child is %s\n",p->left_child);
	    		break;
	    	case 2:
	    		p->right_child = stack[top];
	    		printf("right child is %s\n",p->right_child);
	    		break;
	    	case 3: 
	    	    p->name = stack[top];
	    		printf("name is %s\n",p->name);
	    		break; 
		}
			
	}
  }

  return p;
}
