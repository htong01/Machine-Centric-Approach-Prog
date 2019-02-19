#include "stdio.h"
#include "btree.h"

/*
Test2 is correct


Test1: adding element: only add 0 from the second element
Test3: toArray. When construct a new tree and print it out, it's not printing what I just added. Also not making deep copy in copy constructor.
Test4: not making a deep copy for both copy constructor and asssignment operator
Test5: when removing root element, the root element won't be removed but the last element removed.
Test6: seg fault when remove already removed or not existed element
Test7: contains(). Check if contain an already removed element, still get true.
*/

int main(int argc, char* argv[])
{
	BTree* tree1 = new BTree();
	tree1->add(2);                // add element to a new tree
	tree1->add(1);
	tree1->add(3);
	tree1->add(4);
	int x = tree1->contains(1);   // check if certain element exist
	int y = tree1->contains(2);
	int z = tree1->contains(3);
	int m = tree1->contains(4);

	if(x&&y&&z&&m) printf("true\n");
	else printf("element add wrong\n");

	int s = tree1->size();       // size of the tree
	printf("%d\n",s);

	int* arr = tree1->toArray();  // check array, if the output element is what we added
	for(int i=0;i<s;i++) printf("%d ",arr[i]);
	printf("\n");
	delete []arr;

	printf("test remove:\n");
	tree1->remove(2);
	tree1->remove(2);         // remove already removed element
	tree1->remove(10);        // remove not exist element
	s = tree1->size();
	printf("%d\n",s);

	x = tree1->contains(1);
	y = tree1->contains(3);
	z = tree1->contains(4);

	int check = tree1->contains(2);
	if(check) printf("element already removed but still check get true\n");


	if(x&&y&&z) printf("true\n");
	else printf("element add wrong\n");

	int* arr2 = tree1->toArray();                      // check the rest of tree
	for(int i=0;i<s;i++) printf("%d ",arr2[i]);
	printf("\n");
	delete []arr2;


	printf("test assignment operator:\n");
    BTree* tree2 = new BTree();
    tree2 = tree1;                                    // assignment operator 
    int s2 = tree2->size();
	printf("%d\n",s2);
    int* arr3 = tree2->toArray();
	for(int i=0;i<s2;i++) printf("%d ",arr3[i]);

    tree1->remove(4);                                // remove element from the original tree

    x = tree2->contains(1);
	y = tree2->contains(3);
    s2 = tree2->size();
	printf("%d\n",s2);
	check = tree1->contains(2);   
	if(check) printf("element already removed but still check get true\n");

	if(x&&y) printf("true\n");
	else printf("element add wrong\n");
	arr3 = tree2->toArray();
	for(int i=0;i<s2;i++) printf("%d ",arr3[i]);       // check the new tree if also removed the element
	printf("\n");
	delete []arr3;



// copy constructor
	BTree* tree3 = new BTree();
	tree3->add(5);
	tree3->add(4);
	tree3->add(10);
	tree3->add(1);
	BTree* tree4 = new BTree(*tree3);

	int* arr6 = tree3->toArray();
	for(int i=0;i<tree3->size();i++) printf("%d ",arr6[i]);
	printf("\n");
	delete []arr6;

	int* arr4 = tree4->toArray();
	for(int i=0;i<tree4->size();i++) printf("%d ",arr4[i]);
	printf("\n");
	delete []arr4;
 
	tree3->remove(3);                                  // remove element from original tree

	int *arr5 = tree4->toArray(); 						// check new tree
	for(int i=0;i<tree4->size();i++) printf("%d ",arr5[i]);
	printf("\n");
	delete []arr5;


}

