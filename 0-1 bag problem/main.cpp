#include<iostream>
#include<windows.h>
#include<queue>
#define N 200
using namespace std;


class HeapNode
{
    public:
        double uprofit;//�ڵ�ļ�ֵ�Ͻ�
        double profit; //�ڵ�����Ӧ�ļ�ֵ
        double weight;//�������Ӧ������
        int level;//�������Ӽ����������Ĳ����
        HeapNode* parent;
        bool valid;
};


queue<HeapNode*> H; //��
double w[N],p[N]; //
bool x[N];  //��¼�����ķ���
bool y[N];  //��¼������δ����
double cw,cp,c;
int n;   //�ܹ��ı�����Ŀ
HeapNode* node;
double bestp=0;

int k=0;

/*
    �������޵ĺ���
    int i������ǰ�Ĳ���
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
    ���뵱ǰ�Ķ���
    ������
        1.double up���ڵ�ļ�ֵ�Ͻ�
        2.double cp; //�ڵ�����Ӧ�ļ�ֵ
        3.double cw;//�������Ӧ������
        4.int level;//�������Ӽ����������Ĳ����
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

    //ɾѡ�����һ������Ž�
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
    cout<<"������n��c:";  cin>>n>>c;
    cout<<"������w[i]"<<endl;
    for(int i=1;i<=n;i++)  cin>>w[i];
    cout<<"������p[i]"<<endl;
    for(int i=1;i<=n;i++)  cin>>p[i];
    Knap();
    cout<<"����ֵ�ǣ�"<<bestp<<endl;


    //cout<<node->profit<<endl;

    cout<<"����������ȡ�������"<<endl;
    for(int i=1;i<=n;i++){
        cout<<x[i]<<"    ";
    }

    system("pause");
    return 0;
}
