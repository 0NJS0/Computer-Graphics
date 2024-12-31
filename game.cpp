#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

// Window dimensions
const int window_width = 500;
const int window_height = 600;

// Player properties
float player_x = 0.0f;   // Player's x position
const float player_y = -0.9f; // Player's fixed y position
const float player_size = 0.1f;
float player_speed = 0.05f; // Speed of player movement

// Falling block properties
float block_x = 0.0f;
float block_y = 1.0f;
const float block_size = 0.1f;
float block_speed = 0.01f;

// Game over flag
bool game_over = false;

// Function to render the player
void renderPlayer() {
    glColor3f(0.0f, 1.0f, 0.0f); // Green player
    glBegin(GL_QUADS);
        glVertex2f(player_x - player_size, player_y - player_size);
        glVertex2f(player_x + player_size, player_y - player_size);
        glVertex2f(player_x + player_size, player_y + player_size);
        glVertex2f(player_x - player_size, player_y + player_size);
    glEnd();
}

// Function to render the falling block
void renderBlock() {
    glColor3f(1.0f, 0.0f, 0.0f); // Red block
    glBegin(GL_QUADS);
        glVertex2f(block_x - block_size, block_y - block_size);
        glVertex2f(block_x + block_size, block_y - block_size);
        glVertex2f(block_x + block_size, block_y + block_size);
        glVertex2f(block_x - block_size, block_y + block_size);
    glEnd();
}

// Check for collision between the player and the block
bool checkCollision() {
    if (block_y - block_size < player_y + player_size && block_y + block_size > player_y - player_size &&
        block_x + block_size > player_x - player_size && block_x - block_size < player_x + player_size) {
        return true;
    }
    return false;
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (!game_over) {
        renderPlayer();
        renderBlock();
    } else {
        // Game over text
        glColor3f(1.0f, 0.0f, 0.0f);
        glRasterPos2f(-0.1f, 0.0f);
        const char* gameOverText = "Game Over!";
        for (const char* c = gameOverText; *c != '\0'; c++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
        }
    }

    glutSwapBuffers();
}

// Timer callback for updating the game state
void update(int value) {
    if (!game_over) {
        // Update block position
        block_y -= block_speed;

        // If block goes off the screen, reset its position
        if (block_y < -1.0f) {
            block_y = 1.0f;
            block_x = (rand() % 200 - 100) / 100.0f; // Random new x position
            block_speed += 0.002f; // Increase block speed as difficulty ramps up
        }

        // Check for collision
        if (checkCollision()) {
            game_over = true;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // Update every ~16ms (~60fps)
}

// Keyboard input handler
void handleInput(int key, int x, int y) {
    if (!game_over) {
        if (key == GLUT_KEY_LEFT) {
            player_x -= player_speed;
            if (player_x - player_size < -1.0f) {
                player_x = -1.0f + player_size; // Keep player within the left boundary
            }
        } else if (key == GLUT_KEY_RIGHT) {
            player_x += player_speed;
            if (player_x + player_size > 1.0f) {
                player_x = 1.0f - player_size; // Keep player within the right boundary
            }
        }
    }
}

// Initialize OpenGL
void initOpenGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
}

// Main function
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0))); // Seed for random block position

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(window_width, window_height);
    glutCreateWindow("Dodge the Falling Blocks");

    initOpenGL();

    glutDisplayFunc(display);
    glutSpecialFunc(handleInput); // Register input handler for arrow keys
    glutTimerFunc(16, update, 0); // Timer function to update the game state

    glutMainLoop();
    return 0;
}
