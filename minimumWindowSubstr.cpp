string minWindow(string s, string t)
{
    string ans = "";
    if (s.size() < t.size())
        return "";
    unordered_map<char, int> mp;
    for (int i = 0; i < t.size(); i++)
    {
        mp[t[i]]++;
    }

    int length = INT_MAX;
    int i = 0, j = 0;
    int count = mp.size();
    while (j < s.size())
    {
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                count--;
        }
        if (count > 0)
        {
            j++;
        }
        else if (count == 0)
        {
            while (count == 0)
            {
                if (mp.find(s[i]) != mp.end())
                {

                    if (j - i + 1 < length)
                    {
                        length = j - i + 1;
                        ans = s.substr(i, j - i + 1);
                    }
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                        count++;
                }
                i++;
            }
            j++;
        }
    }

    return ans;
}