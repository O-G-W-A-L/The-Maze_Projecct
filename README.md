# 🌀 Maze Game Project 🌀

## Introduction

Welcome to the Maze Game Project! This project is a maze generation and rendering application that utilizes raycasting and SDL2 to create a 3D maze experience. Explore the maze, navigate through the corridors, and find your way to the end. This project demonstrates the implementation of raycasting techniques to render 3D graphics in a maze environment.

🌐 **Deployed Site:** - https://github.com/O-G-W-A-L/the-maze_project  
📖 **Final Project Blog Article:** https://linkedin.com/pulse/maze-game-my-adventure-devlopment-jonathan-amos-ogwal-btytf/ 
💼 **Author's LinkedIn:** https://linkedin.com/in/jonathan-amos-ogwal-725926285/

---

## Project Story

### 🎮 Inspiration

I had never ventured into game development before and wanted to challenge myself. Inspired by classics like my own urge to try a something I had never done before coupled with chilhood games like Wolfenstein 3D and Doom, I decided to test my skills and learn new ones by creating my own maze game. This project is my journey to explore raycasting, improve my C programming and SDL2 knowledge, and share a game designed entirely by me.

### 🔧 Technical Challenges

Creating this maze game was far from easy and came with several daunting challenges:
- Raycasting Algorithm: Implementing the raycasting algorithm was a grueling task. Accurately rendering walls and textures tested my patience and pushed my coding skills to the limit. Every error felt like a setback, but each small victory was a triumph.
- Performance Optimization: Ensuring a smooth gaming experience was a relentless battle. The game lagged and stuttered, forcing me to delve deep into optimization techniques. Sleepless nights were spent tweaking the code to squeeze out every bit of performance.
- User Input Handling: Designing a responsive control system was a frustrating ordeal. I had to ensure seamless player movement, which meant dealing with unresponsive or erratic inputs. It was a harsh lesson in precision and detail, but essential for creating an engaging game.

### 🤔 Struggles and Learnings

The journey was filled with significant struggles and invaluable learnings:
- Texture Magnification Issues: Severe distortion with texture magnification was a major setback. Countless hours of research and experimentation eventually led to a solution that improved visual quality, making the struggle worthwhile.
- SDL2 Integration: Ensuring compatibility with Kali Linux was challenging. Numerous debugging attempts tested my patience, but the persistence paid off with a smoothly integrated system.
- Lagging and Performance Optimization: The game initially lagged and stuttered, leading to sleepless nights spent optimizing performance. The exhaustion was overwhelming, but achieving a smooth gaming experience was immensely satisfying.
- Rendering Logic and Math: Balancing intricate math for raycasting with SDL rendering logic was daunting. The constant trial and error wore me out, but each breakthrough brought a sense of accomplishment.
- Time Management and Exhaustion: Balancing this project with other responsibilities was tough, leading to severe exhaustion. Despite feeling worn out, the drive to complete the project kept me going.
Through these struggles, I grew in resilience and determination, making this project a deeply personal and transformative journey.

### 🌟 Next Iteration

- **Feature Additions:** Enemy AI, more maze levels, interactive elements like doors and keys.
- **Graphics Enhancements:** Detailed textures and lighting effects.

### 📅 Timeline

Despite the challenges, this project was developed in around 2 weeks! Here’s a breakdown of the timeline:

- **Day 1-3:** Research and planning, initial setup of the project.
- **Day 4-7:** Implementation of raycasting algorithm, basic maze generation.
- **Day 8-10:** Integration with SDL2, player controls, and optimization.
- **Day 11-13:** Testing, debugging, and final touches.

## Installation

To run this project locally on your terminal, follow these steps:

1. **Clone the repository:**
    ```sh
    git clone https://github.com/O-G-W-A-L/the-maze_game.git
    ```

2. **Navigate to the project directory:**
    ```sh
    cd the-maze_game
    ```

3. **Install the necessary dependencies:**
    - Ensure you have `SDL2` installed. You can install SDL2 using the following command:
      ```sh
      sudo apt-get install libsdl2-dev
      ```

4. **Compile the project:**
    ```sh
    make
    ```

5. **Run the executable:**
    ```sh
    ./main
    ```

---

## Usage

Once the project is set up and running, you can navigate through the maze using the following controls:

- **W:** Move forward
- **S:** Move backward
- **A:** Turn left
- **D:** Turn right

Your objective is to find your way through the maze in time to reach the end. Enjoy the challenge and immersive experience of exploring a 3D maze!

---

## Technical Details

### 🖼️ Raycasting Algorithm

The raycasting algorithm is the core of this project. It involves casting rays from the player's position into the maze to determine the distance to the walls. Each ray represents a vertical slice of the screen, and the distance to the wall determines the height of the wall slice. This technique creates a pseudo-3D effect, giving the illusion of depth and perspective.

### 🎨 Texture Mapping

Textures are applied to the walls to enhance the visual experience. The texture mapping process involves determining the exact point on the texture that corresponds to the intersection point of the ray and the wall. This project uses a variety of textures to create a more realistic environment.

### 🎮 Player Controls

The player controls are implemented to allow smooth and responsive movement through the maze. The controls include moving forward and backward and turning left and right. The player’s position and direction are updated based on the input, and the view is recalculated accordingly.

---

## Contributing

Contributions are welcome! If you would like to contribute to this project, please follow these steps:

1. **Fork the repository.**
2. **Create a new branch:**
    ```sh
    git checkout -b feature-branch
    ```
3. **Make your changes and commit them:**
    ```sh
    git commit -m 'Add some feature'
    ```
4. **Push to the branch:**
    ```sh
    git push origin feature-branch
    ```
5. **Create a pull request** on the original repository.

Please ensure that your contributions adhere to the project's coding standards and include appropriate tests where applicable.

---

## Related Projects

If you are interested in similar projects, check out these:

- Raycasting in C - https://github.com/wwwwelton/raycasting-c
- SDL2 Maze Game - https://github.com/DragonSWDev/glMaze
- 3D Game Development with Raycasting - https://github.com/vinibiavatti1/RayCastingTutorial

---

## Licensing

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

---

Thank you for checking out the Maze Game Project! If you have any questions or feedback, feel free to reach out. Enjoy exploring the maze!
