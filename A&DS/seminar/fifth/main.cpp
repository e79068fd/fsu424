#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str, substr;
    cin>>str>>substr;
    int d[str.length()];
    d[0] = 0;
    for(int k = 0, i = 1; i < substr.length(); i++)
    {
        while(k > 0 && substr[i] != substr[k])
            k = d[k - 1];

        if(substr[i] == substr[k])
            k++;

        d[i] = k;
    }
    bool found = false;
    for(int k = 0, i = 0; i < str.length(); i++)
    {
        while(k > 0 && substr[k] != str[i])
            k = d[k - 1];

        if(substr[k] == str[i])
            k++;
        if(k == substr.length())
        {
            found = true;
            cout<<i - substr.length() + 1<<'\n';
            break;
        }
    }
    if(!found)
        cout<<-1<<'\n';
    return 0;
}
