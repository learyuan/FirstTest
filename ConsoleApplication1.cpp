// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<deque>
#include <stack>
#include<iostream>
#include<string>
#include<list>
using std::vector;
using std::string;
using std::deque;

bool Find(vector<vector<int> > array,int target) 
{
	auto it=array.size();
    auto jt=array[0].size();
    int num=(it<jt)?it:jt;
for (int i=0;i<num;i++)
{
	if (target<array[i][i]||target>array[it-1][jt-1])
	{
		return false;
	}
	for (int j=i;j<it;j++)
	{
		if (target==array[j][i])
		{
			return true;
		}
	}
	for (int j=i;j<jt;j++)
	{
		if (target==array[i][j])
		{
			return true;
		}
	}
}
return false;
}

int minNumberInRotateArray(vector<int> rotateArray) 
{
	auto j=rotateArray.size()-1;
	if(j)
	{
		for(int i=0;i<j;i++)
		{
			if((rotateArray[i+1]-rotateArray[i])<0)
				return rotateArray[i+1];

		}
		return rotateArray[0];
	}

	else
		return rotateArray[0];
}

vector<int> printMatrix(vector<vector<int> > matrix) 
{
	vector<int> print;
	auto i=matrix.size()-1;
	auto j=matrix[0].size()-1;
	int in=0,jn=0,ix=0,jx=0,ip=0,jp=0;
	ix=i;
	jx=j;
	for(int k=0;k<=jx;k++)
	{		
		print.push_back(matrix[ip][jp]);
		jp=jp+1;
	}
	jp=jp-1;
	for(int k=1;k<=(i+j);k++)
	{
		switch(k%4)
		{
		case 0:
			{ in=0;jn=1;break;}
		case 1:
			{ in=1;jn=0;break;}
		case 2:
			{ in=0;jn=-1;break;}
		case 3:
			{ in=-1;jn=0;break;}
		default:{ in=0,jn=0;break;}
		}
		switch(k%2)
		{
		case 0://列
			{
				for(int kt=1;kt<=jx;kt++)
				{
					jp=jp+jn;
					print.push_back(matrix[ip][jp]);
				}		
				jx--;
				break;
			}
		case 1://行
			{
				for(int kt=1;kt<=ix;kt++)
				{
					ip=ip+in;
					print.push_back(matrix[ip][jp]);
				}			
				ix--;
				break;
			}
		}
		if(ix*jx)
		{
			break;
		}

	}
	return print;

}

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) 
{
	auto d=data.size()-1;
	int tem =0;
	vector<int> num;
	for(int i=0;i<d;i++ )
		for(int j=i;j<=d;j++)
		{
			if(data[i]>data[j])
			{
				tem=data[j];
				data[j]=data[i];
				data[i]=tem;
			}           
		}
		for(int i=1;i<d;i++ )
		{
			if((data[i]!=data[i-1])&&(data[i]!=data[i+1]))
				num.push_back(data[i]);
		}
		if(data[d]!=data[d-1])
			num.push_back(data[d]);
		*num1=num[0];
		*num2=num[1];
}
//int _tmain(int argc, _TCHAR* argv[])
//{
//	int a[]={2,4,3,6,3,2,5,5};
//	vector<int> matrix;
//	int b[2]={0,0};
//	for(int i=0;i<8;i++)
//	{
//		matrix.push_back(a[i]);
//	}
//	FindNumsAppearOnce(matrix,&b[0],&b[1]);
//	while (1);
//}

int InversePairs(vector<int> data) 
{
	auto num=data.size()-1;
	int sum=0;
	if(num<1)
		return 0;
	else
	{
		for(int k=0;k<num;k++)
		{
			if(data[k]>data[k+1])
				sum++;
		}
		return sum;
	}


}


vector<int> FindNumbersWithSum(vector<int> array,int sum) 
{
	auto num =array.size();
	vector<int> Find ;
	if(num<1)
		return Find;
	else if(sum<=array[0]||sum>(2*array[num-1]))
		return Find;
	else
	{
		int y=0;
		for(int i=0;i<(num-1);i++)
		{
			y=sum-array[i];
			for(int j=i+1;j<num;j++)
			{
				if(y==array[j])
				{
					Find.push_back(i);
					Find.push_back(y);
				}
			}
			if((array[i]+array[i+1])>sum)
				break;
		}
		auto si=Find.size();
		if(si<2)
			return Find;
		else
		{
			vector<int> Find2;
			Find2.push_back(Find[0]);
			Find2.push_back(Find[1]);
			for(int i=2;i<si;i=i+2)
			{
				if((Find2[0]*Find2[1])>(Find[i]*Find[i+1]))
				{

					Find2.clear();
					Find2.push_back(Find[i]);
					Find2.push_back(Find[i+1]);
				}
			}               
			return Find2;
		}   
	}
}


//string ReverseSentence(string str)
//{
//	auto num=str.size();
//	if(num<1)
//		return str;
//	else
//	{            
//		vector<string> p;
//		int k=0,i=0;
//
//		for(i=0;i<num;i++)
//		{
//			if(str[i]!=' ')
//			{
//				k++;
//			}
//			else
//			{			
//				string a(str,i-k,k);
//				p.push_back(a);
//				k=0;
//			}
//		}
//		string a(str,i-k,k);
//		p.push_back(a);
//		
//		auto s=p.size();
//		string Replace;
//		Replace=p[s-1];
//		for(int i=s-2;i>=0;i--)
//		{
//			Replace=Replace+' '+p[i];
//		}
//		return Replace;
//	}
//}
//int LastRemaining_Solution(unsigned int n, unsigned int m)
//{
//	vector<int> child;
//	for(unsigned int i=0;i<n;i++)            
//		child.push_back(1);                  
//	int sum=n;    
//	int j=0;
//	while(sum>1)
//	{
//		while (child[j]==0)
//		{
//			j++;
//			j=j%n;
//		}
//		int p=(m-1)%sum;
//		for (int k=0;k<p;)
//		{
//			j++;
//			j=j%n;
//			if(child[j]==1)
//				k++;			
//		}
//		child[j]=0;		
//		sum--;              
//	}
//	for(int i=0;i<n;i++)
//		if(child[i]!=0)
//			return i;
//	return 0;
//
//}


int StrToInt(string str) 
{
	auto num=str.size();
	if(num<1)
		return 0;
	else
	{
		int result=0,i=0;
		if (str[0]<='9'&&str[0]>='0')
		{
			i=0;
		}
		else if (str[0]=='+'||str[0]=='-')
		{
			i=1;
		}
		else
		{
			return 0;
		}
		for(;i<num;i++)
		{
			if (str[i]<='9'&&str[i]>='0')
			result=(int)(str[i]-'0')+result*10;
			else
			{
				return 0;
			}
		}
		if (str[0]=='-')
		{
			result=-result;
		}
		return result;
	}
}


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};



double GetMedian(vector<int> shu)
{ 
	auto n=shu.size();
	if (n<1)
		return 0;
	else
	{
		vector<int> shuju;
		shuju=shu;
		int tmp=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				if(shuju[i]>shuju[j])
				{
					tmp=shuju[i];
					shuju[i]=shuju[j];
					shuju[j]=tmp;
				}                                               
			}
			if(n%2)
			{
				return shuju[n/2];
			}
			else
			{
				int b=n/2;
				double s=((double)shuju[b-1]+(double)shuju[b])/2;
				return s;
			}
	}   
}


struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

