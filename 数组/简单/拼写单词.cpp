class Solution
{
public:
  int countCharacters(vector<string> &words, string chars)
  {
    map<char, int> m;
    for (int i = 0; i < chars.size(); i++)
    {
      m[chars[i]]++;
    }

    int ret = 0;
    for (int i = 0; i < words.size(); i++)
    {
      int flag = true;
      map<char, int> word_map;

      for (char c : words[i])
      {
        word_map[c]++;
      }
      for (char c : words[i])
      {
        if (word_map[c] > m[c])
        {
          flag = false;
          break;
        }
      }
      if (flag)
      {
        ret += words[i].size();
      }
    }
    return ret;
  }
};