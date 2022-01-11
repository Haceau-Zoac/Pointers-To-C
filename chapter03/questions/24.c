static int w = 5;
extern int x;

static void
func1(int a, int b, int c)
{
  int /*c,*/ d, e = 1;
  {
    int d, e, w;
    {
      int b, c, d;
      static int y = 2;
    }
  }
  {
    register int a, d, x;
    extern   int y;
  }
}

static int y;

void
func2(int a)
{
  extern int y;
  static int z;
}

int main(void)
{

}