vector<TreeNode*>  getTreeValue(TreeNode* pRoot)
{
	vector<TreeNode*> get;
	vector<TreeNode*> right;
	vector<TreeNode*> left;
	if(pRoot!=NULL)
	{
		get.push_back(pRoot);
		left= getTreeValue(pRoot->left);
		auto num=left.size();
		for(int i=0;i<num;i++)
		{
			get.push_back(left[i]);
		}

		right= getTreeValue(pRoot->right);
		num=right.size();
		for(int i=0;i<num;i++)
		{
			get.push_back(right[i]);
		}
	}
	return get;
}

TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
{
	vector< TreeNode*> get=getTreeValue(pRoot);
	auto num=get.size();
	if(num<1)
		return NULL;
	else if(k>=num||k<1)
		return NULL;
	else
	{
		TreeNode* tmp(0);
		tmp=get[0];
		for(int i=0;i<num;i++)
			for(int j=i+1;j<num;j++)
			{
				if((get[i]->val)>(get[j]->val))
				{
					tmp=get[i];
					get[i]=get[j];
					get[j]=tmp;
				}
					
			}
			return get[k];
	}

}


TreeNode* Convert(TreeNode* pRootOfTree)
{
	vector< TreeNode*> get=getTreeValue(pRootOfTree);
	auto num=get.size();
	if(num<1)
		return NULL;
	else if(num==1)
		return pRootOfTree;
	else
	{
		vector<int> a;
		vector<int> b;
		for(int i=0;i<num;i++)
		{
			a.push_back(get[i]->val);
			b.push_back(i);
		}
		int tmp=0;
		for(int i=0;i<num;i++)
			for(int j=i+1;j<num;j++)
			{
				if(a[i]>a[j])
				{
					tmp=a[i];
					a[i]=a[j];
					a[j]=tmp;

					tmp=b[i];
					b[i]=b[j];
					b[j]=tmp;

				}
			}
			for(int i=0;i<num;i++)
			{
				if(i==0)
				{
					get[b[i]]->left=NULL;
					get[b[i]]->right=get[b[i+1]];
				}
				else if(i==num-1)
				{
					get[b[i]]->right=NULL;
					get[b[i]]->left=get[b[i-1]];
				}
				else
				{
					get[b[i]]->left=get[b[i-1]];
					get[b[i]]->right=get[b[i+1]];
				}

			}
			return get[b[0]];
	}

}

vector<int> insertSort(vector<int> a)
{
	vector<int> sort;
	auto num=a.size();
	if(num<1)
		return sort;
	else
	{
	  sort.push_back(a[0]);
      for (int i=1;i<num;i++)
      {
		  sort.push_back(a[i]);
		  for (int j=i-1;j>=0;j--)
		  {
			  int tmp=0;
			  if (sort[j]>sort[j+1])
			  {
				  tmp=sort[j+1];
				  sort[j+1]=sort[j];
				  sort[j]=tmp;
			  }
			  else
			  {
				  break;
			  }
		  }
      }
	  return sort;
	}
}


vector<int>  mergeSort(vector<int> a)
{
	vector<int> sort;
	auto num=a.size();

	if(num<1)
		return sort;
	else if(num==1)
		return a;
	else
	{
      int i=num/2;
	  int ia=0,ib=0;
	  vector<int> sorta,sortb;

	  vector<int> sorta1,sortb1;
	  for (int j=0;j<num;j++)
	  {
		  if(j<i)
			  sorta1.push_back(a[j]);
		  else
		      sortb1.push_back(a[j]);
	  }
	  sorta=mergeSort(sorta1);
	  sortb=mergeSort(sortb1);

		while (ia!=sorta.size()&&ib!=sortb.size())
		{
			if(sorta[ia]<sortb[ib])
			{
				sort.push_back(sorta[ia]);
				ia++;
				if (ia==sorta.size())
				{
					for (;ib<sortb.size();ib++)
					{
						sort.push_back(sortb[ib]);
					}
				}
			}			  
			else
			{
				sort.push_back(sortb[ib]);
				ib++;
				if (ib==sortb.size())
				{
					for (;ia<sorta.size();ia++)
					{
						sort.push_back(sorta[ia]);
					}
				}
			}
		}
		return sort;
	  
	  
	}
}

vector<int> merge(vector<int> sorta,vector<int> sortb)
{
	vector<int>sort;
	int ia=0,ib=0;
	while (ia!=sorta.size()||ib!=sortb.size())
	{
		if(sorta[ia]<sortb[ib])
		{
			sort.push_back(sorta[ia]);
			ia++;
			if (ia==sorta.size())
			{
				for (;ib<sortb.size();ib++)
				{
					sort.push_back(sortb[ib]);
				}
			}
		}			  
		else
		{
			sort.push_back(sortb[ib]);
			ib++;
			if (ib==sortb.size())
			{
				for (;ia<sorta.size();ia++)
				{
					sort.push_back(sorta[ia]);
				}
			}
		}
	}
	return sort;
}

char FirstAppearingOnce(string s)
{
	auto n=s.size();
	if(n<1)
		return '#';
	else
	{
		char a=0;
		vector<int>  num;
		string  kind;
		auto nk=kind.size();
		bool cz=false;
		for(int i=0;i<n;i++)
		{
			nk=kind.size();
			cz=false;
			for(int j=0;j<nk;j++)
			{                                          
				if(s[i]==kind[j])
				{
					num[j]++;
					cz=true;
					break;
				}

			}
			if(!cz)
			{
				kind.push_back(s[i]);
				num.push_back(1);
			}
		}
		nk=num.size();
		for(int i=0;i<nk;i++)
		{
			if(num[i]==1)
			{
				return kind[i];
			}
		}
		return '#';
	}
}

vector<int> selectSort(vector<int> waitsort)
{
	vector<int> sort;
	auto num=waitsort.size();
	if(num<1)
		return sort;
	else
	{
		int least=0,tmp=0;
		for (int i=0;i<num;i++)
		{
			for (int j=i+1;j<num;j++)
			{
				if (waitsort[least]>waitsort[j])
				{
					least=j;
				}
			}
			tmp=waitsort[i];
			waitsort[i]=waitsort[least];
			waitsort[least]=tmp;
		}
		return waitsort;
	}
}


vector<int> printMatrix1(vector<vector<int> > matrix)
{
	vector<int> print;
	auto h=matrix.size();
	if(h<1)
		return print;
	else
	{
		auto  l=matrix[0].size();
		if(l<1)
			return print;
		else
		{
			int h1=0,l1=0,x=0,hx=0,lx=0;
			hx=h-1;
			lx=l;      
			h=0;
			l=-1;
			while(hx>=0&&lx>=0)
			{
				if (lx==0)
				{
					break;
				}
				
				switch(x%4)
				{
				case 0:{ h1=0;l1=1;break;}
				case 1:{ h1=1;l1=0;break;}
				case 2:{ h1=0;l1=-1;break;}
				case 3:{ h1=-1;l1=0;break;}
				}
				for(int i=0;i<lx;i++)
				{
					h=h+h1;
					l=l+l1;
					print.push_back(matrix[h][l]);                         
				}
				lx--;
				x++;
				if (hx==0)
				{
					break;
				}
				switch(x%4)
				{
				case 0:{ h1=0;l1=1;break;}
				case 1:{ h1=1;l1=0;break;}
				case 2:{ h1=0;l1=-1;break;}
				case 3:{ h1=-1;l1=0;break;}
				}
				for(int i=0;i<hx;i++)
				{
					h=h+h1;
					l=l+l1;
					print.push_back(matrix[h][l]);                      
				}
				hx--;
				x++;
			}
			return print;
		}
	}
}

struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) 
{
	auto i=pre.size();
	if(i<1)
		return NULL;
	else
	{
		vector<int> prel;
		vector<int> inl;
		vector<int> prer;
		vector<int> inr;
		int j=0;		
		TreeNode * p=new TreeNode(0);  
		p->val=pre[0];
		for(;j<i;j++)
		{
			if(in[j]==pre[0])
				break;
		}
		for(int k=0;k<j;k++)
		{
			prel.push_back(pre[k+1]);
			inl.push_back(in[k]);
		}
		for(int k=j+1;k<i;k++)
		{
			prer.push_back(pre[k]);
			inr.push_back(in[k]);
		}

		p->left=reConstructBinaryTree(prel,inl);
		p->right=reConstructBinaryTree(prer,inr);

		return p;          
	}
}
//
//bool equal(TreeNode* pRoot1, TreeNode* pRoot2)
//{
//	if(pRoot2==NULL||pRoot1==NULL)
//	{
//		if(pRoot1==pRoot2)
//			return 1;
//		else 
//			return 0;
//	}
//	else 
//	{
//		if(pRoot1->val==pRoot2->val)
//		{
//			if(equal(pRoot1->left,pRoot2->left)&&equal(pRoot1->right,pRoot2->right))
//				return 1;
//			else
//				return 0;
//		}
//		else 
//			return 0;
//	}
//}
//bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
//{
//	if(pRoot2==NULL||pRoot1==NULL)
//		return 0;
//	else
//	{
//		if(equal( pRoot1, pRoot2))
//			return 1;
//		else
//			return (HasSubtree(pRoot1->left,pRoot2)+HasSubtree(pRoot1->right,pRoot2));
//	}
//}

vector<vector<int> >Path(TreeNode *root)
{
	vector<vector<int> >path;
	if(root==NULL)
		return path;
	else if(root->left==NULL&&root->right==NULL)
	{
		vector<int> p;
		p.push_back(root->val);
		path.push_back(p);
		return path;
	}
	else
	{
		vector<vector<int> >pathl,pathr;
		pathl=Path(root->left);
		pathr=Path(root->right);
		auto l=pathl.size();
		auto r=pathr.size();
		for(int i=0;i<l;i++)
		{
			pathl[i].push_back(root->val);
			path.push_back(pathl[i]);
		}
		for(int i=0;i<r;i++)
		{
			pathr[i].push_back(root->val);
			path.push_back(pathr[i]);
		}
		return path;

	}
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) 
{
	vector<vector<int> > find;
	if(root==NULL)
		return find;
	else 
	{
		vector<vector<int> > path=Path(root);
		auto n=path.size();
		for(int i=0;i<n;i++)
		{
			int sum=0;
			auto j=path[i].size();
			for(int k=0;k<j;k++)
			{
				sum=sum+path[i][k];
			}
			if(sum==expectNumber)
			{
				vector<int> r;
				for(int k=j-1;k>=0;k--)
				{
					r.push_back(path[i][k]);
				}
				find.push_back(r);
			}
		}
		return find;
	}
}

   bool isInt(   vector<char> s)
        {
           auto n=s.size();
           if(n<1)
               return 0;
           else
               {
                 if(n==1)
                     {
                       if(s[0]<='9'&&s[0]>='0')
                           return 1;
                       else 
                           return 0;
                     }
                 else
                     {
                       int i=0;
                       if(s[0]=='+'||s[0]=='-')
                           {
                             i=1;
                           }
                       for(;i<n;i++)
                           {
                             if(s[i]<='9'&&s[i]>='0')
                               {;}
                             else
                                 {
                                 return 0;
                                 }
                           }
                       return 1;
                     }
               }
        } 

   bool isNumeric(char* string)
    {
        vector<char> s;
        while(*string!='\0')
         {
            s.push_back(*string);
			string ++;
           }
        
        auto n=s.size();
        if(n<1)
               return 0;
        else
            {
               if(n==1)
                   {
                     if(s[0]<='9'&&s[0]>='0')
                           return 1;
                       else 
                           return 0;
                   }
               else
                   {
                     int i=0,point=0,e=0;
                     if(s[0]=='+'||s[0]=='-')
                           {
                             i=1;
                           }
                       for(;i<n;i++)
                           {
                             if(s[i]<='9'&&s[i]>='0')
                               {;}
                             else if(s[i]=='.')
                                 {
                                   point++;
                                   if(point>1)
                                       return 0;
                                 }
                             else if(s[i]=='e'||s[i]=='E')
                                 {
                                   e++;
                                   i++;
                                   break;
                                 }
                             else 
                                 {
                                   return 0;
                                 }
                           }
                       if(e==1)
                           {
                             vector<char> s1;
                             for(;i<n;i++)
                                 {
                                   s1.push_back(s[i]);   
                                 } 
							 return isInt(s1);
                           }
                       return 1;
                   }
            }
         
    }


   bool equal(TreeNode* pRoot1, TreeNode* pRoot2)
   {
	   if(pRoot2==NULL||pRoot1==NULL)
	   {
		   if(pRoot2==pRoot1)
			   return 1;
		   else 
			   return 0;

	   }
	   else 
	   {
		   if(pRoot1->val==pRoot2->val)
		   {
			   if(equal(pRoot1->left,pRoot2->left)&&equal(pRoot1->right,pRoot2->right))
				   return 1;
			   else
				   return 0;
		   }
		   else 
			   return 0;
	   }
   }

   void Mirror(TreeNode *pRoot)
   {
	   if(pRoot!=NULL)
	   {
		   TreeNode * tmp(0);
		   tmp=pRoot->left;
		   pRoot->left=pRoot->right;
		   pRoot->right=tmp;
		   Mirror(pRoot->left);
		   Mirror(pRoot->right);
	   }
   }

   TreeNode * Copy(TreeNode *pRoot)
   {
	   if(pRoot==NULL)
		   return NULL;
	   else
	   {
		   TreeNode *p=new TreeNode(0);              
		   p->val=pRoot->val;
		   p->left=Copy(pRoot->left);
		   p->right=Copy(pRoot->right);
		   return p;
	   }                               
   }

   bool isSymmetrical(TreeNode* pRoot)
   {
	   if(pRoot==NULL)
		   return 0;
	   else
	   {
		   TreeNode *p=Copy(pRoot);
		   Mirror(p);
		   return equal(pRoot, p);
	   }

   }

   int TreeDepth(TreeNode* pRoot)
   {
	   if(pRoot==NULL)
		   return 0;
	   else 
	   {
		   int depth=TreeDepth(pRoot->left)>TreeDepth(pRoot->right)? TreeDepth(pRoot->left):TreeDepth(pRoot->right);
		   return (depth+1);
	   }

   }

   vector<vector<int> > Print(TreeNode* pRoot) 
   {
	   vector<vector<int> > print;
	   if(pRoot==NULL)
	   {
		   return print;
	   }
	   else
	   {
		   int depth=TreeDepth(pRoot);
		   vector<int> pi,ptmp;
		   deque<TreeNode*> p,p1;
		   p1.push_back(pRoot);
		   for(int i=0;i<depth;i++)
		   {
			   p.clear();
			   p=p1;
			   pi.clear();
			   p1.clear();
			   while(!p.empty())
			   {
				   pi.push_back(p[0]->val);
				   if(p[0]->left!=NULL)
				   p1.push_back(p[0]->left);
				   if(p[0]->right!=NULL)
				   p1.push_back(p[0]->right);   				                    
				   
				   p.pop_front();
		       }
				   if (i%2)
				   {
					   ptmp.clear();
					   ptmp=pi;
					   pi.clear();
					   auto n=ptmp.size();
					   for (int k=n-1;k>=0;k--)
					   {
						   pi.push_back(ptmp[k]);
					   }
				   }
				   print.push_back(pi);   
			   }
		      return print;
		   }
		   

	   
   }


   ListNode* deleteDuplication(ListNode* pHead)
   {
	   if(pHead==NULL)
		   return NULL;
	   else 
	   {
		   vector<ListNode*> pd;
		   while(pHead!=NULL)
		   {
			   auto i=pd.size();
			   if(i<1)
			   {
				   pd.push_back(pHead);
				    pHead=pHead->next;
			   }
			   else
			   {
				   if(pHead->val==pd[i-1]->val)
				   {
					   while(pHead->val==pd[i-1]->val)   
					   {
						   pHead=pHead->next;
						   if (pHead==NULL)
						   {
							   break;
						   }
					   }
					   pd.pop_back();     
				   }
				   else
				   {
					   pd.push_back(pHead);
					    pHead=pHead->next;
				   }
			   }
			  
		   }
		   auto n=pd.size();
		   if(n<1)
			   return NULL;
		   else
		   {
			   for(int i=0;i<n;i++)
			   {
				   if(i==(n-1))
					   pd[i]->next=NULL;
				   else
				   {
					   pd[i]->next=pd[i+1];
				   }
			   }
			   return pd[0];
		   }           
	   }

   }



