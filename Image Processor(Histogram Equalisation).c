/*******************DECLARATION OF THE REQUIRED HEADER FILES***************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
/****************STRUCTURE OF THE INPUT LINKED LIST***********************/
struct node
{
    int data;
    struct node *link;
};

/****************STRUCTURE OF THE OUTPUT LINKED LIST******************/
struct node1
{
    int data1;
    int data2;
    int data3;
    double data4;
    int data5;
    int data6;
    struct node1 *link1;
};
/***********************GLOBAL DECLARATION OF VARIABLES**********************/
  struct node *first=NULL;
  struct node1 *first1=NULL;
  int cnt=0,n,i,num=0;
  float last=0,max;
/******************DECLARATION OF USER DEFINED FUNCTIONS************************/
  void ins(int);
  float find_max();
  void occur(int );
  void freq(int , int);
  void display();
  float cfreq();
  void deci(float ,float );
  void round_off();
  void new_freq();
  void histogram(float );
   void histogram1(float );
/************************MAIN FUNCTION***********************************/
void main()
{
      int op;
      float max;
         printf("\nENTER THE NUMBER OF PIXELS");
         scanf("%d",&n);
         printf("\nENTER THE INTENSITY VALUES BETWEEN THE RANGE 0 TO 255");
         ins(n);
         max=find_max();
         occur(max);
         histogram(max);
         freq(i,cnt);
         last=cfreq();
         deci(last,max);
         round_off();
         new_freq();
         display();
         histogram1(max);
}
/***************CREATES A LINKED LIST AND INSERTS THE INPUT INTO THE LINKED LIST****************/
void ins(int n)
  {
      struct node *p,*t;
      int i;
      for(i=0;i<n;i++)
      {
          p=(struct node *)malloc(sizeof(struct node));

          scanf("%d",&p->data);
          if(p->data>255)
          {
          printf("\nINVALID INPUT(THE RANGE OF VALID INPUT IS 0-255)");
          }
          else
        {
          if(first==NULL)
          {
              first=p;
              p->link=NULL;
          }
          else
          {
               t=first;
             while(t->link!=NULL)
            {
              t=t->link;
            }
              t->link=p;
              p->link=NULL;
          }
        }
      }
  }
