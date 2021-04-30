class Solution
{
public:
  bool canCross(vector<int> &stones)
  {
    if (stones[1] - stones[0] != 1)
      return false;
    bool f = false;
    map<int, bool> m;
    dfs(m, stones, 0, 1, 1, f);
    return f;
  }
  void dfs(map<int, bool> &m, vector<int> &stones, int prevIndex, int step, int index, bool &f)
  {
    int len = stones.size();
    if (index == len - 1)
    {
      f = true;
      return;
    }

    if (m.count(prevIndex * 1000 + step))
    {
      return;
    }

    int offset;
    for (int curStep = step - 1; curStep <= step + 1; curStep++)
    {
      int i = index + 1;
      while (i < len)
      {
        offset = stones[i] - stones[index];
        if (offset == curStep)
        {
          dfs(m, stones, index, curStep, i, f);
        }
        else if (offset > curStep)
        {
          break;
        }
        i++;
      }
    }
    m.emplace(prevIndex * 1000 + step, true);
  }
};