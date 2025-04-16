# LearnOpenGL

This repository is a personal project where I experimented and learned the fundamentals (and some advanced features) of **OpenGL**. It includes various graphics programming concepts such as model loading, lighting, camera systems, instancing, and more.

The code is written in C++ and structured for modularity and clarity. A lot of learning and iteration went into building this project—this is the final form I’m uploading after grasping many of the core ideas.

---

## 🗂️ Project Structure

```
LearnOpenGL/
├── GLAD/           # GLAD loader project, linked to LearnOpenGL  
├── GLFW/           # GLFW project, also linked to LearnOpenGL  
├── LearnOpenGL/    # Main project folder  
│   ├── assets/     # Models, textures, images, etc.  
│   ├── shaders/    # All GLSL shaders  
│   └── main.cpp    # The entry point, puts everything together  
├── ThirdParty/     # External libraries: Assimp and GLM  
```

---

## ✨ Features

- **Model Loading** via Assimp  
- **Lighting**
- **3D Camera System** with support for:
  - Movement (WASD or arrow keys)
  - Mouse look
  - Zooming via scroll
- **Instancing** used to render **10,000+ asteroids** around Saturn model efficiently  
- **Shader System** to manage GLSL programs  
- **Mesh and Model Classes** to encapsulate OpenGL VAO/VBO/texture logic  

---

## 🪐 Default Scene

The current scene features:  
- A textured **Saturn model**  
- Surrounded by **10,000+ instanced asteroid models**  
- Rendered with proper transformation, lighting, and depth  

This demo showcases the power of **instanced rendering** in OpenGL.

---

## 🧠 What I Learned

- Core concepts of the OpenGL pipeline  
- Writing and managing GLSL shaders  
- How to use Assimp for model loading  
- How to structure a reusable rendering engine  
- Performance optimizations like **instancing**  
- Camera math and user interaction  

---

## 🔧 Dependencies

- [GLFW](https://www.glfw.org/)  
- [GLAD](https://glad.dav1d.de/)  
- [GLM](https://github.com/g-truc/glm)  
- [Assimp](https://github.com/assimp/assimp)  

All third-party libraries are included under the `GLAD/`, `GLFW/`, and `ThirdParty/` directories.

---

## 🚀 Getting Started

1. Clone the repository  
2. Open the project in your favorite IDE (like Visual Studio or CLion)  
3. Build the `LearnOpenGL` target  
4. Run the application and explore Saturn’s asteroid field 🚀  

---

## 📸 Screenshots

![image](https://github.com/user-attachments/assets/a390d51f-ffe5-4372-a05b-a64c3143685d)
![image](https://github.com/user-attachments/assets/e551a3cb-fd7c-425d-ac85-b182e4f069de)
![image](https://github.com/user-attachments/assets/3671d094-13e0-41fe-a6f4-8e97f94a83fe)
![image](https://github.com/user-attachments/assets/cf01a684-f490-48b3-b9b8-f3b30719d8d1)

---

## 📌 Notes

This repository serves as a milestone in my OpenGL learning journey. There may be some rough edges or unfinished features, but the core systems work as intended.

---

## 📫 Contact

Feel free to open issues or discussions if you want to ask questions or give feedback!
