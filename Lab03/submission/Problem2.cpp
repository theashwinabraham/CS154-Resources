/*
* AUTHOR: ASHWIN ABRAHAM
*/

//Solution for the Problem regarding TV sets
#include <iostream>
#include <string>

//Basic features present in all TVs
class TV{
    private:
        int Cost;
        std::string Brand;
        int Model_num;
        double Weight;
        int Width;
        int Height;
        int Screen_width;
        int Screen_height;
        int Resolution;
    public:
        TV(int cost, const std::string& brand, int MN, double weight, int width, int height, int s_width, int s_height, int res): 
            Cost(cost),
            Brand(brand),
            Model_num(MN),
            Weight(weight),
            Width(width),
            Height(height),
            Screen_width(s_width),
            Screen_height(s_height),
            Resolution(res){}

        int cost() const{
            return Cost;
        }

        std::string brand() const{
            return Brand;
        }

        int model_num() const{
            return Model_num;
        }

        double weight() const{
            return Weight;
        }

        int width() const{
            return Width;
        }

        int height() const{
            return Height;
        }

        int screen_width() const{
            return Screen_width;
        }

        int screen_height() const{
            return Screen_height;
        }

        int resolution() const{
            return Resolution;
        }
};

//Class for feature internet, which will be inherited into all TVs with internet feature
class Internet{
    public:
        void internet() const{
            std::cout << "Internet is enabled\n";
            return;
        }
};

//Class for feature cable, which will be inherited into all TVs with cable feature
class Cable{
    public:
        void cable() const{
            std::cout << "Cable is enabled\n";
            return;
        }
};

//Class for feature videoin, which will be inherited into all TVs with videoin feature
class Videoin{
    public:
        void videoin() const{
            std::cout << "Videoin is enabled\nVideo is going in\n";
            return;
        }
};

//Class for feature audioin, which will be inherited into all TVs with audioin feature
class Audioin{
    public:
        void audioin() const{
            std::cout << "Audioin is enabled\nAudio is going in\n";
            return;
        }
};

//Class for feature videoout, which will be inherited into all TVs with videoout feature
class Videoout{
    public:
        void videoout() const{
            std::cout << "Videoout is enabled\nVideo is going out\n";
            return;
        }
};

//Class for feature audioout, which will be inherited into all TVs with audioout feature
class Audioout{
    public:
        void audioout() const{
            std::cout << "Audioout is enabled\nAudio is going out\n";
            return;
        }
};

class TV1: public TV, public Internet, public Cable, public Videoin, public Audioin, public Audioout{
    public:
        TV1(int cost = 10000, std::string brand = "LG", int MN = 20, double weight = 40, int width = 3000, int height = 2000, int s_width = 2500,
            int s_height = 1800, int res = 1920): TV(cost, brand, MN, weight, width, height, s_width, s_height, res){}
};

class TV2: public TV, public Videoin, public Audioin{
    public:
        TV2(int cost = 10000, std::string brand = "LG", int MN = 20, double weight = 40, int width = 3000, int height = 2000, int s_width = 2500,
            int s_height = 1800, int res = 1920): TV(cost, brand, MN, weight, width, height, s_width, s_height, res){}
};

class TV3: public TV, public Cable, public Audioin, public Videoout, public Audioout{
    public:
        TV3(int cost = 10000, std::string brand = "LG", int MN = 20, double weight = 40, int width = 3000, int height = 2000, int s_width = 2500,
            int s_height = 1800, int res = 1920): TV(cost, brand, MN, weight, width, height, s_width, s_height, res){}
};

class TV4: public TV, public Internet, public Videoin, public Videoout{
    public:
        TV4(int cost = 10000, std::string brand = "LG", int MN = 20, double weight = 40, int width = 3000, int height = 2000, int s_width = 2500,
            int s_height = 1800, int res = 1920): TV(cost, brand, MN, weight, width, height, s_width, s_height, res){}
};

int main(){
    TV1 tv1;
    std::cout << tv1.brand() << " costing " << tv1.cost() << '\n';
    tv1.audioin();
    tv1.audioout();
    tv1.cable();
    tv1.internet();
    tv1.videoin();
    std::cout << '\n';

    TV2 tv2(20000, "Samsung");
    std::cout << tv2.brand() << " costing " << tv2.cost() << '\n';
    tv2.audioin();
    tv2.videoin();
    std::cout << '\n';

    TV3 tv3(15000, "Apple");
    std::cout << tv3.brand() << " costing " << tv3.cost() << '\n';
    tv3.audioin();
    tv3.audioout();
    tv3.cable();
    tv3.videoout();
    std::cout << '\n';
    
    TV4 tv4(50000, "Lenovo");
    std::cout << tv4.brand() << " costing " << tv4.cost() << '\n';
    tv4.internet();
    tv4.videoin();
    tv4.videoout();
    return 0;
}
