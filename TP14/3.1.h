class Hat {
 public:
  Hat() {  ++num_hats_global_; }
  ~Hat() { --num_hats_global_; }
  static int NumHatsGlobal() { return num_hats_global_; }
 private:
  static int num_hats_global_;
};

class HatFactory {
 public:
  // The factory constructs a new hat, and gives me a pointer to the
  // newly constructed object. The caller does not own the Hat.
  Hat* NewHat();

  // All hats ever constructed are destructed when the factory is destructed.
  ~HatFactory();

 private:
  // TODO
};
