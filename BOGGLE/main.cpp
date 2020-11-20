#include <iostream>
#include <string>

using namespace std;

const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

char _board[5][5];

bool word_check_time_out(int x, int y, string &word, int word_idx)
{
  if(x < 0 || y < 0 || x >= 5 || y >= 5) return false;
  if(word.at(word_idx) != _board[y][x] ) return false;
  if(word_idx + 1 == word.length()) return true;
  
  for(int i=0; i<8; i++){
    bool tmp;
    tmp = word_check_time_out(x + dx[i], y + dy[i], word, word_idx + 1);
    if(tmp) return true;
  }
  return false;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int t;
  cin >> t;
  while(t--)
  {
    for(int i=0; i<5; i++)
      for(int j=0; j<5; j++)
        cin >> _board[i][j];
    
    int num_of_words = 0;
    cin >> num_of_words;
    while(num_of_words--)
    {
      string word;
      cin >> word;
      cout << word;

      bool checker = false;

      // chapter 6
      // timeout version
      // O(8^N)
      //
      // for(int i=0; i<5; i++)
      //   for(int j=0; j<5; j++){
      //     checker = word_check_time_out(j, i, word, 0);
      //     if(checker)
      //     {
      //       i = 10;
      //       break;
      //     }
      //   }
      
      cout << (checker ? " YES" : " NO") << "\n";
    }
  }

  return 0;
}