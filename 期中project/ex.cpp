/* Convolutional Code */ 
/* 輸入(n,k,a) */
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char g[5][5]= {}; //生成多項式
    int n,k,a;
    int sum=0;
    int number=0; //輸入的碼元數 
    char ci[10]= {}; //輸入
    char d[10]= {}; //寄存器
    int re;
    while(re--)
    {
        memset(d,'0',sizeof(d));
        cout<<"請輸入（n，k，a）"<<endl;;
        cout<<"請輸入n：";
        cin>>n;
        k=1;
        cout<<"請輸入k："<<k;
        cout<<"請輸入a：";
        cin>>a;

        cout<<"請輸入生成多項式"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<"g["<<i<<"]=";
            cin>>g[i];
        }
        cout<<"請輸入總碼元數"<<endl;
        cin>>number;
        cin>>ci;
        //計算卷積碼
        for(int m=0; m<number; m++) //第m個輸入
        {
            for(int i=0; i<n; i++) //第i個生成多項式
            {
                sum=(ci[m]-'0')*(g[i][0]-'0');
                for(int l=0; l<a; l++)
                {
                    sum+=(d[l]-'0')*(g[i][l+1]-'0');
                }
                cout<<sum%2;
            }//計算卷積碼輸出
            cout<<endl;

            for(int j=a; j>0; j--)
            {
                d[j]=d[j-1];
            }
            d[0]=ci[m];//寄存器狀態后移
        }
    }
    return 0;
}
