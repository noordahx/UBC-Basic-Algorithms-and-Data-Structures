#ifndef CS221UTIL_RGBAPIXEL_H
#define CS221UTIL_RGBAPIXEL_H


namespace cs221util{

  class RGBAPixel {
    public:
      unsigned char r,g,b;
      double a;
      RGBAPixel();
      RGBAPixel(unsigned char red, unsigned char green, unsigned char blue);
      RGBAPixel(unsigned char red, unsigned char green, unsigned char blue, double alpha);
  };
}
#endif