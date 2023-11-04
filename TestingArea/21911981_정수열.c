extern void my_push(int s);
extern int my_pop(int s);
extern void enqueue(void);

void test_main(void) {
    int i, j, s, h, count;
    int count_0 = 0, count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0, count_5 = 0, count_6 = 0, count_7 = 0, count_8 = 0, count_9 = 0;
    int count_0_1 = 0, count_1_1 = 0, count_2_1 = 0, count_3_1 = 0, count_4_1 = 0, count_5_1 = 0, count_6_1 = 0, count_7_1 = 0, count_8_1 = 0, count_9_1 = 0;
    int count_0_2 = 0, count_1_2 = 0, count_2_2 = 0, count_3_2 = 0, count_4_2 = 0, count_5_2 = 0, count_6_2 = 0, count_7_2 = 0, count_8_2 = 0, count_9_2 = 0;
    int max = 0;

    for (i = 0; i < 10000; i++) {
        s = 0; // stack
        h = my_pop(s); // hold에 값 저장

        if (h == 0)
            enqueue();
        else if (h <= 113) {
            my_push(1);
            count_1++;
        }
        else if (h <= 226) {
            my_push(2);
            count_2++;
        }
        else if (h <= 339) {
            my_push(3);
            count_3++;
        }
        else if (h <= 452) {
            my_push(4);
            count_4++;
        }
        else if (h <= 565) {
            my_push(5);
            count_5++;
        }
        else if (h <= 678) {
            my_push(6);
            count_6++;
        }
        else if (h <= 791) {
            my_push(7);
            count_7++;
        }
        else if (h <= 904) {
            my_push(8);
            count_8++;
        }
        else if (h <= 1023) {
            my_push(9);
            count_9++;
        }
    }

    for (j = 1; j < 10; j++) { // j는 두번째 분할떄 사용되는 스택 번호
        // count, max 설정
        if (j == 1) {
            count = count_1;
            max = 113;
        }
        else if (j == 2) {
            count = count_2;
            max = 226;
        }
        else if (j == 3) {
            count = count_3;
            max = 339;
        }
        else if (j == 4) {
            count = count_4;
            max = 452;
        }
        else if (j == 5) {
            count = count_5;
            max = 565;
        }
        else if (j == 6) {
            count = count_6;
            max = 678;
        }
        else if (j == 7) {
            count = count_7;
            max = 791;
        }
        else if (j == 8) {
            count = count_8;
            max = 904;
        }
        else if (j == 9) {
            count = count_9;
            max = 1023;
        }


        // 두번째 분할
        int ele = max / 9;

        for (i = 0; i < count; i++) {
            h = my_pop(j);

            if (h <= ele) {
                my_push(0);
                count_0_1++;
            }
            else if (h <= ele * 2) {
                my_push(2);
                count_2_1++;
            }
            else if (h <= ele * 3) {
                my_push(3);
                count_3_1++;
            }
            else if (h <= ele * 4) {
                my_push(4);
                count_4_1++;
            }
            else if (h <= ele * 5) {
                my_push(5);
                count_5_1++;
            }
            else if (h <= ele * 6) {
                my_push(6);
                count_6_1++;
            }
            else if (h <= ele * 7) {
                my_push(7);
                count_7_1++;
            }
            else if (h <= ele * 8) {
                my_push(8);
                count_8_1++;
            }
            else {
                my_push(9);
                count_9_1++;
            }
        }

        int ele_1 = ele / 1;
        for (i = 0; i < count_0_1; i++) {
            if (h == ele_1 - 9) {
                my_push(1);
                count_1_2++;
            }
            else if (h == ele_1 - 8) {
                my_push(2);
                count_2_2++;
            }
            else if (h == ele_1 - 7) {
                my_push(3);
                count_3_2++;
            }
            else if (h == ele_1 - 6) {
                my_push(4);
                count_4_2++;
            }
            else if (h == ele_1 - 5) {
                my_push(5);
                count_5_2++;
            }
            else if (h == ele_1 - 4) {
                my_push(6);
                count_6_2++;
            }
            else if (h == ele_1 - 3) {
                my_push(7);
                count_7_2++;
            }
            else if (h == ele_1 - 2) {
                my_push(8);
                count_8_2++;
            }
            else if (h <= ele_1) {
                my_push(9);
                count_9_2++;
            }
        }

        break;
    }

    //    for (i = 0; i < count_1_2; i++) {
    //        h = my_pop(1);
    //        enqueue();
    //    }
    //    for (i = 0; i < count_2_2; i++) {
    //        h = my_pop(2);
    //        enqueue();
    //    }
    //    for (i = 0; i < count_3_2; i++) {
    //        h = my_pop(3);
    //        enqueue();
    //    }
    //    for (i = 0; i < count_4_2; i++) {
    //        h = my_pop(4);
    //        enqueue();
    //    }
    //    for (i = 0; i < count_5_2; i++) {
    //        h = my_pop(5);
    //        enqueue();
    //    }
    //    for (i = 0; i < count_6_2; i++) {
    //        h = my_pop(6);
    //        enqueue();
    //    }
    //    for (i = 0; i < count_7_2; i++) {
    //        h = my_pop(7);
    //        enqueue();
    //    }
    //    for (i = 0; i < count_8_2; i++) {
    //        h = my_pop(8);
    //        enqueue();
    //    }
    //    count_0_2 = 0, count_1_2 = 0;
    //    for (i = 0; i < count_9_2; i++) {
    //        h = my_pop(9);
    //        if (h == ele_1 - 1) {
    //            my_push(0);
    //            count_0_2++;
    //        }
    //        if (h == ele_1) {
    //            my_push(1);
    //            count_1_2++;
    //        }
    //    }

    //    for (i = 0; i < count_0_2; i++) {
    //        h = my_pop(0);
    //        enqueue();
    //    }
    //    for (i = 0; i < count_1_2; i++) {
    //        h = my_pop(1);
    //        enqueue();
    //    }
    //}
}