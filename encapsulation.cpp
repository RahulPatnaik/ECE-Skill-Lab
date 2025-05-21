#include <iostream>
#include <cstring>

using namespace std;

class Enemy; // Forward declaration

class Player {
private:
    char name[50];
    int health;
    int attackPower;

public:
    // Setters
    void setName(const char* newName) {
        strncpy(name, newName, sizeof(name));
    }

    void setHealth(int h) {
        if (h>200)
            health = 200;
        else
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

    // Method to attack an enemy
    void attack(Enemy& enemy);
};

class Enemy {
private:
    char name[50];
    int health;
    int attackPower;

public:
    // Setters
    void setName(const char* newName) {
        strncpy(name, newName, sizeof(name));
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

    // Allow Player to access Enemy’s private members via public interface
    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }
};




















// Define Player's attack function
void Player::attack(Enemy& enemy) {
    cout << getName() << " attacks " << enemy.getName() << " for " << getAttackPower() << " damage!" << endl;
    enemy.takeDamage(getAttackPower());
}

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

    // Simulate an attack
    player.attack(enemy);

    // Output the result
    cout << "Enemy health: " << enemy.getHealth() << endl;

    return 0;
}
