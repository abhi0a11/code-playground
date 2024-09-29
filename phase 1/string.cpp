#include <iostream>
#include <string>
using namespace std;
int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != 0; i++)
    {
        count++;
    }
    return count;
}

void reverse(char name[], int n)
{
    int s = 0, e = n - 1;

    while (s < e)
    {
        swap(name[s], name[e]);
    }
}

char toLowerCase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else
    {
        return ch - 'A' + 'a';
    }
}
bool palinndrome(char name[], int len)
{
    int s = 0, e = len - 1;
    for (int i = 0; s <= e; i++)
    {

        if (toLowerCase(name[s]) != toLowerCase(name[e]))
        {
            return false;
        }
        else
        {
            s++;
            e--;
        }
    }
    return true;
}

// maximum occouring character
int firstOccu(int arr[], int maxIndex)
{
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == arr[maxIndex])
        {
            return i;
        }
    }
    return -1;
}
char maxOccuCharacter(string ch)
{
    int arr[26] = {0};
    for (int i = 0; i < ch.length(); i++)
    {

        if (ch[i] >= 'a' && ch[i] <= 'z')
        {
            arr[(ch[i] - 'a')]++;
        }
        else
        {
            arr[(ch[i] - 'A')]++;
        }
    }
    int maxIndex = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }

    char ans = 'a' + firstOccu(arr, maxIndex);
    return ans;
}

// khali space mai '@40' insert kro
string replaceSpaces(string s)
{
    string temp = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
        {
            temp.push_back(s[i]);
        }
    }
    return temp;
}

string removeAllOccourances(string s, string part)
{
    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

// check whether all permutations of a string is present in another string or not
bool checkEqual(int a[26], int b[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}
bool checkInclusion(string s1, string s2)
{
    int count1[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    int windowSize = s1.length();
    int count2[26] = {0};

    // running for first window
    int i = 0;
    for (i; i < windowSize; i++)
    {
        int index = s2[i] - 'a';
        count2[index]++;
    }

    if (checkEqual(count1, count2))
    {
        return 1;
    }

    // next window
    for (i; i < s2.length(); i++)
    {
        int newCharIndex = s2[i] - 'a';
        count2[newCharIndex]++;

        int oldCharIndex = s2[i - windowSize] - 'a';
        count2[oldCharIndex]--;

        if (checkEqual(count1, count2))
        {
            return 1;
        }
    }
    return 0;
}

int compress(char chars[])
{
    int i = 0;
    int ansIndex = 0;
    int n = sizeof(chars);
    while (i<n)
    {
        int j = i+1;
        while (j<n && chars[i]==chars[j])
        {
            j++;
        }
        
        // AHA KAB AAOGE
        // YA TO ARRAY POORA TRAVERSE KRDIYA
        // YA FER NEW/DIFFERENT CHARACTER ENCOUNTER KIYA

        //oldChar store krlo
        chars[ansIndex++] = chars[i];
        int count = j-i;

        if(count>1){
            //converting count into single digit and saving in answer
            string cnt = to_string(count);
            for(char ch: cnt){
                chars[ansIndex++] = ch;
            }
        }

        i=j;
    }
    return ansIndex;
}
int main()
{
    char name[20] = "dsfghjkl";

    // cout << "Enter your name " << endl;

    // cin >> name;

    // cout << "Your name is " << name << endl;
    // int len = getLength(name);
    // cout << "Length of name is " << len << endl;
    // if (palinndrome(name, len) == 1)
    // {
    //     cout << "Yes" << endl;
    // }
    // else
    //     cout << "NO" << endl;

    // cout << toLowerCase('s') << endl;
    // cout << toLowerCase('D') << endl;

    // string str;
    // cin >> str;
    // cout << maxOccuCharacter(str);

    // string strReplace;
    // getline(cin,strReplace);
    // cout<<replaceSpaces(strReplace);
    string s1 = "we";
    string s2 = "qwewrfwer";
    cout << checkInclusion(s1, s2);
    return 0;
}