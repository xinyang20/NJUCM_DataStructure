//二叉树的最近公共祖先问题
#include<iostream>
using namespace std;
typedef struct BiNode{
	char data;
	struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

char ans=' ';//存放找到的最近公共祖先的值

//按先序次序输入二叉树中结点的值（字符），创建二叉链表表示的二叉树T
void CreateBiTree(BiTree &T)
{		
	char ch;
	cin >> ch;
	if(ch=='#')  
		T=NULL;	
	else{							
		T=new BiTNode;
		T->data=ch;					
		CreateBiTree(T->lchild);	
		CreateBiTree(T->rchild);	
	}								
}

/*-----------------代码开始------------------*/
bool find(BiTree T,char p,char q){
    if(T==NULL)return false;

    bool left=find(T->lchild,p,q);
    bool right=find(T->rchild,p,q);
    bool current=(T->data==p||T->data==q);

    if((left&&right)||(left&&current)||(current&&right)){
        ans=T->data;
    }

    return (left||right||current);
}

/*-----------------代码结束------------------*/

//在以T为根的二叉树中寻找p和q的最近公共祖先，返回ans
//ans为char类型全局变量，用于存放找到的最近公共祖先的值
char lowestCommonAncestor(BiTree T,char p,char q) {
/*-----------------代码开始------------------*/
    find(T,p,q);
/*-----------------代码结束------------------*/
	return ans;
}



int main(){
	BiTree tree;
	CreateBiTree(tree);
	char p,q;
	cin>>p>>q;
	lowestCommonAncestor(tree,p,q);
	cout<<ans;
	return 0;
}
