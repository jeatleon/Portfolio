#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include<time.h>

struct customer{
	char food_name[100];
	int choice, quantity;
};

void alacarte();//function
void combo();
void mainmenu();
void checkout(float, float);
void exit();

COORD coord = {0,0};

void gotoxy(int x,int y) //Coordinat
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int num;
float price;
float total_ala=0,total_com=0;
char choice;
int again;

void main()
{
	mainmenu();
}

void mainmenu()
{
	struct customer makan[20];
	char choice = ' ' ;
	printf("              ==============================          \n");
	printf("                  SOFIYYAH's RESTAUNRANT          \n ");
	printf("             ==============================          \n\n");
	
	printf("\t\tEnter [A] -> Alacarte Menu\n");
	printf("\t\tEnter [B] -> COMBO Menu\n");
	printf("\t\tEnter [C] -> Checkout\n");
	printf("\t\tEnter [D] -> Exit\n\n");
	  
	printf("              ==============================          \n");
	time_t t;   // not a primitive datatype
	time(&t);
	printf("\t\t %s", ctime(&t));
	printf("              ==============================          \n\n");
	  
	printf("\t      Total for alacarte : Rm%.2f\n", total_ala);
	printf("\t      Total for combo    : Rm%.2f\n\n", total_com);
	printf("\t      Please Enter Your Choice: ");
	scanf("%c", &choice);
	system("cls");
	
	{ //else if , string
		if (toupper(choice) == 'A')//toupper(variable...) utk word kecik auto capslock
			alacarte();
		else if (toupper(choice) == 'B')//toupper(variable...) utk word kecik auto capslock
			combo();
		else if (toupper(choice) == 'C')
			checkout(total_ala, total_com);
		else if (toupper(choice) == 'D')
		exit(0);
		else if (toupper(choice) != 'A', 'B' , 'C', 'D' )
		{
			mainmenu();
		}
	}
	
}

