#include "iostream"
#include "string"
#include "cassert"

using namespace std;

string solution(string input, string::iterator& it)
{
  char current = *it;
  it++;

  if(current == 'x')
  {
    string upperLeft = solution(input, it);
    string upperRight = solution(input, it);
    string lowerLeft = solution(input, it);
    string lowerRight = solution(input, it);
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
  }
  else
  {
    return string(1, current);
  }
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int testCases;
  string input = "";

  cin >> testCases;

  while(testCases--)
  {
    cin >> input;
    string::iterator it = input.begin();
    string answer = solution(input, it);
    cout << answer << '\n';
  }

  return 0;
}


// int main(void)
// {
//   string str = "w";
//   string::iterator it = str.begin();
//   assert(solution(str, it) == "w");

//   str = "xbwwb";
//   it = str.begin();
//   assert(solution(str, it) == "xwbbw");

//   str = "xbwxwbbwb";
//   it = str.begin();
//   assert(solution(str, it) == "xxbwwbbbw");

//   str = "xxwwwbxwxwbbbwwxxxwwbbbwwwwbb";
//   it = str.begin();
//   assert(solution(str, it) == "xxwbxwwxbbwwbwbxwbwwxwwwxbbwb");

//   return 0;
// }
