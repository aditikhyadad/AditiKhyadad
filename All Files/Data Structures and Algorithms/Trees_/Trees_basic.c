// TREES USING MULTIPLE FIELDS i.e USING STRUCTURE
// MENU DRIVEN

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct data_node *d_vals;
    struct node *lnode;
    struct node *rnode;
};

struct data_node
{
    int data1;
    char data2[20];
};

struct node* create(struct node *root,struct data_node *p)         //T(n)=2T(n/2)+c
{
    if(root==NULL)
    {
        root=getnode(p);
        return(root);
    }
    if(root->d_vals->data1 < p->data1)
    {
        root->rnode=create(root->rnode,p);
        return(root);
    }
    else if(root->d_vals->data1 > p->data1)
    {
        root->lnode=create(root->lnode,p);
        return(root);
    }
}

void getnode(struct node *p)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->d_vals=p;
    newnode->lnode=NULL;
    newnode->rnode=NULL;
    return(newnode);
};

struct node* search(struct node *root,int key)
{
    if(root==NULL)
    {
        printf("Key not found\n");
        return(root);
    }
    if(root->d_vals->data1 == key)
    {
         printf("Key found\n");
         printf("Details:%d\t%s\n",root->d_vals->data1,root->d_vals->data2);
        return(root);
    }
    if(root->d_vals->data1 < key)
    {
        root->rnode=search(root->rnode,key);
        return(root);
    }
    else if(root->d_vals->data1 > key)
    {
        root->lnode=search(root->lnode,key);
        return(root);
    }
}

struct node* searchstring(struct node* root, char k[20])
{
    if(root==NULL)
    {
        printf("NOT FOUND\n");
        return root;
    }

    if(strcmp(root->d_vals->data2,k)==0)
    {
        printf("FOUND\n\n");
        printf("Details:%d\t%s\n",root->d_vals->data1,root->d_vals->data2);
        return root;
    }

    if(strcmp(root->d_vals->data2,k)<0)
    {
        root->rnode=searchstring(root->rnode,k);
        return root;
    }

    else if(strcmp(root->d_vals->data2,k)>0)
    {
        root->lnode=searchstring(root->lnode,k);
        return root;
    }
};

void inorder(struct node *root)          //prints left-root-right
{
    struct node *temp;
    if(root==NULL)
        return 0;
    inorder(root->lnode);
    printf("Details:%d\t%s\n",root->d_vals->data1,root->d_vals->data2);
    inorder(root->rnode);
}

void preorder(struct node *root)          //prints root-left-right
{
    struct node *temp;
    if(root==NULL)
        return;
    printf("Details:%d\t%s\n",root->d_vals->data1,root->d_vals->data2);
    inorder(root->lnode);
    inorder(root->rnode);
}

void postorder(struct node *root)          //prints left right root
{
    struct node *temp;
    if(root==NULL)
        return;
    inorder(root->lnode);
    inorder(root->rnode);
    printf("Details:%d\t%s\n",root->d_vals->data1,root->d_vals->data2);
}

int findmax(struct node *root)
{
    while(root->rnode!=NULL)
    {
        root=root->rnode;
    }
    return root->d_vals->data1;
}

int findmin(struct node *root)
{
    while(root->lnode!=NULL)
    {
        root=root->lnode;
    }
    return root->d_vals->data1;
}

struct node* del_node(struct node* root,int key)
{
    struct node *temp;
    if(root==NULL)
    {
        return NULL;
    }
    if(root->d_vals->data1>key)
    {
        root->lnode=del_node(root->lnode,key);
    }
    else if(root->d_vals->data1<key)
    {
        root->rnode=del_node(root->rnode,key);
    }
    else if(root->d_vals->data1 == key)
    {
         printf("Key found\n");
         if(root->lnode==NULL && root->rnode==NULL)
         {
            free(root);
            return(NULL);
         }
         else if(root->lnode !=NULL && root->rnode==NULL)
         {
             temp=root->lnode;
             free(root);
             return(temp);
         }
         else if(root->lnode ==NULL && root->rnode!=NULL)
         {
             struct node *temp=root->rnode;
             free(root);
             return(temp);
         }
         else
           {
             key=findmin(root->rnode);
             root->d_vals->data1=key;
             root->rnode=del_node(root->rnode,key);
             return(root);
           }
    }
    return(root);
}

