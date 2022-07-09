/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <cstdlib>
#include <cmath>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

#define PI 3.14159
#define DIM_X 1000 //below 800 not everything fits in screen
#define DIM_Y 1000 //below 800 not everything fits in screen

class Circle: public Fl_Widget{
	private:
		int x; //centre x coordinate
		int y; //centre y coordinate
		int r; //radius
		int col; //color
	public:
     	Circle(int X, int Y, int R, int Col): 
		Fl_Widget (X, Y, R, R), x(X), y(Y), r(R), col(Col){}

		void draw(){
			fl_color(col);
			fl_arc(x-r, y-r, 2*r, 2*r, 0, 360);
		}
};

class Hexagon: public Fl_Widget{
	private:
		int x; //centre x coordinate
		int y; //centre y coordinate
		int l; //sidelength
		double ang; //angle
		int col; //color
	public:
		Hexagon(int X, int Y, int L, int Ang, int Col):
		Fl_Widget (X, Y, L, L), x(X), y(Y), l(L), ang(Ang), col(Col){}

		void draw(){
			fl_color(col);
			fl_begin_loop();
			for(int i = 0; i<6; ++i) fl_vertex(DIM_X/2+300*cos(ang+i*PI/3), DIM_Y/2+300*sin(ang+i*PI/3));
			fl_end_loop();
		}
};

int main(){
	Fl_Window w(DIM_X, DIM_Y, "Rangoli");
	w.color(56);

	std::vector<Circle*> circles_center;
	for(int i = 0; i<100; ++i) circles_center.push_back(new Circle(DIM_X/2, DIM_Y/2, 2*i, rand()%256));

	std::vector<std::vector<Circle*> > circle_sides(6);
	for(int i = 0; i<100; ++i){
		for(int j = 0; j<6; ++j){
			circle_sides[j].push_back(new Circle(DIM_X/2+300*cos(j*PI/3), DIM_Y/2+300*sin(j*PI/3), i, rand()%256));
		}
	}

	Hexagon h(DIM_X/2, DIM_Y/2, 300, 0, 222);
    
	w.show();
	Fl::run();
	
	//memory cleanup
	for(int i = 0; i<100; ++i){
		delete circles_center[i];
		for(int j = 0; j<6; ++j) delete circle_sides[j][i];
	}
	return 0;
}