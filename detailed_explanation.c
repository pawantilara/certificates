#include<stdio.h>
#include<stdlib.h>

int main()
{
		//max array limit is 20
	int burst_time[20],process[20],waiting_time[20];  //array decleration for burst time, process,waiting time
	int turnaround_time[20],priority[20]; //array decleration for turnaround time,priority 
	int arrival_time[20],flag_type[20]; //array decleration for arrival time,flag_type;
	int i,j,k,z,x,limit,sum=0;
	float average_wait_time, average_turnaround_time;
	printf("Enter Total Number of Processes:\t");
	scanf("%d",&limit);//number of processes
	printf("\nEnter Burst Time and arrival_time For %d Proecess\n",limit);
	int count=0,aa;
	int flag=0,number;
	i=0;
	while(i!=limit)
	{
		printf("\nProcess[%d]\n",i+1);
		printf("Process Burst Time:\t");
		scanf("%d",&burst_time[i]);	//enter burst_time
		if(burst_time[i]<=0)
			{
			printf("Enter the burst time again Burst time can not be negative and zero\t");
			scanf("%d",&burst_time[i]);
			}
		printf("Arrival Time\t");
		scanf("%d",&arrival_time[i]);	//enter arrival_time
		if(arrival_time[i]<0)
			{
			printf("Enter the arrival_time again arrival_time can not be negative \t");
			scanf("%d",&arrival_time[i]);
			}
		process[i]=i+1;  //process ID
		//count++;
		i++;
		
	}
	for(i=0;i<limit;i++)  //time complexity is O(n) where n is limit
	{
	waiting_time[i]=0;  		// initializing all array elements of waiting_time to zero
	priority[i]=0;			//initializing all array elements of prority to zero
	flag_type[i]=0;			//initializing all array elements of flag_type to zero
	}
	int min=arrival_time[0];  //min is eqaual to 1st element of arrival_time
	aa=0;
	for(j=1;j<limit;j++)	//time complexity is 2*n where n is limit  (1 is assigment and 1 is comparision so 2*n)
	{	//comparing is min is greater then other arrival_time or not
		if(min>arrival_time[j])		//time complexity is 1 only 1 comparision
	
		{
			//if min is greater than arrival_time of j than min= arrival_time
			min=arrival_time[j];	//time complexity is 1 only 1 comparision
			aa=j;//time complexity is 1 only 1 comparision
			
		}
	//if find minimum of arrival time for first process to run in running state
	}			//total time complexity is 2n+1+1+1 that is eqaul to O(n)
	
	flag_type[aa]=burst_time[aa];//for aa value the inseting the value of burst_time[a] so that further it can not be included goto 3**down
	
	for(number=0;number<limit;number++)	//time complexity is 2*n where n is limit  (1 is assigment and 1 is comparision so 2*n)
	{
		
		
			for(k=0;k<limit;k++)	//time complexity is 2*n where n is limit  (1 is assigment and 1 is comparision so 2*n)
			{
		//comparing is flag_type[k]==0 it will be true only if value of flag_type of element is zero and not processed till now
				if(flag_type[k]==0) //time complexity is 1*n^2only 1 comparision
				{
				//calculating waiting_time of each process execept first process taht entered to running state
				waiting_time[k]=waiting_time[k]+burst_time[aa]; //time complexity is 2*n^2  1 equal and 1 is addition

				//calculating priority for each process except those who already entered into running state
				priority[k]=1+(waiting_time[k]/burst_time[k]);//time complexity is 3*n^2  1 equal , 1 is addition and 1 is division
				min=priority[k];	//time complexity is 1*n^2 only 1 equal
				j=k;		//time complexity is 1*n^2  only 1 equal
				
			
				}
			}
		//till now total comlexity is 2*n+2*n+1*n^2+2*n^2+3*n^2+1*n^2 that is equal to....{ O(n^2) }
	
	 aa=j;
	for(i=0;i<limit;i++) //time complexity is 2*n where n is limit  (1 is assigment and 1 is comparision so 2*n)
	{
		//this code finds the min priority value
		if(min==priority[i] && flag_type==0)  //time complexity is 3 -------------**(goto 3)
		{
			//checks if priority of both process is same  than campare therir arrival_time and take minimum of them
			if(arrival_time[min]>arrival_time[i])//time complexity is 1
			{
				min=priority[i]; //time complexity is 1
				aa=i; //time complexity is 1
			}
			else
			{
			min=min; //time complexity is 1
			aa=i;	//time complexity is 2*n 
			}
		}
		else if(min>priority[k] && flag_type==0) //time complexity is 3
		{
		
			min=priority[i]; //time complexity is 1
			aa=i;//time complexity is 1
		}
		
	}
	count++; //time complexity is 1
	
	
	flag_type[aa]=burst_time[aa];   //time complexity is 1
	
	//till now total comlexity is 2*n+2*n+1*n^2+2*n^2+3*n^2+1*n^2 that is equal to....{ O(n^2) }
	
	
}
//total time for the 2 for loop is Big-O n^2 {..O(n^2)..}
		printf("-------......*********........---------\n");	
	
	for(i=0;i<limit;i++){
	// calculating total waiting_time
	sum=sum+waiting_time[i];
}	// calculating average_wait_time
	average_wait_time=sum/limit;
	sum=0;
	printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
	for(i=0;i<limit;i++)
	{
	//calculating total turnaround time.
	turnaround_time[i] = burst_time[i] + waiting_time[i];
        sum = sum + turnaround_time[i];
	//Now printing the process id ,waiting_time and turnaround_time
	printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n", process[i], burst_time[i], waiting_time[i], turnaround_time[i]);

	}
	// calculating average_turnaround_time.
 	average_turnaround_time = sum / limit;
      	printf("\nAverage Waiting Time:\t%f", average_wait_time);
      	printf("\nAverage Turnaround Time:\t%f\n", average_turnaround_time);

}
// total time complexity for this program is O(n^2)


      return 0;
}
	
