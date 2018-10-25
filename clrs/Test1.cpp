#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;

char puzzle[10][10];
int r0,c0;//记录空格的位置
const char* turns = "ABLR";
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void read(int row, string str)
{
    for(int j=0;j<5;j++){
        puzzle[row][j] = str[j];
        if(str[j]==' ') { r0 = row; c0 = j;}
    }
}

bool move_p(char turn)
{
    int flag = 1;
    //int t = (strchr(turns,turn)-turns);
    int t;
    if(turn == 'A') t =0;
    else if(turn == 'B') t =1;
    else if(turn == 'L') t =2;
    else if(turn == 'R') t =3;
    int x,y;
    x = r0 + dx[t]; y = c0 + dy[t];
    if(x>=0&&x<=4&&y>=0&&y<=4){
        puzzle[r0][c0] = puzzle[x][y];
        puzzle[x][y] = ' ';
        r0 = x; c0 =y;
    }
    else flag = 0;
    if(flag) return true;
    else return false;
}

int main()
{
    freopen("data.in","r",stdin);
    string str,order;
    int icase = 0;
    while(1)
    {
        if(icase!=0) cin.get();
        getline(cin,str); //cin>>str;
        if(str[0]=='Z') break;
        if(icase!=0) cout<<endl;//不同样例之间换行
        read(0,str);
        for(int i=1;i<=4;i++)
        {
            getline(cin,str);
            read(i,str);
        }
        int ok,len;
        order.clear();
        //读入全部指令
        while(1)
        {
            string temp; cin>>temp;
            order += temp;
            len = temp.length();
            if(temp[len-1]=='0') break;
            else continue;
        }

        ok = 1;len = order.length();
        for(int i=0;i<len-1;i++)
        {
            if(move_p(order[i])) continue;
            else { ok = 0; break;}
        }
        cout<<"Puzzle #"<<++icase<<":"<<endl;
        if(ok)
        {
            int i,j;
            for(i=0;i<5;i++){
                for(j=0;j<4;j++) cout<<puzzle[i][j]<<" ";
                cout<<puzzle[i][j]<<endl;
            }
            //cout<<endl;
        }
        else cout<<"This puzzle has no final configuration."<<endl;
    }
    return 0;
}
