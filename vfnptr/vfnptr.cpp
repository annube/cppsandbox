#include <cstdio>

struct S
{
  virtual void vfn () const
  {
    printf("S::vfn\n");
  }
};

struct SD : public S
{
  virtual void vfn () const
  {
    printf("SD::vfn\n");
  }
};

int main()
{

  S s;
  SD sd;

  using vmemPtr = void(S::*)() const;
  vmemPtr ptr = &S::vfn;

  (sd.*ptr)();
}