void max_HelpIfy(TreeNode *root)
{
	if (root ==NULL||root->left ==NULL)
	{
		return ;
	}
	else if(root->right==NULL)
	{
		int large=0;
		if(root->val<root->left->val)
		{
			large=root->left->val;
			root->left->val=root->val;
			root->val=large;
		}
		return ;
	}
	else
	{
		int large=0;
		if(root->right->val<root->left->val)
		{
			
			large=root->left->val;
			if(root->val<large)
			{
               root->left->val=root->val;
			   root->val=large;
			   max_HelpIfy( root->left);
			}			 
			 return;
		}
		else
		{
			large=root->right->val;
			if(root->val<large)
			{
				root->right->val=root->val;
				root->val=large; 
				max_HelpIfy( root->right);
			}
			return;

		}

		

	}


}

void max_HelpHeap(vector<int> & src,int i)
{
	auto n=src.size();
	if(n<1||(2*i+1)>=n)
		return ;
	else
	{
		int large=0;
		if ((2*i+2)>=n)
		{
			if (src[i]<src[2*i+1]) //右边为空
			{
				large=src[2*i+1];
				src[2*i+1]=src[i];
				src[i]=large;
			}
		}
		else
			{
				if(src[2*i+2]<src[2*i+1])
				{

					large=src[2*i+1];
					if(src[i]<large)
					{
						src[2*i+1]=src[i];
						src[i]=large;
						max_HelpHeap(src,2*i+1);
					}			 
					return;
				}
				else
				{
					large=src[2*i+2];
					if(src[i]<large)
					{
						src[2*i+2]=src[i];
						src[i]=large; 
						max_HelpHeap( src,2*i+2);
					}
					return;

				}
			}
		
	}
}

void bulid_max_Heap()
{

}

string trans(string s, int n) 
{
	// write code here
	vector<string> se;
	string a;
	if(n<1)
		return a;
	else
	{
		for(int i=n-1;i>=0;i--)
		{
			if(s[i]==' ')
			{

			}
		}
	}
}

int findsame(TreeNode* root)
{
	if (root==NULL)
	{
		return 0;
	}
	else
	{
		if (root->left==NULL)
		{
			if(root->right==NULL)
				return 1;
			else
			{
				if (root->val==root->right->val)
				{
					return findsame(root->right)+findsame(root->left)+1;
				}
				else
				{
					return 1;
				}
			}
		}
		else if (root->right==NULL)
		{
			if (root->val==root->left->val)
			{
				return findsame(root->right)+findsame(root->left)+1;
			}
			else
				return 1;
		}
		else if (root->val==root->left->val)
		{
			if (root->val==root->right->val)
			{
				return findsame(root->right)+findsame(root->left)+1;
			}
			else
			{
				return findsame(root->left)+1;
			}
		}
		else if (root->val==root->right->val)
		{
			return findsame(root->right)+1;
		}
		else
		{
			return 1;
		}
	}
}

int findPath(TreeNode* root)
{
	// write code here
	if (root==NULL)
	{
		return 0;
	}
	else
	{
		int deep=TreeDepth(root);
		int maxfind=findsame(root);
		if (maxfind>=(deep-1))
		{
			return maxfind;
		}
		else
		{
			deque<TreeNode*> p,p1;
			if(root->left!=NULL)
				p1.push_back(root->left);
			if(root->right!=NULL)
				p1.push_back(root->right);
			for(int i=0;i<deep-1;i++)
			{
				p.clear();
				p=p1;
				p1.clear();
				while(!p.empty())
				{				
					if (findsame(p[0])>maxfind)
					{
						maxfind=findsame(p[0]);
					}
					if(p[0]->left!=NULL)
						p1.push_back(p[0]->left);
					if(p[0]->right!=NULL)
						p1.push_back(p[0]->right);
					 p.pop_front();

				}
			}
			return maxfind;
		}
	}
}

int movingCount(int threshold, int rows, int cols)
{
   for(int i=0;i<rows;i++)
	   for (int j=0;j<cols;j++)
	   {
		   ;
	   }
	   return 0;
}

int wSum(int i)
{
	if (i<0)
	{
		i=-i;
	}
	int sum=0;
	while (i)
	{
     sum=i%10+sum;
	 i=i/10;
	}
	return sum;
}
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

vector<TreeLinkNode*> Msort(TreeLinkNode* pNode)
{
	vector<TreeLinkNode*> p;
	if (pNode==NULL)
	{
		return p;
	}
	else
	{
		vector<TreeLinkNode*> pr;
		p=Msort(pNode->left);
		p.push_back(pNode);
		pr=Msort(pNode->right);
		auto num=pr.size();
		if (num>0)
		{
			for (int i=0;i<num;i++)
			{
				p.push_back(pr[i]);
			}
		}
		return p;
	}
}

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode==NULL)
	{
		return NULL;
	}
	else
	{
		TreeLinkNode* pTmp= new TreeLinkNode(0);		
		pTmp=pNode;
		while (pNode->next!=NULL)
		{
			pNode=pNode->next;
		}
		vector<TreeLinkNode *>p1=Msort(pNode);
		auto num=p1.size();
		p1.push_back(NULL);
		for (int i=0;i<num;i++)
		{
			if (p1[i]==pTmp)
			{
				return p1[i+1];
			}
		}
		return NULL;
	}
}

TreeNode* genThree(vector<int> str)  //建堆
{
	vector<TreeNode*> heapT;
	auto tree_size=str.size();
	for (int i=0;i<tree_size;i++)
	{
		TreeNode * p=new TreeNode(str[i]);
		heapT.push_back(p);
	}
	for (int i=0;i<tree_size;i++)
	{
		if((2*i+1)>=tree_size)
			heapT[i]->left=NULL;
		else
		{
			heapT[i]->left=heapT[(2*i+1)];
		}
		if(2*(i+1)>=tree_size)
			heapT[i]->right=NULL;
		else
		{
			heapT[i]->right=heapT[2*(i+1)];
		}

	}
	return heapT[0];
}

TreeNode* genHeap(vector<int> str,int heap_size)  //建堆
{
	vector<TreeNode*> heapT;
	//	int heap_size=15;
	for (int i=0;i<heap_size;i++)
	{
		TreeNode * p=new TreeNode(str[i]);
		heapT.push_back(p);
	}
	for (int i=0;i<heap_size;i++)
	{
		if((2*i+1)>=heap_size)
			heapT[i]->left=NULL;
		else
		{
			heapT[i]->left=heapT[(2*i+1)];
		}
		if(2*(i+1)>=heap_size)
			heapT[i]->right=NULL;
		else
		{
			heapT[i]->right=heapT[2*(i+1)];
		}

	}
	return heapT[0];
}



