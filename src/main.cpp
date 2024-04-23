#include <iostream> 
#include <string>
#include <thread>

#include <fstream>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include <ftxui/screen/terminal.hpp>


using namespace ftxui;
using namespace std;

int main(int argc, char const *argv[])
{   
    fstream archivo;

    archivo.open("./assets/images/canon.txt");
    string canon;

    while(archivo.eof()){
        string linea;
        archivo >> linea;
        canon.append(linea);
        canon.append("\n");
    }
    archivo.close();

    archivo.open("./assets/images/alien.txt");
    string alien;
     while(archivo.eof()){
        string linea;
        archivo >> linea;
        alien.append(linea);
        alien.append("\n");
    }
    archivo.close();

    int fotograma = 0;

   while(true)
    {
        fotograma++;
        Element personaje = spinner(21, fotograma) | bold | color(Color::Yellow1) | bgcolor(Color::Green1);
        Element tanque = text(canon) | bold | color(Color::Green) | bgcolor(Color::Blue);
        Element lienzo = hbox({personaje , tanque });

        
        Screen pantalla = Screen::Create(
            Dimension::Full(),
            Dimension::Fit(lienzo));

        

        Render(pantalla, lienzo);
        pantalla.Print();
        cout<<pantalla.ResetPosition();

        this_thread::sleep_for(0.1s);
    }
    return 0;
}