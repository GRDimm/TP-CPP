class Array {
public:
    Array(int capacity);
    ~Array();

    Array(const Array& other); // constructeur de copie
    Array& operator=(const Array& other); // opérateur d'affectation

    int size() const;
    double& operator[](int i);
    void push_back(double x);
    void pop_back();

private:
    int capacity_;
    int size_;
    double* data_;
};
