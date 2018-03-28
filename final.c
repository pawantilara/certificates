#include<stdio.h>
#include<stdlib.h>
int main()
{

	int burst_time[20],process[20],waiting_time[20];
	int turnaround_time[20],priority[20],arrival_time[20],flag_type[20];
	int i,j,k,z,x,limit,sum=0, position,temp;
	float average_wait_time, average_turnaround_time;
	printf("Enter Total Number of Processes:\t");
	scanf("%d",&limit);
	printf("\nEnter Burst Time and arrival_time For %d Proecess\n",limit);
	int count=0,aa;
	int c,flag=0,number;
	i=0;
	while(i!=limit)
	{
		printf("\nProcess[%d]\n",i+1);
		printf("Process Burst Time:\t");
		scanf("%d",&burst_time[i]);
		printf("Arrival Time\t");
		scanf("%d",&arrival_time[i]);
		process[i]=i+1;
		//count++;
		i++;
		
	}
	for(i=0;i<limit;i++)
	{
	waiting_time[i]=0;
	priority[i]=0;
	flag_type[i]=0;
	}
	int min=arrival_time[0];
	aa=0;
	for(j=1;j<limit;j++)
	{
		if(min>arrival_time[j])
		{
			min=arrival_time[j];
			aa=j;
			
		}
	}
	
	flag_type[aa]=burst_time[aa];
	
	for(number=0;number<limit;number++)
	{
		
		
			for(k=0;k<limit;k++)
			{
				if(flag_type[k]==0)
				{
					
				waiting_time[k]=waiting_time[k]+burst_time[aa];

				
				priority[k]=1+(waiting_time[k]/burst_time[k]);
				min=priority[k];
				j=k;
				
			
				}
			}
		
	
	 aa=j;
	for(i=0;i<limit;i++){
		if(min==priority[i] && flag_type==0)
		{
			if(arrival_time[min]>arrival_time[i])
			{
				min=priority[i];
				aa=i;
			}
			else
			{
			min=min;
			aa=i;	
			}
		}
		else if(min>priority[k] && flag_type==0)
		{
		
			min=priority[i];
			aa=i;
		}
		
	}
	count++;
	
	
	flag_type[aa]=burst_time[aa];
	
	
	
}
printf("-------......*********..........---------\n");
	
	for(i=0;i<limit;i++){
	sum=sum+waiting_time[i];
}	
	average_wait_time=sum/limit;
	sum=0;
	printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
	for(i=0;i<limit;i++)
	{
	turnaround_time[i] = burst_time[i] + waiting_time[i];
        sum = sum + turnaround_time[i];
	printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n", process[i], burst_time[i], waiting_time[i], turnaround_time[i]);

	}
 	average_turnaround_time = sum / limit;
      	printf("\nAverage Waiting Time:\t%f", average_wait_time);
      	printf("\nAverage Turnaround Time:\t%f\n", average_turnaround_time);

      return 0;
}
	
