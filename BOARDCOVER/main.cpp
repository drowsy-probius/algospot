#include <iostream>
#include <vector>
#define WIDTH 20
#define HEIGHT 20

using namespace std;

const int delta[4][3][2] = {
  { {0, 0}, {0, 1}, {1, 1} },
  { {0, 0}, {1, 0}, {1, 1} },
  { {0, 0}, {1, 0}, {1, -1} },
  { {0, 0}, {1, 0}, {0, 1} }
};

char board[HEIGHT][WIDTH];
int numberOfWhite;
int height, width;

bool isSolvable()
{
  numberOfWhite = 0;
  for(int i=0; i<height; i++)
  {
    for(int j=0; j<width; j++)
    {
      if(board[i][j] == '.')
      {
        numberOfWhite++;
      }
    }
  }
  return numberOfWhite % 3 == 0;
}


int solve()
{
  if( !isSolvable() ) return 0;
  
  int steps = numberOfWhite / 3;
  int answer = 0;
  while(steps--)
  {
    for(int i=0; i<height; i++)
    {
      for(int j=0; j<width; j++)
      {

      }
    }
  }

}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int t;
  cin >> t;
  while(t--)
  {
    cin >> height >> width;
    for(int i=0; i<height; i++)
    {
      for(int j=0; j<width; j++)
      {
        cin >> board[i][j];
      }
    }
    cout << solve() << '\n';
  }
  return 0;
}