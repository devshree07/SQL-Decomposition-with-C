#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct customer                   //structure for customer
{
      int rno;
      int date,month,year;
      char fname[20],mname[20],gender[7];
      long int pincode;
      char add[20],contact[10];
};
typedef struct customer cust;              

struct order				//structure for order
{
	int  orderid;
	int date,month,year;
	int rno;
};
typedef struct order ord;

struct product				//structure for product
{
	int productid;
	char productname[15];
	int price;
	char uom[10];
};
typedef struct product prod;

struct orderdetails		//structure for order details 
{
	int orderid;
	int productid;
	int quantity;
};
typedef struct orderdetails det;

struct llist                   //declaring variables for link for customer
{
	cust data;
	struct llist *next;
};
typedef struct llist node;

struct llist_order 		//declaring variables for link for order
{
     ord data1;
     struct llist_order *next_order;
};
typedef struct llist_order node1;

struct llist_product			//declaring variables for link for product
{
	prod data2;
	struct llist_product *next_product;
};
typedef struct llist_product node2;

struct llist_details			//declaring variables for link for order details
{
	det data3;
	struct llist_details *next_details;
};
typedef struct llist_details node3;

node *insertatend(node*);
node1 *insert_in_order(node1*);
node2 *insert_in_product(node2*);
node3 *insert_in_details(node3*);

void store(node *);
void store_order(node1 *);
void store_product(node2 *);
void store_details(node3 *);


void read(char[]);
void query2(char[]);
void check(cust,char[]);
void query3(char[]);
int check1(cust,char[],char[]);
void query4(char[]);
void query5(char[]);
void net(char[]);
void fname(void);

void ocheck(ord,char[]);
void dcheck(det,char[]);
void pcheck(prod,char[]);

void ocheck1(ord,char[]);
void dcheck1(det,char[]);
void pcheck1(prod,char[]);

void main()
{
	int choice,position,i;
	char query[50],quer[60],que[70],q[80],qoi[40],ch,ch1,ch2,ch3;
	node *head=NULL;
	node1 *head_order=NULL;
	node2 *head_product=NULL;
	node3 *head_details=NULL;
	clrscr();


	while(1)
	{
		printf("\n1. Insert At End");
		printf("\n 2.store in file");
		printf("\n 3. Read from file(whole details):: query 1");
		printf("\n 4. query 2");
		printf("\n 5. query 3");
		printf("\n 6. query 4");
		printf("\n 7. query 5");
		printf("\n 0. exit");

		printf("\n enter your choice");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: do
				{
					head=insertatend(head);
					printf("\n Do you want to enter one more record(y for yes,n for no):");     // to continue adding data
					scanf("%c",&ch);

				}while(ch=='y'||ch=='Y');

				do
				{
					head_order=insert_in_order(head_order);
					printf("\n Do you want to enter one more record ( y for yes, n for no):");
					scanf("%c",&ch1);

				}while(ch1=='y'||ch1=='Y');

				do
				{
					head_product=insert_in_product(head_product);
					printf("\n Do you want to enter one more record:");
					scanf("%c",&ch2);

				}while(ch2=='y'||ch2=='Y');

				do
				{
					head_details=insert_in_details(head_details);
					printf("\n Do you want to enter one more record");
					scanf("%c",&ch3);

				}while(ch3=='y'||ch=='Y');
				break;

			case 2:

				store(head);
				store_order(head_order);
				store_product(head_product);
				store_details(head_details);
				break;

			case 3: printf("\n Enter your query");
				fflush(stdin);       //clear output buffer
				gets(query);
				read(query);
				break;

			case 4: printf("\n Enter your query2:");
				fflush(stdin);
				gets(quer);
				query2(quer);
				break;

			case 5: printf("\n Enter your query 3:");
				fflush(stdin);
				gets(que);
				query3(que);
				break;

			case 6: printf("\n Enter your query 4:");
				fflush(stdin);
				gets(q);
				query4(q);
				break;

			case 7: printf("\n enter your query 5:");
				fflush(stdin);
				gets(qoi);
				query5(qoi);
				break;

			case 0: exit(0);
				break;

			default : printf("\n Enter a valid choice");
		}
	}
	getch();
}

