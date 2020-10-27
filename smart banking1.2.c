#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	FILE *fp,*fp1,*fp2,*fp3;
	SYSTEMTIME stime;
	GetSystemTime(&stime);
	int choice,y,m,d;
	printf("\n\n\n====================WEL-COME TO SMART BANKING SERVICE===================\n ");
	printf("\n\n\n\t=>Select the given option:\n");
	printf("\t\t[1].Create Account\n\t\t[2].Login Account\n\tChoose option:");
	scanf("%d",&choice);
    d=stime.wDay;
    m=stime.wMonth;
    y=stime.wYear;
	switch(choice)
	{
	 case 1:
		{
			char ch[10],an[25],name[20],pw[15];
			int pin,balance=0;
			printf("\n\n\t=>enter 'y' to create an Account:");
			scanf("%s",&ch);
			if(*ch=='y'||*ch=='Y')
				{
					printf("\n\t=>please enter account name in string with some integer value.\n");
					printf("\n\t=>enter your account name to creat:");
					scanf("%s",&an);
					printf("\n\t=>enter Account holder name:");
					scanf("%s",&name);
					printf("\n\t=>enter password:");
					scanf("%s",&pw);
					do
					{
						printf("\n\t=>enter your pin:");
						scanf("%d",&pin);
						if(pin>=1000&&pin<=9999)
						{
							printf("\n\t=>your pin is successfully saved.\n");
						}
						else
						{
							printf("\n\t=>enter pin in 4 digit only:\n");
						}
					}while(pin<1000||pin>9999);

					printf("\n\n\t=>you have successfully creat your account.\n");
					printf("\n\n=============Detail about your Account=============\n");
					printf("\n\t\t=>Account name:%s\n\t\t=>Account holder Name:%s\n\t\t=>Password:%s\n\t\t=>PIN:%d\n\t\t=>Current balance:%d\n",an,name,pw,pin,balance);
					printf("\t\t=>Current date:%d / %d / %d",y,m,d);
					printf("\n====================================================\n\n");
					fp=fopen(an,"w");
					fprintf(fp,"%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n",an,name,pw,pin,balance,y,m,d);
				}
				break;
			}
		case 2:
			{   
			    menu:
				char lan[25],lpw[25],acntnm[25],pswrd[25],lname[25];
			    int lpin,select,cmp1=0,cmp2=0,py,pm,pd;
			    long int lbalance;
			    do
				{
				printf("\n\t=>enter your account name:");
				scanf("%s",&lan);
				printf("\n\t=>enter your account password:");
				scanf("%s",&lpw);
				fp=fopen(lan,"r");
				if(fp==0)
				{
					printf("\n\t=>file doesn't exist.\n");
				}
				fscanf(fp,"%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n",&acntnm,&lname,&pswrd,&lpin,&lbalance,&py,&pm,&pd);
				int ny,nm,nd,td,intrest;
                    if(pd>d)
                    {
                    	nd=(30+d)-pd;
                    	m=m-1;
                    	}
                    	else
                	   {
               	        	nd=d-pd;
                       	}
                       	if(pm>m)
                     	{
                    	 nm=(12+m)-pm;	
                    	 ny=y-py-1;
                        	}
                    	else
	                 {
	                   	nm=m-pm;
	               	   ny=y-py;
	                  }
	                   td=ny*365+nm*30+nd;
	                    intrest=(lbalance*td*16)/36500;
	                  lbalance=lbalance+intrest;
	                  fp1=fopen(acntnm,"w");
			     	fprintf(fp1,"%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n",acntnm,lname,pswrd,lpin,lbalance,y,m,d);
				cmp1=strcmp(lan,acntnm);
				cmp2=strcmp(lpw,pswrd);
				if(cmp1!=0||cmp2!=0)
				{
					printf("\n\t=>your Accont Name and Password doesn't mached.....Try Again.....!!!!\n ");
				}
			   }while(cmp1!=0||cmp2!=0);
			   if(cmp1==0&&cmp2==0)
			   {
			   	printf("\n\n============Hello, %s Wel-come to your login page=============\n",lname);
			   	printf("\n\n\t=>select the given option below:\n");
				printf("\t\t[1].Deposite\n\t\t[2].Withdrawl\n\t\t[3].Transfer\n\t\t[4].Change Password and PIN\n\t\t[5].Check balance\n\t\t[6].About my Account\n\tChoose option:");
				scanf("%d",&select);
				switch(select)
				{
					case 1:
						{ 
						int deposite;
							do
							{
								printf("\n\t=>enter deposite deposite amount in 100's multiple:");
								scanf("%d",&deposite);
								if(deposite>=100&&(deposite%100)==0)
								{
									printf("\n\t=>you have successfully deposited %d rupees.\n",deposite);
									lbalance=lbalance+deposite;
								}
								else
								{
									printf("\n\t=>enter deposite amount in positive 100's multiple only.\n");
								}
							}while(deposite<100||(deposite%100)!=0);
						    fp1=fopen(acntnm,"w");
							fprintf(fp1,"%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n",acntnm,lname,pswrd,lpin,lbalance,y,m,d);
							char gt[10];
							printf("\n\t=>enter 'y' to go menu:");
							scanf("%s",&gt);
							if(*gt=='y'||*gt=='Y')	
							goto menu;
							break;
						}
				case 2:	
						{ 
						int withdrawl,wpin;
							do
							{
								do
								{
									printf("\n\t=>enter your pin to withdrawl:");
									scanf("%d",&wpin);
									if(lpin!=wpin)
									{
										printf("\n\t=>incorrect pin.....Try again..!!!\n");
									}
								}while(wpin!=lpin);
								if(wpin==lpin)
								{
								printf("\n\t=>enter withdrawl deposite amount in 100's multiple:");
								scanf("%d",&withdrawl);
								if(withdrawl>=100&&(withdrawl%100)==0&&lbalance>withdrawl)
								{
									printf("\n\t=>you have successfully withdrawl %d rupees.\n",withdrawl);
									lbalance=lbalance-withdrawl;
								}
								else
								{   
								 if(lbalance<withdrawl)
								   {
								   	printf("\n\t=>you do not have sufficient balance to withdrawl.....\n");
								   }
								    else if((withdrawl%100)!=0)
								    {
								    printf("\n\t=>enter withdrawl amount in 100's multiple only.\n");	
									}
									else
									{
										printf("\n\t=>entetr withdrawl amount in 100's multiple.\n\n\t=>you do not have sufficient balance to withdrawl.\n ");
									}
								}
						    	}
							}while(withdrawl<100||(withdrawl%100)!=0||withdrawl>lbalance);
						    fp1=fopen(acntnm,"w");
							fprintf(fp1,"%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n",acntnm,lname,pswrd,lpin,lbalance,y,m,d);
						    char gt[10];
							printf("\n\t=>enter 'y' to go menu:");
							scanf("%s",&gt);
							if(*gt=='y'||*gt=='Y')
							goto menu;
							break;
						}
				case 3:
					{
						char tan[25],tname[25],tpw[25],tran[25];
						long int tbalance;
						int tpin,trpin,tramount,tpy,tpm,tpd;
						printf("\n\t=>enter the Account name where do you want to transfer your balance:");
						scanf("%s",&tan);
						fp2=fopen(tan,"r");
						fscanf(fp2,"%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n",&tran,&tname,&tpw,&tpin,&tbalance,&tpy,&tpm,&tpd);
				       	int days,month,year,ttld,tintrest;
                          if(tpd>d)
                             {
                    	       days=(30+d)-tpd;
                 	            m=m-1;
                            	}
                          	else
                        	{
               	       	    days=d-tpd;
                        	}
                       	   if(tpm>m)
                        	{
                    	    month=(12+m)-tpm;	
                    	   year=y-tpy-1;
                        	}
                    	  else
	                        {
	                    	month=m-tpm;
	                      	year=y-tpy;
	                         }
	                       ttld=year*365+month*30+days;
	                       tintrest=(tbalance*ttld*16)/36500;
	                       tbalance=tbalance+tintrest;
						 do
						  {
						   printf("\n\t=>enter your pin to transfer balance:");
						   scanf("%d",&trpin);
						   if(lpin!=trpin)
						   {
						   	printf("\n\t=>incorrect pin...Try agian\n");
						   }
						  }while(lpin!=trpin);
				     	if(lpin==trpin)
				    	{
						printf("\n\t=>enter transfer amount:");
						scanf("%d",&tramount);
						tbalance=tbalance+tramount;
						lbalance=lbalance-tramount;
				    	}
				    	printf("\n\t=>you have successfully transfer %d rupees.",tramount);
						fp1=fopen(acntnm,"w");
						fprintf(fp1,"%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n",acntnm,lname,pswrd,lpin,lbalance,y,m,d);
						fp3=fopen(tran,"w");
						if(fp3==0)
						{
							printf("\n\t=>file doesn't exist.\n");
						}
						fprintf(fp3,"%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n",tran,tname,tpw,tpin,tbalance,y,m,d);
							char gt[10];
							printf("\n\t=>enter 'y' to go menu:");
							scanf("%s",&gt);
							if(*gt=='y'||*gt=='Y')
							goto menu;
						break;
					}        	
				case 4:
				    {
					  int choose;
				    	printf("\n\t=>select given option which you want to change:\n");
				    	printf("\t\t[1].Change password\n\t\t[2].change PIN\n\tChoose option:");
				     	scanf("%d",&choose);
				       	switch(choose)
					        {
					    	   case 1:
							 {
								char opw[25],cpswrd[25];
								int pcmp=0;
							  do{
								printf("\n\t=>enter your old password:");
								scanf("%s",&opw);
								pcmp=strcmp(pswrd,opw);
								if(pcmp!=0)
								{
									printf("\n\t=>incorrect password...try again\n");
								}
							  }while(pcmp!=0);
							  printf("\n\t=>enter your new password:");
							  scanf("%s",&cpswrd);
							  printf("\n\t=>you have successfully changed your password.\n");
						     fp1=fopen(acntnm,"w");
						     fprintf(fp1,"%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n",acntnm,lname,cpswrd,lpin,lbalance,y,m,d);
						     break;
						    	}
			                  case 2:
			                	{
			            		int opin,cpin;
			            		do
			            		{
			            			printf("\n\t=>enter your old pin:");
			            			scanf("%d",&opin);
			            			if(opin!=lpin)
			            			{
			            				printf("\n\t=>incorrect pin...try again.");
									}
								}while(opin!=lpin);
								do
								{
								printf("\n\t=>enter new pin:");
								scanf("%d",&cpin);
								if(cpin>999&&cpin<=9999)
								{
									printf("\n\t=>you have changed your PIN.\n ");
								}
								else
								{
									printf("\n\t=>enter 4 digit PIN only.");
								}
								}while(cpin<1000||cpin>9999);
							    fp1=fopen(acntnm,"w");
							    fprintf(fp1,"%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n",acntnm,lname,pswrd,cpin,lbalance,y,m,d);
							    break;
							}
						}
						break;	
					}
				case 5:
				{
					printf("========================================\n");
				   printf("\n\t=>your current balance =%d Rupees\n\n",lbalance);
				   printf("==========================================\n");
							char gt[10];
							printf("\n\t=>enter 'y' to go menu:");
							scanf("%s",&gt);
							if(*gt=='y'||*gt=='Y')
							goto menu;
							break;
				  }
				  case 6:
				  {
					printf("\n\n\n====================About Your account====================\n\n");
					printf("\t\t=>Account Name:%s\n\t\t=>Account holder Name:%s\n\t\t=>Password:%s\n\t\t=>PIN:%d\n\t\t=>Current Balance:%d\n",acntnm,lname,pswrd,lpin,lbalance);
					printf("\t\t=>Previous activities data:%d / %d / %d\n ",py,pm,pd);
					printf("\t\t=>Current date:%d / %d / %d\n",y,m,d);
					printf("\n\n==========================================================\n");
							char gt[10];
							printf("\n\t=>enter 'y' to go menu:");
							scanf("%s",&gt);
							if(*gt=='y'||*gt=='Y')
							goto menu;
							break;
					}	
		    	}
			}
		}		
	}
	fclose(fp);
	return 0;
}
