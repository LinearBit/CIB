#include <iostream>
#include<vector>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int const map = 10;
    float  A[map*map] =
    {
        0, 0, 6, 12, 10, 11, 11, 10, 0, 2,
        6, 30, 4, 8, 2, 0, 0, 8, 12, 0,
		0, 10, 7, 34, 10, 2, 7, 3, 16, 1,
        0, 38, 10, 47, 36, 7, 18, 2, 31, 0,
        0, 37, 85, 56, 23, 118, 57, 5, 13, 5,
        2, 27, 52, 70, 0, 112, 30, 8, 13, 30,
        4, 35, 28, 12, 23, 4, 42, 13, 23, 23,
        2, 31, 47, 15, 0, 36, 44, 20, 7, 28,
        0, 44, 40, 41, 86, 0, 19, 29, 38, 0,
        2, 0, 0, 18, 0, 0, 19, 3, 0, 1
    };

    int const kernel = 3;
    float B[kernel*kernel] =
    {
      0, 1, 0,
      1, 0, 1,
      0, 1, 0
    };

    int const outm = map - kernel + 1;

    int const convAw = kernel*kernel;
    int const convAh = map*map;
    
    float A_convert[convAh*convAw] = { 0 };

    for (int i = 0; i < outm; i++)
    {
        for (int j = 0; j < outm; j++)
        {
            int wh = i * outm * convAw + j * convAw; 

            int col1 = i * map + j;
            A_convert[wh] = A[col1];
            A_convert[wh + 1] = A[col1 + 1];
            A_convert[wh + 2] = A[col1 + 2];

            int col2 = (i + 1) * map + j;
            A_convert[wh + 3] = A[col2];
            A_convert[wh + 4] = A[col2 + 1];
            A_convert[wh + 5] = A[col2 + 2];

            int col3 = (i + 2) * map + j;
            A_convert[wh + 6] = A[col3];
            A_convert[wh + 7] = A[col3 + 1];
            A_convert[wh + 8] = A[col3 + 2];
        }

    }
    vector<int> C;
    for (int i = 0; i < outm; i++)
    {

        for (int j = 0; j < outm; j++)
        {
            int a = 0;
            int wh = i * outm * convAw + j * convAw;
            for (int m =0; m < convAw; m++)
            {
                a += A_convert[wh + m] * B[m] ;

            }
            C.push_back(a);

        }

    }


    cout << "±»¾í»ý¾ØÕó :" << endl;
    for (int i = 0; i < map; i++)
    {
        for (int j = 0; j < map; j++)
        {
            cout << A[i*map + j] << " ";
        }
        cout << endl;
    }
    cout << endl;


    cout << "¾í»ýºË¾ØÕó:" << endl;
    for (int i = 0; i < kernel; i++)
    {
        for (int j = 0; j < kernel; j++)
        {
            cout << B[i*kernel + j] << " ";
        }
        cout << endl;
    }
    cout << endl;


    cout << "¾í»ýºóÊä³ö¾ØÕó£º" << endl;
    for (int i = 0; i < outm; i++)
    {
        for (int j = 0; j < outm; j++)
        {
            cout << C[i*outm + j] << " ";
        }
        cout << endl;
    }

    system("pause");
	
	return 0;
}
