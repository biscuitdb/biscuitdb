/*-------------------------------------------------------------------------
 *
 * main.cpp
 *	  Stub main() routine for the biscuitdb executable.
 *
 * This does some essential startup tasks for any incarnation of any biscuitdb
 * instance.
 *
 *
 * Database Group, Department of Computer Science and Engineering, Jadavpur University
 *
 *
 * IDENTIFICATION
 *	  src/main.cpp
 *
 *-------------------------------------------------------------------------
 */

#include <biscuit.h>
using biscuit::Test;
using std::cout;

/*
 * Any biscuitdb server process begins execution here.
 */
auto main() -> int {
  // print a hello world message
  Test();
  return 0;
}