node *insertatend(node *first)
{
	node *curr=NULL;

	cust c;
	FILE *fp;                      // creating file pointer for customer file

	printf("\n Enter ID: ");
	scanf("\n %d",&c.rno);

	printf("\n Enter first name:");
	scanf("%s",c.fname);

	printf("\n Enter last name");
	scanf("%s",c.mname);

	printf("\n Enter gender:");
	scanf("%s",c.gender);

	printf("\n Enter date/month/year (dob):");
	scanf("%d %d %d",&c.date,&c.month,&c.year);

	printf("\n Enter contact number:");
	scanf("%s",c.contact);

	printf("\n Enter addrerss :");
	scanf("%s",c.add);

	printf("\n Enter pincode");
	scanf("%ld",&c.pincode);


	if(first==NULL)                       //allocation of memory and the
	{
		first = (node*) malloc(sizeof(node));
		first->data = c;
		first->next = NULL;            //declaing NULL for next
	}
	else
	{
		for(curr=first; curr->next != NULL; curr = curr->next);
		curr->next = (node*) malloc(sizeof(node));     //dynamic memory allocation for next
		curr = curr->next;
		curr->data = c;
		curr->next = NULL;
	}

	return first;
}

node1 *insert_in_order(node1 *first1)
{

	node1 *order=NULL;

	ord s;
	FILE *fp1;                 //declaring file pointer for order

	printf("\n Enter order ID: ");
	scanf("%d",&s.orderid);

	printf("\n Enter customer id:");
	scanf("%d",&s.rno);

	printf("\n Enter date/month/year for order:");
	scanf("%d %d %d",&s.date,&s.month,&s.year);

	if(first1==NULL)
	{
		first1 = (node1*) malloc(sizeof(node1));           //allocating memory dynamically
		first1->data1 = s;
		first1->next_order = NULL;
	}
	else
	{
		for(order=first1; order->next_order != NULL; order = order->next_order);
		order->next_order = (node1*) malloc(sizeof(node1));
		order = order->next_order;
		order->data1 = s;
		order->next_order = NULL;
	}


	return first1;
}

node2 *insert_in_product(node2 *first2)
{


       node2 *product=NULL;

	FILE *fp2;                             //declaring file pointer for product file
	prod p;


	printf("\n Enter product  ID: ");
	scanf("%d",&p.productid);

	printf("\n Enter product name:");
	scanf("%s",&p.productname);

	printf("\n Enter price:");
	scanf("%d",&p.price);

	printf("\n Enter unit of measiurement :");
	scanf("%s",p.uom);


	if(first2==NULL)
	{
		first2 = (node2*) malloc(sizeof(node2));
		first2->data2 = p;                          //
		first2->next_product = NULL;
	}
	else
	{
		for(product=first2; product->next_product!= NULL; product = product->next_product);
		product->next_product = (node2*) malloc(sizeof(node2));
		product = product->next_product;
		product->data2 = p;
		product->next_product = NULL;
	}

	return first2;
}

node3 *insert_in_details(node3 *first3)
{

	node3 *details=NULL;
	FILE *fp3;
	det d;

	printf("\n Enter order ID: ");
	scanf("%d",&d.orderid);

	printf("\n Enter product id:");
	scanf("%d",&d.productid);

	printf("\n Enter quantity:");
	scanf("%d",&d.quantity);


	if(first3==NULL)
	{
		first3 = (node3*) malloc(sizeof(node3));
		first3->data3 = d;
		first3->next_details= NULL;
	}
	else
	{
		for(details=first3; details->next_details != NULL; details = details->next_details);
		details->next_details = (node3*) malloc(sizeof(node3));
		details = details->next_details;
		details->data3 = d;
		details->next_details = NULL;
	}


	return first3;
}

void store(node *first)
{

	 node *curr = NULL;
	 FILE *fp;
	 fp=fopen("muskan.txt","a");                 //opening file

	 for(curr=first; curr != NULL; curr = curr->next)
	 {
		 fwrite(&curr->data,sizeof(cust), 1, fp);     //storing data with memory

	 }

	 fclose(fp);
}

void store_order(node1 *first1)
{

	 node1 *order = NULL;
	 FILE *fp1;
	 fp1=fopen("order.txt","a");

	 for(order=first1; order != NULL; order = order->next_order)
	 {
		 fwrite(&order->data1,sizeof(ord), 1, fp1);

	 }

	 fclose(fp1);
}

