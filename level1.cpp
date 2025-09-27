#include<bits/stdc++.h>

using namespace std;

string c;
int user;
int arr[8][6][5][5];//7天 5层 4*4
int cf;
int cd;
int x,y;
string day[10]={
    "","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"
};

void ls(){
    cout<<"登陆成功\n";
}

void login(){
    cin>>c;
    if(c=="Admin"){
        user=100;
        ls();
        return;
    }
    if(c.size()==1&&c[0]>='A'&&c[0]<='Z'){
        user=c[0]-'A'+1;
        ls();
        return;
    }
    cout<<"未找到用户，登录失败\n";
}

bool checkday(){
    if(c=="Monday"){
        cd=1;
        return 1;
    }
    if(c=="Tuesday"){
        cd=2;
        return 1;
    }
    if(c=="Wednesday"){
        cd=3;
        return 1;
    }
    if(c=="Thursday"){
        cd=4;
        return 1;
    }
    if(c=="Friday"){
        cd=5;
        return 1;
    }
    if(c=="Saturday"){
        cd=6;
        return 1;    
    }
    if(c=="Sunday"){
        cd=7;
        return 1;
    }
    return 0;
}

void writeseat(){
    FILE *pfd=fopen("library.txt","w");
    for(int i=1;i<=7;i++){
        for(int j=1;j<=5;j++){
            for(int k=1;k<=4;k++){
                for(int w=1;w<=4;w++){
                    fprintf(pfd,"%d ",arr[i][j][k][w]);
                }
            }
        }
    }
    fclose(pfd);
}

void readseat(){
    FILE *pfd=fopen("library.txt","r");
    if(!pfd){
        memset(arr,0,sizeof(arr));
        return;
    }
    for(int i=1;i<=7;i++){
        for(int j=1;j<=5;j++){
            for(int k=1;k<=4;k++){
                for(int w=1;w<=4;w++){
                    fscanf(pfd,"%d",&arr[i][j][k][w]);
                }
            }
        }
    }
    fclose(pfd);
}

void reserve(){
    cin>>c;
    cd=0;
    checkday();
    cin>>c;
    cin>>cf;
    cin>>c;
    cin>>x>>y;
    readseat();
    if(cd==0||cf<1||cf>5||x<1||x>4||y<1||y>4){
        cout<<"输入不合法\n";
        return;
    }
    if(arr[cd][cf][x][y]!=0){
        cout<<"该位置已被预约，请求失败\n";
        return;
    }
    arr[cd][cf][x][y]=user;
    cout<<"OK\n";
    writeseat();
}

void printfboss(){
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(arr[cd][cf][i][j]==0){
                cout<<0<<" ";
            }else{
                printf("%c ",arr[cd][cf][i][j]+'A'-1);
            }
        }
        cout<<"\n";
    }
}

void printfnow(){
    if(user==100){
        printfboss();
        return;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(arr[cd][cf][i][j]==0){
                cout<<0<<" ";
            }else if(arr[cd][cf][i][j]==user){
                cout<<2<<" ";
            }else{
                cout<<1<<" ";
            }
        }
        cout<<"\n";
    }
}

void prework(){
    FILE *pfd=fopen("library.txt","w");
    for(int i=1;i<=7;i++){
        for(int j=1;j<=5;j++){
            for(int k=1;k<=4;k++){
                for(int w=1;w<=4;w++){
                    fprintf(pfd,"0 ");
                }
            }
        }
    }
    fclose(pfd);
}

void findseat(){   
    readseat();
    for(int i=1;i<=7;i++){
        for(int j=1;j<=5;j++){
            for(int k=1;k<=4;k++){
                for(int w=1;w<=4;w++){
                    if(arr[i][j][k][w]==user){
                        cout<<day[i]<<" ";
                        printf("Floor %d Seat %d %d\n",j,k,w);
                    }
                }
            }
        }
    }
}

int main(){
    //prework();
    while(1){
        cin>>c;
        if(c=="Login"){
            if(user!=0){
                cout<<"请先退出登录\n";
            }
            cout<<"请输入用户名\n";
            login();
            continue;
        }
        if(c=="Exit"){
            user=0;
            cout<<"OK\n";
            continue;
        }
        if(c=="Quit"){
            cout<<"OK\n";
            return 0;
        }

        if(checkday()){
            cin>>c;
            cin>>cf;
            if(cf<1||cf>5){
                cout<<"输入不合法\n";
                continue;
            }
            readseat();
            printfnow();
        }
        if(c=="Reserve"){
            reserve();
            continue;
        }
        if(c=="Clear"){
            if(user!=100){
                cout<<"权限不够";
            }else{   
                prework();
                cout<<"OK\n";
            }
            continue;
        }
        if(c=="Reservation"){
            findseat();
            continue;
        }
    }
    return 0;
}