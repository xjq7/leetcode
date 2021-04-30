class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int n = height.size();
    int i = 0, j = n - 1;
    int max = 0;
    while (i < j)
    {
      int sum = min(height[i], height[j]) * (j - i);
      if (sum > max)
        max = sum;
      if (height[j] > height[i])
      {
        i++;
      }
      else
      {
        j--;
      }
    }
    return max;
  }
};