#include<iostream>
#include<vector>
using namespace std;
struct Node{
	int key;
	Node* left;
	Node* right;
};
void preorder(Node * root){
	if(root==NULL){
		return;
	}
	cout<<root->key;
	preorder(root->left);
	preorder(root->right);
	return;
}
vector<Node*> getTrees(int in[],int start,int end){
	vector<Node *> trees;                      //trees�д�����Ǹ����ڵ�ĸ��ڵ㡣 
	int i,j,k;
	if(start>end){                            //����������������������NULL��β�� 
		trees.push_back(NULL);                //vector�Ĳ�����.  ����-> 
		return trees;
	}
	for(i=start;i<=end;i++){
		vector<Node *> leftTrees=getTrees(in,start,i-1);    //leftTrees����Ϊ���ص������еĸ��ڵ���Ŀ 
		vector<Node *> rightTrees=getTrees(in,i+1,end);
		for(j=0;j<leftTrees.size();j++)                     
			for(k=0;k<rightTrees.size();k++){
				Node* root=new Node();
				root->key=in[i];
				root->left=leftTrees[j];
				root->right=rightTrees[k];
				trees.push_back(root);
			}  
	}
	return trees;
}
int main(){
    int in[] = {4, 5, 7};
    int n = sizeof(in) / sizeof(in[0]);
    vector<Node *> trees = getTrees(in, 0, n-1);
    cout << "Preorder traversals of different "
         << "possible Binary Trees are \n";
    for (int i = 0; i < trees.size(); i++)
    {
        preorder(trees[i]);                         // ǰ����� 
        //cout<<trees[i]->key;
        printf("\n");
    }
    return 0;
} 