void store_product(node2 *first2)
{

	 node2 *product = NULL;
	 FILE *fp2;
	 fp2=fopen("product.txt","a");

	 for(product=first2; product != NULL; product = product->next_product)
	 {
		 fwrite(&product->data2,sizeof(prod), 1, fp2);

	 }

	 fclose(fp2);
}

void store_details(node3 *first3)
{

	 node3 *details = NULL;
	 FILE *fp3;
	 fp3=fopen("details.txt","a");

	 for(details=first3; details != NULL; details = details->next_details)
	 {
		 fwrite(&details->data3,sizeof(det), 1, fp3);

	 }

	 fclose(fp3);
}


void read(char str[50])
{
	cust c;
	ord o;                                //typedef struct order ord
	det d;                                //typedef struct OrderDetails det
	prod p;                               //typedef struct product prod
	FILE *fp,*fp1,*fp2,*fp3;

	int i;
	int j=0,cnt=0;
	char split[10][10];

	for(i=0;i<=(strlen(str));i++)                            //loop till end of line
	{
	    if(str[i]==' ' || str[i]=='\0')
	    {
	     split[cnt][j]='\0';
			cnt++;
			j=0;
	    }
	    else
	    {
		split[cnt][j]=str[i];
			j++;
	    }
	}

	for(i=0;i<cnt;i++)                      //This function will change all the characters of query to lower case letters
	strlwr(split[i]);                   //If you write 'SELECT' in query it will change it to 'select' which is easy for programmer to compare strings

    if(!strcmp(split[0],"select"))          //comparing query line by line
    {
	if(!strcmp(split[2],"from"))
	{
	    if(!strcmp(split[3],"customer"))
	    {
		fp=fopen("muskan.txt","r");         //opening file as per query
		while(fread(&c,sizeof(cust),1,fp))
		{
		    printf("\n ID : %d",c.rno);

		    printf("\n first name: %s",c.fname);

		    printf("\n last name : %s",c.mname);

		    printf("\n  gender: %s",c.gender);

		    printf("\n  date/month/year (dob): %d %d %d",c.date,c.month,c.year);

		    printf("\n contact number: %s",c.contact);

		    printf("\n  addrerss : %s",c.add);

		    printf("\n  pincode : %ld",c.pincode);

		}
		fclose(fp);
	    }
	    else if(!strcmp(split[3],"order"))
	    {
		fp1=fopen("order.txt","r");
		while(fread(&o,sizeof(ord),1,fp1))
		{
		    printf("\n Order id : %d",o.orderid);

		    printf("\n order date : %d/%d/%d",o.date,o.month,o.year);

		    printf("\n customerid : %d",o.rno);

		}
		fclose(fp1);
	    }
	    else if(!strcmp(split[3],"orderdetails"))
	    {

		fp2=fopen("orderdetails.txt","r");
		while(fread(&d,sizeof(det),1,fp2))
		{

		    printf("\n Order Id : %d",d.orderid);

		    printf("\n Product Id : %d",d.productid);

		    printf("\n quantity : %d",d.quantity);

		}
		fclose(fp2);
	    }
	    else if(!strcmp(split[3],"product"))          //comparing
	    {

		fp3=fopen("product.txt","r");
		while(fread(&p,sizeof(prod),1,fp3))
		{
		    printf("\n Product Id: %d",p.productid);

		    printf("\n Product name: %s",p.productname);

		    printf("\n Product Price: %d",p.price);

		    printf("\n Product Unit Of Measurement : %s",p.uom);

		}
		fclose(fp3);
	    }
	    else
		 printf("\n Wrong Query");
	}
    }

}

