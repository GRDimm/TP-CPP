#include <string>
using std::string;

class Shape {
 public:
  virtual string Name();
  virtual double Area();

  // Must be exactly: "<Name>: area=<area>"
  // On utilisera std::to_string pour convertir un nombre en string.
  string Description();

 protected:
  Shape() {}
};

// This square is always oriented "straight", i.e. along the horizontal
// and vertical axis.
class StraightSquare : public Shape {
 public:
  string Name() override;
  double Area() override;

  // Returns a newly allocated StraightSquare.
  static Shape* Create(double x_min, double y_min, double length);

 protected:
  // Coordinates.
  double x_min_;
  double x_max_;
  double y_min_;
  double y_max_;

 private:
  StraightSquare() {};
};
