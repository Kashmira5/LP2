//Rail Fence Tranposition
#include <iostream>
using namespace std;

int main() 
{
    string text, encrypt = "", decrypt = "";
    
    cout << "Enter message: ";
    cin >> text;

    // Encryption
    for(int i = 0; i < text.length(); i = i + 2)
    {
        encrypt = encrypt + text[i];
    }

    for(int i = 1; i < text.length(); i = i + 2)
    {
        encrypt = encrypt + text[i];
    }

    cout << "Encrypted Message: " << encrypt << endl;

    // Decryption
    int mid = (text.length() + 1) / 2;
    int j = 0, k = mid;

    for(int i = 0; i < text.length(); i++)
    {
        if(i % 2 == 0)
        {
            decrypt = decrypt + encrypt[j];
            j++;
        }
        else
        {
            decrypt = decrypt + encrypt[k];
            k++;
        }
    }

    cout << "Decrypted Message: " << decrypt << endl;

    return 0;
}

//Columnar Tranposition
#include <iostream>
using namespace std;

int main()
{
    string text, encrypt = "", decrypt = "";
    int key = 3;

    cout << "Enter message: ";
    cin >> text;

    int len = text.length();

    // ENCRYPTION
    for(int col = 0; col < key; col++)
    {
        for(int i = col; i < len; i = i + key)
        {
            encrypt = encrypt + text[i];
        }
    }

    cout << "Encrypted Message: " << encrypt << endl;

    // DECRYPTION
    int rows = (len + key - 1) / key;
    char matrix[10][10];

    int k = 0;

    // Fill column-wise
    for(int col = 0; col < key; col++)
    {
        for(int row = 0; row < rows; row++)
        {
            int index = row * key + col;

            if(index < len)
            {
                matrix[row][col] = encrypt[k];
                k++;
            }
        }
    }

    // Read row-wise
    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < key; col++)
        {
            int index = row * key + col;

            if(index < len)
            {
                decrypt = decrypt + matrix[row][col];
            }
        }
    }

    cout << "Decrypted Message: " << decrypt << endl;

    return 0;
}