void query2(char str[60])
{
	cust c;
	ord o;                                //typedef struct order ord
	det d;                                //typedef struct OrderDetails det
	prod p;                               //typedef struct product prod
	FILE *fp,*fp1,*fp2,*fp3;
	int i,j=0,cnt=0,count=1;
	char split[10][10];

	for(i=0;i<=strlen(str);i++)
	{
		if(str[i]==' '||str[i]=='\0'||str[i]==',')
		{
			split[cnt][j]='\0';
			cnt++;
			j=0;
		}
		else
		{
			split[cnt][j]=str[i];
			j++;
		}
		if(str[i]==',')
		{
			count++;
		}
	}

	if(!strcmp(split[0],"select"))
	{
		if(!strcmp(split[cnt-2],"from"))
		{
			if(!strcmp(split[cnt-1],"customer"))
			{
				fp=fopen("muskan.txt","r");
				while(fread(&c,sizeof(c),1,fp))
				{

					for(i=1;i<=count;i++)
					{
						check(c,split[i]);
						printf("\n");
					}

				}
				fclose(fp);
			}
			else if(!strcmp(split[cnt-1],"order"))
		{
		fp1=fopen("order.txt","r");
		while(fread(&o,sizeof(o),1,fp1))
		{
		    for(i=1;i<=count;i++)
		    {
			ocheck(o,split[i]);
			printf("\n");
		    }
		}
		fclose(fp1);
	    }
	    else if(!strcmp(split[cnt-1],"orderdetails"))
	    {

		fp2=fopen("orderdetails.txt","r");
		while(fread(&d,sizeof(d),1,fp2))
		{
		    for(i=1;i<=count;i++)
		    {
			dcheck(d,split[i]);
			printf("\n");
		    }

		}
		fclose(fp2);
	    }
	    else if(!strcmp(split[cnt-1],"product"))
	    {
		fp3=fopen("product.txt","r");
		while(fread(&p,sizeof(p),1,fp3))
		{
		    for(i=1;i<=count;i++)
		    {
			pcheck(p,split[i]);
			printf("\n");

		    }

		}
		fclose(fp3);

	    }
	    else
		printf("\n wrong query");

		}
	}
}

void check(cust c,char str[20])
{
	if(!strcmp(str,"fname"))           //compaing field entered
	    printf("%s",c.fname);

	else if(!strcmp(str,"mname"))
	    printf("%s",c.mname);

	else if(!strcmp(str,"gender"))
	    printf("%s",c.gender);

	else if(!strcmp(str,"pincode"))
	    printf("%ld",c.pincode);

	else if(!strcmp(str,"contact"))
	   printf("s",c.contact);

	else if(!strcmp(str,"add"))
	  printf("%s",c.add);

	else if(!strcmp(str,"rno"))
	   printf("%d",c.rno);

	else if(!strcmp(str,"dob"))
	   printf("%d %d %d",c.date,c.month,c.year);

	else
	printf("\n wrong query");
}

void ocheck(ord o,char str[40])
{
	if(!strcmp(str,"orderid"))                    //comparing and printing data as per asked
	printf("%d",o.orderid);

	else if(!strcmp(str,"orderdate"))
	printf("%d %d %d",o.date,o.month,o.year);

	else if(!strcmp(str,"rno"))
	printf("%d",o.rno);

	else
	printf("\n wrong query");
}

void dcheck(det d,char str[40])
{
	if(!strcmp(str,"orderid"))
	printf("%d",d.orderid);

	else if(!strcmp(str,"productid"))
	printf("%d",d.productid);

	else if(!strcmp(str,"quantity"))
	printf("%d",d.quantity);

	else
	printf("\n wrong query");
}

void pcheck(prod p,char str[40])
{
	if(!strcmp(str,"productid"))
	printf("%d",p.productid);

	else if(!strcmp(str,"productname"))
	printf("%s",p.productname);

	else if(!strcmp(str,"price"))
	printf("%d",p.price);

	else if(!strcmp(str,"uom"))
	printf("%d",p.uom);

	else
	printf("\n wrong query");
}


