#include <string>
#include <iostream>
#include <vector>
using namespace std;
string compressedString(string word)
{
    int size = word.size();
    string comp = "";
    int count = 1;
    for (int i = 0; i < size; i++)
    {
        if (i + 1 < size && word[i] == word[i + 1])
        {
            count++;
        }
        else
        {
            while (count > 9)
            {
                // comp += to_string(count);
                // comp += word[i];
                // count = 1;
                comp += to_string(9);
                comp += word[i];
                count -= 9;
            }
            if(count >=1 ){
                comp += to_string(count);
                comp += word[i];
                count = 1;
            }
            
        }
    }
    return comp;
}
int main()
{
    string word = "aaaaaaaaaaaaaaaaaaaabcde";
    string comp;
    comp = compressedString(word);
    cout << comp << endl;
    return 0;
}