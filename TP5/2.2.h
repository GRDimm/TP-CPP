class Pixel {
  public:
    Pixel();
    Pixel(const int x, const int y, const int color);
     
    const int GetX() const;
    const int GetY() const;
    const int GetColor() const;
     
    const void SetX(const int x);
    const void SetY(const int y);
     
  private:
    int x_;
    int y_;
    const int color_;
};