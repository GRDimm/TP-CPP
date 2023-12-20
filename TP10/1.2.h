class Sequence {
public:
    Sequence(int n, double* values);
    Sequence();
    virtual ~Sequence();
    virtual double Value();
    virtual void Next() = 0;

    double* getValues();
    void incrStep();
    void setStep(int i);
    int getStep();

    int step;
    double* values;
    int n;
};

class FibonacciSequence : public Sequence {
public:
    FibonacciSequence();
    FibonacciSequence(const FibonacciSequence& f);
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

class ShiftSequence : public Sequence {
public:
    ShiftSequence(Sequence* seq, int shift);
    virtual ~ShiftSequence();

    ShiftSequence(const ShiftSequence&) = delete;
    ShiftSequence& operator=(const ShiftSequence&) = delete;

    void Next() override;
    double Value() override;
private:
    Sequence* seq;
    int shift;
};
