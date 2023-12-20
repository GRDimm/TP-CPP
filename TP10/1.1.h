class Sequence {
public:
    Sequence(int n, double* values);
    Sequence();
    virtual ~Sequence();
    virtual double Value();
    virtual void Next() = 0;

    double* getValues();
    void incrStep();
    int getStep();
private:
    int step;
    int n;
    double* values;
};

class FibonacciSequence : public Sequence {
public:
    FibonacciSequence();
    void Next() override;
};

class FactorialModXSequence : public Sequence {
public:
    explicit FactorialModXSequence(int x);
    void Next() override;
    double Value() override;
private:
    int x;
};
