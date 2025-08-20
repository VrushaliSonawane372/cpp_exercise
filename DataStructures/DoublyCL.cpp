#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;

}NODE, *PNODE, **PPNODE;

// typedef struct node
// {
//     int data;
//     struct node *next;
//     struct node *prev;
// }NODE, *PNODE, **PPNODE;


class DoublyCL
{
    public:
    int iCount;
    PNODE head;
    PNODE tail;
    DoublyCL()
    {
        iCount = 0;
        head = NULL;
        tail = NULL;
    }

    void InsertFirst(int no)
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn->prev = NULL;
        newn->data = no;
        newn->next = NULL;

        if((head == NULL) && (tail == NULL))
        {
            head = newn;
            tail = newn;
        }
        else
        {
            newn->next = head;
            head->prev = newn;
            head = newn;
        }
        tail->next = head;
        head = tail->next;

        iCount++;
    }
    void InsertLast(int no)
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn->prev = NULL;
        newn->data = no;
        newn->next = NULL;

        if((head == NULL) && (tail == NULL))
        {
            head = newn;
            tail = newn;

            tail->next = head;
        }
        else
        {
           tail->next = newn;
           newn->prev = tail;

           tail = newn;

        }
        tail->next = head;
        head->prev = tail;

        iCount++;

    }
    void InsertAtPos(int no,int ipos)
    {
        int i = 0;

       if((ipos < 1) || (ipos > iCount + 1))
       {
            cout<<"Invalid Position..\n";
       }
       if(ipos == 1)
       {
            InsertFirst(no);
       }
       else if(ipos == iCount + 1)
       {
            InsertLast(no);
       }
       else
       {
            PNODE newn = NULL;
            newn = new NODE;
            newn->prev = NULL;
            newn->data = no;
            newn->next = NULL;

            PNODE temp = NULL;
            temp = head;

            for(i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next->prev = newn;

            newn->prev = temp->next;
            temp->next = newn;

        iCount++;
       } 
    }

    void DeleteFirst()
    {
        if((head == NULL) && (tail == NULL))
        {
            cout<<"LinkedList is Empty..\n";
            return;
        }
        else if(head == tail)
        {
            free(head);
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            delete tail->next;

            tail->next = head;
            head->prev = tail;
        }
        iCount--;
    }
    void DeleteLast()
    {
        if((head == NULL) && (tail == NULL))
        {
            //cout<<"Linked list is Empty..\n";
            return;
        }
        else if(head == tail)
        {
            cout<<"Linked listcontains 1 node..\n";
            free(head);
            head = NULL;
            tail = NULL;
        }
        else
        {
            tail = tail->prev;
            free(tail->next);

        }
            tail->next = head;
            head->prev = tail;

            iCount--;
    }
    void DeleteAtPos(int ipos)
    {
        int i = 0;

       if((ipos < 1) || (ipos > iCount + 1))
       {
            cout<<"Invalid Position..\n";
       }
       if(ipos == 1)
       {
            DeleteFirst();
       }
       else if(ipos == iCount)
       {
            DeleteLast();
       }
       else
       {
            PNODE target = NULL;
            PNODE temp = NULL;
            temp = head;

            for(i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }
            target = temp->next;
            temp->next = target->next;
            target->next->prev = temp;
            free(target);

        iCount--;
     }
    }

    void Display()
    {
       //cout<<"Nodes of LinkedList are : \n";
       cout<<"\n";
        do{
            cout<<"|"<<head->data<<"|<=>";
            head = head->next;
        }while(head != tail->next);
        cout<<"NULL\n";
    }
    int Count()
    {   
        cout<<"Number of Nodes are :  ";
        return iCount;
        cout<<"\n";
    }
   


};

int main()
{
    DoublyCL dobj;
    int iRet = 0;

    dobj.InsertFirst(11);
    dobj.InsertFirst(21);
    dobj.InsertFirst(51);

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(211);

    dobj.Display();
    iRet = dobj.Count();
    cout<<iRet;

    dobj.InsertAtPos(75,3);
    dobj.Display();
    iRet = dobj.Count();
    cout<<iRet;

    dobj.DeleteFirst();
    dobj.Display();
    iRet = dobj.Count();
    cout<<iRet;

    dobj.DeleteLast();
    dobj.Display();
    iRet = dobj.Count();
    cout<<iRet;

    dobj.DeleteAtPos(4);
    dobj.Display();
    iRet = dobj.Count();
    cout<<iRet;
    return 0;
}