#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int PREV_ALL=145;
int CURR_ALL=143;
int check(int num)
{
	if(num>0)
	{
		return num;
	}
	else
	{
		return (num*-1);
	}
}
int main()
{
	int queue[] = {86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130};
	int i,s_index,len=sizeof(queue)/sizeof(int),dist=0,last,curr,a,j;
	//sorting of queue
	 for (i = 0; i < len; ++i) 
        {
 
            for (j = i + 1; j < len; ++j)
            {
 
                if (queue[i] > queue[j]) 
                {
 
                    a =  queue[i];
                    queue[i] = queue[j];
                    queue[j] = a;
 
                }
 
            }
 
        }
        last = CURR_ALL;
    if(CURR_ALL>=PREV_ALL){
        for(i=0; i<len; i++){
            if(queue[i]>CURR_ALL){
                s_index=i;
                break;
            }
        }
        printf("Order    : %4d",last);
        for(i=s_index; i<len; i++){
            printf(", %4d",queue[i]);
            curr = queue[i];

            dist+= check(last-curr);
            printf("[%d]",check(last-curr) );
            last = curr;
        }
        for(i=s_index; i>0; i--){
            printf(", %4d",queue[i-1]);
            curr = queue[i];

            dist+= check(last-curr);
            printf("[%d]",check(last-curr) );
            last = curr;
        }
    }
    else if(CURR_ALL<PREV_ALL){
        for(i=0; i<len; i++){
            if(queue[i]>CURR_ALL){
                s_index=i;
                break;
            }
        }
        printf("Order    : %4d",last);
        for(i=s_index-1; i>=0; i--){
            printf(", %4d",queue[i]);
            curr = queue[i];

            dist+= check(last-curr);
            printf("[%d]",check(last-curr) );
            last = curr;
        }
        for(i=s_index; i<len; i++){
            printf(", %4d",queue[i]);
            curr = queue[i];

            dist+= check(last-curr);
            printf("[%d]",check(last-curr) );
            last = curr;
        }
    }

    printf("\nDistance : %d\n",dist);

    return 0;
}

