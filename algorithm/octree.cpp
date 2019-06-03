//
// Created by mac on 2019-06-01.
//

#include <iostream>

using namespace std;
//定义八叉树节点类
template<class T>
struct OctreeNode
{
    T data; //节点数据
    T xmin,xmax; //节点坐标，即六面体个顶点的坐标
    T ymin,ymax;
    T zmin,zmax;
    OctreeNode <T>*top_left_front,*top_left_back; //该节点的个子结点
    OctreeNode <T>*top_right_front,*top_right_back;
    OctreeNode <T>*bottom_left_front,*bottom_left_back;
    OctreeNode <T>*bottom_right_front,*bottom_right_back;
    OctreeNode //节点类
            (T nodeValue = T(),
             T xminValue = T(),T xmaxValue = T(),
             T yminValue = T(),T ymaxValue = T(),
             T zminValue = T(),T zmaxValue = T(),
             OctreeNode<T>*top_left_front_Node = NULL,
             OctreeNode<T>*top_left_back_Node = NULL,
             OctreeNode<T>*top_right_front_Node = NULL,
             OctreeNode<T>*top_right_back_Node = NULL,
             OctreeNode<T>*bottom_left_front_Node = NULL,
             OctreeNode<T>*bottom_left_back_Node = NULL,
             OctreeNode<T>*bottom_right_front_Node = NULL,
             OctreeNode<T>*bottom_right_back_Node = NULL )
            :data(nodeValue),
             xmin(xminValue),xmax(xmaxValue),
             ymin(yminValue),ymax(ymaxValue),
             zmin(zminValue),zmax(zmaxValue),
             top_left_front(top_left_front_Node),
             top_left_back(top_left_back_Node),
             top_right_front(top_right_front_Node),
             top_right_back(top_right_back_Node),
             bottom_left_front(bottom_left_front_Node),
             bottom_left_back(bottom_left_back_Node),
             bottom_right_front(bottom_right_front_Node),
             bottom_right_back(bottom_right_back_Node){}
};
//创建八叉树
template <class T>
void createOctree(OctreeNode<T> * &root,int maxdepth,double xmin,double xmax,
        double ymin,double ymax,double zmin,double zmax)
{
    //cout<<"处理中，请稍候……"<<endl;
    maxdepth=maxdepth-1; //每递归一次就将最大递归深度-1
    if(maxdepth>=0)
    {
        root=new OctreeNode<T>();
        cout<<"请输入节点值:";
        //root->data =9;//为节点赋值，可以存储节点信息，如物体可见性。由于是简单实现八叉树功能，简单赋值为9。
        cin>>root->data;  //为节点赋值
        root->xmin=xmin; //为节点坐标赋值
        root->xmax=xmax;
        root->ymin=ymin;
        root->ymax=ymax;
        root->zmin=zmin;
        root->zmax=zmax;
        double xm=(xmax-xmin)/2;//计算节点个维度上的半边长
        double ym=(ymax-ymin)/2;
        double zm=(ymax-ymin)/2;
        //递归创建子树，根据每一个节点所处（是几号节点）的位置决定其子结点的坐标。
        createOctree(root->top_left_front,maxdepth,xmin,xmax-xm,ymax-ym,ymax,zmax-zm,zmax);
        createOctree(root->top_left_back,maxdepth,xmin,xmax-xm,ymin,ymax-ym,zmax-zm,zmax);
        createOctree(root->top_right_front,maxdepth,xmax-xm,xmax,ymax-ym,ymax,zmax-zm,zmax);
        createOctree(root->top_right_back,maxdepth,xmax-xm,xmax,ymin,ymax-ym,zmax-zm,zmax);
        createOctree(root->bottom_left_front,maxdepth,xmin,xmax-xm,ymax-ym,ymax,zmin,zmax-zm);
        createOctree(root->bottom_left_back,maxdepth,xmin,xmax-xm,ymin,ymax-ym,zmin,zmax-zm);
        createOctree(root->bottom_right_front,maxdepth,xmax-xm,xmax,ymax-ym,ymax,zmin,zmax-zm);
        createOctree(root->bottom_right_back,maxdepth,xmax-xm,xmax,ymin,ymax-ym,zmin,zmax-zm);
    }
}
int i=1;
//先序遍历八叉树
template <class T>
void preOrder( OctreeNode<T> * & p)
{
    if(p)
    {
        cout<<i<<".当前节点的值为："<<p->data<<"\n坐标为：";
        cout<<"xmin: "<<p->xmin<<" xmax: "<<p->xmax;
        cout<<"ymin: "<<p->ymin<<" ymax: "<<p->ymax;
        cout<<"zmin: "<<p->zmin<<" zmax: "<<p->zmax;
        i+=1;
        cout<<endl;
        preOrder(p->top_left_front);
        preOrder(p->top_left_back);
        preOrder(p->top_right_front);
        preOrder(p->top_right_back);
        preOrder(p->bottom_left_front);
        preOrder(p->bottom_left_back);
        preOrder(p->bottom_right_front);
        preOrder(p->bottom_right_back);
        cout<<endl;
    }
}
//求八叉树的深度
template<class T>
int depth(OctreeNode<T> *& p)
{
    if(p == NULL)
        return -1;
    int h =depth(p->top_left_front);
    return h+1;
}
//计算单位长度，为查找点做准备
int cal(int num)
{
    int result=1;
    if(1==num)
        result=1;
    else
    {
        for(int i=1;i<num;i++)
            result=2*result;
    }
    return result;
}
//查找点
int maxdepth=0;
int times=0;
static double xmin=0,xmax=0,ymin=0,ymax=0,zmin=0,zmax=0;
int tmaxdepth=0;
double txm=1,tym=1,tzm=1;
template<class T>
void find(OctreeNode<T> *& p,double x,double y,double z)
{
    double xm=(p->xmax-p->xmin)/2;
    double ym=(p->ymax-p->ymin)/2;
    double zm=(p->ymax-p->ymin)/2;
    times++;
    if(x>xmax || x<xmin|| y>ymax || y<ymin || z>zmax || z<zmin)
    {
        cout<<"该点不在场景中！"<<endl;
        return;
    }
    if(x<=p->xmin+txm&& x>=p->xmax-txm && y<=p->ymin+tym &&y>=p->ymax-tym && z<=p->zmin+tzm &&z>=p->zmax-tzm )
    {
        cout<<endl<<"找到该点！"<<"该点位于"<<endl;
        cout<<"xmin: "<<p->xmin<<" xmax: "<<p->xmax;
        cout<<"ymin: "<<p->ymin<<" ymax: "<<p->ymax;
        cout<<"zmin: "<<p->zmin<<" zmax: "<<p->zmax;
        cout<<"节点内！"<<endl;
        cout<<"共经过"<<times<<"次递归！"<<endl;
    }
    else if(x<(p->xmax-xm) && y<(p->ymax-ym) &&z<(p->zmax-zm))
    {
        cout<<"当前经过节点坐标："<<endl;
        cout<<"xmin: "<<p->xmin<<" xmax: "<<p->xmax;
        cout<<"ymin: "<<p->ymin<<" ymax: "<<p->ymax;
        cout<<"zmin: "<<p->zmin<<" zmax: "<<p->zmax;
        cout<<endl;
        find(p->bottom_left_back,x,y,z);
    }
    else if(x<(p->xmax-xm) && y<(p->ymax-ym) &&z>(p->zmax-zm))
    {
        cout<<"当前经过节点坐标："<<endl;
        cout<<"xmin: "<<p->xmin<<" xmax: "<<p->xmax;
        cout<<"ymin: "<<p->ymin<<" ymax: "<<p->ymax;
        cout<<"zmin: "<<p->zmin<<" zmax: "<<p->zmax;
        cout<<endl;
        find(p->top_left_back,x,y,z);
    }
    else if(x>(p->xmax-xm) && y<(p->ymax-ym) &&z<(p->zmax-zm))
    {
        cout<<"当前经过节点坐标："<<endl;
        cout<<"xmin: "<<p->xmin<<" xmax: "<<p->xmax;
        cout<<"ymin: "<<p->ymin<<" ymax: "<<p->ymax;
        cout<<"zmin: "<<p->zmin<<" zmax: "<<p->zmax;
        cout<<endl;
        find(p->bottom_right_back,x,y,z);
    }
    else if(x>(p->xmax-xm) && y<(p->ymax-ym) &&z>(p->zmax-zm))
    {
        cout<<"当前经过节点坐标："<<endl;
        cout<<"xmin: "<<p->xmin<<" xmax: "<<p->xmax;
        cout<<"ymin: "<<p->ymin<<" ymax: "<<p->ymax;
        cout<<"zmin: "<<p->zmin<<" zmax: "<<p->zmax;
        cout<<endl;
        find(p->top_right_back,x,y,z);
    }
    else if(x<(p->xmax-xm) && y>(p->ymax-ym) &&z<(p->zmax-zm))
    {
        cout<<"当前经过节点坐标："<<endl;
        cout<<"xmin: "<<p->xmin<<" xmax: "<<p->xmax;
        cout<<"ymin: "<<p->ymin<<" ymax: "<<p->ymax;
        cout<<"zmin: "<<p->zmin<<" zmax: "<<p->zmax;
        cout<<endl;
        find(p->bottom_left_front,x,y,z);
    }
    else if(x<(p->xmax-xm) && y>(p->ymax-ym) &&z>(p->zmax-zm))
    {
        cout<<"当前经过节点坐标："<<endl;
        cout<<"xmin: "<<p->xmin<<" xmax: "<<p->xmax;
        cout<<"ymin: "<<p->ymin<<" ymax: "<<p->ymax;
        cout<<"zmin: "<<p->zmin<<" zmax: "<<p->zmax;
        cout<<endl;
        find(p->top_left_front,x,y,z);
    }
    else if(x>(p->xmax-xm) && y>(p->ymax-ym) &&z<(p->zmax-zm))
    {
        cout<<"当前经过节点坐标："<<endl;
        cout<<"xmin: "<<p->xmin<<" xmax: "<<p->xmax;
        cout<<"ymin: "<<p->ymin<<" ymax: "<<p->ymax;
        cout<<"zmin: "<<p->zmin<<" zmax: "<<p->zmax;
        cout<<endl;
        find(p->bottom_right_front,x,y,z);
    }
    else if(x>(p->xmax-xm) && y>(p->ymax-ym) &&z>(p->zmax-zm))
    {
        cout<<"当前经过节点坐标："<<endl;
        cout<<"xmin: "<<p->xmin<<" xmax: "<<p->xmax;
        cout<<"ymin: "<<p->ymin<<" ymax: "<<p->ymax;
        cout<<"zmin: "<<p->zmin<<" zmax: "<<p->zmax;
        cout<<endl;
        find(p->top_right_front,x,y,z);
    }
}
//main函数
int main ()
{
    OctreeNode<double> *rootNode = NULL;
    int choiced = 0;
    while(true)
    {
        system("cls");
        cout<<"请选择操作：\n";
        cout<<"1.创建八叉树 2.先序遍历八叉树\n";
        cout<<"3.查看树深度 4.查找节点   \n";
        cout<<"0.退出\n\n";
        cin>>choiced;
        if(choiced == 0)
            return 0;
        else if(choiced == 1)
        {
            system("cls");
            cout<<"请输入最大递归深度："<<endl;
            cin>>maxdepth;
            cout<<"请输入外包盒坐标，顺序如下：xmin,xmax,ymin,ymax,zmin,zmax"<<endl;
            cin>>xmin>>xmax>>ymin>>ymax>>zmin>>zmax;
            if(maxdepth>=0|| xmax>xmin || ymax>ymin || zmax>zmin || xmin>0 || ymin>0||zmin>0)
            {
                tmaxdepth=cal(maxdepth);
                txm=(xmax-xmin)/tmaxdepth;
                tym=(ymax-ymin)/tmaxdepth;
                tzm=(zmax-zmin)/tmaxdepth;
                createOctree(rootNode,maxdepth,xmin,xmax,ymin,ymax,zmin,zmax);
            }
            else
            {
                cout<<"输入错误！";
                return 0;
            }
        }
        else if(choiced == 2)
        {
            system("cls");
            cout<<"先序遍历八叉树结果：/n";
            i=1;
            preOrder(rootNode);
            cout<<endl;
            system("pause");
        }
        else if(choiced == 3)
        {
            system("cls");
            int dep =depth(rootNode);
            cout<<"此八叉树的深度为"<<dep+1<<endl;
            system("pause");
        }
        else if(choiced == 4)
        {
            system("cls");
            cout<<"请输入您希望查找的点的坐标，顺序如下：x,y,z\n";
            double x,y,z;
            cin>>x>>y>>z;
            times=0;
            cout<<endl<<"开始搜寻该点……"<<endl;
            find(rootNode,x,y,z);
            system("pause");
        }
        else
        {
            system("cls");
            cout<<"\n\n错误选择！\n";
            system("pause");
        }
    }
}