void query3(char str[70])
{
	FILE *fp;
	cust c;
	ord o;
	det d;
	prod p;
	int i,j=0,cnt=0,count=1,z,t;
	char split[20][20];

	for(i=0;i<=strlen(str);i++)
	{
		if(str[i]==' '|| str[i]==',' || str[i]=='\0')
		{
			split[cnt][j]='\0';
			cnt++;
			j=0;
		}
		else
		{
			split[cnt][j]=str[i];
			j++;
		}
		if(str[i]==',')             //counting words by ","
		{
			count++;
		}
	}

	if(!strcmp(split[0],"select"))
	{
		if(!strcmp(split[count+1],"from"))
		{
	    if(!strcmp(split[count+3],"where"))
			{
					if(!strcmp(split[count+7],"and"))
					{
					    if(!strcmp(split[count+2],"customer"))
			{
			    fp=fopen("muskan.txt","r");
			    while(fread(&c,sizeof(c),1,fp))
			    {
							z=check1(c,split[count+4],split[count+6]);
							t=check1(c,split[count+8],split[count+10]);
							if((z==1) && (t==1))                   //if read value matches checking character
							{
								for(i=1;i<=count;i++)
								{
								   check(c,split[i]);
								}
								//check(c,split[1]);
								printf("\n");
							}
							z=0;
							t=0;
			    }
			    fclose(fp);
			}
		       /*	else if(!strcmp(split[count+2],"order"))
			{

			    fp1=fopen("order.txt","r");
			    while(fread(&o,sizeof(o),1,fp1))
			    {
							z=ocheck1(o,split[count+4],split[count+6]);
							t=ocheck1(o,split[count+8],split[count+10]);
							if((z==1) && (t==1))
							{
								for(i=1;i<=count;i++)
				{
				   check(o,split[i]);
				}
								printf("\n");
							}
							z=0;
							t=0;
			    }

			}
			else if(!strcmp(split[count+2],"orderdetails"))
			{
			    fp2=fopen("orderdetails.txt","r");
			    while(fread(d,sizeof(d),1,fp2))
			    {
				z=dcheck1(d,split[count+4],split[count+6]);
				t=dcheck1(d,split[count+8],split[count+10]);
				if((z==1) && (t==1))
				{
				    for(i=1;i<=count;i++)
				    {
					check(d,split[i]);
				    }
				    printf("\n");
				}
				z=0;
				t=0;

			    }
			}
			else if(!strcmp("product.txt","r"))
			{
				fp3=fopen("product.txt","r")
				while(fread(&p,sizeof(p),1,fp3))
				{
				    z=pcheck1(p,split[count+4],split[count+6]);
				    t=pcheck1(p,split[count+8],split[count+10]);
				    if((z==1) && (t==1))
				    {
					for(i=1;i<=count;i++)
					{
					    check(p,split[i]);
					}
					printf("\n");
				    }
				    z=0;
				    t=0;
				}

			} */
			else
			    printf("\n Wrong query");
			}
		}
	}
}
}
int check1(cust c,char str[20],char s7[20])
{
	int count=0;

	if(!strcmp(str,"fname"))
	{
		if(!strcmp(c.fname,s7))     //if field matches count increment
		{
		count=1;
		}
	}

	else if(!strcmp(str,"mname"))
	    {
		if(!strcmp(c.mname,s7))
		    count=1;
	    }

	else if(!strcmp(str,"gender"))
	    {
		if(!strcmp(c.gender,s7))
		     count=1;
	    }


	/*else if(!strcmp(str,"pincode"))
	{
		if(!strcmp(c.pincode,s7))
		      count=1;
	 }*/

	else if(!strcmp(str,"contact"))
	   {
	     if(!strcmp(c.contact,s7))
		  count=1;
	   }

	else if(!strcmp(str,"add"))
	    {
	       if(!strcmp(c.add,s7))
		    count=1;
	    }

	//else if(!strcmp(str,"rno"))
	  //   {
	    //	if(c.rno==s7)
	      //	     count=1;
	    // }
	     return count;

}

/*int pcheck1(prod p,char str[20],char s7[20])
{
	int count=0;

	if(!strcmp(str,"productId"))
	{
		if(!strcmp(p.productid,s7))
		       count=1;
	}

	else if(!strcmp(str,"productname")
	{
		if(!strcmp(p.productname,s7))
		       count=1;
	}
	else if(!strcmp(str,"price"))
	{
		if(!strcmp(p.price,s7))
		      count=1;
	}
	 else if(!strcmp(str,"uom"))
	 {
		if(!strcmp(p.uom,s7))
		      count=1;
	 }
	 else
	    printf("\n wrong choice");

	 return count;
} */

/*int dcheck1(det d,char str[20],char s7[20])
{
	int count=0;

	if(!strcmp(str,"orderid"))
	{
		if(!strcmp(d.orderid,s7))
		       count=1;
	}
	else if(!strcmp(str,"productid"))
	{
		if(!strcmp(d.productid,s7))
		      count=1;
	}
	else if(!strcmp(str,"quantity"))
	{
		if(!strcmp(d.quantity,s7))
		      count=1;
	}
	else
	   printf("\n wrong query");

	   return count;
} */

