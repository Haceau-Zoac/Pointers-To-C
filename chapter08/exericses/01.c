#include <stdio.h>

int main() {
  static char char_value[3][6][4][5] =
  {
    {
      {
        {
          ' '
        } 
      },
      {
        {
        },
        {
          0, 0, 'A'
        },
        {
          0, 0, 0, 'x'
        }
      },
      {
        {
        },
        {
          0, 0xf3
        }
      },
      {
        {
        },
        {
          0, 0, '\n'
        }
      }
    },
    {
      {
        {
          0, 0320
        }
      },
      {
        {
          '0'
        },
        {
          0, '\''
        },
        {
          '\121'
        }
      },
      {
      },
      {
        {
        },
        {
        },
        {
          0, '3', 3
        }
      },
      {
        {
        },
        {
        },
        {
          0, 0, 0, 125
        }
      }
    }
  };

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 6; ++j)
      for (int k = 0; k < 4; ++k)
        for (int ii = 0; ii < 5; ++ii)
          if (char_value[i][j][k][ii] != 0)
            printf("%d,%d,%d,%d: %d\n", i+1, j+1, k+1, ii+1,char_value[i][j][k][ii]);
}
