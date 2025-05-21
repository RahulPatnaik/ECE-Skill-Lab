#include <iostream>
#include <cstring>

class Enemy; // Forward declaration

class Player {
public:
    char name[50];
    int health;
    int attackPower;

    void attack(Enemy& enemy); // Method to attack an enemy
};

class Enemy {
public:
    char name[50];
    int health;
    int attackPower;
};



















// Define Player's attack function
void Player::attack(Enemy& enemy) {
    std::cout << name << " attacks " << enemy.name << " for " << attackPower << " damage!" << std::endl;
    enemy.health -= attackPower;
    if (enemy.health < 0) enemy.health = 0;
}

int main() {
    // Create player and enemy
    Player player;
    std::strncpy(player.name, "Hero", sizeof(player.name));
    player.health = 100;
    player.attackPower = 20;

    Enemy enemy;
    std::strncpy(enemy.name, "Goblin", sizeof(enemy.name));
    enemy.health = 50;
    enemy.attackPower = 10;

    // Simulate an attack
    player.attack(enemy);

    // Output the result
    std::cout << "Enemy health: " << enemy.health << std::endl;

    return 0;
}
