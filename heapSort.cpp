#include<iostream>
using namespace std;

void MaxHeap(int ara[], int i, int n)
{
    int lar,L,R;
    L = i*2;
    R = L+1;
    lar = i;
    if(L <= n && ara[L] > ara[i])lar=L;
    if(R <= n && ara[R] > ara[lar])lar=R;
    if(lar != i)
    {
        swap(ara[i],ara[lar]);
        MaxHeap(ara,lar,n);
    }
}

void Buildheap(int ara[], int n)
{
    int i;
    for( i = n/2; i>0; i--)MaxHeap(ara,i,n);
    //for(i=1;i<=n;i++)cout<<ara[i]<<" ";
}

void HeapSort(int ara[], int n)
{
    int i;

    Buildheap(ara,n);
   // cout<<endl;
    for( i = n; i > 1; i--)
    {
        swap(ara[1],ara[i]);
        n--;
        MaxHeap(ara,1,n);
    }
}

int main()
{
    int n,i;
    cin >> n;
    int ara[n];
    for( i = 1; i <= n; i++)cin >> ara[i];
    HeapSort(ara,n);
    for( i = 1;i <= n;i++)cout << ara[i] << " ";
    cout << endl;
    return 0;
}
