#include <iostream>
#include <vector>
#define SIZE 10

using namespace std;

int answer;

void solve(int idx, vector<int> pairs[], int inPair[], int numofstudents)
{

  bool isDone = true;
  for(int i=0; i<numofstudents; i++){
    if( !inPair[i] ){
      isDone = false;
      break;
    }
  }
  if(isDone){answer++; return;}

  for(auto it = pairs[idx].begin(); it != pairs[idx].end(); it++)
  {
    if(inPair[*it]){continue;}
    inPair[idx] = inPair[*it] = true;

    int next = 0;
    for(int i=0; i<numofstudents; i++)
    {
      if( !inPair[i] )
      {
        next = i;
        break;
      }
    }

    solve(next, pairs, inPair, numofstudents);
    inPair[idx] = inPair[*it] = false;
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
    answer = 0;

    int numofstudents, numofpairs;
    cin >> numofstudents >> numofpairs;

    vector<int> pairs[SIZE];
    int inPair[SIZE];

    for(int i=0; i<numofpairs; i++)
    {
      int a, b;
      cin >> a >> b;

      pairs[a].push_back(b);
      pairs[b].push_back(a);
    }
    for(int i=0; i<numofstudents; i++)
      inPair[i] = false;

    solve(0, pairs, inPair, numofstudents);
    cout << answer << '\n';
  }
  return 0;
}