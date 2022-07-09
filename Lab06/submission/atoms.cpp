/*
* modified by
* ASHWIN ABRAHAM
* 210050023
*/

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Int_Input.H>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

const int NUM_ELEMENTS = 118;
const double TAU = 6.28318;
const int CENTRE_X = 350;
const int CENTRE_Y = 350;

//draws boundary of a circle with given centre, radius and colour
void circle(double centre_x, double centre_y, double r, Fl_Color col)
{
    for(double theta = 0; theta <= (TAU-1e-4); theta+=0.01)
    {
        Fl_Box* pixel = new Fl_Box(centre_x + r*cos(theta), centre_x + r*sin(theta), 2, 2);
        pixel->box(FL_FLAT_BOX);
        pixel->color(col);
    }
}

//draws filled circle with given centre and radius
void filled_circle(double centre_x, double centre_y, double R, Fl_Color col)
{
    for(double r = 0; r<=R; r+=0.1) circle(centre_x, centre_y, r, col);
}

//draws the circle corresponding to the shell
int draw_shell(int& num_shells)
{
    ++num_shells;
    circle(CENTRE_X, CENTRE_Y, 35*num_shells, FL_GREEN);
    return num_shells;
}

//fills penultimate shell
void fill_penultimate(int shell, int& num_act_filled)
{
    --shell;
    double ang = TAU/(2*(1+(shell/2))*(1+(shell/2)));
    for(double theta = 0; theta <= (TAU-1e-4); theta+=ang)
    {
        Fl_Box* electron = new Fl_Box(CENTRE_X + 35*shell*cos(theta)-3, CENTRE_Y + 35*shell*sin(theta)-3, 6, 6);
        electron->box(FL_FLAT_BOX);
        electron->color(FL_BLACK);
        ++num_act_filled;
    }
}

//the main function which input and drawing take place via
void interact(Fl_Widget* text_input)
{
    Fl_Window* window = new Fl_Window(1000, 700);
    Fl_Int_Input* text = reinterpret_cast<Fl_Int_Input*>(text_input);
    const char* text_string = text->value();
    int atomic_number = atoi(text_string);

    //these were useless in the code given to us also
    //not removed since the pdf given to us has mentioned that we must read from the relevant files
    //from here
    std::string name[NUM_ELEMENTS], IonEnergy[NUM_ELEMENTS], weight[NUM_ELEMENTS], year[NUM_ELEMENTS];
    std::ifstream read_file;

    read_file.open("elements");
    for (int i = 0; i < NUM_ELEMENTS; i++) // input names of elements from file "elements" into an array
        read_file >> name[i];
    read_file.close();

    read_file.open("elements2");
    for (int i = 0; i < NUM_ELEMENTS; i++) // input ionization energies of elements from file "elements2" into an array
        read_file >> IonEnergy[i];
    read_file.close();

    read_file.open("elements3");
    for (int i = 0; i < NUM_ELEMENTS; i++) // input atomic weight of elements from file "elements3" into an array
        read_file >> weight[i];
    read_file.close();

    read_file.open("elements4");
    for (int i = 0; i < NUM_ELEMENTS; i++) // input discovery year of elements from file"elements4"into an array
        read_file >> year[i];
    read_file.close();
    //till here -> useless

    window->color((rand() % 4) + 212); // set window color

    int num_act_filled = 0;
    int shell_num = 0;
    for(int num_filled = 1; num_filled <= atomic_number; ++num_filled)
    {
        if(num_filled==1) draw_shell(shell_num);
        if(num_filled==3||num_filled==11||num_filled==19||num_filled==37||num_filled==55||num_filled==87) fill_penultimate(draw_shell(shell_num), num_act_filled);
        //drawing all shells and filling upto penultimate shell
    }

    //filling ultimate shell
    double ang = TAU/(atomic_number - num_act_filled);
    for(double theta = 0; theta<=(TAU-1e-4); theta+=ang)
    {
        Fl_Box* electron = new Fl_Box(CENTRE_X + 35*shell_num*cos(theta)-3, CENTRE_Y + 35*shell_num*sin(theta)-3, 6, 6);
        electron->box(FL_FLAT_BOX);
        electron->color(FL_BLACK);
    }

    //drawing nucleus
    filled_circle(CENTRE_X, CENTRE_Y, 4, FL_RED);

    window->end();
    window->show();
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    Fl_Window *window1 = new Fl_Window(500, 500);
    Fl_Int_Input *inp = new Fl_Int_Input(0, 0, 500, 100, "Enter atomic number here");
    inp->when(FL_WHEN_ENTER_KEY);
    inp->callback(interact);
    window1->end();
    window1->show();

    return Fl::run();
}