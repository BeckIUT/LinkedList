#include<iostream>
#include<string>
using namespace std;

////////////////////////////////////////
// 		# Name : Oybek Amonov	 	  //
//		# ID : U1610176				  //
//		# Group : CSE 16-5			  //
//		# Section : 003				  //
//		# Course : Data Structure     //
////////////////////////////////////////

class Employee
{
	string name;
	int ID;
	int pnum;
	string DOB;
	string address;
	Employee* next;
public:
	Employee(){}
	friend class EmpLinkedList;
};

class EmpLinkedList
{
public:
	Employee* head;
public:
	EmpLinkedList(){ head = NULL; }

	bool Is_Empty() const { return (head == NULL); }

	void Front()
	{
		if (Is_Empty())
			cout << "--== LIST IS EMPTY ==--\n";
		else
		{
			cout << "--== FRONT ELEMENT ==--\n";
			cout << "Name: " << head->name << "\nID: " << head->ID << "\nPhone number: " << head->pnum << "\nDate of birth:" << head->DOB
				<< "\nAddress: " << head->address << endl;
		}

	}
	void Back()
	{
		Employee* temp = head;
		if (Is_Empty())
			cout << "--== LIST IS EMPTY ==--\n";
		else
		{
			while (temp != NULL)
			{
				if (temp->next == NULL){
					cout << "--== BACK ELEMENT ==--\n";
					cout << "Name: " << temp->name << "\nID: " << temp->ID << "\nPhone number: " << temp->pnum << "\nDate of birth: " << temp->DOB
						<< "\nAddress: " << temp->address << endl;
				}
				temp = temp->next;
			}
		}

	}

	void AddFront()
	{
		Employee* temp = new Employee();
		cout << "Name: ";
		cin >> temp->name;
		cout << "ID: ";
		cin >> temp->ID;
		Employee* temp1 = new Employee();
		temp1 = head;
		while (temp1 != NULL)
		{
			while (temp1->ID == temp->ID)
			{
				cout << "!!! An EMPLOYEE with such ID already exists, please enter another ID then " << temp->ID << " !!!\n";
				cin >> temp->ID;
			}
			temp1 = temp1->next;
		}
		cout << "Phone number: ";
		cin >> temp->pnum;
		cout << "Date of birth: ";
		cin >> temp->DOB;
		cout << "Address: ";
		cin >> temp->address;
		temp->next = NULL;
		if (Is_Empty())
		{
			head = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
	}

	void AddBack()
	{
		Employee* temp = new Employee;
		cout << "Name: ";
		cin >> temp->name;
		cout << "ID: ";
		cin >> temp->ID;
		Employee* temp1 = new Employee();
		temp1 = head;
		while (temp1 != NULL)
		{
			while (temp1->ID == temp->ID)
			{
				cout << "!!! An EMPLOYEE with such ID already exists, please enter another ID then " << temp->ID << " !!!\n";
				cin >> temp->ID;
			}
			temp1 = temp1->next;
		}
		cout << "Phone number: ";
		cin >> temp->pnum;
		cout << "Date of birth: ";
		cin >> temp->DOB;
		cout << "Address: ";
		cin >> temp->address;
		temp->next = NULL;

		if (Is_Empty())
		{
			cout << "--== LIST IS EMPTY, THUS GIVEN ELEMENT IS THE FIRST ==--\n";
			head = temp;
		}
		else
		{
			Employee* temp1 = head;
			while (temp1 != NULL)
			{
				if (temp1->next == NULL){
					temp1->next = temp;
					break;
				}
				temp1 = temp1->next;
			}
		}
	}

	void Print_List()
	{
		
		Employee* temp = head;
		int counter = 1;
		if (Is_Empty())
			cout << "---=== LIST IS EMPTY ===---\n";
		else
		{
			while (temp != NULL)
			{
				cout << "\n --== EMPLOYEE " << counter << " ==--\n";
				cout << "Name: " << temp->name << "\nID: " << temp->ID << "\nPhone number: " << temp->pnum << "\nDate of birth: " << temp->DOB
					<< "\nAddress: " << temp->address << endl;
				temp = temp->next;
				counter++;
			}
		}

	}

	void Find(int i)
	{
		Employee* temp = head;

		if (Is_Empty())
			cout << "--== LIST IS EMPTY ==--\n";
		else
		{
			while (temp != NULL)
			{
				if (temp->ID == i)
				{
					cout << "---=== FOUND ===---\n";
					cout << "Name: " << temp->name << "\nID: " << temp->ID << "\nPhone number: " << temp->pnum << "\nDate of birth: " << temp->DOB
						<< "\nAddress: " << temp->address << endl;
					return;
				}
				temp = temp->next;
			}
			cout << "---=== NOT FOUND ===---\n";
		}
	}

	void Modify(int i)
	{
		Employee* temp = head;

		if (Is_Empty())
			cout << "--== LIST IS EMPTY ==--\n";
		else
		{
			while (temp->ID != i && temp->next != NULL)
			{
				temp = temp->next;
			}

			if (temp->ID == i)
			{
				cout << "---=== FOUND ===---\n";
				cout << "Name: " << temp->name << "\nID: " << temp->ID << "\nPhone number: " << temp->pnum << "\nDate of birth: " << temp->DOB
					<< "\nAddress: " << temp->address << endl;

				cout << "\n\n\tYOU CAN MODIFY ANY INFORMATION EXCEPT THE ID!!!\n";
				cout << "\n\tNow, please re-enter information!!!\n\nName: ";
				cin >> temp->name;
				cout << "\nPhone number: ";
				cin >> temp->pnum;
				cout << "\nDate of birth: ";
				cin >> temp->DOB;
				cout << "\nAddress: ";
				cin >> temp->address;
			}
			else
				cout << "---=== NOT FOUND ===---\n";
		}
	}

	void Count()
	{
		int counter = 0;
		Employee* temp = head;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}

		cout << "--== THERE EXIST " << counter << " EMPLOYEES IN THE LIST ==--\n";
	}

