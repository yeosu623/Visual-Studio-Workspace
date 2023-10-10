#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

extern void get_student_position(int student_index, int* posX, int* posY);
extern void get_school_position(int school_index, int* posX, int* posY);
extern void set_student_school(int student_index, int school_index);

typedef struct _student {
	float d[3];
	int deployed; // ������ �б�

	float t01; // �б�0 -> �б�1�� ���н����� �� �߰��Ǵ� �Ÿ�.
	float t02;
	float t10;
	float t12;
	float t20;
	float t21;
}student;

typedef struct _t_array {
	int student_index;
	float added_distance;
}t_array;

float get_distance(int student_index, int school_index) {
	int student_x, student_y, school_x, school_y;
	int x, y;

	get_student_position(student_index, &student_x, &student_y);
	get_school_position(school_index, &school_x, &school_y);

	x = student_x - school_x;
	y = student_y - school_y;
	return sqrt(pow(x, 2) + pow(y, 2));
}

int get_min_school(float d0, float d1, float d2) {
	if (d0 <= d1 && d0 <= d2)
		return 0;
	else if (d1 <= d0 && d1 <= d2)
		return 1;
	else
		return 2;
}

void get_transfer_distances(student* ps) {
	int i;

	for (i = 0; i < 10000; i++) {
		ps->t01 = ps->d[1] - ps->d[0];
		ps->t02 = ps->d[2] - ps->d[0];
		ps->t10 = ps->d[0] - ps->d[1];
		ps->t12 = ps->d[2] - ps->d[1];
		ps->t20 = ps->d[0] - ps->d[2];
		ps->t21 = ps->d[1] - ps->d[2];

		ps++;
	}
}

void get_t_array_content(t_array* pt, student* ps, int src, int dst) {
	int i;

	for (i = 0; i < 10000; i++) { // ��� �л��� ���ؼ�
		if (ps->deployed == 0 && src == 0 && dst == 1) { // �б�0�� �ִ� �л���, �б�0 ���� �б�1�� ������ �ϰ� �ɋ�
			pt->student_index = i;
			pt->added_distance = ps->t01;
			pt++;
		}
		else if (ps->deployed == 0 && src == 0 && dst == 2) {
			pt->student_index = i;
			pt->added_distance = ps->t02;
			pt++;
		}
		else if (ps->deployed == 1 && src == 1 && dst == 0) {
			pt->student_index = i;
			pt->added_distance = ps->t10;
			pt++;
		}
		else if (ps->deployed == 1 && src == 1 && dst == 2) {
			pt->student_index = i;
			pt->added_distance = ps->t12;
			pt++;
		}
		else if (ps->deployed == 2 && src == 2 && dst == 0) {
			pt->student_index = i;
			pt->added_distance = ps->t20;
			pt++;
		}
		else if (ps->deployed == 2 && src == 2 && dst == 1) {
			pt->student_index = i;
			pt->added_distance = ps->t21;
			pt++;
		}

		ps++;
	}
}

void swap_t_array(t_array* pt, int a, int b) {
	int temp = (pt + a)->student_index;
	float temp_float = (pt + a)->added_distance;

	(pt + a)->student_index = (pt + b)->student_index;
	(pt + a)->added_distance = (pt + b)->added_distance;

	(pt + b)->student_index = temp;
	(pt + b)->added_distance = temp_float;
}

void sort_t_array(t_array* pt, int n) {
	// selection sort�� ���
	int i, j;
	int min;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (((pt + j)->added_distance) < ((pt + min)->added_distance))
				min = j;
		swap_t_array(pt, i, min);
	}
}

void allocate_array(int c[], t_array* t01_array, t_array* t02_array, t_array* t10_array, t_array* t12_array, t_array* t20_array, t_array* t21_array) {
	// --------------------------------
	// �л���ȣ(int)	t01�Ÿ�(float)
	// 0				399.35
	// 3				243.90
	// 4				201.29
	// --------------------------------
	int i;
	for (i = 0; i < 10000; i++) {
		t01_array[i].added_distance = 9999;
		t02_array[i].added_distance = 9999;
		t10_array[i].added_distance = 9999;
		t12_array[i].added_distance = 9999;
		t20_array[i].added_distance = 9999;
		t21_array[i].added_distance = 9999;

		t01_array[i].student_index = -1;
		t02_array[i].student_index = -1;
		t10_array[i].student_index = -1;
		t12_array[i].student_index = -1;
		t20_array[i].student_index = -1;
		t21_array[i].student_index = -1;
	}
}

//void allocate_pointer(t_array* t01_array, t_array* t02_array, t_array* t10_array, t_array* t12_array, t_array* t20_array, t_array* t21_array,
//	t_array** pt01, t_array** pt02, t_array** pt10, t_array** pt12, t_array** pt20, t_array** pt21) {
//	*pt01 = &t01_array[0];
//	*pt02 = &t02_array[0];
//	*pt10 = &t10_array[0];
//	*pt12 = &t12_array[0];
//	*pt20 = &t20_array[0];
//	*pt21 = &t21_array[0];
//}

//void free_array(t_array** t01_array, t_array** t02_array, t_array** t10_array, t_array** t12_array, t_array** t20_array, t_array** t21_array) {
//	free(*t01_array);
//	free(*t02_array);
//	free(*t10_array);
//	free(*t12_array);
//	free(*t20_array);
//	free(*t21_array);
//}

void print_txx_array(student* ps, t_array* ptxx, int src, int dst) {
	// test code - printing specific txx array.

	printf("***t%d%d_array***\n", src, dst);
	printf("index\td%d\td%d\tadded_distance\n", src, dst);
	for (int i = 0; i < 10; i++) {
		int student_index = (ptxx + i)->student_index;
		printf("%d\t%.2f\t%.2f\t%.2f\n", student_index, (ps + student_index)->d[src], (ps + student_index)->d[dst], (ptxx + i)->added_distance);
	}
	printf("\n");
}

