#include<iostream>
#include<windows.h>
#include<queue>
#define N 200
using namespace std;


class HeapNode
{
    public:
        double uprofit;//节点的价值上界
        double profit; //节点所对应的价值
        double weight;//结点所对应的重量
        int level;//活结点在子集树种所处的层序号
        HeapNode* parent;
        bool valid;
};


queue<HeapNode*> H; //堆
double w[N],p[N]; //
bool x[N];  //记录包裹的放入
bool y[N];  //记录包裹的未放入
double cw,cp,c;
int n;   //总共的背包数目
HeapNode* node;
double bestp=0;

int k=0;

/*
    计算上限的函数
    int i：代表当前的层数
*/
double Bound(int i)
{
    double cleft=c-cw,b=cp;
    while(i<=n&&w[i]<=cleft)
    {
        cleft-=w[i];
        b+=p[i];
        i++;
    }
    if(i<=n)  b+=p[i]/w[i]*cleft;
    return b;
}

/*
    加入当前的堆中
    参数：
        1.double up：节点的价值上界
        2.double cp; //节点所对应的价值
        3.double cw;//结点所对应的重量
        4.int level;//活结点在子集树种所处的层序号
*/
void AddLiveNode(double up,double cp,double cw,bool ch,int level)
{
    HeapNode* nod=new HeapNode();
    nod->uprofit=up;
    nod->profit=cp;
    nod->weight=cw;
    nod->level=level;
    nod->valid=ch;
    nod->parent=node;
    if(level<=n+1)  H.push(nod);
}

/*

*/
double Knap()
{
    int i=1;
    cw=cp=0;
    node=0;
    double up=Bound(1);
    while(i!=n+1)
    {
        double wt=cw+w[i];
        if(wt<=c)
        {
            if(cp+p[i]>bestp)   bestp=cp+p[i];
            AddLiveNode(up,cp+p[i],cw+w[i],true,i+1);
            k++;
        }
        up=Bound(i+1);
        if(up>=bestp){
             AddLiveNode(up,cp,cw,false,i+1);
             k++;
        }
        //if(H.empty())
        //    return bestp;
        node=H.front();
        H.pop();
        cw=node->weight;
        cp=node->profit;
        up=node->uprofit;
        i=node->level;
    }

    //删选出最后一层的最优解
    int a=H.size();
    for(int i=0;i<H.size();i++){
        if(node->uprofit<H.front()->uprofit){
            node=H.front();
            H.pop();
        }
        else{
            H.pop();
        }
    }

    for(int j=n;j>0;j--){
        x[j]=node->valid;
        node=node->parent;
    }

}
int main()
{
    cout<<"请输入n和c:";  cin>>n>>c;
    cout<<"请输入w[i]"<<endl;
    for(int i=1;i<=n;i++)  cin>>w[i];
    cout<<"请输入p[i]"<<endl;
    for(int i=1;i<=n;i++)  cin>>p[i];
    Knap();
    cout<<"最优值是："<<bestp<<endl;


    //cout<<node->profit<<endl;

    cout<<"各个背包存取的情况："<<endl;
    for(int i=1;i<=n;i++){
        cout<<x[i]<<"    ";
    }

    system("pause");
    return 0;
}
