#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

void DOCTOR();
void PATIENT();
int CountDoctor(FILE *fptr1);
int CountPatient(FILE *fptr);
void ToUpperCase(char *str);

typedef struct {
    
    int Id, Age;
    char Name[50];
    char Address[50];
    char Disease[50];
    char Treat[50];
    char PhoneNumber[15];

} Patient;
Patient patient;

typedef struct {

    int Id, Age;
    char Name[50];
    char Address[50];
    char Specialization[50];
    char PhoneNumber[15];

} Doctor;
Doctor doctor;

int PatientCount = 0, DoctorCount = 0;

void AddPatient(FILE *fptr) {
    system("cls");
    printf("\033[1;39m");
    printf("Enter the patient's data: \n");
    srand(time(0));
    patient.Id = rand();
    printf("Id: %d\n", patient.Id);
    printf("Full name: ");
    fgets(patient.Name, sizeof(patient.Name), stdin);
    patient.Name[strlen(patient.Name) - 1] = '\0';
    ToUpperCase(patient.Name);
    printf("Age: ");
    scanf("%d", &patient.Age);
    getchar();
    printf("Phone number: ");
    fgets(patient.PhoneNumber, sizeof(patient.PhoneNumber), stdin);
    patient.PhoneNumber[strlen(patient.PhoneNumber) - 1] = '\0';
    printf("Address: ");
    fgets(patient.Address, sizeof(patient.Address), stdin);
    patient.Address[strlen(patient.Address) - 1] = '\0';
    printf("Disease: ");
    fgets(patient.Disease, sizeof(patient.Disease), stdin);
    patient.Disease[strlen(patient.Disease) - 1] = '\0';
    printf("Treat: ");
    fgets(patient.Treat, sizeof(patient.Treat), stdin);
    patient.Treat[strlen(patient.Treat) - 1] = '\0';
    fwrite(&patient, sizeof(Patient), 1, fptr);
    printf("\033[1;32mPatient Added successfully\033[0m\n");
    Sleep(1000);
}

void AddDcotor(FILE *fptr1) {
    system("cls");
    printf("\033[1;39m");
    printf("Enter the doctor's data: \n");
    srand(time(0));
    doctor.Id = rand();
    printf("Id: %d\n", doctor.Id);
    printf("Full name: ");
    fgets(doctor.Name, sizeof(doctor.Name), stdin);
    doctor.Name[strlen(doctor.Name) -1] = '\0';
    ToUpperCase(doctor.Name);
    printf("Age: ");
    scanf("%d", &doctor.Age);
    getchar();
    printf("Phone number: ");
    fgets(doctor.PhoneNumber, sizeof(doctor.PhoneNumber), stdin);
    doctor.PhoneNumber[strlen(doctor.PhoneNumber) -1] = '\0';
    printf("Address: ");
    fgets(doctor.Address, sizeof(doctor.Address), stdin);
    doctor.Address[strlen(doctor.Address) -1] = '\0';
    printf("Specialization: ");
    fgets(doctor.Specialization, sizeof(doctor.Specialization), stdin);
    doctor.Specialization[strlen(doctor.Specialization) -1] = '\0';
    fwrite(&doctor, sizeof(Doctor), 1, fptr1);
    printf("\033[1;32mDoctor Added successfully\033[0m\n");
    Sleep(1000);
}

void DisplayPatient(FILE *fptr) {
    system("cls");
    printf("\033[1;39m");
    PatientCount = CountPatient(fptr);
    rewind(fptr);
    if (PatientCount == 0) {
        printf("\033[1;31mERROR: The list of patinets is empty\033[0m\n");
        Sleep(1500);
    } else {
        rewind(fptr);
        printf("***************Patient's List***************\n");
        while (fread(&patient, sizeof(Patient), 1, fptr) == 1) {
            printf(" Id: %d\n", patient.Id);
            printf(" Name: %s\n", patient.Name);
            printf(" Age: %d\n", patient.Age);
            printf(" Phone number: %s\n", patient.PhoneNumber);
            printf(" Address: %s\n", patient.Address);
            printf(" Disease: %s\n", patient.Disease);
            printf(" Treat: %s\n", patient.Treat);
            printf("*********************************************\n");
        }
        system("pause");
    }
}

