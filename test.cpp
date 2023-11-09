#include <SFML/Graphics.hpp>
using namespace sf;

#include <string>
#include <iostream>


class Menu{
    private:
        RenderWindow * _menu1Window;
        RenderWindow * _menu2Window;
        Text * _startText;
        Text _congrat;
        Font _font;
        int _size1;
        int _size2;
    public:
        Menu(int size1, int size2){
            _menu1Window = new RenderWindow(VideoMode(size1, size2), "Menu 1");
            _menu2Window = new RenderWindow(VideoMode(size1, size2), "Menu 2");
            _size1 = size1;
            _size2 = size2;
            _startText = new Text[3];
            if (!_font.loadFromFile("font.ttf")){
                std:: cout << "Cannot load font." << std::endl;
                exit(0);
            }

            for (int i=0; i<3; i++){
                _startText[i].setFont(_font);
                _startText[i].setFillColor(Color::White);
                _startText[i].setCharacterSize(20);
                //_text[i].setOrigin(size1/2, size2/2 + 50*i);
                _startText[i].setPosition(size1/2-200, size2/3 + 50*i);
            }
            _startText[0].setString("START");
            _startText[1].setString("RESUME");
            _startText[2].setString("EXIT");

            _congrat.setFont(_font);
            _congrat.setFillColor(Color::White);
            _congrat.setCharacterSize(20);
            _congrat.setPosition(size1/2-200, size2/3);
            _congrat.setString("Congrats!! You have won!!!");

        }

        void run(){
            while (_menu1Window->isOpen()) {
                Event event1;
                while (_menu1Window->pollEvent(event1)) {
                    if (event1.type == sf::Event::Closed || event1.key.code == sf::Keyboard::Q)
                        _menu1Window->close();
                    }
                    if (event1.type == Event::TouchBegan){
                        if (event1.touch.y <= _size2/3 + 50 -50  && event1.touch.y >= _size2/3 + 50 + 50 && event1.touch.x >= _size1/2-200-50 && event1.touch.x <= _size1/2-200+50){
                            while (_menu2Window -> isOpen()){
                                Event event2;

                                while(_menu2Window->pollEvent(event2)){
                                    if (event2.type == sf::Event::Closed){
                                        _menu2Window->close();
                                    }
                                }

                                // display the string
                                _menu1Window -> close();
                                _menu2Window -> draw(_congrat);
                                _menu2Window -> display();
                                _menu2Window -> clear();
                            }
                        }
                    }
                _menu1Window -> clear();
                _menu1Window -> draw(_startText[0]);
                _menu1Window -> draw(_startText[1]);
                _menu1Window -> draw(_startText[2]);
                _menu1Window -> display();
            }       
        }
        

        ~Menu(){
            delete [] _startText;
        }
};

int main(){

    Menu m(1000,600);
    m.run();

    
    return 0;
}