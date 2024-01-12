// This class represents an array of doubles, with a fixed capacity
// determined at construction.
class Array {
 public:
  Array();

  // It is important to clean up the memory at destruction!
  ~Array();

  Array(const Array&);
  Array(Array&& );
  // Returns the current size (i.e. number of elements) of the array.
  int size() const;

  // Returns the *mutable* element at index #i.
  double& operator[](int i);

  bool operator<(Array&) const;

  const double& operator[](int i) const;

  // Adds an element at the last position of the array.
  void push_back(double x);

  // Removes the last element of the array.
  void pop_back();
  Array& operator=(const Array& other) = delete; // Opérateur d'assignation de copie
  Array& operator=(Array&& other) noexcept;

 private:
  int size_;
  int capacity_;
  double* data_;
};