void query4(char str[80])
{
	cust c;
	FILE *fp;
	int i,j=0,cnt=0,count=1,n,z,t;
	char split[20][20];

	for(i=0;i<=strlen(str);i++)
	{
		if(str[i]==' '||str[i]==','||str[i]=='\0'||str[i]=='.'||str[i]==':') //counting words as per the parameters
		{
			split[cnt][j]='\0';
			cnt++;
			j=0;
		}
		else
		{
			split[cnt][j]=str[i];
			j++;
		}

		if(str[i]==',')
		     count++;

	}
	z=count*2+1;
	t=count*2-1;
	//y=count*2+2
	n=1;

	if(!strcmp(split[0],"select"))
	{
		 if(!strcmp(split[z],"from"))       //opening file as asked
		 {
			fp=fopen("muskan.txt","r");
			while(fread(&c,sizeof(c),1,fp))
			{
				while(n<=t)
				{
					if(!strcmp(split[n],"customer"))
					{
							check(c,split[n+1]);
							printf("\n");

					}
					n=n+2;
				}
				n=1;
		       }
		 }
	}
	 /*else if(!strcmp(split[n],"order"))
	    {
	       fp1=fopen("order.txt","r");
	       while(fread(&o,sizeof(o),1,fp1))
	       {
		   while(n<=t)
		   {
			    check(o,split[n+1]);
			    printf("\n");
			    n=n+2;
		   }
	       }
	    }
	    else if(!strcmp(split[n],"orderdetails"))
	    {
		fp2=fopen("orderdetails.txt","r");
		while(fread(&d,sizeof(d),1,fp2))
		{
		    while(n<=t)
		    {
			    check(d,split[n+1]);
			    printf("\n");
			    n=n+2;

		    }
		}

	    }
	    else if(!strcmp(split[n],"product"))
	    {
		fp3=fopen("product.txt","r");
		while(fread(&p,sizeof(p),1,fp3))
		{
		    while(n<=t)
		    {
			    check(p,split[n+1]);
			    printf("\n");
			    n=n+2;

		    }
		}
	    }*/
	    else
		printf("\n wrong query");


}

void query5(char str[40])
{
	cust c,s[2],temp;
	char split[20][20];
	int i=0,j,cnt=0,count=1,z=6;

	for(i=0;i<=strlen(str);i++)
	{
		if(str[i]==' '||str[i]=='\0'||str[i]==',')
		{
			split[cnt][j]='\0';
			cnt++;
			j=0;
		}
		else
		{
			split[cnt][j]=str[i];
			j++;
		}
		if(str[i]==',')
		     count++;
	}

	if(!strcmp(split[0],"select"))
	{
		printf("\n hi0");
		if(!strcmp(split[1],"*"))       //2nd word comparision as per query entered
		{
			//printf("\n hi1");
			if(!strcmp(split[2],"from"))         //3rd word
			{
				//printf("\n hi2");
				if(!strcmp(split[4],"order"))
				{
					//printf("\n hi3");
					if(!strcmp(split[5],"by"))
					{
						//printf("\n hi4");
						if(!strcmp(split[3],"customer"))
						{
						     //printf("\n hi5");
						     for(i=0;i<count;i++)
						     {
							net(split[z+i]);
						     }
						}
					}
				}
			}
		}
	}
}
void net(char s[20])
{
	if(!strcmp(s,"fname"))
		fname();

       /*	else if(!strcmp(str,"mname"))


	else if(!strcmp(str,"gender"))


	else if(!strcmp(str,"pincode"))


	else if(!strcmp(str,"contact"))


	else if(!strcmp(str,"add"))


	else if(!strcmp(str,"rno"))


	else if(!strcmp(str,"dob"))*/

	else
	printf("\n wrong query");
}

void fname()
{
	FILE *fp;
	cust c,s[2],temp;
	int i=0,n=2,j;
	int sorted=0;

	fp=fopen("muskan.txt","r");

	while(fread(&c,sizeof(c),1,fp))
	{
		s[i]=c;                            //reading each character
		i++;
	}
	printf("\n hello");

	for(i=0;i<n-1 && sorted==0;i++)
	{  sorted=1;
		for(j=0;j<n-i-1;j++)
		{
			if(strcmp(s[j].fname,s[j+1].fname)>0)
			{
				temp=s[j];             //through 3rd variable and sorting data
				s[j]=s[j+1];
				s[j+1]=temp;
				sorted=0;
			}
		}
	}

	printf("\n details after sorting are :");
	for(i=0;i<n;i++)
	{
		printf("\n customerid: %d",s[i].rno);     //printing data
		printf("\n fname : %s",s[i].fname);
		printf("\n mname : %s",s[i].mname);
		printf("\n pincode: %ld",s[i].pincode);
	}
	fclose(fp);
}