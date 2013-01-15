// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.
#include <stdio.h> // printf
#include "List.h"

int main( void )
{
  List *list = CreateList( );
  node *n;

  int x = 17;
  int y = 18;
  int z = 19;

  InsertFront( list, &x, sizeof( int ) );
  InsertFront( list, &y, sizeof( int ) );
  InsertFront( list, &z, sizeof( int ) );

  // Loop through list. It's important to use ListBegin and ListEnd for proper looping.
  // Make note of what pointers Begin and End return.
  for(n = ListBegin( list ); n != ListEnd( list ); n = n->next)
    printf( "%d\n", NODE_DATA( n, int ) );

  getchar( );

  return 0;
}
