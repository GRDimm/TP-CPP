#include "2.1.h"
#include "main_utils.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int num_tests = 0;
int num_failed = 0;
#define FAIL cout << __FILE__ << ":" << __LINE__ << ": TEST #" << num_tests++ + (0 * num_failed++) << " FAILED: Your code failed to throw an exception" << endl
#define SUCCESS cout << "TEST #" << num_tests++ << " PASSED!" << endl

int main() {
  int x = ParseInt("123");
  CHECK_EQ(x, 123);
  x = ParseInt("0");
  CHECK_EQ(x, 0);
  x = ParseInt("1");
  CHECK_EQ(x, 1);
  x = ParseInt("-1");
  CHECK_EQ(x, -1);
  x = ParseInt("1000000000");
  CHECK_EQ(x, 1000000000);
  x = ParseInt("2147483647");
  CHECK_EQ(x, 2147483647);
  x = ParseInt("-2147483648");
  CHECK_EQ(x, -2147483648);
  cout << "TEST #" << num_tests++ << " PASSED: ParseInt() works on all valid inputs!" << endl;

  try { x = ParseInt("mouhahaha"); FAIL; } catch (BadFormatException& e) { SUCCESS; }
  try { x = ParseInt(""); FAIL; } catch (EmptyStrException& e) { SUCCESS; }
  try { x = ParseInt(nullptr); FAIL; } catch (NullPtrException& e) { SUCCESS; }
  try { x = ParseInt("10000000000"); FAIL; } catch (OverflowException& e) { SUCCESS; }
  try { x = ParseInt("2147483648"); FAIL; } catch (OverflowException& e) { SUCCESS; }
  try { x = ParseInt("-2147483649"); FAIL; } catch (OverflowException& e) { SUCCESS; }
  try { x = ParseInt("4294967297"); FAIL; } catch (OverflowException& e) { SUCCESS; }
  try { x = ParseInt("18446744073709551616"); FAIL; } catch (OverflowException& e) { SUCCESS; }
  try { x = ParseInt("--1"); FAIL; } catch (BadFormatException& e) { SUCCESS; }
  try { x = ParseInt("123-"); FAIL; } catch (BadFormatException& e) { SUCCESS; }
  try { x = ParseInt("123 -"); FAIL; } catch (BadFormatException& e) { SUCCESS; }
  try { x = ParseInt("-0"); FAIL; } catch (BadFormatException& e) { SUCCESS; }
  try { x = ParseInt("01"); FAIL; } catch (BadFormatException& e) { SUCCESS; }
  try { x = ParseInt("00"); FAIL; } catch (BadFormatException& e) { SUCCESS; }
  try { x = ParseInt(" 0"); FAIL; } catch (BadFormatException& e) { SUCCESS; }
  try { x = ParseInt("0 "); FAIL; } catch (BadFormatException& e) { SUCCESS; }
  try { x = ParseInt(" 1"); FAIL; } catch (BadFormatException& e) { SUCCESS; }
  try { x = ParseInt("1 "); FAIL; } catch (BadFormatException& e) { SUCCESS; }
  try { x = ParseInt("- 1"); FAIL; } catch (BadFormatException& e) { SUCCESS; }

  if (num_failed == 0) {
    cout << "Passed all tests!" << endl;
  } else {
    cout << "Failed " << num_failed << " of " << num_tests << " tests. Keep trying!" << endl;
  }
}
