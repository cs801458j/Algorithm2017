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

/* 이중연결리스트의 맨 앞과 맨 뒤 */
Student2 *head_node = (Student2 *)malloc(sizeof(Student2));
Student2 *tail_node = (Student2 *)malloc(sizeof(Student2));

Student2* append2(Student2 *student_list2, Student2 *temp) {

	/*리스트에 원소가 없을 때 */
	if (student_list2 == 0) {
		student_list2 = temp;
		head_node =temp;
		tail_node= temp;
		return student_list2;
	}
	else {
		Student2 *search_node = tail_node;	//	맨 뒤에서부터 탐색하기 위한 포인터 
		Student2 *key_node = temp;			
		while (search_node != NULL) {	
			//	key값이 탐색하는 포인터 보다 클 때 -> 리스트의 뒤에 삽입되어야함
			if (search_node->num <= key_node->num) {
				// 삽입될 곳이 맨 뒤가 아닐 때 
				if (search_node->next != NULL) {
					search_node->next->prev = key_node;
					key_node->next = search_node->next;
					search_node->next = key_node;
					key_node->prev = search_node;
					break;
				}
				// 삽입될 곳이 맨 뒤일 때 (제일 클때)
				else {
					search_node->next = key_node;
					key_node->prev = search_node;
					break;
				}
			}
			search_node = search_node->prev;

		}
		/* 위의 while 조건을 만족하지 않을 때 (제일 작아서 맨 앞에 삽입되어야하는 경우 */
		if (head_node->num > key_node->num) {
			head_node->prev = key_node;
			key_node->next = head_node;
		}

		/* 헤드 앞에 추가되었을 때 */
		if (head_node->prev != NULL) {
			head_node = head_node->prev;
			head_node->prev = NULL;
		}
		/* 테일 뒤에 추가되었을 때 */
		if (tail_node->next != NULL) {
			tail_node = tail_node->next;
			tail_node->next = NULL;
		}
		student_list2 = head_node;
		return student_list2;
	}

}





Student* append(Student *student_list, Student *temp) {
	//Student *head_node = student_list;	//	학생리스트의 맨 앞을 가리킬 노드 
	Student *search_node = student_list;	//	학생 리스트 순회할 노드 
	// 데이터가 없을 때 
	if (student_list == 0) {
		student_list = temp;
		return student_list;
	}
	// 입력된 점수가 헤드노드보다 작을 때 
	else if (temp->score < student_list->score) {
		temp->link = student_list;
		student_list = temp;
		return student_list;
	}
	else {
		while (1) {
			//	맨 뒤까지 순회했는 데 없을 때 (제일 클 때)
			if (search_node->link == NULL) {
				search_node->link = temp;
				return student_list;
				break;
			}
			// 입력된 숫자가 탐색중인 리스트의 노드보다 작거나 같을 때 
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
		printf("%d %d 노드 free\n", temp->studentId, temp->num);
		free(temp);

	}

}

void list_free(Student *start) {

	Student *temp;
	Student *link;

	for (temp = start; temp != NULL; temp = link) {
		link = temp->link;
		printf("%d %d 노드 free\n", temp->studentId, temp->score);
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

	//	파일 읽어서 배열에 
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