TreeLinkNode* genHeapL(vector<int> str,int heap_size)  //建堆
{
	vector<TreeLinkNode*> heapT;
//	int heap_size=15;
	for (int i=0;i<heap_size;i++)
	{
		TreeLinkNode * p=new TreeLinkNode(str[i]);
		heapT.push_back(p);
	}
	for (int i=0;i<heap_size;i++)
	{
		if((2*i+1)>=heap_size)
			heapT[i]->left=NULL;
		else
		{
			heapT[i]->left=heapT[(2*i+1)];
		}
		if(2*(i+1)>=heap_size)
			heapT[i]->right=NULL;
		else
		{
			heapT[i]->right=heapT[2*(i+1)];
		}
		if (i!=0)
		{
			heapT[i]->next=heapT[(i-1)/2];
		}
		else
		{
			heapT[i]->next=NULL;
		}
	}
	return heapT[0];
}

long long  C(int a,int b)
{
	long long sum=1;
	
	int c=b;
	while (c)
	{
		sum=sum*a;
		c--;
		a--;
	}
	while (b)
	{
		sum=sum/b;
		b--;
	}
	return sum;
}



/*
vector<int> pushV,popV;
int a[5]={1,2,3,4,5};
int b[5]={4,5,3,2,1};
int c[5]={4,3,5,1,2};
for (int i=0;i<5;i++)
{
pushV.push_back(a[i]);
popV.push_back(b[i]);
}

bool b1=IsPopOrder(pushV,popV);
*/
bool IsPopOrder(vector<int> pushV,vector<int> popV)
{
  auto num=pushV.size();
  if (num<1||num!=popV.size())
  {
	  return false;
  }
  else
  {
   vector<int> p;
   int i=0,j=0;
   while (1)
   {
	 if (!p.size()&&i<num)
	   {		  
		 p.push_back(pushV[i]);
		 i++;
	   }
	  if (p[p.size()-1]!=popV[j])
	  {
		  if (i>=num)
		  {
			  return false;
		  }
		  else
		  {
			  p.push_back(pushV[i]);
			  i++;
		  }   
	  }
	  else
	  {
		  p.pop_back();
		  j++;
	  }
     if (!p.size()&&j==num)
     {
	  return true;
     }
  }
  }
}


//vector<int> p;
//int a[8]={6,-3,-2,7,-15,1,2,2};		
//for (int i=0;i<8;i++)
//{
//	p.push_back(a[i]);
//}
//
//int b=FindGreatestSumOfSubArray(p);
int FindGreatestSumOfSubArray(vector<int> array) 
{
	auto n=array.size();
	if (n<1)
	{
		return 0;
	}
	int summax=array[0];
	for(int i=0;i<n;i++)
	{
		int tmp=array[i];
		if (summax<tmp)
		{
			summax=tmp;
		}
		for (int j=i+1;j<n;j++)
		  {
			  tmp+=array[j];
			  if (summax<tmp)
			  {
				  summax=tmp;
			  }
		  }
	}
	return summax;
}


struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

//
//vector<RandomListNode*> p;
//int a[5]={1,2,3,4,5};
//for (int i=0;i<5;i++)
//{
//	RandomListNode* pR=new RandomListNode(a[i]);
//	p.push_back(pR);
//}
//for (int i=0;i<5;i++)
//{
//	if (i==4)
//	{
//		p[i]->next=NULL;
//	}
//	else
//	{
//		p[i]->next=p[i+1];
//	}
//	p[i]->random=p[i%3];
//}
//
//RandomListNode* b=Clone(p[0]);
RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead==NULL)
	{
		return NULL;
	}
	else



	{
		vector<RandomListNode*> p;
		vector<RandomListNode*> pt;
		vector<int>  label;
		while(pHead!=NULL)
		{
			RandomListNode* pR=new RandomListNode(0);
			pR->label=pHead->label;
			p.push_back(pR);
			pt.push_back(pHead);
			label.push_back(0);
			pHead=pHead->next;
			if (pHead==pt[0])
			{
				break;
			}
		}
		auto n=p.size();
		for (int i=0;i<n;i++)
		{
			if (pt[i]->random==NULL)
			{
              label[i]=n;
			}
			else
			{
				for (int j=0;j<n;j++)
				{
					if (pt[i]->random==pt[j])
					{
						label[i]=j;
					}
				}
			}		
		}
		for (int i=0;i<n;i++)
		{
			if (label[i]!=n)
			{
				p[i]->random=p[label[i]];
			}
			else
			{
				p[i]->random=NULL;
			}
			if (i==n-1)
			{
              p[i]->next=NULL;  
			}
			else
			{
				p[i]->next=p[i+1];
			}
			
		}
		return p[0];
	}
	


}

//
//string str="aaa";
//vector<string> tmp=Permutation(str);

vector<string> Permutation(string str) 
{
	vector<string> vtmp;
	auto  n=str.size();
	if (n<1)
	{
	}
	else if (n==1)
	{
		vtmp.push_back(str);
	}
	else
	{
		//排序
		char tmp=' ';
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++)
			{
				if(str[i]>str[j])
				{
					tmp=str[i];
					str[i]=str[j];
					str[j]=tmp;
				}
			}
		vector<string> vChild;
		string   sChild;
		tmp=' ';
		for (int i=0;i<n;i++)
		{   
			vChild.clear();
			sChild.clear();
			if (tmp!=str[i])
			{
				tmp=str[i];
				if(i!=0)				
					sChild=str.substr(0,i);			
				if(i!=n-1)
					sChild+=str.substr(i+1); 
				vChild=Permutation(sChild);
				auto nC=vChild.size();
				for (int j=0;j<nC;j++)
				{
					sChild=str[i]+vChild[j];
					vtmp.push_back(sChild);
				}

			}
			
		}
	}
	
	return vtmp;
    
}

 //vector<int> uglyNumber;
	// double k[3]={1,1.5847,2.322};
	// int    k1[3]={0,0,0};
	// double tmp=0;
	// for (int i=0;i<20;i++)
	// {

	// }


	///* for (int i=1;i<20;i++)
	// {
	//	 uglyNumber.push_back(GetUglyNumber_Solution(i));
	// }*/

int GetUglyNumber_Solution(int index)
{
	vector<int> ugly;
	ugly.push_back(1);
	int i=1,n=2,y=0;
	if(index<1)
		return 0;
	else
	{ 
		while(i<index)
		{  
			y=n;           
			if(y%2==0||y%3==0||y%5==0)
			{
				while(y%2==0)
				{
					y=y/2;
				}
				while(y%3==0)
				{
					y=y/3;
				}
				while(y%5==0)
				{
					y=y/5;
				}   
				if(y==1)
				{
					ugly.push_back(n);
					i++;
				}     
			}        		       
			n++;     
		}
		return ugly[index-1];          
	}

}
////
////vector<string> p;
////vector<int> vi;
////int b[]={3,32,321};
////string a[]={"abc","def","hij"};
////for (int i=0;i<3;i++)
////{
////	p.push_back(a[i]);
////	vi.push_back(b[i]);
////}
////string c=PrintMinNumber(vi);
////vector<string> vp=sortStr(p);
vector<string> sortStr(vector <string> vStr)
{
	vector<string> vSort;
	auto n=vStr.size();
	if (n<1)
	{
		return  vSort;
	}
	else if (n==1)
	{
		return vStr;
	}
	else
	{
     vector<string> vChild;
	 vector<string> vTmp;
	 string tmp,tmp1;
	 for (int i=0;i<n;i++)
	 {
	   tmp.clear();
	   vTmp.clear();
	   vTmp=vStr;
       tmp=vTmp[i];
	   vTmp[i]=vTmp.back();
	   vTmp.pop_back();
	   vChild=sortStr(vTmp);
	   for (int j=0;j<vChild.size();j++)
	   {
		   tmp1.clear();
		   tmp1=tmp+vChild[j];
		   vSort.push_back(tmp1);
	   }
	 }
	 return vSort;
	}
}

