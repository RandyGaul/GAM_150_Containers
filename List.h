// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.
typedef struct node
{
  void *data;
  struct node *next;
  struct node *prev;
}node;

typedef struct List
{
  node head;
  node tail;
  unsigned nodeCount;
} List;

// Retrieves the data of a node by typecasting the node's data void pointer to a 
// pointer of desired type, followed by a dereference.
#define NODE_DATA( NODE, TYPE ) \
  (*(TYPE *)(NODE->data))

    /*----------------
      Create/Destroy
    ----------------*/
// Create an empty linked list
List *CreateList( void );

// Delete a node from a list
node *DeleteNode( List *list, node *n );

    /*----------------
        Modifiers
    ----------------*/
// Create a node at front of a list
node *InsertFront( List *list, void *data, unsigned data_size );

// Create a node at back of a list
node *InsertBack( List *list, void *data, unsigned data_size );

// Copy data into a node
void AssignData( void *data, node *n, unsigned data_size );

// Unhooks a node from a list
void UnlinkNode( List *list, node *n );

    /*----------------
       Data Access
    ----------------*/
// Checks to see if a node is apart of a list at all
int IsLinked( node *n );

// It is important to use these for looping over the list
node *ListBegin( List *list );
node *ListEnd( List *list );
