#include <iostream>
#include <string>
#include <vector>
#include <array>


using namespace std;

namespace example_a
{
  void example()
  {
    pair   p(2, 4.5);       // deduces to std::pair<int, double> p(2, 4.5);
    vector v_a{1,2,3,4};    // deduces to std::vector<int> v{1,2,3,4};
    auto   v_b = std::vector<int>{};
  }
}

namespace example_b
{
  template <typename T>
  struct S
  {
    S(T const &aVal)
      :mVal(aVal)
    {
    }
    T mVal;
  };

  S(char const*) -> S<string>;

  void example()
  {
    S i(1);
    S s("hello");
  }
}

namespace example_c
{
  template<typename T, typename U>
  struct S
  {
    T first;
    U second;
  };

  template<typename T, typename U> S(const T &f, const U &s) -> S<T, U>;

  void example()
  {
    S sa = { 42, "hello", };
    S sb = { "hello", "World" };
    cout << sa.first << sa.second << endl;
    cout << sb.first << sb.second << endl;
  }
}

int main()
{
  example_a::example();
  example_b::example();
  example_c::example();
  return 0;
}