void alacarte() 
{
	struct customer makan[20];
	int choice = 0;
	int quantity = 0;
	int again = 0;
	printf("\t            ==============================          \n");
	printf("\t                    Alacarte Menu   \n");
	printf("\t                 by : Chef Sofiyyah   \n");
	printf("\t            ==============================          \n\n");
	
	printf("\t   [1] chicken rice		        - RM 7.00 \n");
	printf("\t   [2] fried noodles		        - RM 6.00 \n");
	printf("\t   [3] tomyum soup with noodles         - RM 12.00 \n");
	printf("\t   [4] tomyum soup with rice            - RM 12.00 \n");
	printf("\t   [5] fried rice                       - RM 6.00 \n");
	printf("\t   [6] Add New One             \n");
	printf("\t   [7] Back To Main-Menu         ");
	printf("\n\n \t   Enter your choice here : ");
	scanf("%d", &choice);
	{
		if (choice == 1)
		{
			strcpy(makan[0].food_name, "set01	chicken rice(alacarte)					RM 7.00");
			printf("\nIngredient : hainanese chicken, hainanese rice, chili sauce, ginger garlic sauce, soy dipping sauce.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_ala = 7 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for chicken rice (alacarte)  Rm.%.2f\n", total_ala);
			printf("====================================          \n");
		}
		else if ( choice == 2)
		{
			strcpy(makan[1].food_name, "set02	fried noodles(alacarte)					RM 6.00");
			printf("\nIngredient : noodles ,cabbage, firm tofu, kicap manis jalin, chili sauce, oyster sauce.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_ala = 7 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for fried noodles (alacarte)  Rm.%.2f\n", total_ala);
			printf("====================================          \n");			
		}
		else if ( choice == 3 )
		{
			strcpy(makan[2].food_name, "set03	tomyum soup with noodles(alacarte)			RM 12.00");
			printf("\nIngredient : ingredients : water, garlic, chicken stock, lemongrass, chili, galangal, kaffir lime leaves, lime, fish sauce, tomato, sugar, mushrooms, onion, coriander, shrimp, noodles.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_ala = 7 * quantity ;;
			printf("===================================          ");
			printf("\nYour amount for tomyum soup with noodles (alacarte)  Rm.%.2f\n", total_ala);
			printf("====================================          \n");			 
		}
		else if ( choice == 4 )
		{
			strcpy(makan[3].food_name, "set04	tomyum soup with rice(alacarte)				RM 12.00");
			printf("\nIngredient : ingredients : water, garlic, chicken stock, lemongrass, chili, galangal, kaffir lime leaves, lime, fish sauce, tomato, sugar, mushrooms, onion, coriander, shrimp, rice.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_ala = 7 * quantity ;;
			printf("===================================          ");
			printf("\nYour amount for tomyum soup with rice (alacarte)  Rm.%.2f\n", total_ala);
			printf("====================================          \n");
		}
		else if ( choice == 5 )
		{
			strcpy(makan[4].food_name, "set05	fried rice(alacarte)					RM 6.00");
			printf("\nIngredient : rice, butter, veggies, oyster sauce. soy sauce, garlic, eggs.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_ala = 7 * quantity ;;
			printf("===================================          ");
			printf("\nYour amount for fried rice (alacarte)  Rm.%.2f\n", total_ala);
			printf("====================================          \n");			 
		}
		    
		else if ( choice == 6 )
		{
			FILE *fp, *ft;
			char another, choice;
			
			struct emp //struct declaration 
		{
			char name[40];
			int pri;
		};
		
		struct emp e; // structure variable creation
		
		char empname[40]; // string to store name of the food
		
		long int recsize; // size of each record of food
		
		fp = fopen("menu.txt","r+");//file
		if(fp == NULL)
		{
			fp = fopen("menu.txt","w+");
		if(fp == NULL)
		{
			printf("Connot open file");
		exit(1);
		}
		}
		
		//size of each record i.e. size of structure variable e
		recsize = sizeof(e);
		
		while(1)
		{
			system("cls"); //clear the console window
			gotoxy(30,10); // move the cursor to position 30, 10 from top-left corner
			printf("1. Add Food");
			gotoxy(30,12);
			printf("2. Display Food");
			gotoxy(30,14);
			printf("3. Delete Food");
			gotoxy(30,16);
			printf("4. Back To Main-Menu");
			gotoxy(30,18);
			printf("Your Choice: ");
			fflush(stdin); // flush the input buffer
			choice  = getche();
			switch(choice)//switch
			{
				case '1':
				system("cls");
				fseek(fp,0,SEEK_END); // search the file and move cursor to end of the file
				// here 0 indicates moving 0 distance from the end of the file
				another = 'y';
				while(another == 'y')
				{
					printf("\nEnter Item's Name: ");
					scanf("%s",e.name);
					printf("\nEnter Price: ");
					scanf("%d", &e.pri);
					fwrite(&e,recsize,1,fp); // write the record in the file
					printf("\nAdd another record(y/n) ");
					fflush(stdin);
					another = getche();
			}
			break;
		
			case '2':
			system("cls");
			rewind(fp); //this moves file cursor to start of the file
			while(fread(&e,recsize,1,fp)==1)  // read the file and fetch the record one record per fetch
			{
				printf("\nItem is %s",e.name);
				printf("\nPrice is: %d",e.pri);
			}
			getch();
			break;
		
			case '3':
			system("cls");
			another = 'y';
			while(another == 'y')
			{
				printf("\nEnter name of Food to delete: ");
				scanf("%s",empname);
				ft = fopen("Temp.txt","w");  // create a intermediate file for temporary storage
				rewind(fp); // move record to starting of file
				while(fread(&e,recsize,1,fp) == 1)  // read all records from file
				{
				if(strcmp(e.name,empname) != 0)  // if the entered record match
				{
				fwrite(&e,recsize,1,ft); // move all records except the one that is to be deleted to temp file
				}
				}
				fclose(fp);
				fclose(ft);
				remove("menu.txt"); // remove the original file
				rename("Temp.txt","menu.txt"); // rename the temp file to original file name
				fp = fopen("menu.txt", "r+");
				printf("Delete another record(y/n)");
				fflush(stdin);
				another = getche();
			}
			break;
		
			case '4':
			fclose(fp);// close the file
			system("cls");
			alacarte();
			}
			}
			
		}
		else if ( choice == 7 )
		{
				mainmenu();
			
		}
		else if (choice != 1 , 2 , 3 , 4 , 5 , 6 , 7)
		{
			system("cls");
			printf("\n\n\t\t   Invalid Choice Entered\n\n");
			alacarte();
		}
	}
	   
	printf("\n");
	total_ala+=total_ala;
	printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
	scanf("%d", &again);
	if(again==1)
		alacarte();
	else if (again==2)
		mainmenu();
	else if(again!=1,2)
	{
		printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
		exit(0);
	}
}

void combo() 
{
	struct customer makan[20];
	int choice;
	int quantity;
	int again;
	
	printf("\t               ==============================          \n");
	printf("\t                        Combo Menu   \n");
	printf("\t                   by : Chef Chef Sofiyyah   \n");
	printf("\t               ==============================          \n\n");
	  
	printf("\t   [1] chicken rice(coca cola bottle 500ml)                   - RM 10.00 \n");
	printf("\t   [2] chicken rice(100 plus bottle 500ml)                    - RM 10.00 \n");
	printf("\t   [3] chicken rice(mineral water 500ml)                      - RM 9.00 \n");
	printf("\t   [4] fried rice(coca cola bottle 500ml)                     - RM 9.00 \n");
	printf("\t   [5] fried rice(100 plus bottle 500ml)                      - RM 9.00 \n");
	printf("\t   [6] fried rice(mineral water 500ml)                        - RM 8.00 \n");
	printf("\t   [7] tomyum soup with rice(coca cola bottle 500ml)          - RM 15.00 \n");
	printf("\t   [8] tomyum soup with rice(100 plus bottle 500ml)           - RM 15.00 \n");
	printf("\t   [9] tomyum soup with rice(mineral water bottle 500ml)      - RM 14.00 \n");
	printf("\t   [10] tomyum soup with noodles(coca cola bottle 500ml)      - RM 15.00 \n");
	printf("\t   [11] tomyum soup with noodles(100 plus bottle 500ml)       - RM 15.00 \n");
	printf("\t   [12] tomyum soup with noodles(mineral water bottle 500ml)  - RM 14.00 \n");
	printf("\t   [13] fried noodles(coca cola bottle 500ml)                 - RM 9.00 \n");
	printf("\t   [14] fried noodles(100 plus bottle 500ml)                  - RM 9.00 \n");
	printf("\t   [15] fried noodles(mineral water bottle 500ml)             - RM 8.00 \n");
	printf("\t   [16] Add New One                     \n");
	printf("\t   [17] Back To Main-Menu               \n");
	
	printf("\n \t   Enter your choice here : ");
	scanf("%d", &choice);
	{
		if (choice == 1)
		{
			strcpy(makan[5].food_name, "set06	chicken rice(coca cola bottle 500ml)			RM 10.00");
			printf("\nIngredient :hainanese chicken, hainanese rice, chili sauce, ginger garlic sauce, soy dipping sauce.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_com = 10 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for chicken rice(coca cola bottle 500ml) Rm.%.2f\n", total_com);
			printf("====================================          \n");
			        
		}
		else if ( choice == 2)
		{
			strcpy(makan[6].food_name, "set07	chicken rice(100 plus bottle 500ml)			RM 10.00");
			printf("\nIngredient : hainanese chicken, hainanese rice, chili sauce, ginger garlic sauce, soy dipping sauce.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_com = 10 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for chicken rice(100 plus bottle 500ml) Rm.%.2f\n", total_com);
			printf("====================================          \n");
		}
		else if ( choice == 3 )
		{
			strcpy(makan[7].food_name, "set08	chicken rice(mineral water 500ml)			RM 9.00");
			printf("\nIngredient : hainanese chicken, hainanese rice, chili sauce, ginger garlic sauce, soy dipping sauce.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_com = 9 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for chicken rice(mineral water 500ml) Rm.%.2f\n", total_com);
			printf("====================================          \n");
		}
		else if ( choice == 4 )
		{
			strcpy(makan[8].food_name, "set09	fried rice(coca cola bottle 500ml)			RM 9.00");
			printf("\nIngredient : rice, butter, veggies, oyster sauce. soy sauce, garlic, eggs.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_com = 9 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for fried rice(coca cola bottle 500ml) Rm.%.2f\n", total_com);
			printf("====================================          \n");
		}
		else if ( choice == 5 )
		{
			strcpy(makan[9].food_name, "set10	fried rice(100 plus bottle 500ml)			RM 9.00");
			printf("\nIngredient : rice, butter, veggies, oyster sauce. soy sauce, garlic, eggs.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_com = 9 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for fried rice(100 plus bottle 500ml) Rm.%.2f\n", total_com);
			printf("====================================          \n");
		}
		else if ( choice == 6 )
		{
			strcpy(makan[10].food_name, "set11	fried rice(mineral water 500ml)				RM 8.00");
			printf("\nIngredient : rice, butter, veggies, oyster sauce. soy sauce, garlic, eggs.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_com = 8 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for fried rice(mineral water 500ml) Rm.%.2f\n", total_com);
			printf("====================================          \n");
		}
		else if ( choice == 7 )
		{
			strcpy(makan[11].food_name, "set12	tomyum soup with rice(coca cola bottle 500ml)		RM 15.00");
			printf("\nIngredient : water, garlic, chicken stock, lemongrass, chili, galangal, kaffir lime leaves, lime, fish sauce, tomato, sugar, mushrooms, onion, coriander, shrimp, rice.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_com = 15 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for tomyum with rice(coca cola bottle 500ml) Rm.%.2f\n", total_com);
			printf("====================================          \n");
		}
		else if ( choice == 8 )
		{
			strcpy(makan[12].food_name, "set13	tomyum soup with rice(100 plus bottle 500ml)		RM 15.00");
			printf("\nIngredient : water, garlic, chicken stock, lemongrass, chili, galangal, kaffir lime leaves, lime, fish sauce, tomato, sugar, mushrooms, onion, coriander, shrimp, rice.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_com = 15 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for tomyum with rice(100 plus bottle 500ml) Rm.%.2f\n", total_com);
			printf("====================================          \n");
		}
		else if ( choice == 9 )
		{
			strcpy(makan[13].food_name, "set14	tomyum soup with rice(mineral water bottle 500ml)	RM 14.00");
			printf("\nIngredient : water, garlic, chicken stock, lemongrass, chili, galangal, kaffir lime leaves, lime, fish sauce, tomato, sugar, mushrooms, onion, coriander, shrimp, rice.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_com = 14 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for tomyum with rice(mineral water 500ml) Rm.%.2f\n", total_com);
			printf("====================================          \n");
		}
		else if ( choice == 10 )
		{
			strcpy(makan[14].food_name, "set15	tomyum soup with noodles(coca cola bottle 500ml)	RM 15.00");
			printf("\nIngredient : water, garlic, chicken stock, lemongrass, chili, galangal, kaffir lime leaves, lime, fish sauce, tomato, sugar, mushrooms, onion, coriander, shrimp, noodles.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_com = 15 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for tomyum with noodles(coca cola bottle 500ml) Rm.%.2f\n", total_com);
			printf("====================================          \n");
		}
		else if ( choice == 11 )
		{
			strcpy(makan[15].food_name, "set16	tomyum soup with noodles(100 plus bottle 500ml)		RM 15.00");
			printf("\nIngredient : water, garlic, chicken stock, lemongrass, chili, galangal, kaffir lime leaves, lime, fish sauce, tomato, sugar, mushrooms, onion, coriander, shrimp, noodles.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_com = 15 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for tomyum with noodles(100 plus bottle 500ml) Rm.%.2f\n", total_com);
			printf("====================================          \n");
		}
		else if ( choice == 12 )
		{
			strcpy(makan[16].food_name, "set17	tomyum soup with noodles(mineral water bottle 500ml)	RM 14.00");
			printf("\nIngredient : water, garlic, chicken stock, lemongrass, chili, galangal, kaffir lime leaves, lime, fish sauce, tomato, sugar, mushrooms, onion, coriander, shrimp, noodles.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_com = 14 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for tomyum with noodles(mineral water 500ml) Rm.%.2f\n", total_com);
			printf("====================================          \n");
		}
		else if ( choice == 13 )
		{
			strcpy(makan[17].food_name, "set18	fried noodles(coca cola bottle 500ml)			RM 9.00");
			printf("\nIngredient : noodles ,cabbage, firm tofu, kicap manis jalin, chili sauce, oyster sauce.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_com = 9 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for tomyum with freind noodles(coca cola bottle 500ml) Rm.%.2f\n", total_com);
			printf("====================================          \n");
		}
		else if ( choice == 14 )
		{
			strcpy(makan[18].food_name, "set19	fried noodles(100 plus bottle 500ml)			RM 9.00");
			printf("\nIngredient : noodles ,cabbage, firm tofu, kicap manis jalin, chili sauce, oyster sauce.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_com = 9 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for tomyum with freind noodles(100 plus bottle 500ml) Rm.%.2f\n", total_com);
			printf("====================================          \n");
		}
		else if ( choice == 15 )
		{
			strcpy(makan[19].food_name, "set20	fried noodles(mineral water bottle 500ml)		RM 8.00");
			printf("\nIngredient : noodles ,cabbage, firm tofu, kicap manis jalin, chili sauce, oyster sauce.\n\n");
			printf("Enter Quantity : ");
			scanf("%d", &quantity);
			total_com = 8 * quantity ;
			printf("===================================          ");
			printf("\nYour amount for tomyum with freind noodles(mineral water 500ml) Rm.%.2f\n", total_com);
			printf("====================================          \n");
		}
	   
		else if ( choice == 16 )
		{
			FILE *fp, *ft;
			char another, choice;
			struct emp
			{
				char name[40];
				int pri;
			};
		
			struct emp e; // structure variable creation
			
			char empname[40]; // string to store name of the food
			
			long int recsize; // size of each record of food
		
			fp = fopen("menu.txt","r+");
			if(fp == NULL)
			{
				fp = fopen("menu.txt","w+");
			if(fp == NULL)
			{
				printf("Cannot open file");
				exit(1);
			}
			}
		
			// size of each record i.e. size of structure variable e
			recsize = sizeof(e);
		
			while(1)
			{
				system("cls"); //clear the console window
				gotoxy(30,10); // move the cursor to position 30, 10 from top-left corner
				printf("1. Add Food");
				gotoxy(30,12);//it is also for us to position the word
				printf("2. Display Food");
				gotoxy(30,14);
				printf("3. Delete Food");
				gotoxy(30,16);
				printf("4. Back To Main-Menu");
				gotoxy(30,18);
				printf("Your Choice: ");
				fflush(stdin); // flush the input buffer
				choice  = getche();
				switch(choice)
				{
					case '1':
					system("cls");
					fseek(fp,0,SEEK_END); // search the file and move cursor to end of the file
					// here 0 indicates moving 0 distance from the end of the file
					
					another = 'y';
					while(another == 'y')
					{
						printf("\nEnter Item Name: ");
						scanf("%s",e.name);
						printf("\nEnter Price: ");
						scanf("%d", &e.pri);
						fwrite(&e,recsize,1,fp); // write the record in the file
						printf("\nAdd another record(y/n) ");
						fflush(stdin);
						another = getche();
					}
					break;
					
					case '2':
					system("cls");
					rewind(fp); //this moves file cursor to start of the file
					while(fread(&e,recsize,1,fp)==1)  // read the file and fetch the record one record per fetch
					{
						printf("\nItem is %s",e.name);
						printf("\nPrice is: %d",e.pri);
					}
					getch();
					break;
					
					case '3':
					system("cls");
					another = 'y';
					while(another == 'y')
					{
						printf("\nEnter name of Food to delete: ");
						scanf("%s",empname);
						ft = fopen("Temp.txt","w");  // create a intermediate file for temporary storage
						rewind(fp); // move record to starting of file
						while(fread(&e,recsize,1,fp) == 1)  // read all records from file
						{
							if(strcmp(e.name,empname) != 0)  // if the entered record match
							{
								fwrite(&e,recsize,1,ft); // move all records except the one that is to be deleted to temp file
							}
						}
						fclose(fp);
						fclose(ft);
						remove("menu.txt"); // remove the original file
						rename("Temp.txt","menu.txt"); // rename the temp file to original file name
						fp = fopen("menu.txt", "r+");
						printf("Delete another record(y/n)");
						fflush(stdin);
						another = getche();
					}
					break;
					
					case '4':
					fclose(fp);// close the file
					system("cls");
					combo();
				}
			}
		}
		else if ( choice == 17 )
		{
			mainmenu();
		
		}
		else if (choice != 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17)
		{
			system("cls");
			printf("\n\n\t\t   Invalid Choice Entered\n\n");
			combo();
		}
	}
		  
	printf("\n");
	total_com+=total_com;
	printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
	scanf("%d", &again);
	if(again==1)
	combo();
	else if (again==2)
	mainmenu();
	else if(again!=1,2)
	{
	printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
	exit(0);
	}
}

void checkout(float total_ala, float total_com)
{
	struct customer makan[20];
	float total;
	total= total_ala+total_com;
	printf("\t\t      Total for alacarte : Rm%.2f\n", total_ala);
	printf("\t\t      Total for combo    : Rm%.2f\n\n", total_com);
	printf("\t\t    ===================================          ");
	printf("\n\t            Your total bill amount is Rm.%.2f,\n\t\t    Payment: CASH\n", total);
	printf("\t\t    ===================================          \n");
	int i, quantity;
	FILE *fwrite;
	fwrite = fopen("Receipt.txt", "w");
	fprintf(fwrite, "-----------------------------------------------------------\n");
	fprintf(fwrite, "                        Receipt\n");
	fprintf(fwrite, "-----------------------------------------------------------\n");
	fprintf(fwrite, "Code---------------------------------------------------Quantity--RM\n");
	for (i=0; i<20;i++)
	{
		fprintf(fwrite, "%d. %s %d\n", i+1, makan[i].food_name, quantity); 
	}
	fprintf(fwrite, "-----------------------------------------------------------\n");
	fprintf(fwrite, "Total payment				RM%.2f", total);		
	fclose(fwrite);
}

void exit(back)  /// Exit Screen
{
	printf("\n\n\t            ===============FOS==================          ");
	printf("   \n                    Thanks for choosing our restaurant\n\n");
	printf("                    We hope to see you again!  \n");
	printf("\t            ====================================  \n");
	getch();
	exit(0);
}
