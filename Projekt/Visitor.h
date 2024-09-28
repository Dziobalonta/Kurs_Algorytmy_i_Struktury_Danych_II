#ifndef VISITOR
#define VISITOR

template <typename T> class Visitor
{
public:
  virtual void Visit (T & element) = 0;
  virtual bool IsDone () { return false; }
};

#endif // VISITOR