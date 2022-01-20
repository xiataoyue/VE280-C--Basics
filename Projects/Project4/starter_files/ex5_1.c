#include <stdio.h>
#include <string.h>


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

int main() {
    char input[20];
    struct patient pat[100];
    int i = 0;

    printf("Welcome to the hospital management system, please type in your command.\n");
    scanf("%s", input);


    while (strcmp(input, "quit") != 0) {
        printf("> ");
        if (strcmp(input, "info") == 0) {
            char test[7];
            scanf("%s", test);
            if (i == 0) {
                printf("There is no patients under this ID yet.\n");
            } else {
                int flag = 0;
                for (int j = 0; j < i; j++) {
                    if (strcmp(pat[j].ID, test) == 0) {
                        flag = 1;
                        printf("%s Age: %d Temp: ", pat[j].ID, pat[j].age);
                        for (int k = pat[j].time; k >= 0; k--) {
                            if (k == 0) {
                                printf("%.1f\n", pat[j].temp[k]);
                            } else {
                                printf("%.1f ", pat[j].temp[k]);
                            }

                        }
                    }
                }
                if(flag == 0) printf("There is no patients under this ID yet.\n");
            }
            fflush(stdin);
            scanf("%s", input);
        } else if (strcmp(input, "checkIn") == 0) {
            int rep = 0;
            char sub[7];
            getchar();
            scanf("%s", sub);
            if(i != 0){
                for(int j = 0; j < i;j++){
                    if(!strcmp(sub, pat[j].ID)){
                        printf("Patient already exists in the system.\n");
                        rep = 1;
                        break;
                    }
                }
            }

            if (rep == 0) {
                strcpy(pat[i].ID, sub);
                pat[i].time = 0;
                printf("Please input this patient's age and temperature\n");
                scanf("%d %lf", &pat[i].age, &pat[i].temp[0]);
                printf("Registration succeed!\n");
                if (pat[i].temp[0] > 37.5) {
                    printf("Abnormal temperature detected!\n");
                }
                i = i + 1;
            }
            fflush(stdin);                        //clear the input in stdin so that scanf would not be skipped.
            scanf("%s", input);

        } else if (strcmp(input, "checkOut") == 0) {
            char test[7];
            int num = -1;
            scanf("%s",test);
            for(int j = 0; j < i; j++) {
                if (!strcmp(pat[j].ID, test)) {
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
                    for (int j = num + 1; j < i; j++) {
                        strcpy(pat[j - 1].ID, pat[j].ID);
                        pat[j - 1].age = pat[j].age;
                        for (int k = 0; k <= pat[j].time; k++) {
                            pat[j - 1].temp[k] = pat[j].temp[k];
                        }

                    }

                }
                printf("\n");
            }
            fflush(stdin);
            scanf("%s", input);
        } else if (strcmp(input, "edit") == 0) {
            char test[7];
            scanf("%s", test);
            for (int j = 0; j < i; j++) {
                if (!strcmp(pat[j].ID, test)) {
                    printf("Please input the updated temperature\n");
                    pat[j].time = pat[j].time + 1;
                    scanf("%lf", &pat[j].temp[pat[j].time]);
                    break;
                }
            }
            fflush(stdin);
            scanf("%s", input);
        } else if (strcmp(input, "order") == 0) {
            char com[20];
            scanf("%s",com);
            if (strcmp(com,"temp") == 0) {
                int arr[100];
                for (int j = 0; j < 100; j++) {
                    arr[j] = j;
                }
                for (int j = 0; j < i; j++) {
                    for (int k = i - 1; k > j; k--) {
                        printf("%d", k);
                        if (pat[k - 1].temp[pat[k - 1].time] > pat[k].temp[pat[k].time]) {
                            int temp = arr[k];
                            arr[k] = arr[k - 1];
                            arr[k - 1] = temp;
                        }
                    }
                }
                for (int j = 0; j < i; j++) {
                    printf("%s %d %.1f\n", pat[arr[j]].ID, pat[arr[j]].age, pat[arr[j]].temp[pat[arr[j]].time]);
                }
            }
            fflush(stdin);
            scanf("%s", input);

        } else {
            printf("Unknown command.\n");
            fflush(stdin);
            scanf("%s", input);
        }
    }

    printf("> Exit the system!\n");
    return 0;
}
