/*
* AUTHOR: ASHWIN ABRAHAM
*/

//solution to problem involving Gaming Laptops
#include <iostream>
#include <vector>
#include <string>

//Extra features in some Laptops but not all are presence of HDD, SSD, other features are present in all Laptops

//Implements basic features of Laptops
class Laptop{
    private:
        double Price; //in dollars
        std::string Name;
        std::string mCPU; //m standing for member variable (distinguishing from member function)
        std::string mGPU;
        unsigned int mRAM; //in GB
        std::string Display;
        unsigned int Res_x;
        unsigned int Res_y;
        double Weight; //in lbs
    public:
        Laptop(){}

        Laptop(double price, const std::string& name, const std::string& CPU, const std::string& GPU, unsigned int RAM, const std::string& display, unsigned int res_x,
            unsigned int res_y, double weight):
            Price(price),
            Name(name),
            mCPU(CPU),
            mGPU(GPU),
            mRAM(RAM),
            Display(display),
            Res_x(res_x),
            Res_y(res_y),
            Weight(weight){}

        virtual bool hasHDD() const{
            return false;
        }

        virtual bool hasSSD() const{
            return false;
        }

        virtual unsigned int storage_space() const{
            return 0;
        }

        double price() const{
            return Price;
        }

        std::string name() const{
            return Name;
        }

        std::string CPU() const{
            return mCPU;
        }

        std::string GPU() const{
            return mGPU;
        }

        unsigned int RAM() const{
            return mRAM;
        }

        std::string display() const{
            return Display;
        }

        unsigned int res_x() const{
            return Res_x;
        }

        unsigned int res_y() const{
            return Res_y;
        }

        double weight() const{
            return Weight;
        }

        virtual ~Laptop(){}
};

//Class for feature HDD, which will be inherited into all Laptops with HDD feature
class HDD: virtual public Laptop{
    private:
        unsigned int Space; //in GB
    public:
        HDD(unsigned int space = 1024): Space(space){}

        bool hasHDD() const{
            return true;
        }

        unsigned int storage_space() const{
            return Space;
        }

        virtual ~HDD(){}
};

//Class for feature SSD, which will be inherited into all Laptops with SSD feature
class SSD: virtual public Laptop{
    private:
        unsigned int Space; //in GB
    public:
        SSD(unsigned int space = 256): Space(space){}
        
        bool hasSSD() const{
            return true;
        }

        unsigned int storage_space() const{
            return Space;
        }

        virtual ~SSD(){}
};

//Describes Laptops which have HDDs but not SSDs
class HDDLaptop: public HDD{
    public:
        HDDLaptop(double price, const std::string& name, const std::string& CPU, const std::string& GPU, unsigned int RAM, const std::string& display, unsigned int res_x,
            unsigned int res_y, double weight, unsigned int space = 1024):
            Laptop(price, name, CPU, GPU, RAM, display, res_x, res_y, weight),
            HDD(space){}
};

//Describes Laptops which have SSDs but not HDDs
class SSDLaptop: public SSD{
    public:
        SSDLaptop(double price, const std::string& name, const std::string& CPU, const std::string& GPU, unsigned int RAM, const std::string& display, unsigned int res_x,
            unsigned int res_y, double weight, unsigned int space = 256):
            Laptop(price, name, CPU, GPU, RAM, display, res_x, res_y, weight),
            SSD(space){}
};

//Diamond Inheritance! Describes Laptops with both SSDs and HDDs
class SSDHDDLaptop: public SSD, public HDD{
    public:
        SSDHDDLaptop(double price, const std::string& name, const std::string& CPU, const std::string& GPU, unsigned int RAM, const std::string& display, unsigned int res_x,
            unsigned int res_y, double weight, unsigned int space_HDD = 1024, unsigned int space_SDD = 256):
            Laptop(price, name, CPU, GPU, RAM, display, res_x, res_y, weight),
            HDD(space_HDD),
            SSD(space_SDD){}
        
        unsigned int storage_space() const{
            return SSD::storage_space() + HDD::storage_space();
        }
};

int main(){
    std::vector<Laptop*> laptops;
    laptops.push_back(new Laptop(100, "Cheap Laptop #101", "Punch Cards", "Pen and Paper", 1, "Paper and Pen", 100, 100, 20));
    laptops.push_back(new SSDHDDLaptop(999.99, "Apple Macbook Pro", "M1 Ultra", "Blackmagic", 16, "20.6 \" TN matte", 2020, 1180, 4));
    laptops.push_back(new HDDLaptop(548.5, "Acer Aspire 3 A315-41-R8UU", "AMD Ryzen 5 2500 U 2.0-3.6 GHz (4c/8t)", "AMD Radeon Vega 8", 8, "15.6 \" TN matte", 1920, 1080, 5.07));
    laptops.push_back(new SSDLaptop(569.99, "Acer Aspire 5 A515-51G-5504", "Intel Core i5-8250U 1.6-3.4GHz (4c/8t)", "NVIDIA GeForce MX150 2GB GDDR5", 8, "15.6 \" TN matte", 1920, 1080, 4.9));
    laptops.push_back(new SSDLaptop(569.99, "Acer Aspire 5 A515-51G-5504", "Intel Core i5-8250U 1.6-3.4GHz (4c/8t)", "NVIDIA GeForce MX150 2GB GDDR5", 8, "15.6 \" TN matte", 1920, 1080, 4.9));
    laptops.push_back(new SSDLaptop(549, "Acer Aspire 5 A515-51G-53V6", "Intel Core i5-8250U 1.6-3.4GHz (4c/8t)", "NVIDIA GeForce MX150 2GB GDDR5", 8, "15.6 \" TN matte", 1920, 1080, 4.9));
    laptops.push_back(new SSDLaptop(559.99, "Acer Aspire 5 A517-51G-54GK", "Intel Core i5-7200U 2.5-3.1GHz (2c/4t)", "NVIDIA GeForce MX150 2GB GDDR5", 8, "15.6 \" IPS matte", 1920, 1080, 6.61));
    laptops.push_back(new SSDLaptop(599.99, "Acer Aspire E15 E5-576G-5762", "Intel Core i5-8250U 1.6-3.4GHz (4c/8t)", "NVIDIA GeForce MX150 2GB GDDR5", 8, "15.6 \" IPS matte", 1920, 1080, 5.27));

    for(unsigned int i = 0; i<laptops.size(); ++i){
        std::cout << "Name: " << laptops[i]->name() << '\n';
        std::cout << "Price: $" << laptops[i]->price() << '\n';
        std::cout << "Has HDD? " << (laptops[i]->hasHDD()? "YES":"NO") << '\n';
        std::cout << "Has SDD? " << (laptops[i]->hasSSD()? "YES":"NO") << '\n';
        std::cout << "Total RAM: " << laptops[i]->RAM() << " GB\n";
        std::cout << "Total Storage: " << laptops[i]->storage_space() << " GB\n";
        std::cout << "CPU: " << laptops[i]->CPU() << '\n';
        std::cout << "GPU: " << laptops[i]->GPU() << '\n';
        std::cout << "Display: " << laptops[i]->display() << '\n';
        std::cout << "Resolution: " << laptops[i]->res_x() << 'x' << laptops[i]->res_y() << '\n';
        std::cout << "Weight: " << laptops[i]->weight() << "lbs\n";
        std::cout << '\n';
        delete laptops[i];
    }
    return 0;
}
