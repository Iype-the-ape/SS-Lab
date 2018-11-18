//Two Level File Organisation

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct directory
{	char dname[20],fname[30][20];
	int fcount;
}d[20];

int n=0;

void createdir()
{	printf("\nEnter directory name:");
	scanf("%s",d[n].dname);
	n++;
}

void create()
{	char name[20];
	int fl=0,i;
	printf("\nEnter directory name:");
	scanf("%s",name);
	for(i=0;i<n;i++)
	{	if(strcmp(d[i].dname,name)==0)
		{	printf("\nEnter name of file:");
			scanf("%s",d[i].fname[d[i].fcount]);
			d[i].fcount++;
			fl=1;
		}
	}
	if(fl==0)
		printf("\nDirectory not found\n");
}

void search()
{	int i,j,fl=0;
	char item[20];
	printf("\nEnter name of file to be searched:");
	scanf("%s",item);
	for(i=0;i<d[0].fcount;i++)
	{	if(strcmp(item,d[0].fname[i])==0)
                        {       printf("\nFile found  in root directory %s",d[0].dname);
				fl=1;
                                break;
			}
	}
	if(fl==0)
	{	for(i=1;i<n;i++)
		{	for(j=0;j<d[i].fcount;j++)
			{	if(strcmp(item,d[i].fname[j])==0)
				{	printf("\nFile found in %s subdirectory of the root directory %s",d[i].dname,d[0].dname);
					fl=1;
					break;
				}
			}
		}
	}
	if(fl==0)
		printf("\nFile not found");
}

void del()
{	int i,j,fl=0,k;
	char item[20];
	printf("\nEnter name of file to be deleted:");
	scanf("%s",item);
	for(i=0;i<n;i++)
	{	for(j=0;j<d[i].fcount;j++)
		{	if(strcmp(item,d[i].fname[j])==0)
			{	for(k=j;k<d[i].fcount-1;k++)
					strcpy(d[i].fname[k],d[i].fname[k+1]);
				printf("\nFile Deleted");
				d[i].fcount--;
				fl=1;
				break;
			}
		}
	}
	if(fl==0)
		printf("\nFile not found");
}

void disp()
{	int i,j;
	printf("\nROOT DIRECTORY:%s\n",d[0].dname);
        if(d[0].fcount!=0)
        {       printf("\nFiles");
                for(i=0;i<d[0].fcount;i++)
                        printf("\n%s",d[0].fname[i]);
        }
	printf("\n\nSubdirectories\t\tFiles");
	for(i=1;i<n;i++)
	{	printf("\n%s\t\t\t",d[i].dname);
		for(j=0;j<d[i].fcount;j++)
			printf("%s     ",d[i].fname[j]);
	}
}

void main()
{	int ch,i;
	printf("\nEnter directory name:");
	scanf("%s",d[0].dname);
	d[0].fcount=0;
	n++;
	while(1)
	{	printf("\n\nMENU\n1)Create Directory\n2)Create File\n3)Search File\n4)Delete File\n5)Display Files\n6)Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		if(ch==1)
			createdir();
		else if(ch==2)
			create();
		else if(ch==3)
			search();
		else if(ch==4)
			del();
		else if(ch==5)
			disp();
		else if(ch==6)
			exit(0);
		else
			printf("\nInvalid Option");
	}
}