void DisplayDoctor(FILE *fptr1) {
    system("cls");
    printf("\033[1;39m");
    DoctorCount = CountDoctor(fptr1);
    rewind(fptr1);
    if (DoctorCount == 0) {
        printf("\033[1;31mERROR: The list of doctors is empty\033[0m\n");
        Sleep(1500);
    } else {
        rewind(fptr1);
        printf("***************Doctor's List****************\n");
        while (fread(&doctor, sizeof(Doctor), 1, fptr1) == 1) {
            printf(" Id: %d\n", doctor.Id);
            printf(" Name: %s\n", doctor.Name);
            printf(" Age: %d\n", doctor.Age);
            printf(" Phone number: %s\n", doctor.PhoneNumber);
            printf(" Address: %s\n", doctor.Address);
            printf(" Specialization: %s\n", doctor.Specialization);
            printf("*********************************************\n");
        }
        system("pause");
    }
}

void SearchPatient(FILE *fptr) {
    system("cls");
    printf("\033[1;39m");
    PatientCount = CountPatient(fptr);
    if (PatientCount == 0) {
        printf("\033[1;31mERROR: There is no patient to search for\033[0m\n");
        Sleep(1500);
    } else {
        int id, choice, test, found = 0;
        char SName[50], SPhon[15];
        rewind(fptr);
        do {
            printf("\033[1;39m");
            printf("How do you want to search for the patient:\n[1] By id\n[2] By name\n[3] By phone number\nEnter your choice: ");
            test = scanf("%d", &choice);
            while (getchar() != '\n');
            if (test == 0) {
                printf("\033[1;31mERROR: Enter a valid input\033[0m\n");
                Sleep(1500);
                system("cls");
            }
        } while (test == 0);
        switch (choice) {
            case 1:
                system("cls");
                printf("\033[1;39m");
                printf("Enter the patient's id to search for: ");
                scanf("%d", &id);
                while (fread(&patient, sizeof(Patient), 1, fptr) == 1) {
                    if (patient.Id == id) {
                        found = 1;
                        break;
                    }
                }
                if (found == 1) {
                    printf("\033[1;32mPatient found\033[0m\n");
                    Sleep(1000);
                    system("cls");
                    printf("\033[1;39m");
                    printf("--------------------------------------------\n");
                    printf(" Id: %d\n", patient.Id);
                    printf(" Name: %s\n", patient.Name);
                    printf(" Age: %d\n", patient.Age);
                    printf(" Phone number: %s\n", patient.PhoneNumber);
                    printf(" Address: %s\n", patient.Address);
                    printf(" Disease: %s\n", patient.Disease);
                    printf(" Treat: %s\n", patient.Treat);
                    printf("--------------------------------------------\n");
                    system("pause");
                } else {
                    printf("\033[1;31mPatient not found\033[0m\n");
                    Sleep(500);
                    printf("\033[1;31mThere is no patient with the id: %d\033[0m\n", id);
                    Sleep(1500);
                }
            break;
            case 2:
                system("cls");
                printf("\033[1;39m");
                printf("Enter the patient's name to search for: ");
                fgets(SName, sizeof(SName), stdin);
                SName[strlen(SName) -1] = '\0';
                ToUpperCase(SName);
                while (fread(&patient, sizeof(Patient), 1, fptr) == 1) {
                    
                    found = strcmp(SName, patient.Name);
                    if (found == 0)
                        break;
                }
                if (found == 0) {
                        printf("\033[1;32mPatient found\033[0m\n");
                        Sleep(1000);
                        system("cls");
                        printf("\033[1;39m");
                        printf("--------------------------------------------\n");
                        printf(" Id: %d\n", patient.Id);
                        printf(" Name: %s\n", patient.Name);
                        printf(" Age: %d\n", patient.Age);
                        printf(" Phone number: %s\n", patient.PhoneNumber);
                        printf(" Address: %s\n", patient.Address);
                        printf(" Disease: %s\n", patient.Disease);
                        printf(" Treat: %s\n", patient.Treat);
                        printf("--------------------------------------------\n");
                        system("pause");
                } else {
                    printf("\033[1;31mPatient not found\033[0m\n");
                    Sleep(500);
                    printf("\033[1;31mThere is no patient with the name: %s\033[0m\n", SName);
                    Sleep(1500);
                    system("cls");
                    
                }
            break;
            case 3:
                system("cls");
                printf("\033[1;39m");
                printf("Enter the patient's phone number to search for: ");
                fgets(SPhon, sizeof(SPhon), stdin);
                SPhon[strlen(SPhon) -1] = '\0';
                while (fread(&patient, sizeof(Patient), 1, fptr) == 1) {
                    found = strcmp(patient.PhoneNumber, SPhon); 
                    if (found == 0)
                        break;
                }
                if (found == 0) {
                    printf("\033[1;32mPatient found\033[0m\n");
                    Sleep(1000);
                    system("cls");
                    printf("\033[1;39m");
                    printf("--------------------------------------------\n");
                    printf(" Id: %d\n", patient.Id);
                    printf(" Name: %s\n", patient.Name);
                    printf(" Age: %d\n", patient.Age);
                    printf(" Phone number: %s\n", patient.PhoneNumber);
                    printf(" Address: %s\n", patient.Address);
                    printf(" Disease: %s\n", patient.Disease);
                    printf(" Treat: %s\n", patient.Treat);
                    printf("--------------------------------------------\n");
                    system("pause");
                } else {
                    printf("\033[1;31mPatient not found\033[0m\n");
                    Sleep(500);
                    printf("\033[1;31mThere is no patient with the phone numbe: %s\033[0m\n", SPhon);
                    Sleep(1500);
                    system("cls");
                }
            break;
            default:
                printf("\033[1;31mERROR: Please Enter a valid input\033[0m\n");
                Sleep(1500);
                SearchPatient(fptr);
            break;
        }
    }
}

