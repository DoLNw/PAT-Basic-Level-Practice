#include <stdio.h>
#include <stdlib.h>

#define swapNode(a, b) {struct node* temp; temp=a; a=b; b=temp;}

//这道题的一个“坑”：可能有孤立节点，整个链表的长度小于N。
//读取每一个节点，存储到一个结构或int[3]数组；
//将节点“链接”成为链表，在数组中排列，找到指向-1的节点说明链表已经结束；
//反转链表。每K个一组，交换第i个和倒数第i个；
//打印列表。反转时没有（也不必）修改每个节点的next，输出时应该相应输出下一个节点的address，最后一个节点的next输出-1。

//把这些数组按照顺序排列，就不用在结构体中引入上、下一个struct*了
typedef struct node *Node;
struct node{
    int address, data, nextAddress;
};

int main() {
    printf("Hellow World!\n");
    int firstAddress, number, circlr;
    Node *nodes, *p;
    
    scanf("%d %d %d", &firstAddress, &number, &circlr);
    
    nodes = (Node*)malloc(number * sizeof(Node));
    
    //read
    for (int i=0; i<number; i++) {
        nodes[i] = (Node)malloc(sizeof(struct node));
        scanf("%d %d %d", &nodes[i]->address, &nodes[i]->data, &nodes[i]->nextAddress);
    }
    
    //link, 这样一整理即可
    for (int i=0; i<number; i++) {
        //我去，这里我之前为了少运算一次，int j=i+1的，然后是给我超时的居然，不加居然是不超时的，孤陋寡闻了。
        for (int j=i; j<number; j++) {
            //注意此处比较是比较i-1和j，但是交换是i和j，妙的地方。
            if (nodes[j]->address == (i ? nodes[i-1]->nextAddress : firstAddress)) {
                swapNode(nodes[i], nodes[j]);
                break;
            }
        }
        if(nodes[i]->nextAddress == -1) {  /* there could be useless nodes */
            number = i + 1;
        }
    }
    
    /* reverse the list */
    for(int i = 0; i < number / circlr; i++)
    {
        p = nodes + i * circlr;
        for(int j = 0; j < circlr / 2; j++)
        {
            swapNode(p[j], p[circlr - j - 1]);
        }
    }
    
    /* print the list */
    for(int i = 0; i < number - 1; i++)
    {
        //注意倒换次序后，本该下一个地址也变化的，此处取巧打印.
        printf("%05d %d %05d\n", nodes[i]->address, nodes[i]->data, nodes[i + 1]->address);
    }
    printf("%05d %d -1\n", nodes[number - 1]->address, nodes[number - 1]->data);
    
    return 0;
}

//还有我现在上面的代码有一个测试点运行超时，下面这个拷贝来的却没有超时。
//#include <stdio.h>
//#include <stdlib.h>
//
//#define SWAPNODE(A, B) {Node temp = A; A = B; B = temp;}
//
//typedef struct node *Node;
//
//struct node{
//    int addr;
//    int data;
//    int next;
//};
//
//int main()
//{
//    int A, N, K;
//    Node *nodes, *p;
//
//    /* read */
//    scanf("%d %d %d", &A, &N, &K);
//    nodes = (Node*)malloc(N * sizeof(Node));
//    for(int i = 0; i < N; i++)
//    {
//        nodes[i] = (Node)malloc(sizeof(struct node));
//        scanf("%d %d %d", &nodes[i]->addr, &nodes[i]->data, &nodes[i]->next);
//    }
//
//    /* link the list */
//    for(int i = 0; i < N; i++)
//    {
//        for(int j = i; j < N; j++)
//        {
//            if(nodes[j]->addr == (i ? nodes[i - 1]->next : A))
//            {
//                SWAPNODE(nodes[i], nodes[j]);
//                break;
//            }
//        }
//        if(nodes[i]->next == -1)   /* there could be useless nodes */
//            N = i + 1;
//    }
//
//    /* reverse the list */
//    for(int i = 0; i < N / K; i++)
//    {
//        p = nodes + i * K;
//        for(int j = 0; j < K / 2; j++)
//        {
//            SWAPNODE(p[j], p[K - j - 1]);
//        }
//    }
//
//    /* print the list */
//    for(int i = 0; i < N - 1; i++)
//    {
//        printf("%05d %d %05d\n", nodes[i]->addr, nodes[i]->data, nodes[i + 1]->addr);
//    }
//    printf("%05d %d -1\n", nodes[N - 1]->addr, nodes[N - 1]->data);
//
//    return 0;
//}


