/* Convolutional Code */ 
/* ��J(n,k,a) */
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char g[5][5]= {}; //�ͦ��h����
    int n,k,a;
    int sum=0;
    int number=0; //��J���X���� 
    char ci[10]= {}; //��J
    char d[10]= {}; //�H�s��
    int re;
    while(re--)
    {
        memset(d,'0',sizeof(d));
        cout<<"�п�J�]n�Ak�Aa�^"<<endl;;
        cout<<"�п�Jn�G";
        cin>>n;
        k=1;
        cout<<"�п�Jk�G"<<k;
        cout<<"�п�Ja�G";
        cin>>a;

        cout<<"�п�J�ͦ��h����"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<"g["<<i<<"]=";
            cin>>g[i];
        }
        cout<<"�п�J�`�X����"<<endl;
        cin>>number;
        cin>>ci;
        //�p����n�X
        for(int m=0; m<number; m++) //��m�ӿ�J
        {
            for(int i=0; i<n; i++) //��i�ӥͦ��h����
            {
                sum=(ci[m]-'0')*(g[i][0]-'0');
                for(int l=0; l<a; l++)
                {
                    sum+=(d[l]-'0')*(g[i][l+1]-'0');
                }
                cout<<sum%2;
            }//�p����n�X��X
            cout<<endl;

            for(int j=a; j>0; j--)
            {
                d[j]=d[j-1];
            }
            d[0]=ci[m];//�H�s�����A�Z��
        }
    }
    return 0;
}
