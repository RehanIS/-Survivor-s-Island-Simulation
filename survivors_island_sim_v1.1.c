//Same as V1, just with improved vocabulary and health add on changed for med kits from restore to 100 to ((player.health)+20)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define player structure
typedef struct {
    int health;
    int wood;
    int water;
    int level;
    int shelters; // Number of shelters crafted
} Player;

// Function declarations
void exploreNorth(Player *player);
void exploreWest(Player *player);
void gatherWood(Player *player);
void gatherWater(Player *player);
void craftShelter(Player *player);
void levelUp(Player *player);

int main() {
    Player player = {100, 0, 0, 1, 0};  // Initialize player with 100 health, empty resources, starting level, and 0 shelters
    int action;

    // Game introduction
    printf("\n\n*TekLingo Destruction* Welcome's you to the Ultimate Survivor's Island!\n");
    printf("Your goal is to survive by gathering resources, crafting shelters, and exploring the island.\n");
    printf("You will encounter various challenges and opportunities as you strive to survive in this harsh environment.\n\n");

    // Instructions on how to play
    printf("Instructions:\n");
    printf("1. Explore the island to find resources like wood and water.\n");
    printf("2. Gather wood to craft shelters, which are essential for your survival.\n");
    printf("3. Keep an eye on your health; you may encounter dangers that can decrease it.\n");
    printf("4. Find healing packs to restore your health when it gets low.\n");
    printf("5. The game has three levels of increasing difficulty. You need to craft shelters to progress to the next level.\n");
    printf("   - Level 1: 1 shelter\n");
    printf("   - Level 2: 2 shelters\n");
    printf("   - Level 3: 3 shelters\n");
    printf("6. You win the game after successfully completing all three levels!\n\n");

    // Seed random number generator
    srand(time(0));

    // Game loop
    while (player.level <= 3) {
        printf("\nCurrent Level: %d\n", player.level);
        printf("Health: %d | Wood: %d | Water: %d | Shelters Crafted: %d\n", player.health, player.wood, player.water, player.shelters);
        printf("\nScroll above to view stats and instructions\n");
        printf("\nChoose an action:\n");
        printf("1. Explore North\n");
        printf("2. Look for wood\n");
        printf("3. Explore West\n");
        printf("4. Look for water\n");
        printf("5. Craft shelter\n");
        printf("Enter action number: ");
        scanf("%d", &action);

        switch (action) {
            case 1:
                exploreNorth(&player);
                break;
            case 2:
                gatherWood(&player);
                break;
            case 3:
                exploreWest(&player);
                break;
            case 4:
                gatherWater(&player);
                break;
            case 5:
                craftShelter(&player);
                break;
            default:
                printf("Invalid action. Try again.\n");
        }

        // Check if player has low health
        if (player.health <= 0) {
            printf("You have lost all your health (Game me nahi jeet sakta Engineering kya karega bhai..... Jeena chhod de tu) Game Over!\n");
            break;
        }

        // Level up condition
        if ((player.level == 1 && player.shelters >= 1) || 
            (player.level == 2 && player.shelters >= 2) || 
            (player.level == 3 && player.shelters >= 3)) {
            levelUp(&player); // Level up after enough shelters crafted
        }
    }

    if (player.level > 3) {
        printf("Congratulations! You have completed all levels and survived on the island! (Aur bhai party kab de rha hai fir)\n");
    }

    return 0;
}

// Function to explore North
void exploreNorth(Player *player) {
    printf("Exploring North...\n");

    int event = rand() % 4;  // Random event, increased to 4 to include healing packs

    if (event == 0) {
        printf("Wooohoooo.......You found some trees, gather some wood.\n");
        player->wood += 10;
    } else if (event == 1) {
        printf("Yayyyyyyyy......You found a river, gather water.\n");
        player->water += 5;
    } else if (event == 2) {
        printf("Oopss......You encounterd a wild animal, you loose 10 health. Remember you can recover your health by finding healing packs\n");
        player->health -= 10;
    } else {
        printf("Hoorahh.....You found a healing pack! Your health is restored by 20.\n");
        player->health = player->health+20; // Restore health by 20
    }
}

// Function to explore West (unique events)
void exploreWest(Player *player) {
    printf("Exploring West...\n");

    int event = rand() % 4;  // Random event for West

    if (event == 0) {
        printf("You find a hidden cave and discover extra resources!\n");
        player->wood += 20;  // Find more wood than North
        player->water += 10; // Find extra water
    } else if (event == 1) {
        printf("You encounter a dangerous cliff and lose 15 health.\n");
        player->health -= 15;
    } else if (event == 2) {
        printf("You stumble upon an abandoned camp and find extra supplies!\n");
        player->wood += 15;
        player->water += 5;
    } else {
        printf("You find a healing pack! Your health incremented by 20.\n");
        player->health = player->health+20; // Restore health byy 20
    }
}

// Function to gather wood
void gatherWood(Player *player) {
    printf("Gathering wood...\n");

    if (player->wood < 30) {
        player->wood += 10;
        printf("You gathered 10 units of wood. Total wood: %d\n", player->wood);
    } else {
        printf("You can't carry more wood.\n");
    }
}

// Function to gather water
void gatherWater(Player *player) {
    printf("Gathering water...\n");

    if (player->water < 15) {
        player->water += 5;
        printf("You gathered 5 units of water. Total water: %d\n", player->water);
    } else {
        printf("You can't carry more water.\n");
    }
}

// Function to craft a shelter
void craftShelter(Player *player) {
    if (player->wood >= 10 && player->water >= 5) {
        player->wood -= 10;
        player->water -= 5;
        player->shelters++; // Increment shelters count
        printf("Shelter crafted successfully! You have now crafted %d shelters.\n", player->shelters);
    } else {
        printf("Not enough resources to craft shelter.\n");
    }
}

// Function to level up
void levelUp(Player *player) {
    if (player->level < 3) {
        player->level++;
        printf("Congratulations! You've leveled up to Level %d!\n", player->level);
    }
}
