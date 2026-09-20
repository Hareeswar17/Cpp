#include <iostream>
using namespace std;

// Base class
class GameObject
{
protected:
    string name;

public:
    GameObject(string n) : name(n) {} // This way of declaring is called member initializer list

    virtual void update() = 0; // Pure virtual function
    // This is made because we don't want to declare any method to this function right now hence we have to declare something we can't leave it empty so we this 

    virtual ~GameObject() = default; // Destructor
    // Because the destructor is virtual, C++ looks at the actual object type
    // And calls the Player destructor and then GameObject destructor
    // This class can have derived classes, so destrcution should be polymorphic hence vitual keyword
};

// Base class 1
class Renderable : virtual public GameObject
{
public:
    Renderable(string n) : GameObject(n) {} // This is the proper way because the base class must be initialized before the constructor body runs 
    // so we cannot do => Renderable(string n) { GameObject(n); }

    void draw()
    {
        cout << name << " is being rendered\n";
    }
};

// Base class 2
class PhysicsBody : virtual public GameObject
{
public:
    PhysicsBody(string n) : GameObject(n) {}

    void move()
    {
        cout << name << " is moving\n";
    }
};

// Multiple inheritance
class Player : public Renderable, public PhysicsBody
{
public:
    Player(string n)
        : GameObject(n), Renderable(n), PhysicsBody(n) {}

    void update() override
    {
        cout << name << " is updating\n";
    }
};

// Multilevel inheritance
class AdminPlayer : public Player
{
public:
    AdminPlayer(string n)
        : GameObject(n), Player(n) {}

    void update() override
    {
        cout << name << " is monitoring the server\n";
    }
};

int main()
{
    Player player("Arthur");
    AdminPlayer admin("Neo");

    // Multiple inheritance
    player.draw();
    player.move();

    // Runtime polymorphism
    GameObject *obj = &admin;
    obj->update();

    return 0;
}