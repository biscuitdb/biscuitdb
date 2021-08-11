/*-------------------------------------------------------------------------
 *
 * main.cpp
 *	  Stub main() routine for the biscuitdb executable.
 *
 * This does some essential startup tasks for any incarnation of any biscuitdb
 * instance.
 *
 *
 * BiscuitDB
 *
 *
 * IDENTIFICATION
 *	  src/main/main.cpp
 *
 *-------------------------------------------------------------------------
 */

#include "main/biscuit.h"
using biscuit::Hello;
using std::cout;

/*
 * Any biscuitdb server process begins execution here.
 */
auto main() -> int {
  // print a hello world message
  Hello();
  return 0;
}