void SearchDoctor(FILE *fptr1) {
    system("cls");
    printf("\033[1;39m");
    DoctorCount = CountDoctor(fptr1);
    if (DoctorCount == 0) {
        printf("\033[1;31mERROR: There is no doctor to search for\033[0m\n");
        Sleep(1500);
    } else {
        int id, choice, test, found = 0;
        char SName[50], SPhon[15];
        
        rewind(fptr1);
        do {
            printf("\033[1;39m");
            printf("How do you want to search for the doctor:\n[1] By id\n[2] By name\n[3] By phone number\nEnter your choice: ");
            test = scanf("%d", &choice);
            while (getchar() != '\n');
            if (test == 0) {
                printf("\033[1;31mERROR: Enter a valid input\033[0m\n");
                Sleep(1500);
                system("cls");
            }
        } while (test == 0);
        switch (choice) {
            case 1:
                system("cls");
                printf("Enter the doctor's id to search for: ");
                scanf("%d", &id);
                while (fread(&doctor, sizeof(Doctor), 1, fptr1) == 1) {
                    if (doctor.Id == id) {
                        found = 1;
                        break;
                    }
                }
                if (found == 1) {
                    printf("\033[1;32mDoctor found\033[0m\n");
                    Sleep(1000);
                    system("cls");
                    printf("\033[1;39m");
                    printf("--------------------------------------------\n");
                    printf("Id: %d\n", doctor.Id);
                    printf("Name: %s\n", doctor.Name);
                    printf("Age: %d\n", doctor.Age);
                    printf("Phone number: %s\n", doctor.PhoneNumber);
                    printf("Address: %s\n", doctor.Address);
                    printf("Specialization: %s\n", doctor.Specialization);
                    printf("--------------------------------------------\n");
                    system("pause");
                } else {
                    printf("\033[1;31mDoctor not found\033[0m\n");
                    Sleep(500);
                    printf("\033[1;31mThere is no doctor with the id: %d\033[0m\n", id);
                    Sleep(1500);
                }
            break;
            case 2:
                system("cls");
                printf("\033[1;39m");       
                printf("Enter the doctor's name to search for: ");
                fgets(SName, sizeof(SName), stdin);
                SName[strlen(SName) -1] = '\0';
                ToUpperCase(SName);
                while (fread(&doctor, sizeof(Doctor), 1, fptr1) == 1) {
                    
                    found = strcmp(SName, doctor.Name);
                    if (found == 0)
                        break;
                }
                if (found == 0) {
                    printf("\033[1;32mDoctor found\033[0m\n");
                    Sleep(1000);
                    system("cls");
                    printf("\033[1;39m");
                    printf("--------------------------------------------\n");
                    printf("Id: %d\n", doctor.Id);
                    printf("Name: %s\n", doctor.Name);
                    printf("Age: %d\n", doctor.Age);
                    printf("Phone number: %s\n", doctor.PhoneNumber);
                    printf("Address: %s\n", doctor.Address);
                    printf("Specialization: %s\n", doctor.Specialization);
                    printf("--------------------------------------------\n");
                    system("pause");
                } else {
                    printf("\033[1;31mDoctor not found\033[0m\n");
                    Sleep(500);
                    printf("\033[1;31mThere is no doctor with the name: %s\033[0m\n", SName);
                    Sleep(1500);
                    system("cls");
                }
            break;
            case 3:
                system("cls");
                printf("\033[1;39m");       
                printf("Enter the doctor's phone number to search for: ");
                fgets(SPhon, sizeof(SPhon), stdin);
                SPhon[strlen(SPhon) -1] = '\0';
                while (fread(&doctor, sizeof(Doctor), 1, fptr1) == 1) {
                    found = strcmp(SPhon, doctor.PhoneNumber);
                    if (found == 0)
                        break;
                }           
                if (found == 0) {
                    printf("\033[1;32mDoctor found\033[0m\n");
                    Sleep(1000);
                    system("cls");
                    printf("\033[1;39m");
                    printf("--------------------------------------------\n");
                    printf("Id: %d\n", doctor.Id);
                    printf("Name: %s\n", doctor.Name);
                    printf("Age: %d\n", doctor.Age);
                    printf("Phone number: %s\n", doctor.PhoneNumber);
                    printf("Address: %s\n", doctor.Address);
                    printf("Specialization: %s\n", doctor.Specialization);
                    printf("--------------------------------------------\n");
                    system("pause");
                } else {
                    printf("\033[1;31mDoctor not found\033[0m\n");
                    Sleep(500);
                    printf("\033[1;31mThere is no doctor with the phone number: %s\033[0m\n", SPhon);
                    Sleep(1500);
                    system("cls");
                }
            break;
            default:
                printf("\033[1;31mERROR: Please Enter a valid input\033[0m\n");
                Sleep(1500);
                SearchPatient(fptr1);
            break;
        }
    }
}

