// This class represents an array of doubles, with a fixed capacity
// determined at construction.
class Array {
 public:
  // The array will be empty at construction, but all the memory 
  // necessary to store up to "capacity" doubles will already be allocated.
  Array(int capacity);

  // It is important to clean up the memory at destruction!
  ~Array();

  // Returns the current size (i.e. number of elements) of the array.
  int size() const;

  // Returns the *mutable* element at index #i.
  double& operator[](int i);

  // Adds an element at the last position of the array.
  void push_back(double x);

  // Removes the last element of the array.
  void pop_back();

 private:
	int size_;
	double* data_;
	Array(const Array&);            // Interdire la construction par copie
	Array& operator=(const Array&); // Interdire l'opérateur d'affectation1
};