void print_full_txx_array(student* ps, t_array* ptxx, int src, int dst, int n) {
	// test code - printing specific txx array.

	printf("***t%d%d_array***\n", src, dst);
	printf("index\td%d\td%d\tadded_distance\n", src, dst);
	for (int i = 0; i < n; i++) {
		int student_index = (ptxx + i)->student_index;
		printf("%d\t%.2f\t%.2f\t%.2f\n", student_index, (ps + student_index)->d[src], (ps + student_index)->d[dst], (ptxx + i)->added_distance);
	}
	printf("\n");
}

float get_final_result(int c[], student* ps) {
	int i;
	int school_index;
	float distance;
	float sum = 0;
	float result;

	for (i = 0; i < 10000; i++) {
		school_index = (ps + i)->deployed;
		distance = (ps + i)->d[school_index];

		sum += distance;
	}
	result = sum / 10000;
	return result;
}

void transfer_students(int process, int c[], student* ps, t_array* pt01, t_array* pt02, t_array* pt10, t_array* pt12, t_array* pt20, t_array* pt21) {
	// t01, t02 �迭���� �ε��� 0���� ���ʴ�� �л����� ���н�Ų��.
	// ���� �ٸ� ������ �̹� ������ �л��̶��, �ε����� ������Ű�� �Ѿ��.

	// ���� : �� �Լ��� ������ ���� ���ؼ��� Case 0�� ���� �Ѵ�.
	// �� ���� Case 1 ~ Case 11�� ������ ������ ����߰�, �ű⼭ ���Ǵ� ������ ���ݾ� �ٸ� ���̴�.
	int i;
	int student, student2;
	int cnt = 0;

	int* tf0 = (int*)malloc(sizeof(int) * c[0]); // transferred from 0
	int* tf1 = (int*)malloc(sizeof(int) * c[1]);
	int* tf2 = (int*)malloc(sizeof(int) * c[2]);
	int tf0_length = 0;
	int tf1_length = 0;
	int tf2_length = 0;
	int* ptf0 = &tf0[0]; // pointer of transferred from 0
	int* ptf1 = &tf1[0];
	int* ptf2 = &tf2[0];
	bool atf0 = false; // already transferred from 0
	bool atf1 = false;
	bool atf2 = false;

	switch (process) {
	case 0: // 0�� 3500���� �ʰ��ϴ� ���
		while (c[0] > 3500 && c[1] < 3500 && c[2] < 3500) {
			if (pt01->added_distance <= pt02->added_distance) { // �б�1���� �����ϴ°� �߰� �Ÿ��� ���� ���
				student = pt01->student_index; // ������ �л��̴�.

				for (i = 0; i < tf0_length; i++) { // ���� ���� Ȯ��
					if (student == tf0[i])
						atf0 = true;
				}

				if (atf0 == true) { // ������ �̹� �� ���
					atf0 = false;
					pt01++;
					continue;
				}
				else { // ������ ���� �ȵ� ���
					set_student_school(student, 1); // ������ ������ �Ѵ�.
					(ps + student)->deployed = 1;
					c[0]--;
					c[1]++;

					*ptf0 = student; // ���� ����� �����Ѵ�.
					ptf0++;
					tf0_length++;

					pt01++; // ���� �л��� �غ��Ѵ�.
				}
			}
			else if (pt01->added_distance > pt02->added_distance) { // �б�2���� �����ϴ°� �߰� �Ÿ��� ���� ���
				student = pt02->student_index;

				for (i = 0; i < tf0_length; i++) {
					if (student == tf0[i])
						atf0 = true;
				}

				if (atf0 == true) {
					atf0 = false;
					pt02++;
					continue;
				}
				else {
					set_student_school(student, 2);
					(ps + student)->deployed = 2;
					c[0]--;
					c[2]++;

					*ptf0 = student;
					ptf0++;
					tf0_length++;

					pt02++;
				}
			}
		} break;
	case 1: // 1�� 3500���� �ʰ��ϴ� ���
		while (c[1] > 3500 && c[0] < 3500 && c[2] < 3500) {
			if (pt10->added_distance <= pt12->added_distance) {
				student = pt10->student_index;

				for (i = 0; i < tf1_length; i++) {
					if (student == tf1[i])
						atf1 = true;
				}

				if (atf1 == true) {
					atf1 = false;
					pt10++;
					continue;
				}
				else {
					set_student_school(student, 0);
					(ps + student)->deployed = 0;
					c[1]--;
					c[0]++;

					*ptf1 = student;
					ptf1++;
					tf1_length++;

					pt10++;
				}
			}
			else if (pt10->added_distance > pt12->added_distance) {
				student = pt12->student_index;

				for (i = 0; i < tf1_length; i++) {
					if (student == tf1[i])
						atf1 = true;
				}

				if (atf1 == true) {
					atf1 = false;
					pt12++;
					continue;
				}
				else {
					set_student_school(student, 2);
					(ps + student)->deployed = 2;
					c[1]--;
					c[2]++;

					*ptf1 = student;
					ptf1++;
					tf1_length++;

					pt12++;
				}
			}
		} break;
	case 2: // 2�� 3500���� �ʰ��ϴ� ���
		while (c[2] > 3500 && c[0] < 3500 && c[1] < 3500) {
			if (pt20->added_distance <= pt21->added_distance) {
				student = pt20->student_index;

				for (i = 0; i < tf2_length; i++) {
					if (student == tf2[i])
						atf2 = true;
				}

				if (atf2 == true) {
					atf2 = false;
					pt20++;
					continue;
				}
				else {
					set_student_school(student, 0);
					(ps + student)->deployed = 0;
					c[2]--;
					c[0]++;

					*ptf2 = student;
					ptf2++;
					tf2_length++;

					pt20++;
				}
			}
			else if (pt20->added_distance > pt21->added_distance) {
				student = pt21->student_index;

				for (i = 0; i < tf2_length; i++) {
					if (student == tf2[i])
						atf2 = true;
				}

				if (atf2 == true) {
					atf2 = false;
					pt21++;
					continue;
				}
				else {
					set_student_school(student, 1);
					(ps + student)->deployed = 1;
					c[2]--;
					c[1]++;

					*ptf2 = student;
					ptf2++;
					tf2_length++;

					pt21++;
				}
			}
		} break;
	case 3: // 0�� 3500���� �ʰ��ϰ� 1�� 3500���� �Ǵ� ���
		while (c[0] > 3500) {
			if (pt02->added_distance <= (pt01->added_distance + pt12->added_distance)) {
				student = pt02->student_index;

				for (i = 0; i < tf0_length; i++) {
					if (student == tf0[i])
						atf0 = true;
				}

				if (atf0 == true) {
					atf0 = false;
					pt02++;
					continue;
				}
				else {
					set_student_school(student, 2);
					(ps + student)->deployed = 2;
					c[0]--;
					c[2]++;

					*ptf0 = student;
					ptf0++;
					tf0_length++;

					pt02++;
				}
			}
			else if (pt02->added_distance > (pt01->added_distance + pt12->added_distance)) {
				student = pt01->student_index;
				student2 = pt12->student_index;

				for (i = 0; i < tf0_length; i++) {
					if (student == tf0[i])
						atf0 = true;
				}
				for (i = 0; i < tf1_length; i++) {
					if (student == tf1[i])
						atf1 = true;
				}

				if (atf0 == true || atf1 == true) {
					if (atf0 == true && atf1 == true) {
						atf0 = false;
						atf1 = false;
						pt01++;
						pt02++;
						continue;
					}
					else if (atf0 == true && atf1 == false) {
						atf0 = false;
						pt01++;
						continue;
					}
					else if (atf0 == false && atf1 == true) {
						atf1 = false;
						pt12++;
						continue;
					}
				}
				else {
					set_student_school(student, 1);
					set_student_school(student2, 2);
					(ps + student)->deployed = 1;
					(ps + student2)->deployed = 2;
					c[0]--;
					c[2]++;

					*ptf0 = student;
					*ptf1 = student2;
					ptf0++;
					ptf1++;
					tf0_length++;
					tf1_length++;

					pt01++;
					pt12++;
				}
			}
		} break;
	case 4: // 0�� 3500���� �ʰ��ϰ� 2�� 3500���� �Ǵ� ���
		while (c[0] > 3500) {
			if (pt01->added_distance <= (pt02->added_distance + pt21->added_distance)) {
				student = pt01->student_index;

				for (i = 0; i < tf0_length; i++) {
					if (student == tf0[i])
						atf0 = true;
				}

				if (atf0 == true) {
					atf0 = false;
					pt01++;
					continue;
				}
				else {
					set_student_school(student, 1);
					(ps + student)->deployed = 1;
					c[0]--;
					c[1]++;

					*ptf0 = student;
					ptf0++;
					tf0_length++;

					pt01++;
				}
			}
			else if (pt01->added_distance > (pt02->added_distance + pt21->added_distance)) {
				student = pt02->student_index;
				student2 = pt21->student_index;

				for (i = 0; i < tf0_length; i++) {
					if (student == tf0[i])
						atf0 = true;
				}
				for (i = 0; i < tf2_length; i++) {
					if (student == tf2[i])
						atf2 = true;
				}

				if (atf0 == true || atf2 == true) {
					if (atf0 == true && atf2 == true) {
						atf0 = false;
						atf2 = false;
						pt02++;
						pt21++;
						continue;
					}
					else if (atf0 == true && atf2 == false) {
						atf0 = false;
						pt02++;
						continue;
					}
					else if (atf0 == false && atf2 == true) {
						atf2 = false;
						pt21++;
						continue;
					}
				}
				else {
					set_student_school(student, 2);
					set_student_school(student2, 1);
					(ps + student)->deployed = 2;
					(ps + student2)->deployed = 1;
					c[0]--;
					c[1]++;

					*ptf0 = student;
					*ptf2 = student2;
					ptf0++;
					ptf2++;
					tf0_length++;
					tf2_length++;

					pt02++;
					pt21++;
				}
			}
		} break;
	case 5: // 1�� 3500���� �ʰ��ϰ� 0�� 3500���� �Ǵ� ���
		while (c[1] > 3500) {
			if (pt12->added_distance <= (pt10->added_distance + pt02->added_distance)) {
				student = pt12->student_index;

				for (i = 0; i < tf1_length; i++) {
					if (student == tf1[i])
						atf1 = true;
				}

				if (atf1 == true) {
					atf1 = false;
					pt12++;
					continue;
				}
				else {
					set_student_school(student, 2);
					(ps + student)->deployed = 2;
					c[1]--;
					c[2]++;

					*ptf1 = student;
					ptf1++;
					tf1_length++;

					pt12++;
				}
			}
			else if (pt12->added_distance > (pt10->added_distance + pt02->added_distance)) {
				student = pt10->student_index;
				student2 = pt02->student_index;

				for (i = 0; i < tf1_length; i++) {
					if (student == tf1[i])
						atf1 = true;
				}
				for (i = 0; i < tf0_length; i++) {
					if (student == tf0[i])
						atf0 = true;
				}

				if (atf1 == true || atf0 == true) {
					if (atf1 == true && atf0 == true) {
						atf1 = false;
						atf0 = false;
						pt10++;
						pt02++;
						continue;
					}
					else if (atf1 == true && atf0 == false) {
						atf1 = false;
						pt10++;
						continue;
					}
					else if (atf1 == false && atf0 == true) {
						atf0 = false;
						pt02++;
						continue;
					}
				}
				else {
					set_student_school(student, 0);
					set_student_school(student2, 2);
					(ps + student)->deployed = 0;
					(ps + student2)->deployed = 2;
					c[1]--;
					c[2]++;

					*ptf1 = student;
					*ptf0 = student2;
					ptf1++;
					ptf0++;
					tf1_length++;
					tf0_length++;

					pt10++;
					pt02++;
				}
			}
		} break;
	case 6: // 1�� 3500���� �ʰ��ϰ� 2�� 3500���� �Ǵ� ���
		while (c[1] > 3500) {
			if (pt10->added_distance <= (pt12->added_distance + pt20->added_distance)) {
				student = pt10->student_index;

				for (i = 0; i < tf1_length; i++) {
					if (student == tf1[i])
						atf1 = true;
				}

				if (atf1 == true) {
					atf1 = false;
					pt10++;
					continue;
				}
				else {
					set_student_school(student, 0);
					(ps + student)->deployed = 0;
					c[1]--;
					c[0]++;

					*ptf1 = student;
					ptf1++;
					tf1_length++;

					pt10++;
				}
			}
			else if (pt10->added_distance > (pt12->added_distance + pt20->added_distance)) {
				student = pt12->student_index;
				student2 = pt20->student_index;

				for (i = 0; i < tf1_length; i++) {
					if (student == tf1[i])
						atf1 = true;
				}
				for (i = 0; i < tf2_length; i++) {
					if (student == tf2[i])
						atf2 = true;
				}

				if (atf1 == true || atf2 == true) {
					if (atf1 == true && atf2 == true) {
						atf1 = false;
						atf2 = false;
						pt12++;
						pt20++;
						continue;
					}
					else if (atf1 == true && atf2 == false) {
						atf1 = false;
						pt12++;
						continue;
					}
					else if (atf1 == false && atf2 == true) {
						atf2 = false;
						pt20++;
						continue;
					}
				}
				else {
					set_student_school(student, 2);
					set_student_school(student2, 0);
					(ps + student)->deployed = 2;
					(ps + student2)->deployed = 0;
					c[1]--;
					c[0]++;

					*ptf1 = student;
					*ptf2 = student2;
					ptf1++;
					ptf2++;
					tf1_length++;
					tf2_length++;

					pt12++;
					pt20++;
				}
			}
		} break;
	case 7: // 2�� 3500���� �ʰ��ϰ� 0�� 3500���� �Ǵ� ���
		while (c[2] > 3500) {
			if (pt21->added_distance <= (pt20->added_distance + pt01->added_distance)) {
				student = pt21->student_index;

				for (i = 0; i < tf2_length; i++) {
					if (student == tf2[i])
						atf2 = true;
				}

				if (atf2 == true) {
					atf2 = false;
					pt21++;
					continue;
				}
				else {
					set_student_school(student, 1);
					(ps + student)->deployed = 1;
					c[2]--;
					c[1]++;

					*ptf2 = student;
					ptf2++;
					tf2_length++;

					pt21++;
				}
			}
			else if (pt21->added_distance > (pt20->added_distance + pt01->added_distance)) {
				student = pt20->student_index;
				student2 = pt01->student_index;

				for (i = 0; i < tf2_length; i++) {
					if (student == tf2[i])
						atf2 = true;
				}
				for (i = 0; i < tf0_length; i++) {
					if (student == tf0[i])
						atf0 = true;
				}

				if (atf2 == true || atf0 == true) {
					if (atf2 == true && atf0 == true) {
						atf2 = false;
						atf0 = false;
						pt20++;
						pt01++;
						continue;
					}
					else if (atf2 == true && atf0 == false) {
						atf2 = false;
						pt20++;
						continue;
					}
					else if (atf2 == false && atf0 == true) {
						atf0 = false;
						pt01++;
						continue;
					}
				}
				else {
					set_student_school(student, 0);
					set_student_school(student2, 1);
					(ps + student)->deployed = 0;
					(ps + student2)->deployed = 1;
					c[2]--;
					c[1]++;

					*ptf2 = student;
					*ptf0 = student2;
					ptf2++;
					ptf0++;
					tf2_length++;
					tf0_length++;

					pt20++;
					pt01++;
				}
			}
		} break;
	case 8: // 2�� 3500���� �ʰ��ϰ� 1�� 3500���� �Ǵ� ���
		while (c[2] > 3500) {
			if (pt20->added_distance <= (pt21->added_distance + pt10->added_distance)) {
				student = pt20->student_index;

				for (i = 0; i < tf2_length; i++) {
					if (student == tf2[i])
						atf2 = true;
				}

				if (atf2 == true) {
					atf2 = false;
					pt20++;
					continue;
				}
				else {
					set_student_school(student, 0);
					(ps + student)->deployed = 0;
					c[2]--;
					c[0]++;

					*ptf2 = student;
					ptf2++;
					tf2_length++;

					pt20++;
				}
			}
			else if (pt20->added_distance > (pt21->added_distance + pt10->added_distance)) {
				student = pt21->student_index;
				student2 = pt10->student_index;

				for (i = 0; i < tf2_length; i++) {
					if (student == tf2[i])
						atf2 = true;
				}
				for (i = 0; i < tf1_length; i++) {
					if (student == tf1[i])
						atf1 = true;
				}

				if (atf2 == true || atf1 == true) {
					if (atf2 == true && atf1 == true) {
						atf2 = false;
						atf1 = false;
						pt21++;
						pt10++;
						continue;
					}
					else if (atf2 == true && atf1 == false) {
						atf2 = false;
						pt21++;
						continue;
					}
					else if (atf2 == false && atf1 == true) {
						atf1 = false;
						pt10++;
						continue;
					}
				}
				else {
					set_student_school(student, 1);
					set_student_school(student2, 0);
					(ps + student)->deployed = 1;
					(ps + student2)->deployed = 0;
					c[2]--;
					c[0]++;

					*ptf2 = student;
					*ptf1 = student2;
					ptf2++;
					ptf1++;
					tf2_length++;
					tf1_length++;

					pt21++;
					pt10++;
				}
			}
		} break;
	case 9: // 0, 1�� 3500���� �ʰ��ϴ� ���
		while (c[0] > 3500 && c[1] > 3500) {
			// 02, 12, 01+12, 10+02 ��ΰ� �ִ�.
			if (pt02->added_distance <= (pt12->added_distance) &&
				pt02->added_distance <= (pt01->added_distance + pt12->added_distance) &&
				pt02->added_distance <= (pt10->added_distance + pt02->added_distance))
			{
				student = pt02->student_index;

				for (i = 0; i < tf0_length; i++) {
					if (student == tf0[i])
						atf0 = true;
				}

				if (atf0 == true) {
					atf0 = false;
					pt02++;
					continue;
				}
				else {
					set_student_school(student, 2);
					(ps + student)->deployed = 2;
					c[0]--;
					c[2]++;

					*ptf0 = student;
					ptf0++;
					tf0_length++;

					pt02++;
				}
			}
			else if (pt12->added_distance <= (pt02->added_distance) &&
				pt12->added_distance <= (pt01->added_distance + pt12->added_distance) &&
				pt12->added_distance <= (pt10->added_distance + pt02->added_distance))
			{
				student = pt12->student_index;

				for (i = 0; i < tf1_length; i++) {
					if (student == tf1[i])
						atf1 = true;
				}

				if (atf1 == true) {
					atf1 = false;
					pt12++;
					continue;
				}
				else {
					set_student_school(student, 2);
					(ps + student)->deployed = 2;
					c[1]--;
					c[2]++;

					*ptf1 = student;
					ptf1++;
					tf1_length++;

					pt12++;
				}
			}
			else if ((pt01->added_distance + pt12->added_distance) <= (pt02->added_distance) &&
				(pt01->added_distance + pt12->added_distance) <= (pt12->added_distance) &&
				(pt01->added_distance + pt12->added_distance) <= (pt10->added_distance + pt02->added_distance))
			{
				student = pt01->student_index;
				student2 = pt12->student_index;

				for (i = 0; i < tf0_length; i++) {
					if (student == tf0[i])
						atf0 = true;
				}
				for (i = 0; i < tf1_length; i++) {
					if (student == tf1[i])
						atf1 = true;
				}

				if (atf0 == true || atf1 == true) {
					if (atf0 == true && atf1 == true) {
						atf0 = false;
						atf1 = false;
						pt01++;
						pt12++;
						continue;
					}
					else if (atf0 == true && atf1 == false) {
						atf0 = false;
						pt01++;
						continue;
					}
					else if (atf0 == false && atf1 == true) {
						atf1 = false;
						pt12++;
						continue;
					}
				}
				else {
					set_student_school(student, 1);
					set_student_school(student2, 2);
					(ps + student)->deployed = 1;
					(ps + student2)->deployed = 2;
					c[0]--;
					c[2]++;

					*ptf0 = student;
					*ptf1 = student2;
					ptf0++;
					ptf1++;
					tf0_length++;
					tf1_length++;

					pt01++;
					pt12++;
				}
			}
			else if ((pt10->added_distance + pt02->added_distance) <= (pt02->added_distance) &&
				(pt10->added_distance + pt02->added_distance) <= (pt12->added_distance) &&
				(pt10->added_distance + pt02->added_distance) <= (pt01->added_distance + pt12->added_distance))
			{
				student = pt10->student_index;
				student2 = pt02->student_index;

				for (i = 0; i < tf1_length; i++) {
					if (student == tf1[i])
						atf1 = true;
				}
				for (i = 0; i < tf0_length; i++) {
					if (student == tf0[i])
						atf0 = true;
				}

				if (atf1 == true || atf0 == true) {
					if (atf1 == true && atf0 == true) {
						atf1 = false;
						atf0 = false;
						pt10++;
						pt02++;
						continue;
					}
					else if (atf1 == true && atf0 == false) {
						atf1 = false;
						pt10++;
						continue;
					}
					else if (atf1 == false && atf0 == true) {
						atf0 = false;
						pt02++;
						continue;
					}
				}
				else {
					set_student_school(student, 0);
					set_student_school(student2, 2);
					(ps + student)->deployed = 0;
					(ps + student2)->deployed = 2;
					c[1]--;
					c[2]++;

					*ptf1 = student;
					*ptf0 = student2;
					ptf1++;
					ptf0++;
					tf1_length++;
					tf0_length++;

					pt10++;
					pt02++;
				}
			}
		} break;
	case 10: // 0, 2�� 3500���� �ʰ��ϴ� ���
		while (c[0] > 3500 && c[2] > 3500) {
			// 01, 21, 02+21, 20+01 ��ΰ� �ִ�.
			if (pt01->added_distance <= (pt21->added_distance) &&
				pt01->added_distance <= (pt02->added_distance + pt21->added_distance) &&
				pt01->added_distance <= (pt20->added_distance + pt01->added_distance))
			{
				student = pt01->student_index;

				for (i = 0; i < tf0_length; i++) {
					if (student == tf0[i])
						atf0 = true;
				}

				if (atf0 == true) {
					atf0 = false;
					pt01++;
					continue;
				}
				else {
					set_student_school(student, 1);
					(ps + student)->deployed = 1;
					c[0]--;
					c[1]++;

					*ptf0 = student;
					ptf0++;
					tf0_length++;

					pt01++;
				}
			}
			else if (pt21->added_distance <= (pt01->added_distance) &&
				pt21->added_distance <= (pt02->added_distance + pt21->added_distance) &&
				pt21->added_distance <= (pt20->added_distance + pt01->added_distance))
			{
				student = pt21->student_index;

				for (i = 0; i < tf2_length; i++) {
					if (student == tf2[i])
						atf2 = true;
				}

				if (atf2 == true) {
					atf2 = false;
					pt21++;
					continue;
				}
				else {
					set_student_school(student, 1);
					(ps + student)->deployed = 1;
					c[2]--;
					c[1]++;

					*ptf2 = student;
					ptf2++;
					tf2_length++;

					pt21++;
				}
			}
			else if ((pt02->added_distance + pt21->added_distance) <= (pt01->added_distance) &&
				(pt02->added_distance + pt21->added_distance) <= (pt21->added_distance) &&
				(pt02->added_distance + pt21->added_distance) <= (pt20->added_distance + pt01->added_distance))
			{
				student = pt02->student_index;
				student2 = pt21->student_index;

				for (i = 0; i < tf0_length; i++) {
					if (student == tf0[i])
						atf0 = true;
				}
				for (i = 0; i < tf2_length; i++) {
					if (student == tf2[i])
						atf2 = true;
				}

				if (atf0 == true || atf2 == true) {
					if (atf0 == true && atf2 == true) {
						atf0 = false;
						atf2 = false;
						pt02++;
						pt21++;
						continue;
					}
					else if (atf0 == true && atf2 == false) {
						atf0 = false;
						pt02++;
						continue;
					}
					else if (atf0 == false && atf2 == true) {
						atf2 = false;
						pt21++;
						continue;
					}
				}
				else {
					set_student_school(student, 2);
					set_student_school(student2, 1);
					(ps + student)->deployed = 2;
					(ps + student2)->deployed = 1;
					c[0]--;
					c[1]++;

					*ptf0 = student;
					*ptf2 = student2;
					ptf0++;
					ptf2++;
					tf0_length++;
					tf2_length++;

					pt02++;
					pt21++;
				}
			}
			else if ((pt20->added_distance + pt01->added_distance) <= (pt01->added_distance) &&
				(pt20->added_distance + pt01->added_distance) <= (pt21->added_distance) &&
				(pt20->added_distance + pt01->added_distance) <= (pt02->added_distance + pt21->added_distance))
			{
				student = pt20->student_index;
				student2 = pt01->student_index;

				for (i = 0; i < tf2_length; i++) {
					if (student == tf2[i])
						atf2 = true;
				}
				for (i = 0; i < tf0_length; i++) {
					if (student == tf0[i])
						atf0 = true;
				}

				if (atf2 == true || atf0 == true) {
					if (atf2 == true && atf0 == true) {
						atf2 = false;
						atf0 = false;
						pt20++;
						pt01++;
						continue;
					}
					else if (atf2 == true && atf0 == false) {
						atf2 = false;
						pt20++;
						continue;
					}
					else if (atf2 == false && atf0 == true) {
						atf0 = false;
						pt01++;
						continue;
					}
				}
				else {
					set_student_school(student, 0);
					set_student_school(student2, 1);
					(ps + student)->deployed = 0;
					(ps + student2)->deployed = 1;
					c[2]--;
					c[1]++;

					*ptf2 = student;
					*ptf0 = student2;
					ptf2++;
					ptf0++;
					tf2_length++;
					tf0_length++;

					pt20++;
					pt01++;
				}
			}
		} break;
	case 11: // 1, 2�� 3500���� �ʰ��ϴ� ���
		while (c[1] > 3500 && c[2] > 3500) {
			// 10, 20, 12+20, 21+10 ��ΰ� �ִ�.
			if (pt10->added_distance <= (pt20->added_distance) &&
				pt10->added_distance <= (pt12->added_distance + pt20->added_distance) &&
				pt10->added_distance <= (pt21->added_distance + pt10->added_distance))
			{
				student = pt10->student_index;

				for (i = 0; i < tf1_length; i++) {
					if (student == tf1[i])
						atf1 = true;
				}

				if (atf1 == true) {
					atf1 = false;
					pt10++;
					continue;
				}
				else {
					set_student_school(student, 0);
					(ps + student)->deployed = 0;
					c[1]--;
					c[0]++;

					*ptf1 = student;
					ptf1++;
					tf1_length++;

					pt10++;
				}
			}
			else if (pt20->added_distance <= (pt10->added_distance) &&
				pt20->added_distance <= (pt12->added_distance + pt20->added_distance) &&
				pt20->added_distance <= (pt21->added_distance + pt10->added_distance))
			{
				student = pt20->student_index;

				for (i = 0; i < tf2_length; i++) {
					if (student == tf2[i])
						atf2 = true;
				}

				if (atf2 == true) {
					atf2 = false;
					pt20++;
					continue;
				}
				else {
					set_student_school(student, 0);
					(ps + student)->deployed = 0;
					c[2]--;
					c[0]++;

					*ptf2 = student;
					ptf2++;
					tf2_length++;

					pt20++;
				}
			}
			else if ((pt12->added_distance + pt20->added_distance) <= (pt10->added_distance) &&
				(pt12->added_distance + pt20->added_distance) <= (pt20->added_distance) &&
				(pt12->added_distance + pt20->added_distance) <= (pt21->added_distance + pt10->added_distance))
			{
				student = pt12->student_index;
				student2 = pt20->student_index;

				for (i = 0; i < tf1_length; i++) {
					if (student == tf1[i])
						atf1 = true;
				}
				for (i = 0; i < tf2_length; i++) {
					if (student == tf2[i])
						atf2 = true;
				}

				if (atf1 == true || atf2 == true) {
					if (atf1 == true && atf2 == true) {
						atf1 = false;
						atf2 = false;
						pt12++;
						pt20++;
						continue;
					}
					else if (atf1 == true && atf2 == false) {
						atf1 = false;
						pt12++;
						continue;
					}
					else if (atf1 == false && atf2 == true) {
						atf2 = false;
						pt20++;
						continue;
					}
				}
				else {
					set_student_school(student, 2);
					set_student_school(student2, 0);
					(ps + student)->deployed = 2;
					(ps + student2)->deployed = 0;
					c[1]--;
					c[0]++;

					*ptf1 = student;
					*ptf2 = student2;
					ptf1++;
					ptf2++;
					tf1_length++;
					tf2_length++;

					pt12++;
					pt20++;
				}
			}
			else if ((pt21->added_distance + pt10->added_distance) <= (pt10->added_distance) &&
				(pt21->added_distance + pt10->added_distance) <= (pt20->added_distance) &&
				(pt21->added_distance + pt10->added_distance) <= (pt12->added_distance + pt20->added_distance))
			{
				student = pt21->student_index;
				student2 = pt10->student_index;

				for (i = 0; i < tf2_length; i++) {
					if (student == tf2[i])
						atf2 = true;
				}
				for (i = 0; i < tf1_length; i++) {
					if (student == tf1[i])
						atf1 = true;
				}

				if (atf2 == true || atf1 == true) {
					if (atf2 == true && atf1 == true) {
						atf2 = false;
						atf1 = false;
						pt21++;
						pt10++;
						continue;
					}
					else if (atf2 == true && atf1 == false) {
						atf2 = false;
						pt21++;
						continue;
					}
					else if (atf2 == false && atf1 == true) {
						atf1 = false;
						pt10++;
						continue;
					}
				}
				else {
					set_student_school(student, 1);
					set_student_school(student2, 0);
					(ps + student)->deployed = 1;
					(ps + student2)->deployed = 0;
					c[2]--;
					c[0]++;

					*ptf2 = student;
					*ptf1 = student2;
					ptf2++;
					ptf1++;
					tf2_length++;
					tf1_length++;

					pt21++;
					pt10++;
				}
			}
		} break;
	}

	//free(tf0);
	//free(tf1);
	//free(tf2);
}