void DeletePatient(FILE *fptr) {
    system("cls");
    printf("\033[1;39m");
    PatientCount = CountPatient(fptr);
    if (PatientCount == 0) { 
        printf("\033[1;31mERROR: There is no patient to delete\033[0m\n");
        Sleep(1000);
    } else {
        int id, found = 0;
        FILE *temp = fopen("temp.bin", "ab+");
        rewind(fptr);
        printf("Enter the patient's id to delte: ");
        scanf("%d", &id);
        while (fread(&patient, sizeof(Patient), 1, fptr) == 1) {
            if (patient.Id != id) {
                fwrite(&patient, sizeof(Patient), 1, temp);
            } else {
                found = 1;
            }
        }
        fclose(fptr);
        fclose(temp);
        if (found == 1) {
            remove("patient.bin");
            rename("temp.bin", "patient.bin");
            printf("\033[1;32mPatient deleted successfully\033[0m\n");
        } else {
            remove("temp.bin");
            printf("\033[1;31mThere is no patient with the id: %d\033[0m\n", id);
            Sleep(1500);
        }
        fptr = fopen("patient.bin", "ab+");
    }
}

void DeleteDoctor(FILE *fptr1) {
    system("cls");
    printf("\033[1;39m");
    DoctorCount = CountDoctor(fptr1);
    if (DoctorCount == 0) {
        printf("\033[1;31mERROR: There is no doctor to delete\033[0m\n");
        Sleep(1000);
    } else {
        int id, found = 0;
        FILE *temp1 = fopen("temp1.bin", "ab+");
        rewind(fptr1);
        printf("Enter the doctor's id to delte: ");
        scanf("%d", &id);
        while (fread(&doctor, sizeof(Doctor), 1, fptr1) == 1) {
            if (doctor.Id != id) {
                fwrite(&doctor, sizeof(Doctor), 1, temp1);
            } else {
                found = 1;
            }
        }
        fclose(fptr1);
        fclose(temp1);
        if (found == 1) {
            remove("doctor.bin");
            rename("temp1.bin", "doctor.bin");
            printf("\033[1;32mDoctor deleted successfully\033[0m\n");
        } else {
            remove("temp1.bin");
            printf("\033[1;31mThere is no doctor with the id: %d\033[0m\n", id);
            Sleep(1500);
        }
        fptr1 = fopen("doctor.bin", "ab+");
    }
}

