#include <iostream>
#include <string>
#include <vector>

class GameObject {
private:
    static int nextValidId;
    int objectId;

protected:
    std:: string name;

public:
    GameObject(std:: string objName) : objectId(++nextValidId), name(objName) {
        std:: cout << "[construct] GameObject: " << name << " (ID: " << objectId << ") \n";
    }

    virtual ~GameObject() {
        std::cout << "[Destruct] GameObject: " << name << '\n';
    }

    int getId() const { return objectId; }

    virtual void update() = 0;
};

int GameObject::nextValidId = 0;

class Renderable : virtual public GameObject {
protected:
    bool isVisible;

public:
    Renderable(std::string name, bool visible) : GameObject(name), isVisible(visible) {
        std::cout << "[Construct] Renderable trait added to: " << this->name << "\n";
    }

    virtual void draw() const {
        if(isVisible){
            std::cout << " -> Drawing model for " << name << " on screen.\n";
        }
    }
};

class PhysicsBody : virtual public GameObject {
protected:
    float mass;
    float velocity;

public:
    PhysicsBody(std::string name, float m) : GameObject(name), mass(m), velocity(0.0f) {
        std::cout << "[construct] Physical trait added to: " << this->name << "\n";
    }

    virtual void applyForce(float force) {
        velocity += (force/mass);
        std::cout << " -> Applied force to " << name << ". Velocity is now " << velocity << "\n";
    }
};

class Player : public Renderable, public PhysicsBody {
    private:
    int health;

    public:
    Player(std::string name, float mass, int hp) : GameObject(name), Renderable(name, true), PhysicsBody(name, mass), health(hp) {
        std::cout << "[construct] PLayer fuly assembled.\n";
    }

    ~Player() override {
        std::cout << "[Destruct] Player.\n";
    }

    void update() override {
        std::cout << "[Update] Player '" << name << "' is thinking. Health:" << health << "\n";
    }

    virtual void takeDamage(int dmg) final {
        health -= dmg;
        std::cout << name << " took " << dmg << " damage! Health: " << health << "\n";
    }
};

class AdminPlayer : public Player {
    public:
    AdminPlayer(std::string name) : GameObject(name), Player(name, 100.0f, 9999) {
        std:: cout << "[construct] Admin privileges granted to " << name << ".\n";
    }

    void update() override {
        std::cout << "[Update] Admin '" << name << "' is monitoring the server.\n";
    }
};

class NetworkSocket {
    public:
    void openConnection() {
        std::cout << "[Network] Socket opened.\n";
    }

    void closeConnection() {
        std::cout << "[Network] Socket closed.\n";
    }
};

class MultiplayerSession : private NetworkSocket {
public:

    void startMatch() {
        openConnection();
        std::cout << "[Match] Match has started.\n";
    }

    void endMatch() {
        std::cout << "[Match] Match ended.\n";
        closeConnection();
    }
};

int main() {
    std::cout << "--- 1. Testing Multiple/Virtual Inheritance & Construction Order ---\n";
    // Observe the output: GameObject is constructed ONLY ONCE despite 2 intermediate classes.
    Player hero("Arthur", 75.5f, 100);
    
    std::cout << "\n--- 2. Testing Multilevel Inheritance ---\n";
    AdminPlayer admin("Neo");

    std::cout << "\n--- 3. Testing Polymorphism (Upcasting) ---\n";
    // Storing derived objects in a collection of base class pointers
    std::vector<GameObject*> gameWorld;
    gameWorld.push_back(&hero);
    gameWorld.push_back(&admin);

    for (GameObject* obj : gameWorld) {
        // Late binding (Dynamic Dispatch): Calls the correct overridden method
        obj->update(); 
    }

    std::cout << "\n--- 4. Testing Sibling Methods ---\n";
    hero.draw();             // Inherited from Renderable
    hero.applyForce(150.0f); // Inherited from PhysicsBody
    hero.takeDamage(20);     // Inherited from Player

    std::cout << "\n--- 5. Testing Private Inheritance ---\n";
    MultiplayerSession session;
    session.startMatch();
    // session.openConnection(); // ERROR: openConnection() is private in MultiplayerSession
    session.endMatch();

    std::cout << "\n--- 6. Testing Destructor Order ---\n";
    // Destructors are called in the exact REVERSE order of constructors.
    return 0;
}