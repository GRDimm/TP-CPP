#include <exception>

// Converts a string to an integer, with strict checking: throws an exception
// if 'str' doesn't represent an integer in the range [-2^31...2^31-1].
//
// Exceptions thrown:
// - NullPtrException: if str == nullptr.
// - EmptyStrException: if str is empty.
// - BadFormatException: if the string doesn't follow the regexp 0|(-?[1-9][0-9]*)
// - OverflowException: if the string follows the regexp above, but the integer
//   is outside p[-2^31...2^31-1].
//
// The last two exceptions take an argument at construction: a string that helps
// to know what failed. Typically it would be the input that's being parsed.
// The first two don't need it, because the context is pretty clear (nullptr
// or empty string).
int ParseInt(const char* str);

using std::exception;
class NullPtrException : public exception {};
class EmptyStrException : public exception {};
class BadFormatException : public exception {
 public:
  explicit BadFormatException(const char* data) : data_(data) {}
  const char* what() const throw() override { return data_; }
 private:
  const char* data_;
};
class OverflowException : public exception {
 public:
  explicit OverflowException(const char* data) : data_(data) {}
  const char* what() const throw() override { return data_; }
 private:
  const char* data_;
};
