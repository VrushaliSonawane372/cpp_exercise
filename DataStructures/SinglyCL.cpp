#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;

};

typedef struct node NODE; 
typedef struct node *PNODE;

class SinglyCL
{
    public:

    int iCount;
    PNODE head;
    PNODE tail;

    SinglyCL()
    {
        head = NULL;
        tail = NULL;
        iCount = 0;
    }

    void InsertFirst(int no)
    {
        PNODE newn = NULL;
        newn = new NODE;

        newn->next = NULL;
        newn->data = no;

        if((head == NULL) && (tail == NULL))
        {
            head = newn;
            tail = newn;
        }
        else
        {
            newn->next = head;
            head = newn;
        }
         tail->next = head;
         iCount++;
    }

    void InsertLast(int no)
    {
        PNODE newn = NULL;
        newn = new NODE;

        newn->next = NULL;
        newn->data = no;

        if((head == NULL) && (tail == NULL))
        {
            head = newn;
            tail = newn;
        }
        else
        {
            tail->next = newn;
            tail = newn;

        }
         tail->next = head;
         iCount++;
    }
    void InsertAtPos(int no,int ipos)
    {
        int i = 0;
        if((ipos < 1) && (ipos > iCount))
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
            PNODE temp = NULL;
            PNODE newn = NULL;
            newn = new NODE;
            newn->next = NULL;
            newn->data = no;

            temp = head;
            for(i = 1; i < ipos - 1; i++)
            {
                temp = temp -> next;
            }
            newn->next = temp->next;
            temp->next = newn;
            iCount++;
        }
    }
    void DeleteFirst()
    {
        PNODE temp = NULL;
          cout<<"Delete First element..\n";
        if((head == NULL) && (tail == NULL))
        {
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
            temp = head;

            head = head->next;
            free(temp);
            tail->next = head;
        }
        iCount--;
    }
    void DeleteLast()
    {
        PNODE temp = NULL;
        cout<<"Delete Last element..\n";
        if((head == NULL) && (tail == NULL))
        {
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
           temp = head;
           while(temp->next != tail)
           {
             temp = temp->next;
           }
           free(temp->next);
           tail = temp;
           tail -> next = head;
        }
        iCount--;
    }
    void DeleteAtPos(int ipos)
    {
        int i = 0;
        if((ipos < 1) && (ipos > iCount))
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
            PNODE temp = NULL;
            PNODE target = NULL;
            temp = head;
            for(i = 1; i < ipos - 1; i++)
            {
                temp = temp -> next;
            }
            target = temp->next;
            temp->next = target->next;
            delete target;
            

            iCount--;
        }
    }
    void Display()
    {
        if((head == NULL) && (tail == NULL))
        {
            cout<<"LinkedList is Empty..\n";
        }
        if(head == tail)
        {
            cout<<"Linked List Contains one node..\n";
        }
        do
        {
            cout<<"| "<<head->data<<"|->";
            head = head->next;
        }while(head != tail->next);
        cout<<"\n";
    }
    int Count()
    {
        return iCount;  
        cout<<"\n"; 
    }
     

};
int main()
{
    SinglyCL sobj;
    int iRet = 0;

    sobj.InsertFirst(1);
    sobj.InsertFirst(11);
    sobj.InsertFirst(21);
    sobj.InsertFirst(51);
    sobj.InsertFirst(0);
    //sobj.Display();

    sobj.InsertLast(501);
    //sobj.Display();
    
    sobj.InsertAtPos(75,2);
    sobj.Display();                 //0 75 51 21 11 1 501 
    iRet = sobj.Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";

    sobj.DeleteFirst();                 // 75 51 21 11 1 501 
    sobj.Display();        

     sobj.DeleteLast();          // 75 51 21 11 1 
    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of Nodes is : "<<iRet<<"\n";

    sobj.DeleteAtPos(3);            // 75 51  11 1
    sobj.Display();         

    iRet = sobj.Count();
    cout<<"Number of Nodes is : "<<iRet<<"\n";

    return 0;
}