void processing(int process, int c[], student* ps,
	t_array* t01_array, t_array* t02_array, t_array* t10_array, t_array* t12_array, t_array* t20_array, t_array* t21_array,
	t_array* pt01, t_array* pt02, t_array* pt10, t_array* pt12, t_array* pt20, t_array* pt21) {

	switch (process) {
	case 0:
		allocate_array(&c[0], t01_array, t02_array, t10_array, t12_array, t20_array, t21_array);

		get_t_array_content(pt01, ps, 0, 1); // �б� 0�� ������ �ִ´�.
		get_t_array_content(pt02, ps, 0, 2);

		// t01, t02 �迭�� ����
		sort_t_array(pt01, c[0]); // �б� 0�� ������ �����Ѵ�.
		sort_t_array(pt02, c[0]);

		// ������ �л����� ���н�Ų��.
		transfer_students(0, &c[0], ps, pt01, pt02, pt10, pt12, pt20, pt21);
		break;
	case 1:
		allocate_array(&c[0], t01_array, t02_array, t10_array, t12_array, t20_array, t21_array);


		get_t_array_content(pt10, ps, 1, 0);
		get_t_array_content(pt12, ps, 1, 2);

		sort_t_array(pt10, c[1]);
		sort_t_array(pt12, c[1]);

		transfer_students(1, &c[0], ps, pt01, pt02, pt10, pt12, pt20, pt21);

		break;
	case 2:
		allocate_array(&c[0], t01_array, t02_array, t10_array, t12_array, t20_array, t21_array);

		get_t_array_content(pt20, ps, 2, 0);
		get_t_array_content(pt21, ps, 2, 1);

		sort_t_array(pt20, c[2]);
		sort_t_array(pt21, c[2]);

		transfer_students(2, &c[0], ps, pt01, pt02, pt10, pt12, pt20, pt21);
		break;
	case 3:
		allocate_array(&c[0], t01_array, t02_array, t10_array, t12_array, t20_array, t21_array);
		
		get_t_array_content(pt02, ps, 0, 2);
		get_t_array_content(pt01, ps, 0, 1);
		get_t_array_content(pt12, ps, 1, 2);
		sort_t_array(pt02, c[0]);
		sort_t_array(pt01, c[0]);
		sort_t_array(pt12, c[1]);

		transfer_students(3, &c[0], ps, pt01, pt02, pt10, pt12, pt20, pt21);
		
		break;
	case 4:
		allocate_array(&c[0], t01_array, t02_array, t10_array, t12_array, t20_array, t21_array);

		get_t_array_content(pt01, ps, 0, 1);
		get_t_array_content(pt02, ps, 0, 2);
		get_t_array_content(pt21, ps, 2, 1);
		sort_t_array(pt01, c[0]);
		sort_t_array(pt02, c[0]);
		sort_t_array(pt21, c[2]);

		transfer_students(4, &c[0], ps, pt01, pt02, pt10, pt12, pt20, pt21);

		break;
	case 5:
		allocate_array(&c[0], t01_array, t02_array, t10_array, t12_array, t20_array, t21_array);

		get_t_array_content(pt12, ps, 1, 2);
		get_t_array_content(pt10, ps, 1, 0);
		get_t_array_content(pt02, ps, 0, 2);
		sort_t_array(pt12, c[1]);
		sort_t_array(pt10, c[1]);
		sort_t_array(pt02, c[0]);

		transfer_students(5, &c[0], ps, pt01, pt02, pt10, pt12, pt20, pt21);
		
		break;
	case 6:
		allocate_array(&c[0], t01_array, t02_array, t10_array, t12_array, t20_array, t21_array);

		get_t_array_content(pt10, ps, 1, 0);
		get_t_array_content(pt12, ps, 1, 2);
		get_t_array_content(pt20, ps, 2, 0);
		sort_t_array(pt10, c[1]);
		sort_t_array(pt12, c[1]);
		sort_t_array(pt20, c[2]);

		transfer_students(6, &c[0], ps, pt01, pt02, pt10, pt12, pt20, pt21);
		
		break;
	case 7:
		allocate_array(&c[0], t01_array, t02_array, t10_array, t12_array, t20_array, t21_array);

		get_t_array_content(pt21, ps, 2, 1);
		get_t_array_content(pt20, ps, 2, 0);
		get_t_array_content(pt01, ps, 0, 1);
		sort_t_array(pt21, c[2]);
		sort_t_array(pt20, c[2]);
		sort_t_array(pt01, c[0]);

		transfer_students(7, &c[0], ps, pt01, pt02, pt10, pt12, pt20, pt21);
		
		break;
	case 8:
		allocate_array(&c[0], t01_array, t02_array, t10_array, t12_array, t20_array, t21_array);

		get_t_array_content(pt20, ps, 2, 0);
		get_t_array_content(pt21, ps, 2, 1);
		get_t_array_content(pt10, ps, 1, 0);
		sort_t_array(pt20, c[2]);
		sort_t_array(pt21, c[2]);
		sort_t_array(pt10, c[1]);

		transfer_students(8, &c[0], ps, pt01, pt02, pt10, pt12, pt20, pt21);
		
		break;
	case 9:
		allocate_array(&c[0], t01_array, t02_array, t10_array, t12_array, t20_array, t21_array);

		get_t_array_content(pt02, ps, 0, 2);
		get_t_array_content(pt12, ps, 1, 2);
		get_t_array_content(pt01, ps, 0, 1);
		get_t_array_content(pt10, ps, 1, 0);

		sort_t_array(pt02, c[0]);
		sort_t_array(pt12, c[1]);
		sort_t_array(pt01, c[0]);
		sort_t_array(pt10, c[1]);

		transfer_students(9, &c[0], ps, pt01, pt02, pt10, pt12, pt20, pt21);
		
		break;
	case 10:
		allocate_array(&c[0], t01_array, t02_array, t10_array, t12_array, t20_array, t21_array);

		get_t_array_content(pt01, ps, 0, 1);
		get_t_array_content(pt21, ps, 2, 1);
		get_t_array_content(pt02, ps, 0, 2);
		get_t_array_content(pt20, ps, 2, 0);

		sort_t_array(pt01, c[0]);
		sort_t_array(pt21, c[2]);
		sort_t_array(pt02, c[0]);
		sort_t_array(pt20, c[2]);

		transfer_students(10, &c[0], ps, pt01, pt02, pt10, pt12, pt20, pt21);
		
		break;
	case 11:
		allocate_array(&c[0], t01_array, t02_array, t10_array, t12_array, t20_array, t21_array);

		get_t_array_content(pt10, ps, 1, 0);
		get_t_array_content(pt20, ps, 2, 0);
		get_t_array_content(pt12, ps, 1, 2);
		get_t_array_content(pt21, ps, 2, 1);

		sort_t_array(pt10, c[1]);
		sort_t_array(pt20, c[2]);
		sort_t_array(pt12, c[1]);
		sort_t_array(pt21, c[2]);

		transfer_students(11, &c[0], ps, pt01, pt02, pt10, pt12, pt20, pt21);

		break;
	}
}

