#include <iostream>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>

using namespace std;

class myRect: public Fl_Widget {
private:
    Fl_Color color;
    void draw(){
    fl_color(color);
    fl_rectf(x(),y(),w(),h(),color);
}

public:
    myRect(int X,int Y,int W,int H, Fl_Color c)
        :Fl_Widget(X,Y,W,H),color(c) {}
};

vector<myRect*> allRect;

void winUpdate(void *data)
{
    std::cout << "ayy\n";
    static unsigned i = 0;
    Fl_Double_Window *o = (Fl_Double_Window*)data;
    if(i < allRect.size()){
        o->add(allRect[i]);
        if(i>=3) o->remove(allRect[i-3]);
        o->redraw();
        Fl::add_timeout(0.1,winUpdate,data);
        ++i;
    }
}

int main (int argc, char** argv)
{
    for(int i=0; i<8; ++i){
        allRect.push_back(new myRect(i*30,i*30,50,50,i));
    }
    Fl_Double_Window *window = new Fl_Double_Window (400, 400, "FLTK Test");
    Fl::add_timeout(0.1,winUpdate,window);
    window->end();
    //Fl::visual(FL_DOUBLE|FL_INDEX);
    window->show();
    return Fl::run();
}
