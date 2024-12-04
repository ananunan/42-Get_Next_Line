# 📖 Get Next Line: The Art of Reading, Line by Line 🌟  

Welcome to **Get Next Line**, where reading a file becomes an elegant adventure!  
This project is all about crafting a function that reads *exactly one line* at a time, no matter the size of the file or the complexity of its content. ✨  

---

## 📜 **What’s the Story?**  
Imagine a function so versatile it can:  
- Read from a file. 📂  
- Process standard input. ⌨️  
- Handle giant chunks of text without losing its cool. 💪  

Meet `get_next_line`—your new partner in text-processing crime!  

---

## 🛠️ **How It Works**  
`get_next_line` reads one line at a time, even if the line spans multiple buffers!  
It’s built with:  
- A **static variable** to save your progress like a bookmark. 📚  
- Clever use of `read()` to avoid overflow. 🌊  
- Buffers, because reading bit by bit is the key to success. 🔑  

---

## 🌟 **Features**  
- Supports **any file descriptor**. 🎉  
- Handles files of all sizes. 📜  
- Works its magic with a customizable `BUFFER_SIZE`. 🛠️  

---

## 🚀 **Getting Started**  
1. Clone this repository:  
   ```bash
   git clone https://github.com/ananunan/42-Get_Next_Line.git
   cd 42-Get_Next_Line
   
2. Compile with your code:
   `cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c`

3. Call get_next_line like a pro:
   ```bash
   char *line;
   while ((line = get_next_line(fd)) != NULL)
   {
    printf("%s", line);
    free(line);
   }