string PrintMinNumber(vector<int> numbers) 
{
  string str="";
  auto n=numbers.size();
  if (n<1)
  {
	  return str;
  }
  else
  {
   vector<string> vStr;
   string sTmp;
   for (int i=0;i<n;i++)
   {
	   sTmp.clear();
	   while (numbers[i])
	   {
		   sTmp=((char)(numbers[i]%10+'0'))+sTmp;
		   numbers[i]=numbers[i]/10;
	   }
	   vStr.push_back(sTmp);
	
   }
   //排列组合
   vector<string> vSortStr=sortStr(vStr);
   str=vSortStr[0];
   for (int i=0;i<vSortStr.size();i++)
   {
	  if (str>vSortStr[i])
	  {
		  str=vSortStr[i];
	  }
   }
   return str;
  }
}


//
//char str[]="ADCDEFGHIJKLMNOPQRSTUVWXYZ";
//int index=0;
//for(int i=0;i<26;i++)
//{
//	for(int j=0;j<5;)
//	{
//		if(str[index]!='0')
//		{		  	 
//			j++;		
//		}
//		index=index+1;
//		index=index%26;
//
//	}
//	if (index==0)
//	{
//		std::cout<<str[25]<<" ";
//		str[25]='0';
//	}
//	else
//	{
//		std::cout<<str[index-1]<<" ";
//		str[index-1]='0';
//	}		 
//}

//
//string  a="aeiou",b="BarackObama" ;
//bool a1=checkDifferent(a);
//bool a2=checkDifferent(b);
bool checkDifferent(string iniString)
{
	// write code here
	auto num=iniString.size();
	for(int i=1;i<num;i++)
		for(int j=0;j<i;j++)
		{
			if (iniString[i]==iniString[j])
				return false;
		}
	return true;
}


