/*
CO253 Mini Project
Author-E/18/415
*/

//Importing required header files
#include<stdio.h>                    
#include<string.h>                

//Declare a structure type for storing data.
typedef struct {                         
    int NIC;
    char fullname[40];
    int age;
    char gender[8];
    char admissionDate [15];
} patient_t;

//Declaration and initialization of some required variables
int patient_No=0,nic_no;


//Make this variable static so that it can be accessed anywhere from this code file as a database.
static patient_t patient_details[100];

//Declaring function prototypes for all the functions
void printAllRecords();       
void deletePatientRecord(); 
void showPatientDetails();     
void terminalUI();  
void addPatientDetails();
                                
int main() {
    int option;
    //Print the UI of the databse by calling this function.
    terminalUI();
    while(1){
        //Take input for options from user and proceed with assigned functions according to input.
        printf("------------------\n");
        printf("ENTER OPTION [0-4]\n");
        printf("------------------\n");
        scanf("%d",&option);
    switch(option)   
	{	
    //Exit the program.
	case 0:                    
    	    return 0;
    //Add patient record for a single patient.
	case 1:
	        addPatientDetails(); 
            putchar('\n');   
            break;   
    //Show a particular patient's record.
	case 2:
	        showPatientDetails();       
            putchar('\n'); 
            break;
    //Print all the records in the volatile database.
    case 3:
    	    printAllRecords();
            putchar('\n');  
            break;    
    //Delete a particular patient's record.
	case 4:
	        deletePatientRecord();
            putchar('\n'); 
            break;
    //If any other choice is given as input, prompt the use to enter a valid input.
	default:
	        printf("Enter a proper option");
            putchar('\n'); 
            break;
	    }
    }
    return 0;
}


//Function to add Patient Record
void addPatientDetails(){
    NIC:
    printf("Enter the NIC number (8 numbers): ");
    scanf("%d",&patient_details[patient_No].NIC);

    //make a copy of NIC number so that the real data is not changed while finding the length.
    int count = 0,NIC_Copy=patient_details[patient_No].NIC;
    //Find the length of NIC number and check whether the length is 10.
    while (NIC_Copy != 0)
    {
        NIC_Copy=NIC_Copy/ 10;
        ++count;
    }
    if(count!=8)       //check whether the input is a valid
	{
		printf(" Invalid NIC number. \n");
		goto NIC;
	}

    //Fullname
    printf("Enter Full Name of Patient: ");
    scanf(" %39[^\n]",patient_details[patient_No].fullname);

    //Age
    AGE:
    printf("Enter age (0<age<120): ");
    scanf("%d",&patient_details[patient_No].age);
    if ((patient_details[patient_No].age<0)||(patient_details[patient_No].age>120)){
        printf(" Invalid Age!\n");
		goto AGE;
    }

    //Gender
    GENDER:
    printf("Enter the gender(Male/Female): ");
    scanf("%s",patient_details[patient_No].gender);
    
    //Admission date
    DATE:
    printf("Enter the Admission Date (DD/MM/YYYY): ");
    scanf("%s",patient_details[patient_No].admissionDate);
    if (strlen(patient_details[patient_No].admissionDate)!=10){
        printf("Invalid Date format!\n");
        goto DATE;
    }
    patient_No=patient_No+1;

}

//Function to display requested patient's details.
void showPatientDetails(){
    //check variable ensures whether a requested data is in the volatile database or not.
    int check=0;
    printf("Enter Patient's NIC Number:");
    scanf("%d",&nic_no);
    int i=0;
    for (i=0; i<patient_No ;i++) {
        //Compare NIC number with available NIC in volatile database, and check for availability.
        if(patient_details[i].NIC==nic_no){
            check=1;
            break;
        }
    }
    if (check==1){
        printf("%s\t %d\t %s\t %d \t %s\t \n",patient_details[i].fullname, patient_details[i].age, patient_details[i].gender, patient_details[i].NIC,  patient_details[i].admissionDate);
    }
    //if check=0, then display a message that requested data is not in database.
    else{
        printf("No patient with the given NIC Number!\n");
    }
}

void terminalUI(){
    printf("\n\n--------------------------------------------\n");
    printf("COVID-19 PATIENT MANAGEMENT SYSTEM\n");
    printf("--------------------------------------------\n");
    printf("0. Quit\n");
    printf("1. Add a Patient Record\n");
    printf("2. Print a Patient Record\n");
    printf("3. Print all Patient Record\n");
    printf("4. Delete a Patient Record\n");
}

void printAllRecords(){
    for (int i=0;i<patient_No;i++){
        printf("%s\t %d\t %s\t %d \t %s\t \n",patient_details[i].fullname, patient_details[i].age, patient_details[i].gender, patient_details[i].NIC,  patient_details[i].admissionDate);			
	}
}

void deletePatientRecord(){
    //check variable ensures whether a requested data is in the volatile database or not.
    int check=0,i=0;    
    printf("Enter Patient's NIC Number: ");
    scanf("%d",&nic_no);
    for(i=0;i<patient_No;i++){
            if(patient_details[i].NIC==nic_no) {
                check=1;
                break;			 
        }
    }
    if (check==1){
            for(int j=i;j<patient_No;j++){
                patient_details[j]=patient_details[j+1];
             }
            patient_No=patient_No-1;
            printf("Data of requested patient is deleted!\n");        
    }
    //if check=0, then display a message that requested data is not in database.
    else{
        printf("No patient with the given NIC Number!\n");
    }
}
