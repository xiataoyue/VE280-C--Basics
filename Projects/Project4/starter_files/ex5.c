#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct patient{
    char ID[7];
    int age;
    double temp[10];
    int time;
};

void swap(int *a, int*b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main(int argc,char* argv[]) {
    struct patient pat[100];
    int i = 0;

    printf("Welcome to the hospital management system, please type in your command.\n");
    int count = 1;


    while (count < argc) {
        printf("> ");
        if (strcmp(argv[count], "info") == 0) {
            if (i == 0) {
                printf("There is no patients under this ID yet.\n");
            } else {
                int flag = 0;
                for (int j = 0; j < i; j++) {
                    if (strcmp(pat[j].ID, argv[count + 1]) == 0) {
                        flag = 1;
                        printf("%s Age: %d Temp: ", pat[j].ID, pat[j].age);
                        for (int k = pat[j].time; k >= 0; k--) {
                            if (k == 0) {
                                printf("%g\n", pat[j].temp[k]);
                            } else {
                                printf("%g ", pat[j].temp[k]);
                            }

                        }
                    }
                }
                if(flag == 0) printf("There is no patients under this ID yet.\n");
            }
            count = count + 2;
        } else if (strcmp((argv[count]), "checkIn") == 0) {
            int rep = 0;
            char id[7];
            count = count + 1;
            strcpy(id, argv[count]);
            if(i != 0){
                for(int j = 0; j < i;j++){
                    if(strcmp(id, pat[j].ID) == 0){
                        printf("Patient already exists in the system.\n");
                        rep = 1;
                        break;
                    }
                }
            }

            if (rep == 0) {
                strcpy(pat[i].ID, id);
                pat[i].time = 0;
                printf("Please input this patient's age and temperature\n");
                pat[i].age = atoi(argv[count + 1]);
                pat[i].temp[0] = atof(argv[count + 2]);
                count = count + 2;

                printf("Registration succeed!\n");
                if (pat[i].temp[0] > 37.5) {
                    printf("Abnormal temperature detected!\n");
                }
                i = i + 1;
            }
            count = count + 1;

        } else if (strcmp(argv[count], "checkOut") == 0) {
            int num = -1;
            count = count + 1;
            for(int j = 0; j < i; j++) {
                if (!strcmp(pat[j].ID, argv[count])) {
                    num = j;
                    break;
                }
            }
            if(num == -1){
                printf("Patient not in the system.\n");
            }else {
                if (num == i - 1) {
                    i = i - 1;
                } else {
                    for (int j = num + 1; j < i - 1; j++) {
                        strcpy(pat[j - 1].ID, pat[j].ID);
                        pat[j - 1].age = pat[j].age;
                        for (int k = 0; k <= pat[j].time; k++) {
                            pat[j - 1].temp[k] = pat[j].temp[k];
                        }

                    }

                }
            }
            count = count + 1;
        } else if (strcmp(argv[count], "edit") == 0) {
            count = count + 1;
            for (int j = 0; j < i; j++) {
                if (!strcmp(pat[j].ID, argv[count])) {
                    printf("Please input the updated temperature\n");
                    pat[j].time = pat[j].time + 1;
                    count = count + 1;
                    pat[j].temp[pat[j].time] = atoi(argv[count]);

                    break;
                }
            }
            count = count + 1;
        } else if (strcmp(argv[count], "order") == 0) {
            count = count + 1;
            if (strcmp(argv[count],"temp") == 0) {
                int arr[100];
                for (int j = 0; j < 100; j++) {
                    arr[j] = j;
                }
                for (int j = 0; j < i; j++) {
                    for (int k = 0; k < i - j - 1; k++) {
                        if (pat[k].temp[pat[k].time] > pat[k + 1].temp[pat[k + 1].time]) {
                            swap(&arr[k], &arr[k + 1]);
                        }
                    }
                }
                for (int j = 0; j < i; j++) {
                    printf("%s %d %g\n", pat[arr[j]].ID, pat[arr[j]].age, pat[arr[j]].temp[pat[arr[j]].time]);
                }
            }
            count = count + 1;

        } else if(strcmp(argv[count], "quit") == 0){
            break;
        } else {
            printf("Unknown command.\n");
            count = count + 1;

        }
    }

    printf("Exit the system!\n");
    return 0;
}