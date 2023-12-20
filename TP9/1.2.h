class Pixel {
 public:
  Pixel(int x, int y);

  int X() const;
  int Y() const;

  // Prints "INVALID" if the pixel is not valid, otherwise prints "(x, y)".
  virtual void DebugPrint() const;

 protected:
  // A valid pixel is a pixel with non-negative coordinates.
  bool IsValid() const;

 private:
  const int x_;
  const int y_;
};


class ColoredPixel : public Pixel {
    public:
    ColoredPixel(int x, int y, int color_rgb);

    int ColorRgb() const;
    
    // Like before, but we also print the color like this:
    // (4, 3, 0xff0080) -> "(4, 3, R255:G0:B128)"
    void DebugPrint() const;

    // We inherit Pixel::IsValid() and don't change it. We don't do more checks.

    private:
    const int color_rgb_;
};