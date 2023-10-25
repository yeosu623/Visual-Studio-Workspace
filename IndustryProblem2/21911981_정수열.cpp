extern void my_push(int s);
extern int my_pop(int s);
extern void enqueue();

int stack2_list[10][9] = { // �ι�° ���ҿ� ���
	{-1, -1, -1, -1, -1, -1, -1, -1, -1}, // by stack 0
	{ 0,  2,  3,  4,  5,  6,  7,  8,  9}, // by stack 1
	{ 0,  1,  3,  4,  5,  6,  7,  8,  9}, // by stack 2
	{ 0,  1,  2,  4,  5,  6,  7,  8,  9}, // by stack 3
	{ 0,  1,  2,  3,  5,  6,  7,  8,  9}, // by stack 4
	{ 0,  1,  2,  3,  4,  6,  7,  8,  9}, // by stack 5
	{ 0,  1,  2,  3,  4,  5,  7,  8,  9}, // by stack 6
	{ 0,  1,  2,  3,  4,  5,  6,  8,  9}, // by stack 7
	{ 0,  1,  2,  3,  4,  5,  6,  7,  9}, // by stack 8
	{ 0,  1,  2,  3,  4,  5,  6,  7,  8}  // by stack 9
};

int stack3_list[10][13] = { // ������ ���ҿ� ���
	//�迭�� ���ڰ� ��� ���� : (hold - s) �� ���. �ش� �ڵ� ����
	//0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12
	{-1,  1,  2,  3,  4,  5,  6,  7,  8,  9,  9,  9,  9}, // Select stack 0
	{-1,  0,  2,  3,  4,  5,  6,  7,  8,  9,  9,  9,  9}, // Select stack 1
	{-1,  0,  1,  3,  4,  5,  6,  7,  8,  9,  9,  9,  9}, // Select stack 2
	{-1,  0,  1,  2,  4,  5,  6,  7,  8,  9,  9,  9,  9}, // Select stack 3
	{-1,  0,  1,  2,  3,  5,  6,  7,  8,  9,  9,  9,  9}, // Select stack 4
	{-1,  0,  1,  2,  3,  4,  6,  7,  8,  9,  9,  9,  9}, // Select stack 5
	{-1,  0,  1,  2,  3,  4,  5,  7,  8,  9,  9,  9,  9}, // Select stack 6
	{-1,  0,  1,  2,  3,  4,  5,  6,  8,  9,  9,  9,  9}, // Select stack 7
	{-1,  0,  1,  2,  3,  4,  5,  6,  7,  9,  9,  9,  9}, // Select stack 8
	{-1,  0,  1,  2,  3,  4,  5,  6,  7,  8,  8,  8,  8}  // Select stack 9
};

int stack4_list[4] = { -1, 0, 1, 2 }; // �׹�° ���ҿ� ���

int s2_list[10] = { -1, 0, 114, 228, 342, 456, 570, 684, 798, 912 }; // �ι�° ���ҿ� ���

typedef struct _range {
	int s1, d1;
	int s2, d2;
	int s3, d3;
	int s4, d4;
}range;

typedef struct _count {
	int stack1[10];
	int stack2[10];
	int stack3[10];
	int stack4[10];
	int queue;
}count;

void test_main() {
	int i, j;
	int temp;
	int hold;
	int s, d;
	int stack1, stack2, stack3, stack4;
	range r;
	count c;

	c = 
	{ {10000, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // stack1
	  {	   0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // stack2
	  {	   0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // stack3
	  {	   0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0 }; // stack4, queue

	// ù��° ���� : �ϳ��� ���ÿ� 114 ������ ���� ���� (������ ������ 114-2 = 112��)
	r.s1 = 0;
	r.d1 = 113;

	while (c.stack1[0] != 0) {
		hold = my_pop(0);
		c.stack1[0]--;

		for (stack1 = 1; stack1 <= 9; stack1++) {
			s = r.s1 + 114 * (stack1 - 1);
			d = r.d1 + 114 * (stack1 - 1);

			if (s <= hold && hold <= d) {
				my_push(stack1);
				c.stack1[stack1]++;
				break;
			}
		}
	}

	for (stack1 = 1; stack1 <= 9; stack1++) { // ù��° ���ҿ��� ���� ������ ���ʴ�� ����
		r.s2 = s2_list[stack1];
		r.d2 = r.s2 + 12;

		while (c.stack1[stack1] != 0) { // �ι�° ���� : �ϳ��� ���ÿ� 13������ ���� ���� (�������� 13-3 = 10����)
			hold = my_pop(stack1);
			c.stack1[stack1]--;
			
			for (i = 0; i < 9; i++) {
				s = r.s2 + (i * 13);
				d = r.d2 + (i * 13);

				if (s <= hold && hold <= d) {
					stack2 = stack2_list[stack1][i];

					my_push(stack2);
					c.stack2[stack2]++;

					break;
				}
			}
		}

		// ����° ���� : �ι�° ������ ������, ���� ���� ���ں��� ť�� �ֱ�
		for (i = 0; i < 9; i++) {
			stack2 = stack2_list[stack1][i];

			s = r.s2 + (i * 13);
			d = r.d2 + (i * 13);

			while (c.stack2[stack2] != 0) { // �ι�° ���ҿ��� ���� ������.
				hold = my_pop(stack2);
				c.stack2[stack2]--;

				if (hold == s) {
					enqueue();
					c.queue++;
				}
				else {
					stack3 = stack3_list[stack2][hold - s];

					my_push(stack3);
					c.stack3[stack3]++;
				}
			}

			// 3���� ������ ������ ������ �����ϰ� ���ڸ� ���ʴ�� ť�� �ִ´�.
			// ��, 2���� ������ ������ ������ �۾��ϴ� ���, 2���� ������ ������ ������ 10���̴�. ���� �ٷ� ť�� �ְ� �۾��� �����Ѵ�.
			if (i == 8) temp = 10;
			else temp = 9;
			for (j = 1; j < temp; j++) { 
				stack3 = stack3_list[stack2][j];

				while (c.stack3[stack3] != 0) {
					hold = my_pop(stack3);
					c.stack3[stack3]--;

					enqueue();
					c.queue++;
				}
			}
			if (temp == 10) continue;
			else {
				r.s4 = s + 9;
			}

			// 2���� ������ ������ ������ 13������ ���, 3��° ������ ������ ���ÿ��� 4������ ���ڰ� �����ִ�.
			// �̰� ������ 4���� ���ҷ� �����.
			stack3 = stack3_list[stack2][9];
			while (c.stack3[stack3] != 0) {
				hold = my_pop(stack3);
				c.stack3[stack3]--;

				if (hold == r.s4) {
					enqueue();
					c.queue++;
				}
				else {
					stack4 = stack4_list[hold - r.s4];

					my_push(stack4);
					c.stack4[stack4]++;
				}
			}

			// 4��° ���ҿ��� �ٷ� ť�� ���� �ִ´�.
			for (j = 1; j <= 3; j++) {
				stack4 = stack4_list[j];

				while (c.stack4[stack4] != 0) {
					hold = my_pop(stack4);
					c.stack4[stack4]--;

					enqueue();
					c.queue++;
				}
			}
		}
	}
}