int count_node(struct node* root)
{
    if (root == NULL)
        return 0;

    int l = count_node(root->lnode);
    int r = count_node(root->rnode);

    return 1 + l + r;
}

void indegree(struct node* root)
{
    if(root==NULL)
        printf("No root is present\n");
    else
        printf("Indegree=0\n");
}

int outdegree(struct node *root)
{
    int count=0;
    if(root==NULL)
        count=0;
    if(root->lnode!=NULL)
        count++;
    else if(root->rnode!=NULL)
        count++;
    return count;
}

void topview(struct node *root)
{
     struct node *temp;
     temp=root;
    while(temp!=NULL)
    {
        printf("Details:%d\t%s\n",root->d_vals->data1,root->d_vals->data2);
        temp=temp->lnode;
    }
    temp=root->rnode;
    while(temp!=NULL)
    {
        printf("Details:%d\t%s\n",root->d_vals->data1,root->d_vals->data2);
        temp=temp->rnode;
    }

}

int levelnode(struct node *root, int key)
{
    int c=0;
     while(root)
    {
        if(key>root->d_vals->data1)
        {
            c++;
            root=root->rnode;
        }
        else if(key<root->d_vals->data1)
        {
            c++;
            root=root->lnode;
        }
        else
        {
            printf("level of the node=%d\n",c);
            return 1;
        }
    }
    return 0;
}

void printleaf(struct node *root)
{
   if(root==NULL)
    return;
   if(root->lnode==NULL && root->rnode==NULL)
    printf("%d ",root->d_vals->data1);
    printleaf(root->lnode);
    printleaf(root->rnode);
}

