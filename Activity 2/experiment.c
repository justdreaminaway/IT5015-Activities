#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
  
typedef struct {
	int group;
	char leader[100];
	char title[100];
	char desc[250];
	char field[100];
	char grade[10];
}experiment;
experiment records[9];


int main(void)
{

	FILE *fp = fopen("experiment.txt","r");
	experiment S;
    int count=0, total=0, x=0, i=0, y;
    int choice, display;

	for(total = 0; total < 19; total++)
	{
	 	char row[5000];
	 	fgets(row, 5000, (FILE*)fp);
	 	count++;
	 	if(count != 1)
	 	{
	 		total++;
	    	storeRecords(row,x);
	    	x++;
	 	}
	}
	
	displayOption();
	fflush(stdin);

	return 0;
}

void storeRecords(char characters[], int x)
{
   char *token = strtok(characters,",");
   int counter=0,i,j;

   while(token != NULL) 
   {		
		switch(counter){
			case 0:
			records[x].group = atoi(token);
			break;
			
			case 1:
			strcpy(records[x].leader, token);
			break;
			
			case 2:
			strcpy(records[x].title, token);
			break;
			
			case 3:
			strcpy(records[x].desc, token);
			break;
			
			case 4:
			strcpy(records[x].field, token);
			break;
			
			case 5:
			strcpy(records[x].grade, token);
			break;
		}	
	
		counter++;
		token = strtok(NULL,",");
   }
}

void sortRecords(int display){
	int i;
	
	switch(display){
    	case 1:
    	printf("\n\n*****************************************************************************\n\n");
    	printf("                          GROUP EXPERIMENT RECORDS                               \n\n");
    	printf("*****************************************************************************\n\n");   
 		for(i = 0; i < 9; i++){
 			printf("GROUP NUMBER: %d \tEXPERIMENT TITLE: %s\n", records[i].group, records[i].title);
		}
		break;	
		
		case 2:
    	printf("\n\n*****************************************************************************\n\n");
    	printf("                          BIOLOGY EXPERIMENT RECORDS                               \n\n");
    	printf("*****************************************************************************\n\n");   
 		for(i = 0; i < 9; i++){
 			if(strcmp(records[i].field, "Biology") == 0){
 				printf("GROUP NUMBER: %d \tEXPERIMENT TITLE: %s\n", records[i].group, records[i].title);
 			}
		}
		break;	
		
		case 3:
    	printf("\n\n*****************************************************************************\n\n");
    	printf("                          CHEMISTRY EXPERIMENT RECORDS                               \n\n");
    	printf("*****************************************************************************\n\n");   
 		for(i = 0; i < 9; i++){
 			if(strcmp(records[i].field, "Chemistry") == 0){
 				printf("GROUP NUMBER: %d \tEXPERIMENT TITLE: %s\n", records[i].group, records[i].title);
 			}
		}
		break;	
		
		case 4:
    	printf("\n\n*****************************************************************************\n\n");
    	printf("                          PHYSICS EXPERIMENT RECORDS                               \n\n");
    	printf("*****************************************************************************\n\n");   
 		for(i = 0; i < 9; i++){
 			if(strcmp(records[i].field, "Physics") == 0){
 				printf("GROUP NUMBER: %d \tEXPERIMENT TITLE: %s\n", records[i].group, records[i].title);
 			}
		}
		break;	
	}
}

void displayOption(){
	int display, choice, option;

	printf("[1] Display All Experiments\n[2] Display Biology Experiments\n[3] Display Chemistry Experiments\n[4] Display Physics Experiments\n");
	printf("\nSELECT DISPLAY OPTION: ");
	scanf("%d", &display);
	sortRecords(display);
	fflush(stdin);
	
	printf("\n[1] Select Another Display Option\n[2] View Group Details\n");
	printf("\nSELECT OPTION: ");
	scanf("%d", &option);
	
	if(option == 1){
		system("cls");
		displayOption();
	}else if (option == 2){
		printf("\n\nENTER GROUP NUMBER TO VIEW DETAILS: ");
		scanf("%d", &choice);
		system("cls");
		displayRecordDetails(choice);
	}
}

void displayRecordDetails(int number){
	int i, option;
	
	for(i = 0; records[i].group != number; i++);
	printf("*****************************************************************************\n");
    printf("                            EXPERIMENT DETAILS                               \n");
    printf("*****************************************************************************\n");   
	printf("\n[[ GROUP NUMBER ]]: %d\n", records[i].group);
	printf("[[ GROUP LEADER ]]: %s\n\n\n", records[i].leader);
	printf("[[ EXPERIMENT TITLE ]]: %s\n", records[i].title);
	printf("[[ EXPERIMENT DESCRIPTION ]]: \n%s\n\n\n", records[i].desc);
	printf("[[ FIELD ]]: %s\n", records[i].field);
	printf("[[ GRADE ]]: %s\n", records[i].grade);
	printf("*****************************************************************************\n");   
	fflush(stdin);
	printf("\n\n[1] Update Grade\n[2] Go Back\n");
	printf("\nSELECT AN OPTION: ");
	scanf("%d", &option);
	
	if(option == 1){
		updateGrade(number);
	}else if (option == 2){
		system("cls");
		displayOption();
	}	
}
//==================================================================================
void updateGrade(int grp){
	int option;
	char pass[]="Pass";
	char fail[]="Fail";
	
	printf("\nNote: Group %d Grade: %s",records[grp-1].group,records[grp-1].grade);
	fflush(stdin);
	
	//------------------------------------------------------------------------------
	printf("\n\nChange this group's Grade to:\n[1] Pass\n[2] Fail");
	printf("\nEnter your option: ");
	scanf("%d", &option);
	
	if(option == 1){
		strcpy(records[grp-1].grade,pass);
	}else if (option == 2){
		strcpy(records[grp-1].grade,fail);
	}
	
	//-----------------------------------------------------------------------------
	system("cls");
	printf("\n\n***Group's Grade has been successfully changed!***\n\n");
	
	displayRecordDetails(grp);
}
