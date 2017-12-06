#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


typedef struct Student {
	int studentId;
	int score;
	struct Student *link;
} Student;


typedef struct Student2 {
	int studentId;
	int num;
	struct Student2 *prev;
	struct Student2 *next;

}Student2;

/* ���߿��Ḯ��Ʈ�� �� �հ� �� �� */
Student2 *head_node = (Student2 *)malloc(sizeof(Student2));
Student2 *tail_node = (Student2 *)malloc(sizeof(Student2));

Student2* append2(Student2 *student_list2, Student2 *temp) {

	/*����Ʈ�� ���Ұ� ���� �� */
	if (student_list2 == 0) {
		student_list2 = temp;
		head_node =temp;
		tail_node= temp;
		return student_list2;
	}
	else {
		Student2 *search_node = tail_node;	//	�� �ڿ������� Ž���ϱ� ���� ������ 
		Student2 *key_node = temp;			
		while (search_node != NULL) {	
			//	key���� Ž���ϴ� ������ ���� Ŭ �� -> ����Ʈ�� �ڿ� ���ԵǾ����
			if (search_node->num <= key_node->num) {
				// ���Ե� ���� �� �ڰ� �ƴ� �� 
				if (search_node->next != NULL) {
					search_node->next->prev = key_node;
					key_node->next = search_node->next;
					search_node->next = key_node;
					key_node->prev = search_node;
					break;
				}
				// ���Ե� ���� �� ���� �� (���� Ŭ��)
				else {
					search_node->next = key_node;
					key_node->prev = search_node;
					break;
				}
			}
			search_node = search_node->prev;

		}
		/* ���� while ������ �������� ���� �� (���� �۾Ƽ� �� �տ� ���ԵǾ���ϴ� ��� */
		if (head_node->num > key_node->num) {
			head_node->prev = key_node;
			key_node->next = head_node;
		}

		/* ��� �տ� �߰��Ǿ��� �� */
		if (head_node->prev != NULL) {
			head_node = head_node->prev;
			head_node->prev = NULL;
		}
		/* ���� �ڿ� �߰��Ǿ��� �� */
		if (tail_node->next != NULL) {
			tail_node = tail_node->next;
			tail_node->next = NULL;
		}
		student_list2 = head_node;
		return student_list2;
	}

}





Student* append(Student *student_list, Student *temp) {
	//Student *head_node = student_list;	//	�л�����Ʈ�� �� ���� ����ų ��� 
	Student *search_node = student_list;	//	�л� ����Ʈ ��ȸ�� ��� 
	// �����Ͱ� ���� �� 
	if (student_list == 0) {
		student_list = temp;
		return student_list;
	}
	// �Էµ� ������ ����庸�� ���� �� 
	else if (temp->score < student_list->score) {
		temp->link = student_list;
		student_list = temp;
		return student_list;
	}
	else {
		while (1) {
			//	�� �ڱ��� ��ȸ�ߴ� �� ���� �� (���� Ŭ ��)
			if (search_node->link == NULL) {
				search_node->link = temp;
				return student_list;
				break;
			}
			// �Էµ� ���ڰ� Ž������ ����Ʈ�� ��庸�� �۰ų� ���� �� 
			if (temp->score <= search_node->link->score) {
				temp->link = search_node->link;
				search_node->link = temp;
				return student_list;
				break;
			}

			search_node = search_node->link;
		}
		
	}

}

void list_free2(Student2 *start) {

	Student2 *temp;
	Student2 *next;

	for (temp = start; temp != NULL; temp = next) {
		next = temp->next;
		printf("%d %d ��� free\n", temp->studentId, temp->num);
		free(temp);

	}

}

void list_free(Student *start) {

	Student *temp;
	Student *link;

	for (temp = start; temp != NULL; temp = link) {
		link = temp->link;
		printf("%d %d ��� free\n", temp->studentId, temp->score);
		free(temp);

	}

}
int main(void) {
	
	Student *student_list=0;
	Student *temp=0;
	Student2 *temp2 = 0;
	Student2 *student_list2 = 0;
	
	int i = 0;

	FILE *fp = fopen("C:\\Users\\eunjeong\\Desktop\\Algo1\\test1.txt", "r");

	//	���� �о �迭�� 
	while (!feof(fp)) {
		//temp = (Student *)malloc(sizeof(Student));
		temp2 = (Student2 *)malloc(sizeof(Student2));
		//fscanf(fp, "%d %d", &temp->studentId, &temp->score);
		fscanf(fp, "%d %d", &temp2->studentId, &temp2->num);
		if (temp2->num > 0) {
			temp2->prev = NULL;
			temp2->next = NULL;
			//student_list = append(student_list, temp);
			student_list2 = append2(student_list2, temp2);

		}
		//temp->link = NULL;
		
		//printf("%d %d \n",temp->studentId, temp->score);
		//fscanf(fp, "%d", &array[i]);
		//insertionSort(array, i + 1);
		//i++;
	}

	//list_free(student_list);
	list_free2(student_list2);
	fclose(fp);
	return 0;
}