//
//string  a="aeioub";
//string b=reverseString(a);
string reverseString(string iniString) 
{
	// write code here
	char tmp=' ';
	for(int i=0;i<(int)(iniString.size()/2);i++)
	{
		tmp=iniString[iniString.size()-1-i];
		iniString[iniString.size()-1-i]=iniString[i];
		iniString[i]=tmp;
	}
	return iniString;
}
//
//string  a="This is nowcoder",b="is This nowcoder" ;
//bool c=checkSam(a,b);
bool checkSam(string stringA, string stringB)
{
	// write code here
	if (stringA.size()!=stringB.size())
	{
		return false;
	}
	else
	{
		char tmp=' ';
		for (int i=0;i<stringA.size();i++)
		{
			for (int j=i+1;j<stringA.size();j++)
			{
			  if (stringA[i]>stringA[j])
			  {
				  tmp=stringA[i];
				  stringA[i]=stringA[j];
			      stringA[j]=tmp;
			  }
			}
		}
		for (int i=0;i<stringB.size();i++)
		{
			for (int j=i+1;j<stringB.size();j++)
			{
				if (stringB[i]>stringB[j])
				{
					tmp=stringB[i];
					stringB[i]=stringB[j];
					stringB[j]=tmp;
				}
			}
		}
		if (stringA==stringB)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}


//
//string  a="aeio u b";
//string b=replaceSpace(a,7);
string replaceSpace(string iniString, int length)
{
	// write code here
	for(int i=0;i<length;i++)
	{
		if(iniString[i]==' ')
		{
			length+=2;
			iniString=iniString+"  ";
			for(int j=length;j>i+2;j--)
			{
				iniString[j]=iniString[j-2];  
			}
			iniString[i]='%';
			iniString[i+1]='2';
			iniString[i+2]='0';
		}
	}
	return iniString;
}

//
//string a="jjjjjjxxxxxxxooZLLLLLLLLQQQQQQQQQLLLLLLLLECXXXXXXXIIIIIIIIIhjjyyySSooooooooommmuuEEEEEEEEEnnnnnnnffffffAAAAAllllllllbbbbkkkkkkkkkkkkKKKKKKhhhhhhhhhooooooooooYCCCCCCOOOOOOOOOMMMMMMMMMMiiiiiivvvvvvvWWWWkkkkkkwwwwwwwMmmmmmmmmLLLwwwwwwwkkkjjjjjjttttQQQQQQQQQaaaaaaaFFFFFFFlllllllllggggggggggPPPPPPuuuuuuuuaYYYYYYwQQQFFFFFFFFFFaaaaapXXXXXXXxxxxxxQQQQQQQQQsssssGGGGfffffffddddddpppQQQQQQHHHTTTaaaaaaGGGGGGddyyyyyMhhllllllllllNNNNNNNNUUUWWWWWWLLLLLLLLLYYYYYYYYYYTTKKKKKKKKiiiiiiitttttttXXXXXXXXXLLLHZZZZZZZssssjjJJJEEEEEOOOOOttttttttttBBttttttTTTTTTTTTTrrrrttttRRRRRyyooooooaaaaaaaaarrrrrrrPPPPPPPjjPPPPddddddddddHHHHnnnnnnnnnnSSSSSSSSSSzzHHHHHHHHHddddddDDDzzzhhhhhfffffffffftttttteeeeeeeeEEEEEEEEEaaaaaaccccccccccFFFFFFFF";
//string b=zipString(a);
string zipString(string iniString)
{
	// write code here
	string  as=iniString;

	char tmp=iniString[0];
	int t_time=1;
	int length=iniString.size();
	string st;
	for (int i=1;i<length;i++)
	{
		if (iniString[i]!=tmp)
		{
			if (t_time>1)
			{
			  st=std::to_string(t_time);
			  for (int j=0;j<st.size();j++)
			  {
                  iniString[i-t_time+1+j]=st[j];
			  }
			  length=length-t_time+st.size()+1;
			  for (int k=i-t_time+1+st.size();k<length;k++)
			  {
				  iniString[k]=iniString[k+t_time-st.size()-1];
			  }
			  i=i-t_time+st.size()+1;
			}
			else
			{
				
				length=length+1;
				iniString=iniString+' ';
				for (int k=length-1;k>i;k--)
				{
					iniString[k]=iniString[k-1];
				}
				iniString[i]='1';
				i=i+1;
			}
			tmp=iniString[i];
			t_time=1;
		}
		else
		{
			t_time++;
		}
	}
	if (t_time>1)
	{
		st=std::to_string(t_time);
		for (int j=0;j<st.size();j++)
		{
			iniString[length-t_time+1+j]=st[j];
		}
		 length=length-t_time+st.size()+1;
	}
	else
	{
		iniString[length]='1';
		length=length+1;
	}
	iniString.erase(length);
	if (length<as.size())
	{
		return iniString;
	}
	else
	{
		return as;
	}

}

//
//int a=sum(3);
int sum(int s)
{
   int r=sqrt(s);
   int s1 =0;
   for (int i=-r;i<=r;i++)
   {
	   for (int j=-r;j<=r;j++)
	   {
		  
		   if ((i*i+j*j)==s)
		   {
			   s1++;
		   }
	   }
   }
   return s1;
}
//
//int a[5][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
//vector<int>a1,a2,a3,a4,a5;
//for (int i=0;i<5;i++)
//{
//	a1.push_back(a[0][i]);
//	a2.push_back(a[1][i]);
//	a3.push_back(a[2][i]);
//	a4.push_back(a[3][i]);
//	a5.push_back(a[4][i]);
//}
//vector<vector<int> >v;
//v.push_back(a1);
//v.push_back(a2);
//v.push_back(a3);
//v.push_back(a4);
//v.push_back(a5);
//
//vector<vector<int> >v1=transformImage(v,5);
vector<vector<int> > transformImage(vector<vector<int> > mat, int n)
{
	// write code here
	for (int i=0;i<n/2;i++)
	{
		mat[i].swap(mat[n-i-1]);
	}
	int tmp=0;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
		{
			tmp=mat[i][j];
			mat[i][j]=mat[j][i];
			mat[j][i]=tmp;
		}
	return  mat;

}
//
//int a[3][3]={1,2,3,0,1,2,0,0,1};
//		vector<int>a1,a2,a3,a4,a5;
//		for (int i=0;i<3;i++)
//		{
//			a1.push_back(a[0][i]);
//			a2.push_back(a[1][i]);
//			a3.push_back(a[2][i]);
//			/*a4.push_back(a[3][i]);
//			a5.push_back(a[4][i]);*/
//		}
//		vector<vector<int> >v;
//		v.push_back(a1);
//		v.push_back(a2);
//		v.push_back(a3);
//		/*v.push_back(a4);
//		v.push_back(a5);*/
//
//		vector<vector<int> >v1=clearZero(v,3);
vector<vector<int> > clearZero(vector<vector<int> > mat, int n)
{
	// write code here
  vector<int> h,l;
  int k=mat.size();
	for (int i=0;i<k;i++)
       for (int j=0;j<n;j++)
       {
		   if (!mat[i][j])
		   {
			   h.push_back(i);
			   l.push_back(j);
		   }
       }
	for (int i=0;i<h.size();i++)
	{
		for (int j=0;j<n;j++)
		{
			mat[h[i]][j]=0;
		}
	}
	for (int i=0;i<l.size();i++)
	{
		for (int j=0;j<k;j++)
		{
			mat[j][l[i]]=0;
		}
	}
 return mat;
}




	ListNode* plusAB1(ListNode* a, ListNode* b) 
	{
		// write code here
		vector<ListNode*> v;
		int c=0;//进位标志
		do
		{
			ListNode* pNood=new ListNode(0);	
			pNood->val=(a->val+b->val+c)%10;
			c=(a->val+b->val+c)/10;
			v.push_back(pNood);
			a=a->next;
			b=b->next;
		}
		while(a!=NULL&&b!=NULL);
		if (a!=NULL&&b==NULL)
		{
			do
			{
				ListNode* pNood=new ListNode(0);
				c=(a->val+c)/10;
				pNood->val=(a->val+c)%10;
				v.push_back(pNood);
				a=a->next;
			}
			while(a->next!=NULL);
		}
		else if (a==NULL&&b!=NULL)
		{
			do
			{
				ListNode* pNood=new ListNode(0);
				c=(b->val+c)/10;
				pNood->val=(a->val+c)%10;
				v.push_back(pNood);
				b=b->next;
			}
			while(b->next!=NULL);
		}
		if (a==NULL&&b==NULL&&c>0)
		{
			ListNode* pNood=new ListNode(0);
			pNood->val=c;
			v.push_back(pNood);
		}
		for (int i=0;i<v.size()-1;i++)
		{
			v[i]->next=v[i+1];
		}
		return v[0];
	}

	/*int a[5]={3,2,1,9,4};
	int b[3]={3,2,1};
	vector<ListNode*> va,vb;
	for (int i=0;i<5;i++)
	{
		ListNode* pNooda=new ListNode(a[i]);
		va.push_back(pNooda);
	}
	for (int i=0;i<3;i++)
	{
		ListNode* pNoodb=new ListNode(b[i]);
		vb.push_back(pNoodb);
	}
	for (int i=0;i<va.size()-1;i++)
	{
		va[i]->next=va[i+1];
	}
	for (int i=0;i<vb.size()-1;i++)
	{
		vb[i]->next=vb[i+1];
	}
	ListNode* p=plusAB(va[0],vb[0]);*/
	ListNode* plusAB(ListNode* a, ListNode* b) 
	{
		// write code here
		ListNode* p=a;
		int c=0;
		while (a->next!=NULL&&b->next!=NULL)
		{
			c=a->val+b->val+c;
			a->val=c%10;
			c=c/10;
			a=a->next;
			b=b->next;
		} 
		if (a->next==NULL&&b->next==NULL)
		{
			c=a->val+b->val+c;
			a->val=c%10;
			c=c/10;
			if (c!=0)
			{
			  a->next=new ListNode(c);
			}		
		}
		else 
		{
			if (a->next==NULL&&b->next!=NULL)
			{
			a->next=b->next;
			b->next=NULL;
			}
			c=a->val+b->val+c;
			a->val=c%10;
			c=c/10;
			a=a->next;
		  while (c!=0&&a->next!=NULL)
		  {
			  c=a->val+c;
			  a->val=c%10;
			  c=c/10;
			  a=a->next;
		  }
		  c=a->val+c;
		  a->val=c%10;
		  c=c/10;
		  if (a->next==NULL&&c!=0)
		  {
		   a->next=new ListNode(c);
		  }

		}	
		
		return p;
	}/*
	int a[]={63,72,269,868,975,581,941,443,836,536,824,838,282,348,109,344,196,284,502,260,327,374,932,561,199,905,668,645,151,295,7,70,582,221,913,919,540,396,841,783,696,510,229,788,372,287,890,912,946,175,35,947,455,302,937,432,31,482,918,124,211,526,225,459,271,125,220,958,586,498,8,50,328,949,674,354,949,259,380,834,101,218,546,274,766,311,538,382,514,698,447,885,284,460,811,662,548,575,551,339,477,888,657,673,265,367,361,272,695,165,670,712,235,257,85,97,723,52,620,204,952,501,204,786,718,840,388,260,63,903,537,486,940,261,894,433,670};	
	vector<ListNode*> va;
	for (int i=0;i<137;i++)
	{
		ListNode* pNooda=new ListNode(a[i]);
		va.push_back(pNooda);
	}

	for (int i=0;i<va.size()-1;i++)
	{
		va[i]->next=va[i+1];
	}	
	ListNode* p=partition(va[0],43);*/
	ListNode* partition(ListNode* pHead, int x) 
	{
		// write code here
		ListNode *p1=NULL,*p2=NULL,*p3=NULL,*p4=NULL;
		{
			while (pHead!=NULL)
			{
				if (pHead->val<x)
				{
					if (p1==NULL)
					{
						p1=pHead;
						p3=p1;
					}
					else
					{
						p1->next=pHead;
						p1=p1->next;
					}
				}
				else
				{
					if (p2==NULL)
					{
						p2=pHead;
						p4=p2;
					}
					else
					{
						p2->next=pHead;
						p2=p2->next;
					}
				}
				pHead=pHead->next;
			}
			if (p2!=NULL)
			{
				p2->next=NULL;
			}
			if (p1!=NULL)
			{
			  p1->next=p4;
			}		
			if (p3!=NULL)
			{
				return p3;
			}
			else
			{
				return p4;
			}
			
		}
	}


	bool isPalindrome1(ListNode* pHead) 
	{
		// write code here
		vector<ListNode*> vp;
		ListNode *p=pHead;
		while (pHead!=NULL)
		{
			ListNode * pv=new ListNode(pHead->val);
			vp.push_back(pv);
			pHead=pHead->next;
		}
		for (int i=vp.size()-1;i>0;i--)
		{
			vp[i]->next=vp[i-1];
		}	
		while(p!=NULL)
		{
			if (p->val!=vp[vp.size()-1]->val)
			{
				return false;
			}
			p=p->next;
			vp[vp.size()-1]=vp[vp.size()-1]->next;
		}
		return true;

	}
	/*
	int a[]={1,2,3,2,3};	
	vector<ListNode*> va;
	for (int i=0;i<5;i++)
	{
	ListNode* pNooda=new ListNode(a[i]);
	va.push_back(pNooda);
	}

	for (int i=0;i<va.size()-1;i++)
	{
	va[i]->next=va[i+1];
	}	
	bool p=isPalindrome(va[0]);*/
	bool isPalindrome(ListNode* pHead)
    {
        // write code here
        ListNode *fast = pHead;
		ListNode *slow = pHead;
		std::stack<int> s;
		/**
		 * 将链表的前半部分元素装入栈中，当快速runner
                 *（移动的速度是慢速runner的两倍）
		 * 到底链表尾部时，则慢速runner已经处于链表中间位置
		 */
		while(fast != NULL && fast->next != NULL){
			s.push(slow->val);
			slow = slow->next;
			fast = fast->next->next;
		}
		//当链表为奇数个时，跳过中间元素
		if (fast != NULL) {
			slow = slow->next;
		}
		while(slow != NULL){
			//如果两者不相同，则该链表不是回文串
			if (s.top() != slow->val) {
				return false;
			}
			slow = slow->next;
			s.pop();
		}
		return true;
    }
/*
	int a[]={1,2,3,4,5,6,7,8};
	vector<int> a1;
	for (int i=0;i<8;i++)
	{
		a1.push_back(a[i]);
	}
	int a2=buildMinimalBST(a1);*/
	int buildMinimalBST(vector<int> vals)
	{
		// write code here
		auto n=vals.size();
		if (n<2)
		{
			return n;
		}
		vector<int> left,right;
		for (int i = 0; i < n; i++)
		{
			if (i<n/2)
			{
				left.push_back(vals[i]);
			}
			else if (i>n/2)
			{
				right.push_back(vals[i]);
			}
		}
		return (1+(buildMinimalBST(left)>buildMinimalBST(right)?buildMinimalBST(left):buildMinimalBST(right)));
		
	}

	struct Point {
		int x;
		int y;
		Point() :
			x(0), y(0) {
		}
		Point(int xx, int yy) {
			x = xx;
			y = yy;
		}
	};

	//int a[8][2]={136,6278,3958,6278,3958,2456,136,2456,-3898,11132,7238,11132,7238,-4,-3898,-4};
	//vector<Point> A,B;
	//for (int i=0;i<4;i++)
	//{
	//	Point p(a[i][0],a[i][1]);
	//	A.push_back(p);
	//}
	//for (int i=4;i<8;i++)
	//{
	//	Point p(a[i][0],a[i][1]);
	//	B.push_back(p);
	//}
	//vector<double> r=getBipartition(A,B);
	vector<double> getBipartition(vector<Point> A, vector<Point> B)
	{
		// write code here
		double x1=0,y1=0,x2=0,y2=0;
		for(int i=0;i<4;i++)
		{
			x1+=(double)A[i].x;
			y1+=(double)A[i].y;
			x2+=(double)B[i].x;
			y2+=(double)B[i].y;
		}
		x1/=4.0;
		y1/=4.0;
		x2/=4.0;
		y2/=4.0;
		double k=(y2-y1)/(x2-x1);
		double b=y1-k*x1;
		vector<double> p;
		p.push_back(k);
		p.push_back(b);
		return p;
	}

using namespace std ;


/**题目：加法运算替代     未完！
要求：请编写一个方法，实现整数的乘法、减法和除法运算(这里的除指整除)。只允许使用加号。
给定两个正整数int a,int b,同时给定一个int type代表运算的类型，1为求a ＊ b，0为求a ／ b，-1为求a － b。
请返回计算的结果，保证数据合法且结果一定在int范围内。
测试样例：
1,2,1    返回：2

测试LY:
**/
int calc(int a, int b, int type) 
{
	// write code here
	switch (type)
	{
	case -1:  //相乘
		{}
	case 0:   //整除
		{}
	case 1:   //相减
		{
			if (b<0)
			{
				
			}
		}

	default:
		break;
	}
	return -1;
}


/**题目：无判断max     完成
要求：请编写一个方法，找出两个数字中最大的那个。条件是不得使用if-else等比较和判断运算符。
给定两个int a和b，请返回较大的一个数。若两数相同则返回任意一个。
测试样例：
1，2
返回：2

测试LY:
int a=111,b=21;
int c=getMax(a,b);

标准答案：
**/
int getMax(int a, int b) 
{
	// write code here
	int c=a;
	bool t=(a>b)&&(c=a);
	t=(b>a)&&(c=b);
	return c;
}




/**题目：约瑟夫问题I  未完！
要求：
约瑟夫问题是一个非常著名的趣题，即由n个人坐成一圈，按顺时针由1开始给他们编号。然后由第一个人开始报数，数到m的人出局。现在需要求的是最后一个出局的人的编号。
给定两个int n和m，代表游戏的人数。请返回最后一个出局的人的编号。保证n和m小于等于1000。
测试样例：
5 3
返回：4
测试LY:


标准答案：把n个人的编号改为0~n-1，然后对删除的过程进行分析。
第一个删除的数字是(m-1)%n，几位k，则剩余的编号为(0,1,...,k-1,k+1,...,n-1)，下次开始删除时，顺序为(k+1,...,n-1,0,1,...k-1)。
用f(n,m)表示从(0~n-1)开始删除后的最终结果。
用q(n-1,m)表示从(k+1,...,n-1,0,1,...k-1)开始删除后的最终结果。
则f(n,m)=q(n-1,m)。

下面把(k+1,...,n-1,0,1,...k-1)转换为(0~n-2)的形式，即
k+1对应0
k+2对于1
...
k-1对应n-2
转化函数设为p(x)=(x-k-1)%n, p(x)的你函数为p^(x)=(x+k+1)%n。
则f(n,m)=q(n-1,m)=p^(f(n-1,m))=(f(n-1,m)+k+1)%n，又因为k=(m-1)%n。
f(n,m)=(f(n-1,m)+m)%n;

最终的递推关系式为
f(1,m) = 0;                        (n=1)
f(n,m)=(f(n-1,m)+m)%n; （n>1）

代码如下
public int getResult(int n, int m) {
if (n < 0 || m < 0) {
return -1;
}
int last = 0;
for(int i=2;i<=n;++i){
last = (last+m)%i;
}
// 因为实际编号为(1~n)
return (last+1);

**/
int getResult(int n, int m) 
{
	// write code here

	list<int> l;
	for(int i=1;i<=n;i++)
		l.push_back(i);
	int tmp=1;
	auto p=l.begin();
	while(l.size()>1)
	{
		if(!(tmp%m))
		{
          p=l.erase(p);
		}
		else
		{
         p++;
		}
		tmp++;
		if (p==l.end())
		{
			p=l.begin();
		}

	}
	p=l.begin();
	return *p;
}



/**题目：二进制插入    完成
要求：
有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位,其中二进制的位数从低位数到高位且以0开始。
给定两个数int n和int m，同时给定int j和int i，意义如题所述，请返回操作后的数，保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1。
测试样例：
1024，19，2，6
返回：1100

标准答案：
**/int binInsert(int n, int m, int j, int i)
{
	// write code here
	return n=n|(m<<j);
}


int _tmain(int argc, _TCHAR* argv[])
	{
		int c=binInsert(1024,19,2,6);
		while (1);
	}
