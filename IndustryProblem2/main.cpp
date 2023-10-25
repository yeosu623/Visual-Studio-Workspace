//#include <stdio.h>
//#include <stdlib.h> 
//
//#define SIZE 10000
//
//void test_main(void);
//
//static int stack[10][SIZE];
//
//static int sp[10];
//
//static int queue[SIZE];
//
//static int qs;
//
//static int hold;
//
//static long long SCORE = 0;
//
//void my_push(int s)
//{
//    SCORE++;
//    stack[s][sp[s]++] = hold;
//}
//
//int my_pop(int s)
//{
//    SCORE++;
//    hold = stack[s][--sp[s]];
//    stack[s][sp[s]] = -1;
//    return hold;
//}
//
//void enqueue(void)
//{
//    queue[qs++] = hold;
//    hold = -1;
//}
//
//static void build_data(void)
//{
//    for (int c = 0; c < SIZE; c++)
//    {
//        stack[0][c] = rand() % 1024;
//    }
//    sp[0] = SIZE;
//    for (int c = 1; c < 10; c++) sp[c] = 0;
//    qs = 0;
//}
//
//static void is_sorted(void)
//{
//    int min = 0;
//
//    for (int i = 0; i < SIZE; i++) {
//        if (min <= queue[i]) {
//            min = queue[i];
//        }
//        else {
//            printf("queue is not sorted!!\n");
//            printf("index : %d\n", i);
//            exit(1);
//        }
//    }
//    
//    printf("queue is sorted.\n");
//}
//
//static void print_queue(void) {
//    printf("index 0~19 : ");
//    for (int i = 0; i < 20; i++) {
//        printf("%d ", queue[i]);
//    }
//    printf("\n");
//
//    printf("index 1738 ~ 1757 : ");
//    for (int i = 1738; i < 1758; i++) {
//        printf("%d ", queue[i]);
//    }
//    printf("\n");
//
//    printf("index 4959 ~ 4978 : ");
//    for (int i = 4959; i < 4979; i++) {
//        printf("%d ", queue[i]);
//    }
//    printf("\n");
//
//    printf("index 9980 ~ 9999 : ");
//    for (int i = 9980; i < 9999; i++) {
//        printf("%d ", queue[i]);
//    }
//    printf("\n\n");
//}
//
//static void print_stack(int s, int idx_start, int idx_end) {
//    printf("stack[%d] idx %d ~ %d : ", s, idx_start, idx_end);
//    for (int i = idx_start; i < idx_end; i++) {
//        printf("%d ", stack[s][i]);
//    }
//    printf("\n");
//}
//
//int main(void)
//{
//    SCORE = 0;
//    for (int c = 0; c < 1; c++)
//    {
//        printf("try : %d\n", c);
//        build_data();
//        test_main();
//        
//        //// see all stacks
//        //for (int i = 0; i < 10; i++) {
//        //    printf("stack %d : ", i);
//
//        //    for (int j = 0; j < 10; j++) {
//        //        printf("%d ", stack[i][j]);
//        //    }
//        //    printf("\n");
//        //}
//        //printf("\n");
//
//        //print_queue();
//        //is_sorted();
//    }
//    printf("SCORE = %d\n", SCORE);
//}