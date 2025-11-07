void SelectTwoMin(int upbound, HuffmanTree HT, int &s1, int &s2)
{
    int m1=1000,m2=1000;
    int x1=0,x2=0;
    for(int i=1;i<=upbound;i++)
    {
        
        if(HT[i].parent==0&&HT[i].weight<m1)
        {
            
            m2=m1;
            x2=x1;
            m1=HT[i].weight;
            x1=i;
        }else if(HT[i].parent==0&&HT[i].weight<m2)
                {
                     m2=HT[i].weight;
                     x2=i;
               
                }
    }
    s1=x1;
    s2=x2;
}
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{
    int s1=0,s2=0;
    int m=2*n-1;
    HC=new char*[n+1];

    HT=new HTNode[m+1];

    for(int i=0;i<n;i++)
    {
        
        HT[i+1].weight=w[i];
    }
    for(int i=1;i<=m;i++)
    {
        
        HT[i].lchild=0;
        HT[i].rchild=0;
        HT[i].parent=0;
    }
 
    for(int i=n+1;i<=m;i++)
    {
        SelectTwoMin(i-1,HT,s1,s2);
        
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
   
   
    for(int i=1;i<=n;i++)
    {
         char cd[n];
         cd[n-1]='\0';
        int start=n-1;
        int c=i;
        int f=HT[i].parent;
        while(f!=0)
        {
            start--;
            if(HT[f].lchild==c) {cd[start]='0';}
            else {cd[start]='1';}
            c=f; f=HT[f].parent;
            
        }
        HC[i]=new char[n-start];
        strcpy(HC[i],&cd[start]);
    }
    //delete cd;
}