class Pixel {
 public:
  Pixel(int x, int y);

  int X() const;
  int Y() const;

  // Prints "INVALID" if the pixel is not valid, otherwise prints "(x, y)".
  void DebugPrint() const;

 protected:
  // A valid pixel is a pixel with non-negative coordinates.
  bool IsValid() const;

 private:
  const int x_;
  const int y_;
};