void EditPatient(FILE *fptr) {
    system("cls");
    printf("\033[1;39m");
    PatientCount = CountPatient(fptr);
    if (PatientCount == 0) {
        printf("\033[1;31mERROR: There is no patient to edit\033[0m\n");
    } else {
        int id, NewId, EccpctId, found = 0;
        char choice;
        FILE *temp = fopen("temp.bin", "ab+");
        rewind(fptr);
        printf("Enter the patient's id: ");
        scanf("%d", &id);
        while (fread(&patient, sizeof(Patient), 1, fptr) == 1) {
            
            if (patient.Id == id) {
                system("cls");
                found = 1;
                getchar();
                printf("Enter the  new patient's data\n");
                printf("Full name: ");
                fgets(patient.Name, sizeof(patient.Name), stdin);
                patient.Name[strlen(patient.Name) -1] = '\0';
                ToUpperCase(patient.Name);
                printf("Phone number: ");
                fgets(patient.PhoneNumber, sizeof(patient.PhoneNumber), stdin);
                patient.PhoneNumber[strlen(patient.PhoneNumber) -1] = '\0';
                printf("Age: ");
                scanf("%d", &patient.Age);
                getchar();
                printf("Address: ");
                fgets(patient.Address, sizeof(patient.Address), stdin);
                patient.Address[strlen(patient.Address) -1] = '\0';
                printf("Disease: ");
                fgets(patient.Disease, sizeof(patient.Disease), stdin);
                patient.Disease[strlen(patient.Disease) -1] = '\0';
                printf("Treat: ");
                fgets(patient.Treat, sizeof(patient.Treat), stdin);
                patient.Treat[strlen(patient.Treat) -1] = '\0';
                fwrite(&patient, sizeof(Patient), 1, temp);
            } else {
                fwrite(&patient, sizeof(Patient), 1, temp);
            }            
        }
        fclose(fptr);
        fclose(temp);
        if (found == 1) {
            remove("patient.bin");
            rename("temp.bin", "patient.bin");
            printf("\033[1;32mPatient edited successfully\033[0m\n");
            Sleep(1000);
            system("cls");
            printf("\033[1;39m");
            printf("--------------------------------------------\n");
            printf("Patient's data after edit: \n");
            printf("Id: %d\n", patient.Id);
            printf("Name: %s\n", patient.Name);
            printf("Age: %d\n", patient.Age);
            printf("Phone number: %s\n", patient.PhoneNumber);
            printf("Address: %s\n", patient.Address);
            printf("Disease: %s\n", patient.Disease);
            printf("Treat: %s\n", patient.Treat);
            printf("--------------------------------------------\n");
            system("pause");
            
        } else {
            remove("temp.bin");
            printf("\033[1;31mThere is no patient with the id: %d\033[0m\n", id);
            Sleep(1500);
        }
        fptr = fopen("patient.bin", "ab+");
    }
}

