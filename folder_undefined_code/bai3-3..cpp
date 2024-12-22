#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;
double pi = 3.14;
class Diem {
    private:
        int x, y;
    public:
        Diem(int a = 0, int b = 0) {
            x = a;
            y = b;
        }

        void setX(int a) {
            x = a;
        }
        void setY(int b) {
            y = b;
        }

        int getX() {
            return x;
        }
        int getY() {
            return y;
        }

        void DiChuyen(int a, int b){
            setX(getX() + a);
            setY(getY() + b);
        }
};

class DaGiac {
    private:
        int Num;
    public:
        void setNum(int num) {
            Num = num;
        }
        int getNum() {
            return Num;
        }
        map<int, Diem> mp;
        DaGiac(int num) {
            setNum(num);
            for(int i = 0; i < getNum(); i++){
                mp[i + 1] = {i, i};
            }
        }

        void Xoay(int Goc) {
            double rad = Goc * pi/180;
            int h = 500;
            double cos_rad = cos(rad);
            double sin_rad = sin(rad);
            int x_symmetry = h - mp[1].getX();
            int y_symmetry = h - mp[1].getY();
            for(int i = 1; i <= getNum(); i++) {
                int x = mp[i].getX();
                int y = mp[i].getY();
                int new_x = (int)(cos_rad * (x - h) - sin_rad * (y - h) + h + x_symmetry);
                int new_y = (int)(sin_rad * (x - h) + cos_rad * (y - h) + h + y_symmetry);
                mp[i].setX(h - new_x);
                mp[i].setY(h - new_y);
            }
        }

        Diem getDinh(int num){
            return Diem(mp[num].getX(), mp[num].getY());
        }

        void setDinh(int num, Diem point) {
                mp[num].setX(point.getX());
                mp[num].setY(point.getY());
        }

        void DiChuyen(int a, int b) {
            for(int i = 1; i <= getNum(); i++)
            mp[i].DiChuyen(a, b);
        }

        void PhongTo(double k) {
            for(int i = 1; i <= getNum(); i++) {
                mp[i].setX(mp[i].getX() * k);
                mp[i].setY(mp[i].getY() * k);
            }
        }
        void ThuNho(double k){
            for(int i=1;i<=getNum();i++){
                mp[i].setX(mp[i].getX() / k);
                mp[i].setY(mp[i].getY() / k);
            }
        }
};  

int main() {
    Diem point[4] = {{30, 10}, {50, 40}, {30, 70}, {10, 40}};
    DaGiac A = DaGiac(4);
    
    for (int i = 0; i < A.getNum(); i++) {
        A.setDinh((i+1), point[i]);
    }

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");
    sf::Vertex Oy[] = {
        sf::Vertex(sf::Vector2f(window.getSize().x/2, window.getSize().y)),
        sf::Vertex(sf::Vector2f(window.getSize().x/2, 0))
    };

    sf::Vertex Ox[] = {
        sf::Vertex(sf::Vector2f(0, window.getSize().y/2)),
        sf::Vertex(sf::Vector2f(window.getSize().x, window.getSize().y/2))
    };

    float TrucOy = window.getSize().y/2;
    float TrucOx = window.getSize().x/2;

    sf::ConvexShape base;
    sf::ConvexShape move_zoom;
    base.setPointCount(4);
    move_zoom.setPointCount(4);

    for(int i = 0; i < A.getNum(); i++)
        base.setPoint(i, sf::Vector2f(A.getDinh(i + 1).getX() + TrucOx, TrucOy - A.getDinh(i + 1).getY()));

    A.DiChuyen(-200,0);
    A.PhongTo(2);
    for(int i = 0; i < A.getNum(); i++)
        move_zoom.setPoint(i, sf::Vector2f(A.getDinh(i + 1).getX() + TrucOx, TrucOy - A.getDinh(i + 1).getY()));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) 
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(Oy, 2, sf::Lines);
        window.draw(Ox, 2, sf::Lines);
        window.draw(base);
        window.draw(move_zoom);
        window.display();
    }
    return 0;
}