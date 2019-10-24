#include<iostream>
using namespace std;

void buildmaxheap(int ara[], int n)
{
    int l,r,lar,i,j;
    for(i=n/2; i>0; i--)
    {
        l=i*2;
        r=l+1;
        lar=j=i;
        if(l<=n && ara[i]<ara[l])lar=l;
        if(r<=n && ara[lar]<ara[r])lar=r;
        while(lar!=j)
        {
            swap(ara[j],ara[lar]);
            j=lar;
            l=j*2;
            r=l+1;
            if(l<=n && ara[j]<ara[l])lar=l;
            if(r<=n && ara[lar]<ara[r])lar=r;
        }
    }
}

void heapsort(int ara[], int n)
{
    int i,j,l,r,lar;
    buildmaxheap(ara,n);

    for(i=n; i>1; i--)
    {
        swap(ara[1],ara[i]);
        l=2;
        r=l+1;
        lar=j=1;
        if(l<i && ara[1]<ara[l])lar=l;
        if(r<i && ara[lar]<ara[r])lar=r;
        while(lar!=j)
        {
            swap(ara[j],ara[lar]);
            j=lar;
            l=j*2;
            r=l+1;
            if(l<i && ara[j]<ara[l])lar=l;
            if(r<i && ara[lar]<ara[r])lar=r;
        }
    }
}

int main()
{
    int n,i;
    cin>>n;
    int ara[n+2];
    for(i=1; i<=n; i++)cin>>ara[i];
    heapsort(ara,n);
    for(i=1; i<=n; i++)cout<<ara[i]<<" ";
    cout<<endl;
}


