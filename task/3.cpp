#include <iostream>
#include <string>
using namespace std;

//проверка наличия символов    
bool check_func(char simb)
{
    if(simb == ' ' || simb == ',' || simb == '.' || simb == '!' || simb == '?' || simb == ';' || simb == ':')
    { 
        return true;
    
    } else {
        return false;
    }
}

int main()
{
    string s, temp;
    int index = 0, counter = 0, size;
    cout << "Введите строку: ";
    getline(cin, s);

    while(s[index]) 
    {
        if(check_func(s[index])) 
        {                         
            while(check_func(s[index])) 
            {
                index++; 
            }
            counter++; 
        }
        index++; 
    }

    size = counter+1 ; 
    string* str;
    str = new string[size]; 
    counter = 0;
    index = 0;

    //поиск повторяющихся слов
    while(s[index])
        {
            if(!check_func(s[index]))
            {
                temp += s[index]; 
                if(!s[index + 1]) 
                {
                    str[counter] = temp; 
                temp.clear(); 
                    counter++; 
                }              
            }
            else
            {
                if(temp != "") 
                {
                    str[counter] = temp; 
                    temp.clear(); 
                    counter++; 
                }
            }
            index++;
        }

    counter = 0;

    //Поиск не повторяющихся слов
        for(int i = 0; i < size; i++)
        {
            temp = str[i]; 
            for(int j = 0; j < size; j++)
            {
                if(temp == str[j]) 
                    counter++; 
            }
            if(counter == 1) 
                cout << str[i] << "\n";
            counter = 0; 
        }

        cout << "\n";
    return 0;
}