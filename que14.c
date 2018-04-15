#include<stdio.h>
int main()
{
	int id[20],bt[20], sel[20], wt[20],tat[20],i, k, n, temp;
float wtavg, tatavg;
printf("enter the number of Candidates(Student+teacher) --- ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
id[i] = i;
printf("time taken by candidate %d --- ", i);
scanf("%d",&bt[i]);
printf("teacher/student candidate (0/1) ? --- ");
scanf("%d", &sel[i]);
}
for(i=0;i<n;i++)
for(k=i+1;k<n;k++)
if(sel[i] > sel[k])
{
temp=id[i];
id[i]=id[k];
id[k]=temp;
temp=bt[i];
bt[i]=bt[k];
bt[k]=temp;
temp=sel[i];
sel[i]=sel[k];
sel[k]=temp;
}
wtavg = wt[0] = 0;
tatavg = tat[0] = bt[0];
for(i=1;i<n;i++)
{
wt[i] = wt[i-1] + bt[i-1];
tat[i] = tat[i-1] + bt[i];
wtavg = wtavg + wt[i];
tatavg = tatavg + tat[i];
}
printf("\ncandidate\t\t teacher/student candidate \talloted TIME\tWAITING TIME\tTURNAROUND TIME");
for(i=0;i<n;i++)
printf("\n\n\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",id[i],sel[i],bt[i],wt[i],tat[i]);
printf("\nAverage Waiting Time is --- %f",wtavg/n);
printf("\nAverage Turnaround Time is --- %f",tatavg/n);
getch();
}


