// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.
#include <stdlib.h> // malloc, free
#include <string.h> // memcpy
#include <assert.h>
#include "List.h"

#define PTR_ADD( PTR, OFFSET ) \
  (void *)((char *)PTR + OFFSET)

/*------------------------------------------------------------------------------------------------

                                         Create / Destroy

------------------------------------------------------------------------------------------------*/
List *CreateList( void )
{
  List *list = (List *)malloc( sizeof( List ) );

  // Set node count to zero
  list->nodeCount = 0;

  // Make dummy head point to tail
  list->head.next = &list->tail;
  list->head.prev = NULL;

  // Make dummy tail point to head
  list->tail.prev = &list->head;
  list->tail.next = NULL;

  return list;
}

// Creates a new node and initializes the data fields
node *CreateNode( unsigned data_size )
{
  node *newNode = (node *)malloc( sizeof( node ) + data_size );
  newNode->next = NULL;
  newNode->prev = NULL;

  // Make data point to end of the allocated node where the data's space is
  newNode->data = PTR_ADD( newNode, sizeof( node ) );

  return newNode;
}

node *DeleteNode( List *list, node *n )
{
  // Get the next pointer so we can return it
  node *next = n->next;

  // We're not going to delete the head or tail >.<
  assert( n != &list->head );
  assert( n != &list->tail );

  // Unlink node from list then free node
  UnlinkNode( list, n );
  free( n );

  return next;
}

/*------------------------------------------------------------------------------------------------

                                           Modifiers

------------------------------------------------------------------------------------------------*/
// Create a node at front of a list
node *InsertFront( List *list, void *data, unsigned data_size )
{
  // Create our node with initialized data fields
  node *newNode = CreateNode( data_size );

  // Copy our data into the newNode's memory space
  AssignData( data, newNode, data_size );

  // Make newNode point to what head points at
  newNode->next = list->head.next;
  newNode->prev = &list->head;

  // Make head point to newNode
  list->head.next->prev = newNode;
  list->head.next = newNode;

  // Add one to the nodeCount
  ++list->nodeCount;

  return newNode;
}

// Create a node at back of a list
node *InsertBack( List *list, void *data, unsigned data_size )
{
  // Create our node with initialized data fields
  node *newNode = CreateNode( data_size );
  
  // Make newNode point to what tail points at
  newNode->next = &list->tail;
  newNode->prev = list->tail.prev;
  
  // Make tail point to newNode
  list->tail.prev->next = newNode;
  list->tail.prev = newNode;
  
  // Add one to the nodeCount
  ++list->nodeCount;

  return newNode;
}

// Copy data into a node
void AssignData( void *data, node *n, unsigned data_size )
{
  memcpy( n->data, data, data_size );
}

// Unhooks a node from a list
void UnlinkNode( List *list, node *n )
{
  // Unhook node from the list
  n->prev->next = n->next;
  n->next->prev = n->prev;

  // Decrement list's nodecount
  --list->nodeCount;
}

/*------------------------------------------------------------------------------------------------

                                          Data Access

------------------------------------------------------------------------------------------------*/
// Checks to see if a node is apart of a list at all
int IsLinked( node *n )
{
  return n->prev || n->next;
}

node *ListBegin( List *list )
{
  return list->head.next;
}

node *ListEnd( List *list )
{
  return &list->tail;
}
