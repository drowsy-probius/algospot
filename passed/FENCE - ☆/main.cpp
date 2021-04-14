#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int solution(const vector<int>& fences, int left, int right)
{
  // [left, right)
  if(left == right) return fences[left];
  int answer = 0;
  int mid = (left + right)/2;

  // select bigger between leftside and rightside
  answer = max(solution(fences, left, mid), solution(fences, mid+1, right));

  // calculate intersection [lo, hi)
  int lo = mid, hi = mid+1;
  int height = min(fences[lo], fences[hi]);
  answer = max(answer, 2*height);

  while(lo > left || hi < right)
  {
    if(hi < right && (lo == left || fences[lo-1] < fences[hi+1]))
    {
      hi += 1;
      height = min(height, fences[hi]);
    }
    else
    {
      lo += -1;
      height = min(height, fences[lo]);
    }
    answer = max(answer, (hi-lo+1)*height);    
  }

  

  return answer;
}

int main(void)
{
  // assert(solution({7, 1, 5, 9, 6, 7, 3}, 0, 6) == 20);
  // assert(solution({1, 4, 4, 4, 4, 1, 1}, 0, 6) == 16);
  // assert(solution({1, 8, 2, 2}, 0, 3) == 8);

  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int testcase;
  cin >> testcase;
  while(testcase--)
  {
    int length, tmp;
    vector<int> fences;
    cin >> length;
    while(length--)
    {
      cin >> tmp;
      fences.push_back(tmp);
    }
    cout << solution(fences, 0, fences.size()-1) << '\n';
  }

  return 0;
}