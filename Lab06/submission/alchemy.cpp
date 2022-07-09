/*
* modified by
* ASHWIN ABRAHAM
* 210050023
*/

/* This game lets you create the world around you using the four elements of Archimedes - air, fire, water and earth. 
You can combine two of the known elements and create a new element. 
This goes on till all elements have been created. 
The elements are a structure, having four attributes, namely -
Name, Baap1 and Baap2 (the creator elements) and status (whether it has been created or not). The user has several options -

To Combine and Create
To Look up the database of created elements
To look up all the information (which has been explored by the user) of a certain element
To Look up the list of possible elements
To exit the program if the user gets infy bored
*/

#include <iostream>
#include <fstream>

#define THING_SIZE 364

//class of elements
class Element {
	private:
		std::string Baap1; //name of baap1
		std::string Baap2; //name of baap2
		bool Status; //whether Element has been created or not
		std::string Name; //name of element
	public:
		Element(const std::string& name = "", const std::string& baap1 = "elemental", const std::string& baap2 = "elemental", bool status = false):
			Baap1(baap1), Baap2(baap2), Status(status), Name(name){}

		std::string& baap1()
		{
			return Baap1;
		}

		std::string& baap2()
		{
			return Baap2;
		}

		bool& created()
		{
			return Status;
		}

		std::string& name()
		{
			return Name;
		}

		//If the element has already been created, exits with code 1, does nothing
		//otherwise, it creates the element and prints a message and exits with code 0
		int create()
		{
			if(Status) return 1;
			std::cout << "\nCongratulations, new Element " << Name << " created\n";
			Status = true;
			return 0;
		}
};


//This function has four input parameters- username, string1 and string2 and the array of all elements,'thing'.
//Status of both strings is checked. If one of them corresponds to an element that hasn't been created, function exits with code -1.
//If they are both present and created and there exists an element that hasn't been created with baaps with names string1 and string2
//then it creates that element and exits with non-negative code (success) (the return value corresponds to the index of the created element)
//In other cases (eg: one name corresponding to a created element, and the other corresponding to no element), it exits with code -2
int create(const std::string& username, const std::string& name1, const std::string& name2, Element* thing)
{
	//checking if one of the names corresponds to an element that hasn't been created
	for(int i = 0; i<THING_SIZE; ++i)
	{
		if((thing[i].name() == name1 || thing[i].name() == name2) && !thing[i].created())
		{
			std::cout << "ERROR: Element used not created\n";
			return -1;
		}
	}

	//if they are present in thing, then corresponding elements have been created
	//checks if there is an element whose baaps are name1 and name2
	for(int i = 0; i<THING_SIZE; ++i)
	{
		if((thing[i].baap1() == name1 && thing[i].baap2() == name2) ||
			(thing[i].baap1() == name2 && thing[i].baap2() == name1))
		{
			//if there is such an element and it hasn't been previously created,
			//then message is displayed and function terminates
			//logs creation in user.c
			if(thing[i].create() == 0)
			{
				std::ofstream user;
				user.open("user.c", std::ios_base::app);
				user << username << '\n' << thing[i].name() << " = " << thing[i].baap1() << " + " << thing[i].baap2() << '\n' << username << '\n';
				return i;
			}
		}
	}
	//This is reached if either name1 or name2 do not correspond to elements
	//or if all elements with baaps name1 and name2 have already been created
	std::cout << "Sorry, no new element created\n";
	return -2;
}

//prints all created elements
void look(Element* thing)
{
	std::cout << '\n';
	for(int i = 0, x = 1; i<THING_SIZE; ++i)
	{
		if(thing[i].created())
		{
			std::cout << x << ". " << thing[i].name() << '\n';
			++x;
		}
	}
}

//prints all created elements with search string as name or baaps name
void lookinfo(const std::string& search_string, Element* thing)
{
	std::cout << '\n';
	for(int i = 0, x = 1; i<THING_SIZE; ++i)
	{
		if(thing[i].created() && ((thing[i].name()==search_string) ||
		(thing[i].baap1() == search_string) ||
		(thing[i].baap2() == search_string)))
		{
			std::cout << x << ". " << thing[i].name() << '\n';
			++x;
		}
	}
}

//prints all elements
void lookall(Element* thing){
	std::cout << '\n';
	for(int i = 0; i<THING_SIZE; ++i) std::cout << thing[i].name() << '\n';
}

