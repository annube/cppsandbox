#include <cstdio>

#include <boost/type_index.hpp>


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
};

int main()
{
  printSize<long>();
  printSize<long long int>();
  printSize<unsigned int>();
  printSize<double>();
  printSize<S>();
}
