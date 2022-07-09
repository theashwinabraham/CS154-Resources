#include <iostream>
using namespace std;

class Observer  {
	public:
		virtual void handle(int e)=0;
};

class Tile : public Observer {
int r, c;

	public:
		Tile (int x, int y) { r =x; c=y;}
		void handle (int e) { cout << "mouse clicked on me, I am tile no. " << r << " " <<
					c << " " << " it was event no. " << e << endl;}

};

class Board {
int sizex, sizey;
Tile *t[3][3];
// Tile ** t;   // try this design too!
	public:
		Board () { 
			for (int r=0; r<3; r++)
				for (int c=0; c<3; c++)
					t[r][c]=new Tile(r,c);
		}

		void receiveMouseOnAllTiles() {
		int RightClick=125;
		 for (int r=0; r<3; r++)
			for (int c=0; c<3; c++)
				t[r][c]->handle(RightClick);
		}

};


int main (int argc, char *argv[]) {

Board b;
	b.receiveMouseOnAllTiles();

}


