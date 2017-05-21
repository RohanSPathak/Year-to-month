#include <stdio.h>
#include <stdbool.h>

int month(int day, int year, int *m, int *d)
{
	int months[2][13]={{31,28,31,30,31,30,31,31,30,31,30,31},
				   {31,29,31,30,31,30,31,31,30,31,30,31}};
	//Condition for a leap year
	// If year is leap, leap=1 otherwise leap=0
	bool yearisleap=false;
	if( ((year%4==0) &&(year%100!=0)) || ((year%100==0) && (year%400==0) ) )
		yearisleap=true;

	if(day<=(yearisleap+365))
	{

		int sum=0;
		int i=0;
		while((sum + months[yearisleap][i])<day)
		{
			sum +=months[yearisleap][i];
			++i;
		}
		*d=day-sum;
		*m=i+1;
		return 1;



	}
	else return 0;

}

main()
{
	int day, year, m=0, d=0;
	scanf("%d",&year);

	scanf("%d", &day);

	int c=month(day, year, &m,&d);
	if(c==1)
	printf("Date: %d/%d/%d\n",d,m,year );
	else printf("Wrong Date\n");
}