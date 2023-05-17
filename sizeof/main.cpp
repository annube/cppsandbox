#include <cstdio>

#include <boost/type_index.hpp>
#include <vector>

template <typename T>
void printSize() {
  boost::typeindex::type_index typeInfo = boost::typeindex::type_id<T>();
  std::printf("%s %ld\n", typeInfo.pretty_name().c_str(), sizeof(T));
}

struct S
{
  int x;
  char c;
  int z;
  virtual void fnv() const = 0;
};

struct T{
  int x;
  char c;
  int z;
  int fn() const;
};

int main()
{
  printSize<long>();
  printSize<long long int>();
  printSize<unsigned int>();
  printSize<double>();

  printSize<decltype(std::distance(std::declval<std::vector<int>::const_iterator>(),
                                   std::declval<std::vector<int>::const_iterator>()))>();

  printSize<std::size_t>();

  printSize<S>();
  printSize<void(S::*)()>();

  printSize<T>();
  printSize<void(T::*)()>();
}
