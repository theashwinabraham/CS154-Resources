/*
* AUTHOR: ASHWIN ABRAHAM
*/

//solution to problem involving Smartphones
#include <iostream>
#include <vector>
#include <string>

//Extra features in some Smartphones but not all are storage expansion and Battery Replacement, other features are present in all Smartphones

//Implements basic features of Smartphones
class Smartphone{
    private:
        std::string Name;
        double Price; //in dollars
        std::string Operating_system;
        double Display; //in inches
        unsigned int Res_x;
        unsigned int Res_y;
        double Length; //in mm
        double Width; //in mm
        double Thickness; //in mm
        double Weight; //in g
        unsigned int mRAM; //in GB
        std::string mCPU; //m standing for member variable (distinguishing from member function)
        unsigned int rCam; //resolution in MP
        unsigned int fCam; //resolution in MP
        unsigned int Storage; //in GB
        unsigned int Battery; //capacity in mAh
    public:
        Smartphone(){}

        Smartphone(const std::string& name, double price, const std::string& os, double display, unsigned int res_x, unsigned int res_y,
            double length, double width, double thickness, double weight, unsigned int RAM, const std::string& CPU, unsigned int rcam, unsigned int fcam,
            unsigned int storage, unsigned int battery):
            Name(name),
            Price(price),
            Operating_system(os),
            Display(display),
            Res_x(res_x),
            Res_y(res_y),
            Length(length),
            Width(width),
            Thickness(thickness),
            Weight(weight),
            mRAM(RAM),
            mCPU(CPU),
            rCam(rcam),
            fCam(fcam),
            Storage(storage),
            Battery(battery){}

        virtual bool can_expand_storage() const{
            return false;
        }

        virtual bool can_replace_battery() const{
            return false;
        }

        virtual unsigned int maximum_storage_expansion() const{
            return 0;
        }

        std::string name() const{
            return Name;
        }

        double price() const{
            return Price;
        }

        std::string OS() const{
            return Operating_system;
        }

        double display() const{
            return Display;
        }

        unsigned int res_x() const{
            return Res_x;
        }

        unsigned int res_y() const{
            return Res_y;
        }

        double length() const{
            return Length;
        }

        double width() const{
            return Width;
        }

        double thickness() const{
            return Thickness;
        }

        double weight() const{
            return Weight;
        }

        unsigned int RAM() const{
            return mRAM;
        }

        std::string CPU() const{
            return mCPU;
        }

        unsigned int rCam_res() const{
            return rCam;
        }

        unsigned int fCam_res() const{
            return fCam;
        }

        unsigned int storage() const{
            return Storage;
        }

        unsigned int battery() const{
            return Battery;
        }

        virtual ~Smartphone(){}
};

//Class for feature storage expansion, which will be inherited into all Smartphones with storage expansion feature
class StorExp: virtual public Smartphone{
    private:
        unsigned int Max_exp; //maximum possible expansion in GB
    public:
        StorExp(unsigned int max_exp = 32): Max_exp(max_exp){}

        bool can_expand_storage() const{
            return true;
        }

        unsigned int maximum_storage_expansion() const{
            return Max_exp;
        }

        virtual ~StorExp(){}
};

//Class for feature Battery Replacement, which will be inherited into all Smartphones with Battery Replacement feature
class BatteryReplacement: virtual public Smartphone{
    public:
        bool can_replace_battery() const{
            return true;
        }

        virtual ~BatteryReplacement(){}
};

//Describes Smartphones which have Storage Expansion but not Battery Replacement
class StorExpphone: public StorExp{
    public:
        StorExpphone(const std::string& name, double price, const std::string& os, double display, unsigned int res_x, unsigned int res_y,
            double length, double width, double thickness, double weight, unsigned int RAM, const std::string& CPU, unsigned int rcam, unsigned int fcam,
            unsigned int storage, unsigned int battery, unsigned int max_exp = 32):
            Smartphone(name, price, os, display, res_x, res_y, length, width, thickness, weight, RAM, CPU, rcam, fcam, storage, battery),
            StorExp(max_exp){}
};

//Describes Smartphones which have Battery Replacement but not Storage Expansion
class BRphone: public BatteryReplacement{
    public:
        BRphone(const std::string& name, double price, const std::string& os, double display, unsigned int res_x, unsigned int res_y,
            double length, double width, double thickness, double weight, unsigned int RAM, const std::string& CPU, unsigned int rcam, unsigned int fcam,
            unsigned int storage, unsigned int battery): 
            Smartphone(name, price, os, display, res_x, res_y, length, width, thickness, weight, RAM, CPU, rcam, fcam, storage, battery){}
};

