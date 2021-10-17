#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp;

struct library
{
    char bk_name[30];
    char author[30];
    int pages;
    float price;
}l[100];
int INDEX;
void file_read(){ // 1st call
	fp = fopen("input.txt", "r");
	INDEX = 0;
	while(fscanf(fp, "%s %s %d %f", l[INDEX].bk_name, l[INDEX].author, &l[INDEX].pages, &l[INDEX].price) != EOF){
		++INDEX;
	}
}
void file_write(){ // 2nd call
	fp = fopen("input.txt", "w");
	for(int i = 0; i < INDEX; i++){
		fprintf(fp,"%s %s %d %f\n", l[INDEX].bk_name, l[INDEX].author, l[INDEX].pages, l[INDEX].price);
	}
}

int main()
{
    char ar_nm[30],bk_nm[30], ind;
    int i,j, keepcount;
    i=j=keepcount = 0;
    printf(".....................................Daffodil International University.................................................\t");
    printf(".....................................Library Management.................................................\t");
    printf("............................................Welcome.....................................................\t");
    file_read();
    while(j!=6)
    {
        printf("\n\n1. Add book information\n2. Display book information\n");
        printf("3. List all books of given author\n");
        printf("4. List the title of specified book\n");
        printf("5. List the count of books in the library\n");
        printf("6. Delete\n");
        printf("7. Exit\n");

        printf ("\n\nEnter one of the above : ");
        fflush(stdin);

        scanf("%d",&j);

        switch (j)
        {
        /* Add book */
        case 1:
            fp = fopen("input.txt", "a");


            printf ("Enter book name = ");
            fflush(stdin);

            scanf ("%s",l[i].bk_name);

            printf ("Enter author name = ");
            fflush(stdin);

            scanf ("%s",l[i].author);

            printf ("Enter pages = ");
            fflush(stdin);

            scanf ("%d",&l[i].pages);

            printf ("Enter price = ");
            fflush(stdin);

            scanf ("%f",&l[i].price);
            keepcount++;
            fprintf(fp,"%s %s %d %.2f\n",l[i].bk_name, l[i].author, l[i].pages, l[i].price);
            fclose(fp);


            break;
        case 2:
            printf("you have entered the following information\n");
            for(i=0; i<keepcount; i++)
            {
                printf ("book name = %s",l[i].bk_name);

                printf ("\t author name = %s",l[i].author);

                printf ("\t  pages = %d",l[i].pages);

                printf ("\t  price = %.2f",l[i].price);
            }
            break;

        case 3:
            printf ("Enter author name : ");
            scanf ("%s",ar_nm);
            for (i=0; i<keepcount; i++)
            {
                if (strcmp(ar_nm, l[i].author) == 0)
                    printf ("%s %s %d %.2f",l[i].bk_name,l[i].author,l[i].pages,l[i].price);
            }
            break;

        case 4:
            printf ("Enter book name : ");
            scanf ("%s",bk_nm);
            for (i=0; i<keepcount; i++)
            {
                if (strcmp(bk_nm, l[i].bk_name) == 0)
                    printf ("%s \t %s \t %d \t %.2f",l[i].bk_name,l[i].author,l[i].pages,l[i].price);
            }
            break;

        case 5:
            printf("\n No of books in library : %d", keepcount);
            break;
        case 7:
            exit (0);
        case 6:
        	file_read();
        	printf("Enter book name: ");
        	scanf("%s", bk_nm);
        	ind = -1;
        	for(i = 0; i < INDEX; i++){
        		if(strcmp(bk_nm, l[i].bk_name) == 0){
        			ind = i;
        			break;
        		}
        	}
        	--INDEX;
        	for(i = ind; i < INDEX; i++){
        		l[i] = l[i + 1];
        	}

        	file_write();
        }
    }
    return 0;

}
