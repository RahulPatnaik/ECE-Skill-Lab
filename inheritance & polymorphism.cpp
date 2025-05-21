#include <iostream>
#include <cstring>

using namespace std;

// Base class Character
class Character {
protected:
    char name[50];
    int health;
    int attackPower;

public:
    // Setters
    void setName(const char* newName) {
        strncpy(name, newName, sizeof(name));
        name[sizeof(name)-1] = '\0'; // Ensure null termination
    }

    void setHealth(int h) {
        health = h;
    }

    void setAttackPower(int power) {
        attackPower = power;
    }

    // Getters
    const char* getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

    int getAttackPower() const {
        return attackPower;
    }

    // Method to take damage
    virtual void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    // Virtual method for attack (can be overridden)
    virtual void attack(Character& target) {
        cout << name << " attacks " << target.getName()
                  << " for " << attackPower << " damage!" << endl;
        target.takeDamage(attackPower);
    }
};

// Player inherits from Character
class Player : public Character {
public:
    // Player-specific methods can go here

    // Override attack if needed
    void attack(Character& target) override {
        cout << "Player " << name << " attacks " << target.getName()
                  << " with power " << attackPower << "!" << endl;
        target.takeDamage(attackPower);
    }
};

// Enemy inherits from Character
class Enemy : public Character {
public:
    // Enemy-specific methods can go here

    // Override attack if needed
    void attack(Character& target) override {
        cout << "Enemy " << name << " attacks " << target.getName()
                  << " with power " << attackPower << "!" << endl;
        target.takeDamage(attackPower);
    }
};

int main() {
    Player player;
    player.setName("Hero");
    player.setHealth(100);
    player.setAttackPower(20);

    Enemy enemy;
    enemy.setName("Goblin");
    enemy.setHealth(50);
    enemy.setAttackPower(10);

    // Player attacks Enemy
    player.attack(enemy);
    cout << enemy.getName() << "'s health after attack: " << enemy.getHealth() << endl;

    // Enemy attacks Player back
    enemy.attack(player);
    cout << player.getName() << "'s health after attack: " << player.getHealth() << endl;

    return 0;
}