//Diamond Inheritance! Describes Smartphones with both Battery Replacement and Storage Expansion
class BRStorExpPhone: public BatteryReplacement, public StorExp{
    public:
        BRStorExpPhone(const std::string& name, double price, const std::string& os, double display, unsigned int res_x, unsigned int res_y,
            double length, double width, double thickness, double weight, unsigned int RAM, const std::string& CPU, unsigned int rcam, unsigned int fcam,
            unsigned int storage, unsigned int battery, unsigned int max_exp = 32):
            Smartphone(name, price, os, display, res_x, res_y, length, width, thickness, weight, RAM, CPU, rcam, fcam, storage, battery),
            StorExp(max_exp){}
};

int main(){
    std::vector<Smartphone*> phones;
    phones.push_back(new Smartphone("iPhone 5s", 199, "iOS 7", 4, 1136, 540, 123.8, 58.6, 7.6, 112, 1, "1GHz dual-core", 8, 1, 32, 250));
    phones.push_back(new BRStorExpPhone("Product A", 399, "Android 4.2", 5, 1920, 1080, 136.6, 69.8, 7.9, 130, 2, "1.7GHz quad-core", 13, 2, 32, 2600));
    phones.push_back(new BRStorExpPhone("Product B", 399, "Android 4.1", 4.7, 1920, 1080, 137.8, 69.3, 10.4, 156, 2, "1.7GHz quad-core", 4, 2.1, 32, 2300));
    phones.push_back(new Smartphone("Product C", 199, "Windows Phone 8", 4.5, 1280, 768, 130.4, 71.4, 10.4, 158, 2, "1.5GHz dual-core", 4.1, 1.2, 32, 2000));
    phones.push_back(new Smartphone("Product D", 0, "Android 4.2.2", 5.5, 1920, 1080, 149, 77, 7.9, 147, 2, "1.5G Hz", 13, 5, 16, 3050));
    phones.push_back(new StorExpphone("Product E", 150, "Blackberry 10", 4.2, 1280, 780, 130, 65.6, 9, 137.5, 2, "1.5GHz dual-core", 8, 2, 16, 1800, 48));
    phones.push_back(new BRphone("Product F", 300, "Blackberry 11", 4.5, 1280, 768, 130.4, 71.4, 10.4, 128, 2, "1.3GHz dual-core", 4, 1.2, 32, 1000));

    for(unsigned int i = 0; i<phones.size(); ++i){
        std::cout << "Name: " << phones[i]->name() << '\n';
        std::cout << "Price: $" << phones[i]->price() << '\n';
        std::cout << "Operating System (OS): " << phones[i]->OS() << '\n';
        std::cout << "Storage Expansion Possible? " << (phones[i]->can_expand_storage()? "YES":"NO") << '\n';
        if(phones[i]->can_expand_storage()) std::cout << "Maximum Storage Expansion: " << phones[i]->maximum_storage_expansion() << '\n';
        std::cout << "Battery Replacement Possible? " << (phones[i]->can_replace_battery()? "YES":"NO") << '\n';
        std::cout << "Display: " << phones[i]->display() << '\n';
        std::cout << "Resolution: " << phones[i]->res_x() << 'x' << phones[i]->res_y() << '\n';
        std::cout << "Total RAM: " << phones[i]->RAM() << " GB\n";
        std::cout << "CPU: " << phones[i]->CPU() << '\n';
        std::cout << "Total Storage: " << phones[i]->storage() << " GB\n";
        std::cout << "Front Camera: " << phones[i]->fCam_res() << " MP\n";
        std::cout << "Rear Camera: " << phones[i]->rCam_res() << " MP\n";
        std::cout << "Battery: " << phones[i]->battery() << " mAh\n";
        std::cout << "Length: " << phones[i]->length() << " mm\n";
        std::cout << "Width: " << phones[i]->width() << " mm\n";
        std::cout << "Thickness: " << phones[i]->thickness() << " mm\n";
        std::cout << "Weight: " << phones[i]->weight() << " g\n";
        std::cout << '\n';
        delete phones[i];
    }
    return 0;
}
