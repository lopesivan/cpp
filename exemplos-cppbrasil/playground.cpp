#include <iostream>

template <class T>
class SadBart
{
public:
  SadBart(T lesson) : lesson(lesson) {
  }

  template <class U>
  void operator()(std::ostream &os, U width, U height) {
    while (height --> 0) {
      auto w = width;
      while (w --> 0)
        if (w > 0)
          os << lesson << ' ';
        else
          os << lesson;
      os << '\n';
    }
  }

private:
  T lesson;
};

int main()
{
  SadBart<int>(42)(std::cout, 4, 2);
}
