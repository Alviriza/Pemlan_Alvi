#include <stdio.h>

/*******************************************
   Fungsi Rekursif untuk f(n) = f(n-1) * 2
********************************************/
unsigned int deret2(int n)
{
  if (n == 1)
    return 1;
  else
    return (deret2(n-1) / 2);
}

int main()
{
  float x;

  for (x=1; x<=3; x++)
    printf("%.3f", deret2(x));

  return 0;
}
