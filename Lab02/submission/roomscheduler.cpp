/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <iostream>
#include <vector>
#include <string>

const std::string days[7] = {"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};
//the number i is used in the following class definitions in stead of day[i]

class Room{
    //auxiliary class that models a room, which days it is booked on and for what events
    private:
        int room_num;
        bool booked[7];
        std::string event[7];
    public:
        Room(int Room_num = 0): room_num(Room_num){
            //initializes Room as unbooked throughout the week
            for(int i = 0; i<7; ++i){
                event[i] = "";
                booked[i] = false;
            }
        }
        int Room_num() const{
            //returns room number
            return room_num;
        }
        bool Booked(int day) const{
            //returns whether it is booked on a given day
            return booked[day];
        }
        void book(int day, const std::string& Event){
            //if the room is unbooked on that day, books the room for the given event
            //if it is booked, gives an error message and does nothing else
            if(booked[day]){
                std::cout << "This room is already booked on this day\n";
                return;
            }
            booked[day] = true;
            event[day] = Event;
            return;
        }
        void unbook(int day){
            //unbooks room on a given day
            booked[day] = false;
            event[day] = "";
        }
        std::string Event(int i) const{
            //returns the event for which a room is booked
            //since the event corresponding to an unbooked room is the empty string,
            //returns empty string for unbooked rooms
            return event[i];
        }
};

class RoomScheduler{
    private:
        std::vector<Room> rooms; //dynamic array of Rooms
    public:
        RoomScheduler(): rooms(0){}
        void add_room(int room_num){
            //adds room to the Dynamic array
            //does nothing if the room is already present
            for(int i = 0; i<rooms.size(); ++i){
                if(rooms[i].Room_num() == room_num) return;
            }
            rooms.push_back(Room(room_num));
            return;
        }
        void remove_room(int room_num){
            //removes room from the Dynamic array
            //does nothing if the room is not present
            for(int i = 0; i<rooms.size(); ++i){
                if(rooms[i].Room_num() == room_num){
                    rooms.erase(rooms.begin()+i);
                    return;
                }
            }
            return;
        }
        void book(int room_num, int day, const std::string& event = "Unspecified"){
            //books a given room on a given day for an event
            //gives error message if the room is already booked (error message comes from Room::book function)
            //or if the room is not found
            for(int i = 0; i<rooms.size(); ++i){
                if(rooms[i].Room_num() == room_num){
                    rooms[i].book(day, event);
                    return;
                }
            }
            std::cout << "Room not found\n";
            return;
        }
        void cancel(int room_num, int day){
            //unbooks a particular room on a particular day
            //gives an error message if the room is not found
            for(int i = 0; i<rooms.size(); ++i){
                if(rooms[i].Room_num() == room_num){
                    rooms[i].unbook(day);
                    return;
                }
            }
            std::cout << "Room not found\n";
            return;
        }
        int num_rooms() const{
            return rooms.size();
        }
        void print_schedule(){
            //prints the weekly schedule of each room
            std::cout << "ROOM        ";
            for(int i = 0; i<7; ++i){
                std::cout << days[i] << "        ";
            }
            std::cout << '\n';
            for(int i = 0; i<110; ++i) std::cout << '_';
            std::cout << '\n';
            for(int i = 0; i<rooms.size(); ++i){
                std::cout << rooms[i].Room_num() << "         ";
                for(int j = 0; j<7; ++j){
                    std::cout << rooms[i].Event(j);
                    for(int k = 0; k<8+days[j].length()-rooms[i].Event(j).length(); ++k) std::cout << ' ';
                }
                std::cout << '\n';
                for(int i = 0; i<110; ++i) std::cout << '_';
                std::cout << '\n';
            }
        }
};

int main(int argc, char* argv[]){
    //example demonstrating usage of the class
    RoomScheduler rs;
    rs.add_room(101);
    rs.add_room(105);
    rs.add_room(106);
    rs.add_room(107);
    rs.add_room(108);
    rs.add_room(109);
    rs.add_room(111);
    rs.add_room(119);
    rs.add_room(152);
    rs.book(100, 0); //room not found
    rs.book(101, 0, "CS 101");
    rs.book(101, 3, "CS 101");
    rs.book(101, 4, "BB 101");
    rs.book(152, 0, "CS 152");
    rs.book(152, 1, "CS 152");
    rs.book(152, 2, "CS 152");
    rs.book(152, 3, "CS 152");
    rs.book(152, 4, "CS 152");
    rs.book(152, 5, "CS 152");
    rs.book(152, 6, "CS 152");
    rs.book(106, 1, "MA 106");
    rs.book(107, 6, "PH 107");
    rs.book(107, 1, "PH 107");
    rs.book(107, 2, "CH 107");
    rs.book(107, 1, "CH 107"); //room already booked
    rs.book(105, 2, "CH 105");
    rs.book(105, 4, "CH 105");
    rs.book(106, 5, "MA 106");
    rs.book(106, 3, "MA 106");
    rs.book(108, 5, "PH 108");
    rs.book(108, 5, "MA 108"); //room already booked
    rs.book(108, 4, "MA 108");
    rs.book(109, 0, "MA 109");
    rs.book(109, 6, "MA 109");
    rs.book(111, 5, "MA 111");
    rs.book(111, 3, "MA 111");
    rs.book(119, 0, "ME 119");
    std::cout << "\n\n";
    rs.print_schedule();
    std::cout << "\n\n\n";
    rs.cancel(101, 4);
    rs.cancel(105, 2);
    rs.cancel(105, 4);
    rs.cancel(119, 0);
    rs.remove_room(119);
    rs.print_schedule();
    return 0;
}