void run_contest(void)
{
	int i, j;
	int temp;
	int c[3] = { 0,0,0 }; // �б�0, �б�1, �б�2�� �ִ� �л� ��
	static int result_count = 0;
	float temp_float;
	float result;
	static float result_sum = 0;
	student s[10000];
	student* ps = &s[0];
	t_array t01_array[10000];
	t_array t02_array[10000];
	t_array t10_array[10000];
	t_array t12_array[10000];
	t_array t20_array[10000];
	t_array t21_array[10000];
	t_array* pt01 = &t01_array[0];
	t_array* pt02 = &t02_array[0];
	t_array* pt10 = &t10_array[0];
	t_array* pt12 = &t12_array[0];
	t_array* pt20 = &t20_array[0];
	t_array* pt21 = &t21_array[0];

	// ������ �л��� ���ؼ� �б�0, �б�1, �б�2�� �Ÿ��� ���ϰ� float d[3]�� �����Ѵ�.
	for (i = 0; i < 10000; i++) {
		for (j = 0; j < 3; j++) {
			temp_float = get_distance(i, j); // �б��� �л� ��ȣ�� �Ÿ��� ������ִ� �Լ�
			s[i].d[j] = temp_float;
		}
	}

	// ������ �л��� ���ؼ� �Ÿ��� ���� ª�� �б��� �����Ѵ�.
	// ������ �б����� �л��� �� �� �ִ����� ���� 
	for (i = 0; i < 10000; i++) {
		temp = get_min_school(s[i].d[0], s[i].d[1], s[i].d[2]);

		c[temp]++;
		s[i].deployed = temp;
		set_student_school(i, temp);
	}

	// ���н����� �� �Ÿ��� �󸶳� �߰��Ǵ����� ����Ѵ�.
	get_transfer_distances(ps);

	/****************************************
	* �ϳ��� �б������� ������ �ʰ��ϴ� ���
	*****************************************/

	// 1. �б�0�� 3500���� �ʰ��ϴ� ��� : 01, 02 ��η� ������.
	if (c[0] > 3500 && c[1] <= 3500 && c[2] <= 3500) {
		processing(0, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);

		// 1-1. �б�1���� 3500���� �� ���
		if (c[1] == 3500)	processing(3, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);
		// 1-2. �б�2���� 3500���� �� ���
		else if (c[2] == 3500)	processing(4, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);
	}
	// 2. �б�1�� 3500���� �ʰ��ϴ� ���
	else if (c[1] > 3500 && c[0] <= 3500 && c[2] <= 3500) {
		processing(1, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);

		// 2-1. �б�0���� 3500���� �� ���
		if (c[0] == 3500)	processing(5, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);
		// 2-2. �б�2���� 3500���� �� ���
		else if (c[2] == 3500)	processing(6, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);
	}
	// 3. �б�2�� 3500���� �ʰ��ϴ� ���
	else if (c[2] > 3500 && c[0] <= 3500 && c[1] <= 3500) {
		processing(2, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);

		// 3-1. �б�0���� 3500���� �� ���
		if (c[0] == 3500)	processing(7, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);
		// 3-2. �б�1���� 3500���� �� ���
		else if (c[1] == 3500)	processing(8, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);
	}

	/****************************************
	* �� ���� �б����� ������ �ʰ��ϴ� ���
	*****************************************/
	// 1. �б�0, �б�1���� 3500���� �ʰ��ϴ� ���
	if (c[0] > 3500 && c[1] > 3500) {
		processing(9, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);

		// 1-1. �б�0���� 3500���� �� ���
		if (c[0] == 3500)	processing(5, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);
		// 1-2. �б�1���� 3500���� �� ���
		else if (c[1] == 3500)	processing(3, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);
	}
	// 2. �б�0, �б�2���� 3500���� �ʰ��ϴ� ���
	else if (c[0] > 3500 && c[2] > 3500) {
		processing(10, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);

		// 2-1. �б�0���� 3500���� �� ���
		if (c[0] == 3500)	processing(7, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);
		// 2-2. �б�2���� 3500���� �� ���
		else if (c[2] == 3500)	processing(4, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);
	}
	// 3. �б�1, �б�2���� 3500���� �ʰ��ϴ� ���
	if (c[1] > 3500 && c[2] > 3500) {
		processing(11, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);

		// 3-1. �б�1���� 3500���� �� ���
		if (c[1] == 3500)	processing(8, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);
		// 3-2. �б�2���� 3500���� �� ���
		else if (c[2] == 3500)	processing(6, &c[0], ps, t01_array, t02_array, t10_array, t12_array, t20_array, t21_array, pt01, pt02, pt10, pt12, pt20, pt21);
	}

	//���� ��� ���
	//result = get_final_result(&c[0], ps);
	//if (result_count == 0) {
	//	printf("c0\tc1\tc2\tdistance\n");
	//	printf("-----------------------------------\n");
	//}
	//printf("%d\t%d\t%d\t%.3f\n", c[0], c[1], c[2], result);

	//result_count++;
	//result_sum += result;
	//if (result_count == 10)
	//	printf("\nThe Final Result is --- %.3f\n\n", result_sum / 10);
}
