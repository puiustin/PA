
Heap* create(int capacitate)
{
    Heap h=(Heap)malloc(sizeof(Heap));
    if(h==NULL)
    {
        printf("Alocare dinamica esuata\n");
        exit(1);
    }
    h->size=0;
    h->capacity=capacitate;
    if(h->vec==NULL)
        {
            printf("Alocare dinamica esuata");
            exit(1);
        }    
    return h;
}

int parent(Heap *h, int i)
{
    if(i>(h->size)-1 || i<=0)
        return -1;
    return (i-1)/2;
}

int max(Heap *h)
{
    if(h->size==0)
        return -1;
    return h->vec[0];
}

int min(Heap *h)
{
    if(h->size==0)
        return -1;
    return h->vec[h->size];
}

int left_child(Heap *h,int i)
{
    int poz=2*i+1;
    if(poz>(h->size)-1 || i<0)
        return -1;
    return poz;
}

int right_child(Heap *h, int i)
{
    int poz=2*i+2;
    if(poz>(h->size)-1 || i<0)
        return -1;
    return poz;
}

void resize(Heap *h)
{
    int v=(int *)realloc(h->vec,h->capacity=2);
    if(v==NULL)
    {
        printf("Alocare dinamica esuata\n");
        exit(1);
    }
    else
        h->vec=v;
}

void insert(Heap *h, int x)
{
    int i;
    if(h->size==h->capacity)
        resize(h);
    i=h->size;
    h->size++;
    while(i>0 && x>h->vec[(i-1)/2])
    {
        h->vec[i]=h->vec[(i-1)/2];
        i=(i-1)/2;
    }
    h->vec[i]=x;
}

void delete_heap(Heap **h)
{
    if(*h==NULL)
        return ;
    if((*h)->vec!=NULL)
        free((*h)->vec);
    free(*h);
    *h=NULL;
}

void printHeap(Heap *h)
{
    int i;
    printf("\n");
    for(i=0;i<h->size;i++)
        printf("%d ",h->vec[i]);
    printf("\n");
}

void heapify_down(Heap *h, int i)
{
    int l, r, max=i, aux;
    while(1)
    {
        l=left_child(h,i);
        r=right_child(h,i);
        if(l==-1 && r==-1)
            return ;
        if(l!=-1 && h->vec[l]>h->vec[max])
            max=l;
        if(r!=-1 && h->vec[i]>h->vec[max])
            max=r;
        if(max!=i)
        {
            aux=h->vec[i];
            h->vec[i]=h->vec[max];
            h->vec[max]=aux;
        i=max;
        }
        else
            break;
    }   
}

void heapify_up(Heap *h, int i)
{
    int tata,temp;
    while(i>0)
    {
        tata=parent(h,i);
        if(h->vec[i]>h->vec[tata])
        {
            temp=h->vec[i];
            h->vec[i]=h->vec[tata];
            h->vec[tata]=temp;
            i=tata;
        }
        else
            break;
    }

}

void heapsort(Heap *h, int *buf, int n)
{
    int i,aux;
    if(h==NULL || buf==NULL || n==0)
        return ;
    while(n>(h->capacity))
        resize(h);
    for(i=0;i<n;i++)
        h->vec[i]=buf[i];
    h->size=n;
    for(i=(n-1)/2;i>=0;i--)
    {
        aux=h->vec[0];
        h->vec[0]=h->vec[i];
        h->vec[i]=aux;
        h->size=i;
        heapify_down(h,0);
    }
    h->size=n;
    printHeap(h);
}

void populate(Heap *h, int *buf, int n)
{
    int i;
    if(h==NULL || buf==NULL || n==0)
        return ;
    while(n>h->capacity)
        resize(h);
    for(i=0;i<n;i++)
        h->vec[i]=buf[i];
    h->size=n;
    for(i=(n-1)/2;i>=0;i--)
        heapify_down(h,i);
}