#include <vector>
#include <memory>

using namespace std;

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
  Hat* NewHat();

  ~HatFactory();

 private:
   vector<unique_ptr<Hat>> hats_;
};