void EditDoctor(FILE *fptr1) {
    system("cls");
    printf("\033[1;39m");
    DoctorCount = CountDoctor(fptr1);
    if (DoctorCount == 0) {
        printf("\033[1;31mERROR: There is no doctor to edit\033[0m\n");
    } else {
        int id, NewId, EccpctdId, found = 0;
        FILE *temp1 = fopen("temp1.bin", "ab+");
        rewind(fptr1);
        printf("Enter the doctor's id: ");
        scanf("%d", &id);
        while (fread(&doctor, sizeof(Doctor), 1, fptr1) == 1) {            
            if (doctor.Id == id) {
                found = 1;
                getchar();
                printf("Enter the new doctor's data\n");
                printf("Full name: ");
                fgets(doctor.Name, sizeof(doctor.Name), stdin);
                doctor.Name[strlen(doctor.Name) -1] = '\0';
                ToUpperCase(doctor.Name);
                printf("Phone number: ");
                fgets(doctor.PhoneNumber, sizeof(doctor.PhoneNumber), stdin);
                doctor.PhoneNumber[strlen(doctor.PhoneNumber) -1] = '\0';
                printf("Age: ");
                scanf("%d", &doctor.Age);
                getchar();
                printf("Address: ");
                fgets(doctor.Address, sizeof(doctor.Address), stdin);
                doctor.Address[strlen(doctor.Address) -1] = '\0';
                printf("Specialization: ");
                fgets(doctor.Specialization, sizeof(doctor.Specialization), stdin);
                doctor.Specialization[strlen(doctor.Specialization) -1] = '\0';
                fwrite(&doctor, sizeof(Doctor), 1, temp1);
            } else {
                fwrite(&doctor, sizeof(Doctor), 1, temp1);
            }
        }
        fclose(fptr1);
        fclose(temp1);
        if (found == 1) {
            remove("doctor.bin");
            rename("temp1.bin", "doctor.bin");
            printf("\033[1;32mDoctor edited successfully\033[0m\n");
            Sleep(1000);
            system("cls");
            printf("\033[1;39m");
            printf("--------------------------------------------\n");
            printf("Doctor's data after edit: \n");
            printf("Id: %d\n", doctor.Id);
            printf("Name: %s\n", doctor.Name);
            printf("Age: %d\n", doctor.Age);
            printf("Phone number: %s\n", doctor.PhoneNumber);
            printf("Address: %s\n", doctor.Address);
            printf("Specialization: %s\n", doctor.Specialization);
            printf("--------------------------------------------\n");
            system("pause");
        } else {
            remove("temp1.bin");
            printf("\033[1;31mThere is no doctor with the id: %d\033[0m\n", id);
            Sleep(1500);
        }
        fptr1 = fopen("doctor.bin", "ab+");
    }
}

int main() {
    system("cls");
    int choice, test;
    printf("\033[1;39m");
    printf("**************Doctor's office**************\n");
    printf("   What operation would you like to make: \n");
    printf("   [1] Patients control panel\n   [2] Doctors control panel\n   [3] Exit\n*******************************************\n");
    do {
        printf("Enter your choice: ");
        test = scanf("%d", &choice);
        while (getchar() != '\n');
        if (test == 0) {
            printf("\033[1;31mERROR: Enter a valid input\033[0m\n");
            Sleep(1500);
            main();
        }
    } while (test == 0);
    switch (choice) {
        case 1:
            system("cls");
            PATIENT();
        break;
        case 2:
            system("cls");
            DOCTOR();
        break;
        case 3:
            system("cls");
            exit(0);
        break;
        default:
            printf("\033[1;31mERROR: Please Enter a valid input\033[0m\n");
            Sleep(1500);
            main();
        break;
    }
    return 0;
}