/****************************FINDS THE MAXIMUM VALUE IN THE INPUT***********************************/
 float find_max()
{
    struct node* temp=first;
    float max_value= temp->data;
  if(temp!=NULL)
  {
       while(temp!=NULL)
      {
        if(max_value < temp->data)
        {
           max_value=temp->data;
        }
          temp=temp->link;
      }
       printf("\nTHE MAXIMUM VALUE IS : %f",max_value);
  }
  return max_value;
}
/*************************FINDS THE FREQUENCY OF EACH ELEMENT****************************/
void occur(int max)
{
     struct node *temp=first;
     int i,cnt=0;
      for(i=0;i<=max;i++)
      {
          while(temp!=NULL)
          {
             if(temp->data==i)
             {
               cnt++;
               temp=temp->link;
             }
             else
             {
               temp=temp->link;
             }
          }
              freq(i,cnt);
              num++;
              temp=first;
              cnt=0;
     }
}
/*************CREATES SECOND LINKED LIST TO HOLD ALL THE VALUES OF THE HISTOGRAM TABLE***********/
void freq(int i, int cnt)
{
    struct node1 *b,*temp1=first1;
    int j;
    b=(struct node1 *)malloc(sizeof(struct node1));
        b->data1=i;
        b->data2=cnt;
        if(first1==NULL)
        {
            first1=b;
            b->link1=NULL;
        }
        else
        {
            while(temp1->link1!=NULL)
          {
            temp1=temp1->link1;

          }
            temp1->link1=b;
            b->link1=NULL;
        }
}
/**********************DISPLAYS THE GRAPH OF THE INTENSITY VALUES BEFORE HISTOGRAM EQUALISATION***************************/
void histogram(float max)
{
    struct node1 *temp1=first1;
    int j;
        printf("\n\n\n\n                                GRAPH BEFORE HISTOGRAM EQUALISATION");
        printf("\n                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n\n%s%20s%25s\n","INTENSITY","FREQUENCY","HISTOGRAM");
    for(i=0;i<=max;i++)
    {
        printf("\n    %d                     ",temp1->data1);
        printf("%d                  ",temp1->data2);
        for(j=0;j<(temp1->data2);j++)
        {
             printf("*");
        }
        printf("\n");
      temp1=temp1->link1;
    }
}
/***********************CALCULATES CUMULATIVE FREQUENCY***********************/
float cfreq()
{
    int i, j;
    float cf=0,la=0;
    struct node1 *temp1;
  for(i=0;i<num;i++)
  {
     temp1=first1;
     for(j=0;j<=i;j++)
     {
         cf=cf+temp1->data2;

         if(j==i)
        {
           temp1->data3=cf;
           la=temp1->data3;
        }
         else
         {
         temp1=temp1->link1;
         }
     }
        if(i==num)
          la=cf;
        else
          cf=0;
 }
         printf("\n\nTHE TOTAL NUMBER OF PIXELS =%f",la);
         return la;
}
/********************CALCULATES NEW PIXEL VALUES***********************/
void deci(float last,float max)
{
    double l;
    struct node1 *temp1=first1;
 while(temp1!=NULL)
   {
    temp1->data4= ((temp1->data3)/last)*max;
    temp1=temp1->link1;
   }
}
/****************NEW PIXEL VALUES ARE ROUNDED OFF TO THE NEAREST INTEGER*****************/
void round_off()
{
    struct node1 *temp1=first1;
    while(temp1!=NULL)
    {
        temp1->data5=round(temp1->data4);
        temp1=temp1->link1;
    }
}
/********************CALCULATES NEW FREQUENY VALUES***********************/
void new_freq()
{
    struct node1 *temp1=first1,*prev1;
      prev1=temp1;
        temp1=temp1->link1;
    while(temp1!=NULL)
    {
        if((temp1->data5)!=(prev1->data5))
        {
            if(prev1==first1)
            {
                temp1->data6=temp1->data2;
                prev1->data6=prev1->data2;
                prev1=temp1;
                temp1=temp1->link1;
            }
            else
            {
                temp1->data6=temp1->data2;
                prev1=temp1;
                temp1=temp1->link1;
            }
        }
        else
        {
           if((prev1->data5)>(prev1->data1))
           {
               temp1->data6=((temp1->data2)+(prev1->data2));
               prev1->data6=0;
           }
           else
            {
                prev1->data6=((prev1->data2)+(temp1->data2));
                temp1->data6=0;

            }
                prev1=temp1;
                temp1=temp1->link1;
        }
    }
}
/***************************DISPLAYS THE HISTOGRAM EQUALISATION TABLE***************************************/
void display()
{
     struct node1 *temp1=first1;
     if(first1!=NULL)
     {
        printf("\n\n\n\n                                HIST0GRAM EQUALIZATION TABLE");
        printf("\n                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
         printf("\n\nPIXEL VALUE    FREQUENCY    CUMULATIVE FREQUENCY    NEW PIXEL VALUE    ROUNDED VALUE    NEW FREQUENCY");
        while(temp1->link1!=NULL)
         {
            printf("\n    %d              %d                  %d                %f              %d               %d",temp1->data1,temp1->data2,temp1->data3,temp1->data4,temp1->data5,temp1->data6);
            temp1=temp1->link1;
         }
     }
}
/**********************DISPLAYS THE GRAPH OF THE INTENSITY VALUES AFTER HISTOGRAM EQUALISATION***************************/
void histogram1(float max)
{
    struct node1 *temp1=first1;
    int j;
        printf("\n\n\n\n                                GRAPH AFTER HIST0GRAM EQUALIZATION ");
        printf("\n                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n\n%s%20s%25s\n","INTENSITY","FREQUENCY","HISTOGRAM");
    for(i=0;i<=max;i++)
    {
        printf("\n    %d                     ",temp1->data1);
        printf("%d                  ",temp1->data6);
        for(j=0;j<(temp1->data6);j++)
        {
             printf("*");
        }
        printf("\n");
      temp1=temp1->link1;
    }
}















