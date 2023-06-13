
#include<linkedlist.h>
#include<stdlib.h>
// node* centerNodeLeft = (node*) malloc (sizeof(node));
// node* centerNodeRight = (node*) malloc (sizeof(node));
// void findCenterNodeLeft(linkedList* ls)
// {
//     static int size = ls->size;
//     size = size/2;
//     static int num = 0;
//     node* p = ls->head;
//     if(size >= 2)
//     {
//         num++;
//         centerNodeLeft = (node*)realloc(centerNodeLeft,sizeof(node)*num);
//         for(int i = 1; i < size;i++)
//         {
//             p = p->next;
//         }
//         centerNodeLeft[num-1] = *p;
//         printf("num: %d\n",num);    
//         printf("%d\n",centerNodeLeft[num-1].data);
//         findCenterNodeLeft(ls);
//     }
//     static int index =0;
//     while(index < num-1)
//     {
//         size = centerNodeLeft[index].data-centerNodeLeft[index+1].data - 1;
//         if( size >=4 )
//         {
//             num++;
//             centerNodeLeft = (node*)realloc(centerNodeLeft,sizeof(node)*num);
//             node* p = centerNodeLeft[index+1].next;
//             size = size/2;
//             for(int i = 1; i < size;i++)
//             {
//                 p = p->next;
//             }
//             node temp = centerNodeLeft[index+1];
//             centerNodeLeft[index+1] = *p;
//             centerNodeLeft[]
//         }     
//     }
// }

// void find(linkedList *ls,uint8_t data)
// {

// }
int binarySearch(linkedList *ls,int start,int end,uint8_t data)
{
    int size = end - start;
    if(size %2 != 0) size ++;
    size = size/2;
    static int index = size;
    node* p;
    if(start == 0) p = ls->head;
    else
    {
        p = ls->head;
        for(int i = 0; i < start; i++)
        {
            p = p->next;
        } 
    }
    if(size >= 1)
    {
        for(int i = 1; i < size; i++)
        {
           p = p->next;
        }
        if(data == p->data)
        {
            return size + start;
        } 
        else if(data < p->data) 
        {
            if((size + start)<= index) return binarySearch(ls,start,size,data);
            else return binarySearch(ls,indestart,size,data);
        }
        else 
        {
            if(size <index) return binarySearch(ls,size,size*2,data);
            else(size>index) return binarySearch(ls,size/2,size,data);
            else if(size == index)
            {
                binarySearch(ls,size,ls->size,data);
            }
        }
    } 
    else return -1;
}
void search(linkedList *ls,uint8_t data)
{
   int result= binarySearch(ls, 0, ls->size ,data);
   if(result == -1)printf("Khong tim thay %d\n",data);
   else printf("Tim thay %d tai vi tri %d\n",data,result);
}
void addNode(linkedList *ls,uint8_t data)
{
    node* newNode = new_Node(data);
    if(isEmpty(ls)) 
    {
        ls->head = newNode;
        ls->tail = newNode;
    }
    else
    {
        node *p = ls->head;
        node *temp = p;
        while(p != NULL)
        {
            if(newNode->data > p->data)
            {
                temp = p;
                p = p->next;
            }
            else
            {
                newNode->next = p;
                if(ls->head == p) 
                {
                    ls->head = newNode;
                }
                else temp->next = newNode;
                ls->size ++;
                return;    
            } 
        }
        temp->next = newNode;
    }
    ls->size ++;
}
int main()
{
    linkedList ls;
    linkedList_Init(&ls);
    addNode(&ls,5);
    addNode(&ls,17);
    addNode(&ls,6);
    addNode(&ls,11);
    addNode(&ls,3);
    addNode(&ls,1);
    addNode(&ls,7);
    addNode(&ls,4);
    // addNode(&ls,13);
    // addNode(&ls,16);
    // addNode(&ls,9);
    // addNode(&ls,10);
    // addNode(&ls,19);
    // addNode(&ls,12);
    // addNode(&ls,20);
    // addNode(&ls,15);
    // addNode(&ls,2);
    // addNode(&ls,18);
    // addNode(&ls,8);
    // addNode(&ls,14);
    display(&ls);
    printf("size of list: %d\n",length(ls));
    //search(&ls,1);
    search(&ls,11);
    // search(&ls,4);
    //search(&ls,5);
    // search(&ls,6);
    // search(&ls,7);
    // search(&ls,11);
    // search(&ls,17);
    //findCenterNodeLeft(&ls);
    return 0;
}