	void DeleteFront()
	{
		if (Is_Empty())
			cout << "---=== LIST IS EMPTY ===---\n";
		else
		{
			Employee* old = head;
			head = old->next;
			delete old;
		}

	}

	void DeleteBack()
	{
		if (Is_Empty())
			cout << "---=== LIST IS EMPTY ===---\n";
		else
		{
			Employee* old = head;

			if (head->next == NULL)
			{
				head = old->next;
				delete old;
			}
			else{

				while (old != NULL)
				{
					if (old->next->next == NULL){
						old->next = NULL;
						delete old->next;
						break;
					}
					old = old->next;
				}
			}
		}

	}

	void Delete()
	{
		if (Is_Empty()){
			cout << " ---=== LIST IS EMPTY ===---" << endl;
			return;
		}

		Employee* temp = head;
		Employee* tail;
		while (temp != NULL){
			cout << "Employee: " << temp->name << " with ID: " << temp->ID << endl;
			temp = temp->next;
		}
		temp = head;
		
		int i;
		cout << "Enter ID: "; cin >> i;
		bool  validID = false;
		
		while (temp != NULL){
			if (i == temp->ID)
				validID = true;
		}
		//cout << "\n --== CAUTION, DON'T ENTER an ID that DOES NOT EXIST in the LIST. OTHERWISE, PROGRAM THROWS AN EXCEPTION ==--\n\n";
		
		if (validID)
		{
			temp = head;
			while (temp != NULL){

				if (temp->ID == i & temp == head){
					head = temp->next;
					delete temp;
					return;
				}
				else if (temp->next->ID == i){
					tail = temp->next;
					temp->next = tail->next;
					delete tail;
					return;
				}
				temp = temp->next;
			}
		}
		else
		{
			cout << "--== ENTERED AN INVALID ID, THERE IS NO SUCH EMPLOYEE WITH SUCH ID ==--\n";
			return;
		}
	}

