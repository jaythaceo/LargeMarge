 

#include <iostream>

using std::cout;
using std::endl;

class Increment {
public:
  Increment(int c = 0, int i = 1);
  void addIncrement() { count += increment;}
  void print() const;

private:
  int count;
  const int increment;

};

Increment::Increment(int c, int i)
: increment(i)
{ count = c; }

void Increment::print() const {

  cout << "count = " << count << ", increment = " 
  << increment << endl;
}

int main(int argc, char const *argv[])
{
  Increment value(10, 5);

  cout << "Before incrementing: ";
  value.print();

  for (int j = 0; j < 3; ++j)
  {
    value.addIncrement();
    cout << "After increment: " << j + 1 << " : ";
    value.print();
  }
  
  
  return 0;
}
