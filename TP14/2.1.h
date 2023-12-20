class MyObj {
 public:
  explicit MyObj(int seed);  // Implemented in 2.1.test.cc
  ~MyObj();                  // Implemented in 2.1.test.cc

  // NOT default- and copy-constructible!
  MyObj() = delete;
  MyObj(const MyObj&) = delete;

  int Value() const { return value_; }
 private:
  const int value_;
};

// This function, which you must implement, should do the following:
// - Construct N instances of MyObj, with seed=0...N-1.
// - Sort them by Value()
// - Return the "median" value, i.e. the Value() of the N/2-th MyObj in the
//   sorted list.
// - [IMPORTANT!] Destroy all instances of MyObj before returning.
int ComputeMedianMyObj(int N);