	void Add()
	{
		Employee* temp = new Employee();
		cout << "Name: ";
		cin >> temp->name;
		cout << "ID: ";
		cin >> temp->ID;
		Employee* temp1 = new Employee();
		temp1 = head;
		while (temp1 != NULL)
		{
			while (temp1->ID == temp->ID)
			{
				cout << "!!! An EMPLOYEE with such ID already exists, please enter another ID then " << temp->ID << " !!!\n";
				cin >> temp->ID;
			}
			temp1 = temp1->next;
		}
		cout << "Phone number: ";
		cin >> temp->pnum;
		cout << "Date of birth: ";
		cin >> temp->DOB;
		cout << "Address: ";
		cin >> temp->address;
		temp->next = NULL;

		cout << endl;
		Print_List();
		cout << endl;

		if (Is_Empty())
		{
			head = temp;
			cout << " ---=== LIST IS EMPTY, THUS NEW EMPLOYEE IS THE FIRST IN THE LIST NOW\n";
			return;
		}

		int i;
		cout << "Please, enter the ID of employee before that employee you want to enter the new employee\n (I CAN'T ADD YOU AT THE END NOW, BUT BEFORE THE LAST ONE IS POSSIBLE)\n";
		cout << "\n --== CAUTION, DON'T ENTER an ID that DOES NOT EXIST in the LIST. OTHERWISE, PROGRAM THROWS AN EXCEPTION ==--\n\n";
		cin >> i;

		if (head->ID == i)
		{
			temp->next = head;
			head = temp;
		}
		else
		{
			Employee* successor = head;

			while (successor != NULL)
			{
				if (successor->next->ID == i){
					temp->next = successor->next;
					successor->next = temp;
					break;
				}
				successor = successor->next;
			}
		}
	}
};

int main()
{
	EmpLinkedList list;
	bool choice = true;
	while (choice)
	{
		int ch;
		cout << "---------------------------------------------\n\t\t --== MENU ==--\n\n\t\t1. Add Front\n\t\t2. Add Back\n\t\t3. Print List\n\t\t4. Display Front";
		cout << "\n\t\t5. Display Back\n\t\t6. Delete Front\n\t\t7. Delete Back\n\t\t8. Search(by ID)\n\t\t9. Modify(using ID)\n\t\t10. Add(by ID)\n\t\t11. Delete(By ID)\n\t\t12. Count\n\t\t13. Exit\n";
		cout << "\n---------------------------------------------\n\t Choice : ";
		cin >> ch;
		while (cin.fail())
		{
			cout << "!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!\n";
			cin >> ch;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			continue;
		}
		
		int id;
		switch (ch)
		{
		case 1:
			list.AddFront();
			cin.get();
			break;
		case 2:
			list.AddBack();
			cin.get();
			break;
		case 3:
			list.Print_List();
			cin.get();
			break;
		case 4:
			list.Front();
			cin.get();
			break;
		case 5:
			list.Back();
			cin.get();
			break;
		case 6:
			list.DeleteFront();
			cin.get();
			break;
		case 7:
			list.DeleteBack();
			cin.get();
			break;
		case 8:
			cout << "Enter the ID : ";
			cin >> id;
			list.Find(id);
			cin.get();
			break;
		case 9:
			cout << "Enter the ID : ";
			cin >> id;
			cin.get();
			list.Modify(id);
			break;
		case 10:
			list.Add();
			cin.get();
			break;
		case 11:
			list.Delete();
			cin.get();
			break;
		case 12:
			list.Count();
			cin.get();
			break;
		case 13:
			choice = false;
			break;
		default:
			cout << "\n\t\t\tINVALID OPTION\n";
			cin.get();
			break;
		}
	}
	cin.get();
	return 0;
}
