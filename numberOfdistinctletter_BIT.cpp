#include<bits/stdc++.h>
using namespace std;
char ara[100002];
int bit[26][100002],n,cnt[26];

void update(int pos, int i, int val)
{
    for(; i<=n; i+=(i&(-i)))
    {
        bit[pos][i]+=val;
    }
}

int query(int pos,int l, int r)
{
    int s,k;
    s=k=0;
    for(;l>0;l-=(l&(-l)))s+=bit[pos][l];
    for(;r>0;r-=(r&(-r)))k+=bit[pos][r];
    if(k-s>0)return 1;
    return 0;
}

int main()
{
    int i,q,op,l,r,s;
    char c[3];
    scanf("%s",ara);
    n=strlen(ara);
    for(i=0; i<n; i++)
    {
        cnt[ara[i]-'a']++;
        update(ara[i]-'a',i+1,1);
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&op,&l);
       // cout<<op<<endl;
        if(op==1)
        {
            //getchar();
            scanf("%s",c);
            if(c[0]!=ara[l-1])
            {
                cnt[ara[l-1]-'a']--;
                update(ara[l-1]-'a',l,-1);
                ara[l-1]=c[0];
                cnt[c[0]-'a']++;
                update(c[0]-'a',l,1);
            }
        }
        else
        {
            s=0;
            scanf("%d",&r);
            for(i=0; i<26; i++)
            {
                if(ara[l-1]-'a'==i)
                {
                    s++;
                    continue;
                }
                s+=query(i,l-1,r);
            }
            printf("%d\n",s);
        }
    }
    return 0;
}

