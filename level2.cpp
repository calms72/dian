#include<bits/stdc++.h>

using namespace std;

string c;
int user;
int arr[8][6][100][100];//7天 5层 4*4
int arrx[8][6];//记录每层的行数
int arry[8][6][100];//记录每层每行的列数
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
    FILE *pfd=fopen("library2.txt","w");
    for(int i=1;i<=7;i++){
        for(int j=1;j<=5;j++){
            fprintf(pfd,"%d ",arrx[i][j]);
            for(int k=1;k<=arrx[i][j];k++){
                fprintf(pfd,"%d ",arry[i][j][k]);
                for(int w=1;w<=arry[i][j][k];w++){
                    fprintf(pfd,"%d ",arr[i][j][k][w]);
                }
            }
        }
    }
    fclose(pfd);
}

void readseat(){
    FILE *pfd=fopen("library2.txt","r");
    if(!pfd){
        fclose(pfd);
        memset(arr,0,sizeof(arr));
        memset(arrx,0,sizeof(arrx));
        memset(arry,0,sizeof(arry));
        for(int i=1;i<=7;i++){
            for(int j=1;j<=5;j++){
                arrx[i][j]=4;
                for(int k=1;k<=4;k++){
                    arry[i][j][k]=4;
                }
            }
        }
        for(int i=1;i<=7;i++){
            for(int j=1;j<=5;j++){
                for(int k=1;k<=arrx[i][j];k++){
                    for(int w=1;w<=arry[i][j][k];w++){
                        arr[i][j][k][w]=30;
                    }
                }
            }
        }
        writeseat();
        return;
    }
    for(int i=1;i<=7;i++){
        for(int j=1;j<=5;j++){
            fscanf(pfd,"%d",&arrx[i][j]);
            for(int k=1;k<=arrx[i][j];k++){
                fscanf(pfd,"%d",&arry[i][j][k]);
                for(int w=1;w<=arry[i][j][k];w++){
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
    if(arr[cd][cf][x][y]!=30){
        cout<<"该位置已被预约，请求失败\n";
        return;
    }
    arr[cd][cf][x][y]=user;
    cout<<"OK\n";
    writeseat();
}

void printfboss(){
    for(int i=1;i<=arrx[cd][cf];i++){
        for(int j=1;j<=arry[cd][cf][i];j++){
            if(arr[cd][cf][i][j]==30){
                cout<<0<<" ";
            }else if(arr[cd][cf][i][j]==0){
                cout<<-1<<" ";
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
    for(int i=1;i<=arrx[cd][cf];i++){
        for(int j=1;j<=arry[cd][cf][j];j++){
            if(arr[cd][cf][i][j]==30){
                cout<<0<<" ";
            }else if(arr[cd][cf][i][j]==user){
                cout<<2<<" ";
            }else if(arr[cd][cf][i][j]==0){
                cout<<-1<<" ";
            }else{
                cout<<1<<" ";
            }
        }
        cout<<"\n";
    }
}

void prework(){
    FILE *pfd=fopen("library2.txt","w");
    memset(arr,0,sizeof(arr));
    memset(arrx,0,sizeof(arrx));
    memset(arry,0,sizeof(arry));
    for(int i=1;i<=7;i++){
        for(int j=1;j<=5;j++){
            fprintf(pfd,"%d ",4);
            arrx[i][j]=4;
            for(int k=1;k<=arrx[i][j];k++){
                fprintf(pfd,"%d ",4);
                arry[i][j][k]=4;
                for(int w=1;w<=arry[i][j][k];w++){
                    fprintf(pfd,"0 ");
                }
            }
        }
    }
    fclose(pfd);
}

void findseatboss(){
    readseat();
    for(int i=1;i<=7;i++){
        for(int j=1;j<=5;j++){
            for(int k=1;k<=arrx[i][j];k++){
                for(int w=1;w<=arry[i][j][k];w++){
                    if(arr[i][j][k][w]!=30&&arr[i][j][k][w]!=0){
                        cout<<day[i]<<" ";
                        printf("Floor %d Seat %d %d User %c\n",j,k,w,arr[i][j][k][w]+'A'-1);
                    }
                }
            }
        }
    }
}

void findseat(){  
    readseat();
    if(user==100){
        findseatboss();
    }
    for(int i=1;i<=7;i++){
        for(int j=1;j<=5;j++){
            for(int k=1;k<=arrx[i][j];k++){
                for(int w=1;w<=arry[i][j][k];w++){
                    if(arr[i][j][k][w]==user){
                        cout<<day[i]<<" ";
                        printf("Floor %d Seat %d %d\n",j,k,w);
                    }
                }
            }
        }
    }
}

void reserveboss(){
    cin>>c;
    int now= c[0] - 'A' + 1;
    cin>>c;
    checkday();
    cin>>c;
    cin>>cf;
    cin>>c;
    cin>>x>>y;
    arr[cd][cf][x][y]=now;
    writeseat();
}

void eraseday(){//boss Erase Monday 
    readseat();
    cin>>c;
    if(c=="All"){
        for(int j=1;j<=5;j++){
            for(int k=1;k<=arrx[cd][j];k++){
                for(int w=1;w<=arry[cd][j][k];w++){
                    arr[cd][j][k][w]=30;
                }
            }
        }
        writeseat();
    }
    if(c=="Floor"){
        cin>>cf;
        for(int k=1;k<=arrx[cd][cf];k++){
            for(int w=1;w<=arry[cd][cf][k];w++){
                arr[cd][cf][k][w]=30;
            }
        }
        writeseat();
    }
}

void eraseboss(){
    cin>>c;
    if(checkday()){
        eraseday();
        return;
    }
    int now= c[0] - 'A' + 1;
    cin>>c;
    checkday();
    cin>>c;
    cin>>cf;
    cin>>c;
    cin>>x>>y;
    if(arr[cd][cf][x][y]==now){
        arr[cd][cf][x][y]=30;
        cout<<"OK\n";
    }else{
        cout<<"取消失败\n";
    }
    writeseat();
}

void erasenormal(){
    cin>>c;
    checkday();
    cin>>c;
    cin>>cf;
    cin>>x>>y;
    if(arr[cd][cf][x][y]==user){
        arr[cd][cf][x][y]=30;
        cout<<"\n";
    }else{
        cout<<"你没有预约该座位\n";
    }
    writeseat();
}

void checkloc(){
    readseat();
    if(x<=arrx[cd][cf]&&y<=arry[cd][cf][x]){
        arr[cd][cf][x][y]=0;
    }
    writeseat();
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
            if(user==0){
                cout<<"请先登录\n";
                continue;
            }
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
            if(user==0){
                cout<<"请先登录\n";
                continue;
            }
            if(user==100){
                reserveboss();
                continue;
            }
            reserve();
            continue;
        }
        if(c=="Erase"){
            if(user==0){
                cout<<"请先登录\n";
                continue;
            }
            if(user==100){
                eraseboss();
            }else{
                erasenormal();
            }
        }
        if(c=="Clear"){
            if(user==0){
                cout<<"请先登录\n";
                continue;
            }
            if(user!=100){
                cout<<"权限不够";
            }else{   
                prework();
                cout<<"OK\n";
            }
            continue;
        }
        if(c=="Reservation"){
            if(user==0){
                cout<<"请先登录\n";
                continue;
            }
            findseat();
            continue;
        }
        if(c=="Del"){
            if(user==100){
                cin>>c;
                checkday();
                cin>>c;
                cin>>cf;
                cin>>c;
                cin>>x>>y;
                checkloc();
            }else{
                cout<<"权限不够\n";
            }
        }
        if(c=="Add"){
            if(user==100){
                cin>>c;
                checkday();
                cin>>c;
                cin>>cf;
                cin>>c;
                cin>>x>>y;
                readseat();
                while(x>arrx[cd][cf]){
                    arrx[cd][cf]=x;
                }
                if(y>arry[cd][cf][x]){
                    arry[cd][cf][x]=y;
                }
                arr[cd][cf][x][y]=30;
                writeseat();
            }else{
                cout<<"权限不够\n";
            }
        }
        //cout<<"Wrong"<<"\n";
    }
    return 0;
}