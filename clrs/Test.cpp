#include<stdio.h>
#include<ctime>
#include<cstring>
#include<ctype.h>
#include<vector>
#include<cmath>
using namespace std;

const int MAX = 1000;
const int INF = 100000000;

//#define LOCAL
char data[6][6];
char dodata[MAX];

bool check(int currindex,char donow)
{
    if(currindex<=4 && donow == 'A')
        return false;
    if(currindex%5 == 0 && donow == 'L')
        return false;
    if(currindex%5 == 4 && donow == 'R')
        return false;
    if(currindex>=20 && currindex <= 24 && donow == 'B')
        return false;
    return true;
}

void exchange(char& a, char& b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}

int change(int currindex,char donow)
{
    int a = currindex/5;
    int b = currindex%5;
    switch(donow)
    {
    case 'A':
        exchange(data[a][b], data[a-1][b]);
        return currindex-5;
        break;
    case 'B':
        exchange(data[a][b], data[a+1][b]);
        return currindex+5;
        break;
    case 'L':
        exchange(data[a][b-1], data[a][b]);
        return currindex-1;
        break;
    case 'R':
        exchange(data[a][b], data[a][b+1]);
        return currindex+1;
        break;
    }
    return currindex;
}
        

int main()
{
#ifdef LOCAL
    freopen("data.in", "rb", stdin);
    freopen("data.out","wb",stdout);
#endif

    freopen("data.in", "rb", stdin);
    char tempc;
    bool begin1 = true;
    int tempi = 0;
    int cur = 1;
    while(1)
    {
        int currindex = 0;
        bool end = true, end1 = true;
        tempi = 0;
        tempc = '\0';
        while(1){
            if((tempi == 1 && tempc == 'Z')||tempi == 25){
                if(tempc == 'Z' && tempi == 1)
                    end1 = false;
                break;
            }
            tempc = getchar();
            if(tempc == ' '||(tempc == '\n'&&tempi%5 == 4))
            {
                if(tempi%5 == 4)
                {
                    char ct;
                    while((ct = getchar()) == ' ');
                }
                currindex = tempi;
                tempc = ' ';
            }
            if(tempi%5 == 4)
            {
                if(currindex%5 != 4 || tempi != currindex)//其实是这里有问题，是将输入尾部的空格和换行除掉
                {
                    char ct;
                    while((ct = getchar()) == ' ');
                }
            }
            data[tempi/5][tempi%5] = tempc;
            tempi++;
        }
        
        if(!end1)
            break;
        if(!begin1){
            printf("\n");
        }
        begin1 = false;
        tempi = 0;
        while((tempc = getchar()) != '0'){
            if(tempc == ' '|| tempc == '\n')
                continue;
            dodata[tempi++] = tempc;
        }
              getchar();
        int len = tempi;
        for(int i = 0; i != len; i++)
        {
            if(!(end = check(currindex, dodata[i])))
               break;
            if(dodata[i] != 'A'&&dodata[i]!= 'L'&&dodata[i] != 'R'&& dodata[i] != 'B')
                dodata[i] = dodata[i-1];
            currindex = change(currindex, dodata[i]);
        }
        printf("Puzzle #%d:\n",cur++);
        if(!end)
            printf("This puzzle has no final configuration.\n");
        else
        {
            for(int i = 0; i != 5; i++)
            {
                for(int j = 0; j != 5; j++)
                {
                    if(j != 4)
                        printf("%c ",data[i][j]);
                    else
                        printf("%c\n",data[i][j]);
                }
            }
        }
    }
    return 0;
}
/* 蛇形填数   
    int n,curr = 1;
    int time = 0;
    scanf("%d",&n);
    while(time != (n+1)/2)
    {
        for(int i = time;i !=n-time; i++,curr++)
            a[i][n-1-time] = curr;
        for(int i = 1+time;i !=n-time; i++,curr++)
            a[n-1-time][n-i-1] = curr;
        for(int i = 1+time;i !=n-time; i++,curr++)
            a[n-i-1][time] = curr;
        for(int i = 2+time;i <n-time; i++,curr++)
            a[time][i-1] = curr;
        time++;
    }
    for(int i = 0; i!=n; i++)
    {
        for(int j = 0; j != n; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
            
    printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
*/