int main()
{
	std::cout<<"\n\n*******************************************************************************************************************\n"; 
	std::cout << "This game lets you create the world around you using the four elements of Archimedes - air, fire, water and earth.\n"; 
	std::cout << "You can combine two of the known elements and create a new element. This goes on till all elements have been created.\n\n\n";
	std::cout << "**Please do not use Capital Letters. \n\n\n";
	std::cout << "**Enter all data in small case.Like password, this program is case sensitive";
	std::cout<<"\n_________________________________________________________________________________________________________________________________";
	std::cout << "-\nAre you a new user?Enter 'yes' if you are. If you are not a new user then enter no. \n";

	//New user check
	std::string ans, username;
	std::cin >> ans;

	//checks if username already exists
	if(ans == "yes")
	{
		bool exists = false;
		do{
			exists = false;
			std::cout << "Enter a Username: ";
			std::cin >> username;
			std::ifstream usr;
			usr.open("user.c");
			std::string usr_file;
			while(usr >> usr_file)
			{
				if(username == usr_file)
				{
					std::cout << "\nSorry, this username is taken\n";
					exists = true;
					break;
				}
			}
			usr.close();
		} while(exists);
		std::ofstream add_usr;
		add_usr.open("user.c", std::ios_base::app);
		add_usr << "newUser " << username << '\n' << username << " \n ";
		add_usr.close();
	}
	else
	{
		//checks if user actually exists
		bool exists = false;
		do
		{
			std::cout << "Enter your Username: ";
			std::cin >> username;
			std::ifstream usr;
			usr.open("user.c");
			std::string usr_file;
			while(usr >> usr_file)
			{
				if(usr_file == username)
				{
					exists = true;
					std::cout << "\nPleased to meet you again\n";
					break;
				}
			}
			if(!exists)
			{
				std::cout << "Sorry, your username was not found\n";
			}
			usr.close();
		} while (!exists);
	}

	//reading the elements into thing from data.c
	Element thing[THING_SIZE];
	std::ifstream data;
	data.open("data.c");
	for(int i = 0; i<THING_SIZE; ++i)
	{
		data >> thing[i].name() >> thing[i].baap1() >> thing[i].baap2();
		if(thing[i].name() == "air" || thing[i].name() == "water" || thing[i].name() == "earth" || thing[i].name() == "fire")
		{
			thing[i].baap1() = "elemental";
			thing[i].baap2() = "elemental";
			thing[i].created() = true;
		}

		//in case the user has already unlocked elements, their status is set to created
		std::ifstream users;
		users.open("user.c");
		std::string value;
		users >> value; //skips fist word (newUser)
		//format of user.c is:
		/*
		newUser name //newUser only when a newUser is registered
		created element
		name
		another_name
		...
		...
		name
		another created element
		name
		*/
		while(!users.eof())
		{
			//goes through user.c until the required username appears
			while(value!=username && !users.eof()) users >> value;

			//goes to the next word when loop condition is initially executed
			//(now we are in the list of created elements) (if the list is empty we are now at the terminating name)
			while(users >> value && value!=username) //breaks when EOF is reached or terminating name is reached
			{
				if(thing[i].name() == value) thing[i].created() = true;
			}

		}
		users.close();
	}
	data.close();

	//start the main loop
	while(true)
	{
		std::cout << "\n\n------------------------------------------------------------------------------------------------------------\n\n";
		std::cout << "Enter your choice\n";
		std::cout << "1. Combine and Create\n";
		std::cout << "2.Look up all created elements\n";
		std::cout << "3.Look up info of one element\n";
		std::cout << "4.Look up all possible elements\n";
		std::cout << "5. Exit\n: ";

		int choice;
		std::cin >> choice;

		switch (choice)
		{
			case 1:
			{
				std::cout << "\nEnter the Elements you wish to combine: ";
				std::string baap1, baap2;
				std::cin >> baap1 >> baap2;
				create(username, baap1, baap2, thing);
				break;
			}
			
			case 2:
			{
				std::cout<<"\n\n-----------------------------------You have the following Elements--------------------------------------\n";
				std::cout << "\n--fire, earth, air and water are elemental. \n";
				std::ifstream user;
				user.open("user.c");
				std::string value;
				//iterates through all members of user.c to find username (in between 2 instances of username will be the stored elements)
				while(user >> value)
				{
					if(value == username)
					{
						user >> value; //moves to beginning of element list
						while(value!=username)
						{
							std::cout << "--";
							//each created element is logged as name = baap1 + baap2 (5 words)
							//hence we print out these words
							for(int i = 0; i<5; ++i)
							{
								std::cout << value;
								user >> value;
							}
							std::cout << '\n';
							//now value is at another instance of username hence we break out of while loop also
						}
					}
				}
				user.close();
				break;
			}

			case 3:
			{
				std::cout<<"\nEnter the element whose info you want: ";
				std::string search_string;
				std::cin >> search_string;
				lookinfo(search_string, thing);
				break;
			}

			case 4:
			{
				lookall(thing);
				break;
			}
			
			case 5:
			{
				//saving user profile again on exit
				std::ofstream User;
				User.open("user.c", std::ios_base::app);
				User << '\n' << username << ' ' << username << ' ';
				return 0;
			}
		}
	}
	return 0;
}