#include <iostream>
#include <cstring>

// Abstract base class (Abstraction)
class Character {
protected:
    char name[50];
    int health;
    int attackPower;

public:
    virtual void attack(Character& target) = 0;      // pure virtual (abstract) function
    virtual void takeDamage(int damage) = 0;         // pure virtual (abstract) function

    // Common setters
    void setName(const char* newName) {
        std::strncpy(name, newName, sizeof(name));
    }

    void setHealth(int h) {
        health = h;
    }

    void setAttackPower(int power) {
        attackPower = power;
    }

    // Common getters
    const char* getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

    int getAttackPower() const {
        return attackPower;
    }
};

// Player class (inherits abstraction + uses encapsulation)
class Player : public Character {
public:
    void attack(Character& target) override {
        std::cout << name << " attacks " << target.getName()
                  << " for " << attackPower << " damage!" << std::endl;
        target.takeDamage(attackPower);
    }

    void takeDamage(int damage) override {
        health -= damage;
        if (health < 0) health = 0;
    }
};

// Enemy class (inherits abstraction + uses encapsulation)
class Enemy : public Character {
public:
    void attack(Character& target) override {
        std::cout << name << " bites " << target.getName()
                  << " for " << attackPower << " damage!" << std::endl;
        target.takeDamage(attackPower);
    }

    void takeDamage(int damage) override {
        health -= damage;
        if (health < 0) health = 0;
    }
};

int main() {
    // Create player and enemy
    Player player;
    player.setName("Hero");
    player.setHealth(100);
    player.setAttackPower(20);

    Enemy enemy;
    enemy.setName("Goblin");
    enemy.setHealth(50);
    enemy.setAttackPower(10);

    // Use abstraction: base class pointer to derived objects
    Character* attacker = &player;
    Character* defender = &enemy;

    // Simulate attack using abstract interface
    attacker->attack(*defender);

    // Output the result
    std::cout << defender->getName() << " health: " << defender->getHealth() << std::endl;

    return 0;
}