void PATIENT() {
    system("cls");
    FILE *fptr = fopen("patient.bin", "ab+");
    int choice, test;
    while (1) {       
        do {
            PatientCount = CountPatient(fptr);
            printf("\033[1;39m");
            printf("****************Patient Count: [%d]*****************\n", PatientCount);
            printf("[1] Add Patient\n[2] Delete patient\n[3] Search for a patient\n[4] Edit patint's data\n[5] Display the list of patients\n[6] Go Back to Menu\n[7] Exit\n");
            printf("***************************************************\n");       
            printf("Enter your choice: ");
            test = scanf("%d", &choice);
            while (getchar() != '\n');
            if (test == 0) {
                printf("\033[1;31mERROR: Enter a valid input\033[0m\n");
                Sleep(1500);
                system("cls");
            }
        } while (test == 0);
        switch (choice) {
            case 1:
                AddPatient(fptr);
                Sleep(1000);
                system("cls");
            break;
            case 2:
                DeletePatient(fptr);
                Sleep(1000);
                system("cls");
            break;
            case 3:
                SearchPatient(fptr);
                Sleep(1000);
                system("cls");
            break;
            case 4:
                EditPatient(fptr);
                Sleep(1000);
                system("cls");
            break;
            case 5:
                DisplayPatient(fptr);
                system("cls");
            break;
            case 6:
                main();
            break;
            case 7:
                fclose(fptr);
                system("cls");
                exit(0);
            break;
            default:
                printf("\033[1;31mERROR: Please Enter a valid input\033[0m\n");
                Sleep(1500);
                PATIENT();
            break;
        }
    }
}

void DOCTOR() {
    system("cls");
    FILE *fptr1 = fopen("doctor.bin", "ab+");
    int choice, test;
    while (1) {
        do {
            DoctorCount = CountDoctor(fptr1);
            printf("\033[1;39m");
            printf("**************Doctor Count: [%d]******************\n", DoctorCount);
            printf("[1] Add doctor\n[2] Delte doctor\n[3] Search for a doctor\n[4] Modify a doctor's data\n[5] Diplay the list of doctors\n[6] Go Back to Menu\n[7] Exit\n");
            printf("**************************************************\n");
            printf("Enter your choice: ");
            test = scanf("%d", &choice);
            while (getchar() != '\n');
            if (test == 0) {
                printf("\033[1;31mERROR: Enter a valid input\033[0m\n");
                Sleep(1500);
                system("cls");
            }
        } while (test == 0);
        switch (choice) {
            case 1:
                AddDcotor(fptr1);
                Sleep(1000);
                system("cls");
            break;
            case 2:
                DeleteDoctor(fptr1);
                Sleep(1000);
                system("cls");
            break;
            case 3:
                SearchDoctor(fptr1);
                Sleep(1000);
                system("cls");
            break;
            case 4:
                EditDoctor(fptr1);
                Sleep(1000);
                system("cls");
            break;
            case 5:
                DisplayDoctor(fptr1);
                system("cls");
            break;
            case 6:
                main();
            break;
            case 7:
                fclose(fptr1);
                system("cls");
                exit(0);
            break;
            default:
                printf("\033[1;31mERROR: Please Enter a valid input\033[0m\n");
                Sleep(1500);
                DOCTOR();
            break;
        }
    }
}

int CountPatient(FILE *fptr) {
    PatientCount = 0;
    rewind(fptr);
    while (fread(&patient, sizeof(Patient), 1, fptr) == 1) {
        PatientCount++;
    }
    return PatientCount;
}

int CountDoctor(FILE *fptr1) {
    DoctorCount = 0;
    rewind(fptr1);
    while (fread(&doctor, sizeof(Doctor), 1, fptr1) == 1) {
        DoctorCount++;
    }
    return DoctorCount;
}

void ToUpperCase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}