#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
  


int main(void)
{

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