void ancestor(struct node *root, int key)
{
    int c=0;
     while(root)
    {
        if(key>root->d_vals->data1)
        {
            printf("Details:%d\t%s\n",root->d_vals->data1,root->d_vals->data2);
            c++;
            root=root->rnode;
        }
        else if(key<root->d_vals->data1)
        {
            printf("Details:%d\t%s\n",root->d_vals->data1,root->d_vals->data2);
            c++;
            root=root->lnode;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

void range(struct node *root,int r1, int r2)
{
    if(root==NULL)
    return;
    if(root->d_vals->data1>r1&&root->d_vals->data1<r2)
        printf("%d\n",root->d_vals->data1);
    range(root->lnode,r1,r2);
    range(root->rnode,r1,r2);

}

void lrbview(struct node *root,int key)
{
    if(root==NULL)
        return;
    if(root->d_vals->data1<key)
    {
        printf("%d\n",root->rnode);
        root=root->rnode;

    }
    if(root->d_vals->data1>key)
    {
        printf("%d\n",root->lnode);
        root=root->lnode;

    }
    if(root->lnode==NULL && root->rnode==NULL)
    printf("Details:%d\t%s\n",root->d_vals->data1,root->d_vals->data2);
    printleaf(root->lnode);
    printleaf(root->rnode);

}

int max_sub(struct node* root)
{
    struct node* temp = root;

    while (temp->rnode != NULL) {
        temp = temp->rnode;
    }
    return (temp->d_vals->data1);
}
int min_sub(struct node* root)
{
    struct node* temp = root;

    while (temp->lnode != NULL) {
        temp = temp->lnode;
    }
    return (temp->d_vals->data1);
}
struct node*depth(struct node*node)
{
    struct node* temp = node;
    int c=0;
    while (temp->rnode != NULL)
    {
        temp = temp->rnode;
        c++;
    }
    return c;
}
int lcount(struct node * root)
{
    int lh=0;
    while(root)
    {
        lh++;
        root=root->lnode;
    }
    return lh;

}
int rcount(struct node *root)
{
    int lh=0;
    while(root)
    {
        lh++;
        root=root->rnode;
    }
    return lh;
}
struct node* lside(struct node* root)
{
    struct node* temp = root;
    int c=0;
    while (temp->lnode != NULL)
    {
        temp = temp->lnode;
        c++;
    }
    return c;
}
struct node* rside(struct node* root)
{
    struct node* temp= root;
    int d=0;
    while (temp->rnode != NULL)
    {
        temp = temp->rnode;
        d++;
    }
    return d;
}
int add(struct node *root){
    int sum, lsum, rsum;
    sum = rsum = lsum = 0;

    if(root == NULL) {
        printf("Tree is empty\n");
        return 0;
    }
    else
    {
        if(root->lnode != NULL)
            lsum = add(root->lnode);

        if(root->rnode != NULL)
              rsum = add(root->rnode);

        sum = root->d_vals->data1 + lsum + rsum;
        return sum;
  }
}

void path(struct node* node , int key)
{
    struct node* temp = node;

    printf("%d->", temp->d_vals->data1);
    if (temp->d_vals->data1 >= node->d_vals->data1)
    {
        while (temp->d_vals->data1 != key)
        {
        temp = temp->rnode;
         printf("%d->", temp->d_vals->data1);
        }
    }
    else if (temp->d_vals->data1 <= node->d_vals->data1)
    {
        while (temp->d_vals->data1 != key)
        {
        temp = temp->lnode;
        printf("%d->", temp->d_vals->data1);
        }
    }

}

struct node* findLCA(struct node* root, int key1, int key2)
{
    if (root == NULL)
        return NULL;
    if (root->d_vals->data1 == key1 || root->d_vals->data1 == key2)
        return root;

    struct node* lnode_lca = findLCA(root->lnode,key1,key2);
    struct node* rnode_lca = findLCA(root->rnode,key1,key2);

    if (lnode_lca && rnode_lca)
        return root;
    return (lnode_lca != NULL) ? lnode_lca : rnode_lca;
}
int search2(struct node *root,char key[12])
{
  while(root)
  {
    if(strcmp(key,root->d_vals->data2)<0)
        root = root->lnode;
    else if(strcmp(key,root->d_vals->data2)>0)
        root=root->rnode;
    else
        return 0;
   }
   return 1;
}

void checksecondmin(struct node* root,int c)
{
   if(root==NULL || c>=2)
    return;
   checksecondmin(root->rnode,c);
   c++;
   if(c==2)
   {
       printf("secmin=%d\n",root->d_vals->data1);
       printf("c=%d",c);

   }
   checksecondmin(root->lnode,c);
}

void secondmin(struct node * root)
{
    int c=0;
    checksecondmin(root,c);
}

void colour(struct node *root,int key)
{
    int col=levelnode(root,key);
    char colo[10];
    if (col==0)
    {
        strcpy(colo,"bLACK");
    }
 else  if (col==1)
    {
        strcpy(colo,"MAROON");
    }
    else
    {
        strcpy(colo,"GREEN");
    }
    printf("COLOUR IS %s ",colo);
}
int main()
{
    struct node* root=NULL;
    struct data_node *p;
    int ch,key,key1,key2,min,max;
    int c,d,c_out;
    int n,m,g;
    int r1,r2;
    char k[20];

    while(1)
    {
        printf("\n1.---Insert node\n");
        printf("2.---Search node\n");
        printf("3.---Search node using a string value\n");
        printf("4.---Display in order\n");
        printf("5.---Display pre order\n");
        printf("6.---Display post order\n");
        printf("7.---Find max\n");
        printf("8.---Find min\n");
        printf("9.---Delete a node\n");
        printf("10.---Count the no of nodes in the tree\n");
        printf("11.---Indegree of the tree\n");
        printf("12.---Outdegree of the tree\n");
        printf("13.---Top view of the tree\n");
        printf("14.---Level of the given key of the tree\n");
        printf("15.---Leaf node of the tree\n");
        printf("16.---Ancestor of the node\n");
        printf("17.---Range of the tree\n");
        printf("18.---Left, right and bottom view of the tree\n");
        printf("19.---Minimum of the subtree\n");
        printf("20.---Maximum of the subtree\n");
        printf("21.---Depth of a node\n");
        printf("22.---Count of a left node\n");
        printf("23.---Count of a right node\n");
        printf("24.---Largest sub_tree\n");
        printf("25.---Path\n");
        printf("26.---Sum of the elements in the given tree\n");
        printf("27.---Common ansectors\n");
        printf("28.---Search with a string value\n");
        printf("29.---Secondmin\n");
        printf("30.---Secondmax\n");
        printf("31.---Colouring logic\n");

        printf("0.---Exit\n");
        printf("--Enter your choice--\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: p=(struct data_node*)malloc(sizeof(struct data_node));
                    printf("Enter data1,data2 i.e one integer, one string values\n");
                    scanf("%d%s",&p->data1,&p->data2);
                    root=create(root,p);
                    break;
            case 2:printf("Enter value to be searched\n");
                    scanf("%d",&key);
                    root=search(root,key);
                    break;
            case 3:printf("Enter the value to be searched\n");
                    scanf("%s",k);
                    root=searchstring(root,k);
                    break;
            case 4:inorder(root);
                    break;
            case 5:preorder(root);
                    break;
            case 6:postorder(root);
                    break;
            case 7:max=findmax(root);
                    printf("maxval=%d",max);
                    break;
            case 8: min=findmin(root);
                    printf("minval=%d",min);
                    break;
            case 9: printf("Enter the key value that is to be deleted (only the elements with one child or zero child)=");
                    scanf("%d",&key);
                    root=del_node(root,key);
                    break;
            case 10:c=count_node(root);
                    printf("node_count=%d",c);
                    break;
            case 11:indegree(root);
                    break;
            case 12:c_out=outdegree(root);
                    printf("%d\n",c_out);
                    break;
            case 13:printf("\nTop view of BST - ");
                    topview(root);
            case 14:printf("enter the key to be found and to know the level of the key\n");
                    scanf("%d",&key);
                    m=levelnode(root,key);
                    if(m==1)
                    printf("key found\n");
                    else
                    printf("key not found\n");
                    break;
            case 15:printf("\nLeaf nodes of BST -\n ");
                    printleaf(root);
                    break;
            case 16:printf("enter the node of which the ancestor is to be found\n");
                    scanf("%d",&key);
                    ancestor(root,key);
                    break;
            case 17:printf("enter the range\n");
                    scanf("%d%d",&r1,&r2);
                    range(root,r1,r2);
                    break;
            case 18:printf("left right and bottom view:\n");
                    lrbview(root,key);
                    break;
            case 19:printf("\n Minimum value in left SubTree is %d", min_sub(root->lnode));
                    printf("\n Minimum value in right SubTree is %d", min_sub(root->rnode));
                    break;
            case 20:printf("\n Maximum value in left SubTree is %d", max_sub(root->lnode));
                    printf("\n Maximum value in right SubTree is %d", max_sub(root->rnode));
                    break;
            case 21:printf("Depth of BST is %d\n", depth(root));
                    break;
            case 22:printf("%d",lcount(root));
                    break;
            case 23:printf("%d",rcount(root));
                    break;
            case 24:c=lside(root->lnode);
                    d=rside(root->rnode);
                    if(c<d)
                    printf("Right subtree is largest\n");
                    else if(c>d)
                    printf("Left subtree is largest\n");
                    else
                    printf("Both are equal\n");
                    break;
            case 25:printf("enter the key to be found and to know the path of the key\n");
                    scanf("%d",&key);
                    path(root,key);
                    break;
            case 26:printf("Sum of all elements of binary tree: %d",add(root));
                    break;
            case 27:printf("Enter the values of the keys\n");
                    scanf("%d%d",&key1,&key2);
                    printf("\nLCA(%d, %d) = ",key1,key2);
                    printf("%d\n",findLCA(root,key1,key2)->d_vals->data1);
                    break;
            case 28:printf("Enter string_val to be searched\n");
                    char key[12];
                    scanf("%s",&key);
                    g=search2(root,key);
                    if(g==0)
                        printf("String_value Found\n");
                    else
                        printf("String_value not found\n");
                    break;
            case 29:secondmin(root);
                    break;
            case 31:printf("Enter the key value");
                    scanf("%d",&key);
                    colour(root,key);
                    break;
            case 0:exit(0);
                    break;
            default:printf("Invalid choice\n");
                    break;
        }
    }
}

